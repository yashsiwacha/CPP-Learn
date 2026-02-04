// Program to demonstrate abstraction using abstract classes in C++
// Abstraction: Hiding implementation details and showing only essential features
// Polymorphism: Ability to process objects differently based on their data type/class
#include <iostream>
#include <vector>
#include <memory> // For smart pointers
#include <cmath>
#define PI 3.14
using namespace std;

// Abstract class - Cannot be instantiated directly
// Contains at least one pure virtual function (= 0)
// Provides interface for derived classes
class Shape
{
private:
    string name; // Encapsulated member variable

public:
    // Getter function for name (Encapsulation)
    string getName() const { return name; }

    // Setter function for name
    void setName(const string &shapeName) { name = shapeName; }

    // Pure virtual functions - must be overridden by derived classes
    // Using virtual functions to make the class abstract.
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    // Virtual destructor for proper cleanup of derived classes
    // Critical when deleting derived objects through base class pointers
    virtual ~Shape() {}
};

// Inherting the abstract class
// Circle class is child class of Shape
class Circle : public Shape
{
    double radius;

public:
    Circle(double radius)
    {
        setName("Circle"); // Use setter for encapsulation
        this->radius = radius;
    }
    // Overriding the area function.
    double area() const
    {
        return PI * radius * radius;
    }

    // Overriding the perimeter function.
    double perimeter() const
    {
        return 2 * PI * radius;
    }
};

// Inherting the abstract class
// Rectangle class is child class of Shape
class Rectangle : public Shape
{
    double length;
    double width;

public:
    Rectangle(double length, double width)
    {
        setName("Rectangle"); // Use setter for encapsulation
        this->length = length;
        this->width = width;
    }

    // Overriding the area function.
    double area() const
    {
        return length * width;
    }
    // Overriding the perimeter function.
    double perimeter() const
    {
        return 2 * (length + width);
    }
};

// Inherting the abstract class
// Triangle class is child class of Shape
class Triangle : public Shape
{
    double side1;
    double side2;
    double side3;

public:
    Triangle(double side1, double side2, double side3)
    {
        setName("Triangle"); // Use setter for encapsulation
        this->side1 = side1;
        this->side2 = side2;
        this->side3 = side3;
    }
    // Overriding the area function using Heron's formula.
    double area() const
    {
        // Using Heron's formula to calculate area
        double s = (side1 + side2 + side3) / 2; // semi-perimeter
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
    // Overriding the perimeter function - sum of all three sides.
    double perimeter() const
    {
        return side1 + side2 + side3;
    }
};

int main()
{
    // Demonstrating Polymorphism:
    // Using a vector of base class smart pointers to store different derived class objects
    // std::unique_ptr provides automatic memory management (no manual delete needed)
    vector<unique_ptr<Shape>> shapes;

    // Creating objects and transferring ownership to unique_ptr
    shapes.push_back(make_unique<Circle>(5));
    shapes.push_back(make_unique<Rectangle>(4, 6));
    shapes.push_back(make_unique<Triangle>(3, 4, 5)); // Right triangle with sides 3, 4, 5

    // Polymorphic behavior: calling overridden methods through base class pointers
    // The correct method is called based on the actual object type at runtime (dynamic binding)
    for (const auto &shape : shapes)
    {
        cout << "The Shape is " << shape->getName() << endl; // Using getter for encapsulation
        cout << "Area: " << shape->area() << endl;
        cout << "Perimeter: " << shape->perimeter() << endl;
        cout << "------------------------" << endl;
    }

    // No manual delete needed - unique_ptr automatically cleans up memory
    return 0;
}