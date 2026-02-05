// Program to demonstrate Hierachical Inheritance.
#include <iostream>
using namespace std;
#define PI 3.14
class Shape
{
protected:
    string name;

public:
    // Getter and Setter for name
    void setName(string n) { name = n; }
    string getName() const { return name; }

    void draw()
    {
        cout << "Drawing the shape." << endl;
    }
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

class Circle : public Shape
{
    double radius;

public:
    // Constructor
    Circle(double r = 0.0)
    {
        radius = r;
        name = "Circle";
    }

    // Getter and Setter for radius
    void setRadius(double r) { radius = r; }
    double getRadius() const { return radius; }

    double area() const override
    {
        return PI * radius * radius;
    }
    double perimeter() const override
    {
        return PI * radius * 2;
    }
};
class Square : public Shape
{
    double side;

public:
    // Constructor
    Square(double s = 0.0)
    {
        side = s;
        name = "Square";
    }

    // Getter and Setter for side
    void setSide(double s) { side = s; }
    double getSide() const { return side; }

    double area() const override
    {
        return side * side;
    }
    double perimeter() const override
    {
        return 4 * side;
    }
};

class Rectangle : public Shape
{
    int length;
    int width;

public:
    // Constructor
    Rectangle(int l = 0, int w = 0)
    {
        length = l;
        width = w;
        name = "Rectangle";
    }

    // Getters and Setters for length and width
    void setLength(int l) { length = l; }
    int getLength() const { return length; }
    void setWidth(int w) { width = w; }
    int getWidth() const { return width; }

    double area() const override
    {
        return length * width;
    }
    double perimeter() const override
    {
        return 2 * (length + width);
    }
};

int main()
{
    cout << "========== HIERARCHICAL INHERITANCE DEMONSTRATION ==========" << endl;
    cout << "Shape (Base) -> Circle, Square, Rectangle (Derived Classes)" << endl;
    cout << "============================================================" << endl;

    // ========== CIRCLE DEMONSTRATION ==========
    cout << "\n--- Creating Circle Object ---" << endl;
    Circle circle(5.0);

    cout << "Shape Name: " << circle.getName() << endl;
    cout << "Radius: " << circle.getRadius() << endl;
    cout << "Area: " << circle.area() << endl;
    cout << "Perimeter: " << circle.perimeter() << endl;
    circle.draw();

    cout << "\n--- Modifying Circle using Setters ---" << endl;
    circle.setRadius(7.5);
    cout << "New Radius: " << circle.getRadius() << endl;
    cout << "New Area: " << circle.area() << endl;
    cout << "New Perimeter: " << circle.perimeter() << endl;

    // ========== SQUARE DEMONSTRATION ==========
    cout << "\n--- Creating Square Object ---" << endl;
    Square square(4.0);

    cout << "Shape Name: " << square.getName() << endl;
    cout << "Side Length: " << square.getSide() << endl;
    cout << "Area: " << square.area() << endl;
    cout << "Perimeter: " << square.perimeter() << endl;
    square.draw();

    cout << "\n--- Modifying Square using Setters ---" << endl;
    square.setSide(6.0);
    cout << "New Side Length: " << square.getSide() << endl;
    cout << "New Area: " << square.area() << endl;
    cout << "New Perimeter: " << square.perimeter() << endl;

    // ========== RECTANGLE DEMONSTRATION ==========
    cout << "\n--- Creating Rectangle Object ---" << endl;
    Rectangle rectangle(8, 5);

    cout << "Shape Name: " << rectangle.getName() << endl;
    cout << "Length: " << rectangle.getLength() << endl;
    cout << "Width: " << rectangle.getWidth() << endl;
    cout << "Area: " << rectangle.area() << endl;
    cout << "Perimeter: " << rectangle.perimeter() << endl;
    rectangle.draw();

    cout << "\n--- Modifying Rectangle using Setters ---" << endl;
    rectangle.setLength(10);
    rectangle.setWidth(7);
    cout << "New Length: " << rectangle.getLength() << endl;
    cout << "New Width: " << rectangle.getWidth() << endl;
    cout << "New Area: " << rectangle.area() << endl;
    cout << "New Perimeter: " << rectangle.perimeter() << endl;

    // ========== COMPARISON ==========
    cout << "\n--- Comparing All Shapes ---" << endl;
    cout << "Circle (r=" << circle.getRadius() << "):        Area = " << circle.area() << endl;
    cout << "Square (s=" << square.getSide() << "):        Area = " << square.area() << endl;
    cout << "Rectangle (l=" << rectangle.getLength() << ", w=" << rectangle.getWidth() << "): Area = " << rectangle.area() << endl;

    cout << "\n========== HIERARCHICAL INHERITANCE BENEFITS ==========" << endl;
    cout << "1. All shapes inherit common functionality from Shape base class" << endl;
    cout << "2. Each derived class adds its specific properties and calculations" << endl;
    cout << "3. Code reuse through inheritance (draw method shared by all)" << endl;
    cout << "============================================================" << endl;

    return 0;
}