// Program to demonstrate the use of 'this' pointer in C++ OOPs.
// The 'this' pointer is an implicit pointer that points to the object for which
// a member function is called. It helps in resolving naming conflicts and enables
// method chaining.

#include <iostream>
#include <string>
using namespace std;

class Box
{
private:
    // Private data members for proper encapsulation
    int length, width, height;
    string name;

public:
    // Constructor demonstrates 'this' pointer resolving naming conflict
    // When parameter name matches member variable name, 'this->' distinguishes them
    Box(string name)
    {
        this->name = name; // 'this->name' refers to member variable, 'name' is parameter
    }

    // Setter function using 'this' pointer for clarity and consistency
    // 'this->' explicitly shows we're setting the current object's members
    void setDimensions(int l, int w, int h)
    {
        this->length = l;
        this->width = w;
        this->height = h;
    }

    // Getter functions for private members
    int getLength() const { return length; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    string getName() const { return name; }

    // Calculate volume - const function doesn't modify object state
    float calculateVolume() const
    {
        return length * width * height;
    }

    // Compare volumes and return reference to the box with greater volume
    // Takes const reference to avoid copying and ensure the parameter isn't modified
    // Returns const reference for efficiency and to prevent modification
    const Box &compareVolume(const Box &b) const
    {
        if (calculateVolume() > b.calculateVolume())
        {
            return *this; // Dereference 'this' to return current object by reference
        }
        else
        {
            return b;
        }
    }
};

int main()
{
    // Creating two box objects with names
    Box b1("Box1");
    Box b2("Box2");

    // Setting dimensions for both boxes
    b1.setDimensions(10, 20, 30);
    b2.setDimensions(20, 30, 40);

    cout << "\nBox1 Dimensions\n";
    cout << "Length: " << b1.getLength() << "\n";
    cout << "Width: " << b1.getWidth() << "\n";
    cout << "Height: " << b1.getHeight() << "\n";
    cout << "Volume: " << b1.calculateVolume() << " cubic units\n";

    cout << "\nBox2 Dimensions\n";
    cout << "Length: " << b2.getLength() << "\n";
    cout << "Width: " << b2.getWidth() << "\n";
    cout << "Height: " << b2.getHeight() << "\n";
    cout << "Volume: " << b2.calculateVolume() << " cubic units\n";

    cout << "\nComparison Result\n";
    const Box &largerBox = b1.compareVolume(b2);
    cout << "Box with greater volume: " << largerBox.getName() << "\n";

    return 0;
}