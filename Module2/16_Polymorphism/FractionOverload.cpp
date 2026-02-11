// Program to demonstrate operator overloading with Fraction class
//
// Operator Overloading: Redefining the behavior of operators for user-defined types
// Benefits:
// 1. Makes code more intuitive and readable (f1 == f2 instead of f1.equals(f2))
// 2. Allows user-defined types to behave like built-in types
// 3. Enables natural mathematical notation for custom classes
//
// How the compiler resolves operator overloading:
// 1. The compiler identifies the operator and the types of operands
// 2. It searches for operator overload functions that match the signature
// 3. For member functions: left operand is 'this', right operand is the parameter
// 4. For friend functions: both operands are explicit parameters
// 5. The matching operator function is called at compile time
// 6. This is compile-time polymorphism (resolved during compilation)

#include <iostream>
using namespace std;

class Fraction
{
    int numerator;
    int denominator;

public:
    Fraction(int n = 0, int d = 1) : numerator(n), denominator(d) {}

    // Overloaded operator== to compare two fractions for equality
    // Signature: bool operator==(const Fraction&) const
    // Called when: fraction1 == fraction2
    // The compiler translates f1 == f2 to f1.operator==(f2)
    // Uses cross-multiplication to avoid division and maintain precision
    // Logic: a/b == c/d if and only if a*d == b*c
    bool operator==(const Fraction &f) const
    {
        return (numerator * f.denominator) == (denominator * f.numerator);
    }

    // Overloaded operator< to compare two fractions for less-than relation
    // Signature: bool operator<(const Fraction&) const
    // Called when: fraction1 < fraction2
    // The compiler translates f1 < f2 to f1.operator<(f2)
    // Uses cross-multiplication to avoid floating-point errors
    // Logic: a/b < c/d if and only if a*d < b*c (assuming positive denominators)
    bool operator<(const Fraction &c) const
    {
        return (numerator * c.denominator) < (denominator * c.numerator);
    }

    // Friend function declaration to overload operator<< for output
    // Must be a friend because:
    // - The left operand is ostream (cout), not Fraction
    // - We cannot add member functions to the standard library ostream class
    // - Friend status allows access to private members (numerator, denominator)
    friend ostream &operator<<(ostream &out, const Fraction &f);
};

// Overloaded operator<< to enable printing fractions with cout
// Signature: ostream& operator<<(ostream&, const Fraction&)
// Called when: cout << fraction
// Returns ostream& to enable chaining: cout << f1 << f2
ostream &operator<<(ostream &out, const Fraction &f)
{
    out << f.numerator << "/" << f.denominator;
    return out;
}

int main()
{
    Fraction f1(2, 4);  // 2/4 = 0.5
    Fraction f2(4, 8);  // 4/8 = 0.5
    Fraction f3(4, 16); // 4/16 = 0.25

    // Display the fractions using overloaded operator<<
    cout << "Created fractions:" << endl;
    cout << "  f1 = " << f1 << " (decimal: 0.5)" << endl;
    cout << "  f2 = " << f2 << " (decimal: 0.5)" << endl;
    cout << "  f3 = " << f3 << " (decimal: 0.25)" << endl;

    // Test operator== with user-friendly output
    cout << "\nEquality Comparison (operator==):" << endl;
    cout << "  f1 is equal to f2: " << (f1 == f2 ? "true" : "false") << endl;
    cout << "  f1 is equal to f3: " << (f1 == f3 ? "true" : "false") << endl;

    // Test operator< with user-friendly output
    cout << "\nLess-than Comparison (operator<):" << endl;
    cout << "  f1 is less than f3: " << (f1 < f3 ? "true" : "false") << " (0.5 < 0.25 is false)" << endl;
    cout << "  f3 is less than f1: " << (f3 < f1 ? "true" : "false") << " (0.25 < 0.5 is true)" << endl;
    cout << "  f1 is less than f2: " << (f1 < f2 ? "true" : "false") << " (equal values)" << endl;

    return 0;
}