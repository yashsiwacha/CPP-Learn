// Program to demonstrate compile-time polymorphism (function overloading) in C++
//
// Function Overloading: Multiple functions with the same name but different parameters
// This is a form of compile-time polymorphism where the compiler determines which
// function to call based on the number and types of arguments at compile time.
//
// How the compiler resolves function overloading:
// 1. The compiler examines the function name and the argument types at the call site
// 2. It matches these against all available overloaded functions with that name
// 3. The function whose parameter types exactly match (or best match) the argument types is selected
// 4. This resolution happens during compilation, not at runtime, making it "compile-time polymorphism"
// 5. Each function has a unique signature: function_name + parameter_types

#include <iostream>
using namespace std;

class Calculator
{
public:
    // Overloaded add() function for integer addition
    // Signature: add(int, int)
    // The compiler selects this version when both arguments are of type int
    int add(int a, int b)
    {
        return a + b;
    }

    // Overloaded add() function for double addition
    // Signature: add(double, double)
    // The compiler selects this version when both arguments are of type double
    double add(double a, double b)
    {
        return a + b;
    }

    // Overloaded add() function for string concatenation
    // Signature: add(const string&, const string&)
    // The compiler selects this version when both arguments are of type string
    string add(const string &a, const string &b)
    {
        return a + b;
    }
};

int main()
{
    Calculator cal;
    string a = "Yash";
    string b = " Aryan";

    // Demonstrating compile-time polymorphism through function overloading
    // The compiler examines each call to add() and matches it to the appropriate overload
    // by analyzing the argument types at compile time (not at runtime)

    // Call 1: Compiler sees add(int, int) and selects the int version
    cout << "Result of adding integers (1 + 5): " << cal.add(1, 5) << endl;

    // Call 2: Compiler sees add(double, double) and selects the double version
    cout << "Result of adding doubles (1.022 + 2.558): " << cal.add(1.022, 2.558) << endl;

    // Call 3: Compiler sees add(string, string) and selects the string version
    cout << "Result of concatenating strings (\"Yash\" + \" Aryan\"): " << cal.add(a, b) << endl;

    return 0;
}