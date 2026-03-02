#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

class Circle;

class Rectangle
{
private:
    double length;
    double width;

public:
    Rectangle(double length, double width) : length(length), width(width) {}

    friend void compareArea(const Rectangle &rectangle, const Circle &circle);
};

class Circle
{
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    friend void compareArea(const Rectangle &rectangle, const Circle &circle);
};

void compareArea(const Rectangle &rectangle, const Circle &circle)
{
    const double pi = 3.14159265358979323846;
    const double rectangleArea = rectangle.length * rectangle.width;
    const double circleArea = pi * circle.radius * circle.radius;

    cout << fixed << setprecision(2);
    cout << "Rectangle Area: " << rectangleArea << '\n';
    cout << "Circle Area   : " << circleArea << '\n';

    const double epsilon = 1e-9;
    if (rectangleArea - circleArea > epsilon)
    {
        cout << "Result: Rectangle has the larger area.\n";
    }
    else if (circleArea - rectangleArea > epsilon)
    {
        cout << "Result: Circle has the larger area.\n";
    }
    else
    {
        cout << "Result: Both areas are equal.\n";
    }
}

int main()
{
    Rectangle rectangle(6.0, 5.0);
    Circle circle(3.0);

    compareArea(rectangle, circle);

    return 0;
}
