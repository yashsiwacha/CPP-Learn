// Program to demonstrate Polymorphism using the Shape Hierarchy
#include <iostream>
#include <vector>
#include <memory>
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
    virtual ~Shape() {} // Virtual destructor for proper cleanup
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
};

int main()
{
    // Create a vector that can hold pointers to any Shape
    // This demonstrates polymorphism - one container for multiple derived types
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Circle>(5.21));
    shapes.push_back(make_unique<Rectangle>(25.2, 52.5));
    shapes.push_back(make_unique<Triangle>(3.21, 25.01));

    // Dynamic dispatch: the correct area() method is called based on actual object type at runtime
    cout << "Circle area: " << shapes[0]->area() << endl;
    cout << "Rectangle area: " << shapes[1]->area() << endl;
    cout << "Triangle area: " << shapes[2]->area() << endl;

    return 0;
}