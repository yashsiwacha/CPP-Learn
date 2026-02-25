// Program to demonstrate Polymorphism using the Shape Hierarchy
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
using namespace std;
#define PI 3.14

// Base class Shape demonstrates polymorphism through virtual functions
// Virtual functions allow derived classes to override methods while maintaining a common interface
class Shape
{
public:
    // Pure virtual function = 0 makes this an abstract class
    // Each derived class MUST implement its own version of area()
    // This is called dynamic dispatch - the correct function is called at runtime based on object type
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    // Virtual destructor is required so deleting through Shape* runs derived destructors first.
    // This ensures correct cleanup and shows destructor chain in polymorphic hierarchies.
    virtual ~Shape()
    {
        cout << "Shape destructor called." << endl;
    }
};

class Circle : public Shape
{
    double radius;

public:
    Circle(double r)
    {
        this->radius = r;
    }
    // Override: provides Circle-specific area calculation
    double area() const
    {
        return PI * radius * radius;
    }

    double perimeter() const
    {
        return 2 * PI * radius;
    }

    ~Circle() override
    {
        cout << "Circle destructor called." << endl;
    }
};

class Rectangle : public Shape
{
    double length;
    double width;

public:
    Rectangle(double l, double w)
    {
        this->length = l;
        this->width = w;
    }
    // Override: provides Rectangle-specific area calculation
    double area() const
    {
        return length * width;
    }

    double perimeter() const
    {
        return 2 * (length + width);
    }

    ~Rectangle() override
    {
        cout << "Rectangle destructor called." << endl;
    }
};

class Triangle : public Shape
{
    double base;
    double height;

public:
    Triangle(double b, double h)
    {
        this->base = b;
        this->height = h;
    }
    // Override: provides Triangle-specific area calculation
    double area() const
    {
        return 0.5 * base * height;
    }

    // Treating this as a right triangle: third side = sqrt(base^2 + height^2).
    double perimeter() const
    {
        return base + height + sqrt(base * base + height * height);
    }

    ~Triangle() override
    {
        cout << "Triangle destructor called." << endl;
    }
};

int main()
{
    // Create a vector that can hold pointers to any Shape
    // This demonstrates polymorphism - one container for multiple derived types
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Circle>(5.21));
    shapes.push_back(make_unique<Rectangle>(25.2, 52.5));
    shapes.push_back(make_unique<Triangle>(3.21, 25.01));

    // Dynamic dispatch: correct area() and perimeter() are selected at runtime.
    cout << "Circle area: " << shapes[0]->area() << ", perimeter: " << shapes[0]->perimeter() << endl;
    cout << "Rectangle area: " << shapes[1]->area() << ", perimeter: " << shapes[1]->perimeter() << endl;
    cout << "Triangle area: " << shapes[2]->area() << ", perimeter: " << shapes[2]->perimeter() << endl;

    cout << "Exiting main -> unique_ptr will trigger destructor chain automatically." << endl;

    return 0;
}