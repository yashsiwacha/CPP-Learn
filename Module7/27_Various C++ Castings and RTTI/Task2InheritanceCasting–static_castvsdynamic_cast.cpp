#include <iostream>
#include <typeinfo>

class Shape
{
public:
    virtual ~Shape() = default; // Polymorphic base is required for dynamic_cast

    virtual void draw() const
    {
        std::cout << "Drawing Shape" << std::endl;
    }
};

class Circle : public Shape
{
public:
    void draw() const override
    {
        std::cout << "Drawing Circle" << std::endl;
    }

    void circleSpecific() const
    {
        std::cout << "Circle-specific method" << std::endl;
    }
};

class Rectangle : public Shape
{
public:
    void draw() const override
    {
        std::cout << "Drawing Rectangle" << std::endl;
    }

    void rectangleSpecific() const
    {
        std::cout << "Rectangle-specific method" << std::endl;
    }
};

int main()
{
    Shape *s = new Circle();

    std::cout << "--- static_cast ---" << std::endl;
    Circle *c1 = static_cast<Circle *>(s); // Unchecked downcast; safe only if actual type is Circle
    if (c1)
    {
        c1->circleSpecific();
    }

    Shape *s2 = new Rectangle();
    // Wrong static_cast example (do not execute):
    // static_cast only changes the pointer type at compile time.
    // It does NOT verify the runtime object type, so this downcast can compile
    // and still become undefined behavior when used.
    // Circle* c2 = static_cast<Circle*>(s2);
    // c2->circleSpecific(); // Undefined behavior because s2 is not a Circle

    std::cout << "--- dynamic_cast ---" << std::endl;
    Circle *c3 = dynamic_cast<Circle *>(s); // Succeeds
    if (c3)
    {
        c3->circleSpecific();
        std::cout << "dynamic_cast to Circle* succeeded." << std::endl;
    }
    else
    {
        std::cout << "dynamic_cast to Circle* failed." << std::endl;
    }

    Rectangle *r = dynamic_cast<Rectangle *>(s); // Fails and returns nullptr
    if (r)
    {
        r->rectangleSpecific();
    }
    else
    {
        std::cout << "dynamic_cast to Rectangle* failed (nullptr)" << std::endl;
    }

    std::cout << "\n--- dynamic_cast with references ---" << std::endl;
    try
    {
        Circle &refOk = dynamic_cast<Circle &>(*s); // Success: *s is Circle
        refOk.circleSpecific();
        std::cout << "dynamic_cast<Circle&>(*s) succeeded." << std::endl;
    }
    catch (const std::bad_cast &e)
    {
        std::cout << "Unexpected failure: " << e.what() << std::endl;
    }

    try
    {
        Circle &refFail = dynamic_cast<Circle &>(*s2); // Throws: *s2 is Rectangle
        refFail.circleSpecific();
    }
    catch (const std::bad_cast &e)
    {
        std::cout << "dynamic_cast<Circle&>(*s2) failed with std::bad_cast: " << e.what() << std::endl;
    }

    std::cout << "\nSafety difference:" << std::endl;
    std::cout << "- static_cast does not check runtime type for downcasting." << std::endl;
    std::cout << "- dynamic_cast performs runtime type checking and returns nullptr on failure." << std::endl;
    std::cout << "- For references, dynamic_cast throws std::bad_cast on failure." << std::endl;
    std::cout << "- Always check pointer results for nullptr before using them." << std::endl;
    std::cout << "- Prefer dynamic_cast when actual derived type is uncertain." << std::endl;

    delete s;
    delete s2;

    return 0;
}
