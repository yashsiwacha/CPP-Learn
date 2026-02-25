// Program to demonstrate operator overloading in C++
// Operator overloading allows us to redefine how operators work with user-defined types
// This enables intuitive syntax like c1 + c2 for complex number addition

#include <iostream>
using namespace std;

class Complex
{
private:
    double real; // Real part of complex number
    double imag; // Imaginary part of complex number

public:
    // Constructor to initialize complex number
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overloaded operator+ as a member function
    // This allows syntax: c1 + c2
    // The left operand (c1) is the implicit 'this' object
    // The right operand (c2) is passed as a parameter
    Complex operator+(const Complex &other) const
    {
        // Add real parts and imaginary parts separately
        double newReal = this->real + other.real;
        double newImag = this->imag + other.imag;
        return Complex(newReal, newImag);
    }

    // Declare operator<< as a friend function
    // Friend functions can access private members of the class
    // operator<< must be a friend (not a member) because:
    // - The left operand is cout (an ostream object), not a Complex object
    // - We cannot add members to the ostream class
    friend ostream &operator<<(ostream &out, const Complex &c);
};

// Definition of operator<< as a friend function
// This enables syntax: cout << c1
// Parameters:
// - out: reference to the output stream (cout)
// - c: the Complex object to be printed
ostream &operator<<(ostream &out, const Complex &c)
{
    // Print in standard mathematical format: "a + bi" or "a - bi"
    out << c.real;
    if (c.imag >= 0)
        out << " + " << c.imag << "i";
    else
        out << " - " << -c.imag << "i"; // Use -c.imag to print positive value after minus sign
    return out;                         // Return the stream to allow chaining (e.g., cout << c1 << c2)
}

int main()
{
    // Create two Complex objects
    Complex c1(2.5, 4.5);  // 2.5 + 4.5i
    Complex c2(3.5, -1.5); // 3.5 - 1.5i

    // Demonstrate operator overloading
    cout << "Complex Number 1: " << c1 << endl;
    cout << "Complex Number 2: " << c2 << endl;

    // Add two complex numbers using overloaded operator+
    // The compiler translates c1 + c2 to c1.operator+(c2)
    Complex result = c1 + c2;

    cout << "\nResult of addition (c1 + c2): " << result << endl;

    // Additional demonstration: chaining operations
    Complex c3(1.0, 2.0);
    Complex finalResult = c1 + c2 + c3;
    cout << "Result of c1 + c2 + c3: " << finalResult << endl;

    return 0;
}