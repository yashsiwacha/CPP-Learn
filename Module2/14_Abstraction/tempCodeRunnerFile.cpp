// Program to demonstrate abstraction using abstract classes in C++
#include <iostream>
#include <vector>
#define PI 3.14
using namespace std;
// Abstract class
class Shape
{
public:
    // Using virtual functions to make the class abstract.
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

// Inherting the abstract class
// Circle class is child class of Shape
class Circle : public Shape
{
    double radius;

public:
    Circle(double radius)
    {
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
    double base;
    double height;

public:
    Triangle(double base, double height)
    {
        this->base = base;
        this->height = height;
    }
    // Overriding the area function.
    double area() const
    {
        return 0.5 * base * height;
    }
    // Overriding the perimeter function.
    double perimeter() const
    {
        // For a simple triangle, we can't calculate perimeter with just base and height
        // Returning an approximate value
        return base * 3;
    }
};

int main()
{
    // Using Vector to store Differnt shapes .
    vector<Shape *> shapes;
    shapes.push_back(new Circle(5));
    shapes.push_back(new Rectangle(4, 6));
    shapes.push_back(new Triangle(4, 5));

    for (Shape *shape : shapes)
    {
        cout << "Area: " << shape->area() << endl;
        cout << "Perimeter: " << shape->perimeter() << endl;
    }
    for (Shape *shape : shapes)
    {
        delete shape;
    }
}