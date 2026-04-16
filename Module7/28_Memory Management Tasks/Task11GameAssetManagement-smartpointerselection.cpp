#include <iostream>
#include <memory>
#include <string>

class Texture
{
private:
    std::string name;

public:
    explicit Texture(const std::string &textureName) : name(textureName)
    {
        std::cout << "[Texture] Loading: " << name << std::endl;
    }

    ~Texture()
    {
        std::cout << "[Texture] Unloading: " << name << std::endl;
    }

    void render() const
    {
        std::cout << "[Texture] Rendering with: " << name << std::endl;
    }
};

class Shader
{
private:
    std::string name;

public:
    explicit Shader(const std::string &shaderName) : name(shaderName)
    {
        std::cout << "[Shader] Compiling: " << name << std::endl;
    }

    ~Shader()
    {
        std::cout << "[Shader] Deleting: " << name << std::endl;
    }

    void apply() const
    {
        std::cout << "[Shader] Applying: " << name << std::endl;
    }
};

class GameObject
{
private:
    // Exclusive ownership: each GameObject owns exactly one Texture instance.
    std::unique_ptr<Texture> texture_;

    // Shared ownership: multiple GameObjects can reuse the same Shader.
    std::shared_ptr<Shader> shader_;

public:
    GameObject(const std::string &textureName, std::shared_ptr<Shader> sharedShader)
        : texture_(std::make_unique<Texture>(textureName)), shader_(std::move(sharedShader))
    {
        std::cout << "[GameObject] Created." << std::endl;
    }

    ~GameObject()
    {
        std::cout << "[GameObject] Destroyed." << std::endl;
    }

    void draw() const
    {
        texture_->render();
        shader_->apply();
    }

    void changeTexture(const std::string &newTextureName)
    {
        texture_ = std::make_unique<Texture>(newTextureName);
    }
};

int main()
{
    std::shared_ptr<Shader> defaultLightingShader = std::make_shared<Shader>("BasicLightingShader");
    std::shared_ptr<Shader> postFxShader = std::make_shared<Shader>("GrayscaleFilterShader");

    GameObject player("PlayerTexture", defaultLightingShader);
    GameObject enemy("EnemyTexture", defaultLightingShader);
    GameObject background("BackgroundTexture", postFxShader);

    std::cout << "\n--- Drawing GameObjects ---" << std::endl;
    player.draw();
    enemy.draw();
    background.draw();

    std::cout << "\n--- Change Player Texture ---" << std::endl;
    player.changeTexture("PlayerDamagedTexture");
    player.draw();

    std::cout << "\n--- Demonstrate Scope-based Cleanup ---" << std::endl;
    {
        std::cout << "Entering a local scope..." << std::endl;
        GameObject temporaryProp("TempPropTexture", defaultLightingShader);
        temporaryProp.draw();
        std::cout << "Exiting local scope..." << std::endl;
    }

    std::cout << "\nProgram end. Remaining objects will be cleaned automatically." << std::endl;
    return 0;
}
