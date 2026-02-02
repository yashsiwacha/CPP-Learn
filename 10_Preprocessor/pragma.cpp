// Program demonstrating #pragma directives
#include <iostream>
#pragma message("Compiling pragma.cpp - Start")

#pragma warning(disable : 4996) // Disable deprecated function warnings
using namespace std;

int main()
{
    cout << "Hello, World!" << endl;
    int a = 4996;
    cout << "Value of a: " << a << endl;
}