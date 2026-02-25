#include <iostream>
#include <string>

// Shared base class at the top of the diamond hierarchy.
class LivingBeing
{
protected:
    std::string name;

public:
    explicit LivingBeing(const std::string &livingName = "Unknown")
        : name(livingName)
    {
    }

    void setName(const std::string &livingName)
    {
        name = livingName;
    }

    void show() const
    {
        std::cout << "LivingBeing name: " << name << " | this = " << this << std::endl;
    }
};

// Animal and Plant both inherit from LivingBeing.
// `virtual` is essential here: without it, Hybrid would contain two separate
// LivingBeing subobjects (one from Animal path and one from Plant path).
// Virtual inheritance ensures both paths share one common LivingBeing instance.
class Animal : virtual public LivingBeing
{
public:
    explicit Animal(const std::string &livingName = "Unknown")
        : LivingBeing(livingName)
    {
    }
};

class Plant : virtual public LivingBeing
{
public:
    explicit Plant(const std::string &livingName = "Unknown")
        : LivingBeing(livingName)
    {
    }
};

// Most-derived class combines both branches of the diamond.
// In virtual inheritance, the most-derived class is responsible for constructing
// the virtual base (LivingBeing).
class Hybrid : public Animal, public Plant
{
public:
    explicit Hybrid(const std::string &livingName)
        : LivingBeing(livingName), Animal(livingName), Plant(livingName)
    {
    }
};

int main()
{
    Hybrid hybrid("Chimera");
    std::cout << "Demonstrating virtual inheritance in a diamond hierarchy" << std::endl;
    std::cout << "Expected: both base-path addresses should be identical (single LivingBeing instance)." << std::endl;

    std::cout << "Accessing LivingBeing::show() through Animal path:" << std::endl;
    static_cast<Animal *>(&hybrid)->show();

    std::cout << "Accessing LivingBeing::show() through Plant path:" << std::endl;
    static_cast<Plant *>(&hybrid)->show();

    LivingBeing *viaAnimal = static_cast<LivingBeing *>(static_cast<Animal *>(&hybrid));
    LivingBeing *viaPlant = static_cast<LivingBeing *>(static_cast<Plant *>(&hybrid));

    std::cout << "Address of LivingBeing instance via Animal path: " << viaAnimal << std::endl;
    std::cout << "Address of LivingBeing instance via Plant path : " << viaPlant << std::endl;

    if (viaAnimal == viaPlant)
    {
        std::cout << "Confirmation: addresses are identical, so Hybrid has exactly one shared LivingBeing instance." << std::endl;
    }
    else
    {
        std::cout << "Warning: addresses differ (this would indicate duplicate LivingBeing subobjects)." << std::endl;
    }

    return 0;
}
