#include <iostream>
#include <typeinfo>

class Animal
{
public:
    virtual ~Animal() = default; // Required for RTTI with polymorphic behavior

    virtual void speak() const
    {
        std::cout << "Animal speaks" << std::endl;
    }
};

class Dog : public Animal
{
public:
    void speak() const override
    {
        std::cout << "Woof!" << std::endl;
    }

    void fetch() const
    {
        std::cout << "Dog fetching..." << std::endl;
    }
};

class Cat : public Animal
{
public:
    void speak() const override
    {
        std::cout << "Meow!" << std::endl;
    }

    void scratch() const
    {
        std::cout << "Cat scratching..." << std::endl;
    }
};

void identifyAnimal(Animal *a)
{
    if (!a)
    {
        std::cout << "Null pointer provided." << std::endl;
        return;
    }

    // typeid reveals the dynamic type for polymorphic objects.
    std::cout << "typeid: " << typeid(*a).name() << std::endl;

    // dynamic_cast performs a safe runtime-checked downcast.
    if (Dog *dog = dynamic_cast<Dog *>(a))
    {
        dog->fetch();
    }
    else if (Cat *cat = dynamic_cast<Cat *>(a))
    {
        cat->scratch();
    }
    else
    {
        std::cout << "Unknown animal type." << std::endl;
    }
}

int main()
{
    Animal *animals[3] = {new Dog(), new Cat(), new Animal()};

    for (Animal *a : animals)
    {
        a->speak();
        identifyAnimal(a);
    }

    Animal *onlyCat = new Cat();
    Dog *wrongDogCast = dynamic_cast<Dog *>(onlyCat);
    if (wrongDogCast == nullptr)
    {
        std::cout << "dynamic_cast<Dog*>(Cat*) failed safely (nullptr)." << std::endl;
    }
    delete onlyCat;

    for (Animal *a : animals)
    {
        delete a;
    }

    std::cout << "\nRTTI notes:" << std::endl;
    std::cout << "- Use typeid when you need to query or display runtime type information." << std::endl;
    std::cout << "- Use dynamic_cast when you need safe downcasting to call derived-specific APIs." << std::endl;
    std::cout << "- If RTTI is disabled (for example, g++ -fno-rtti), typeid/dynamic_cast on polymorphic types may fail to compile." << std::endl;
    std::cout << "- dynamic_cast returns nullptr for failed pointer casts." << std::endl;

    return 0;
}
