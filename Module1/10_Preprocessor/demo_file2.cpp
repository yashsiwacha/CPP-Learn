/*
 * DEMO_FILE2.CPP
 * ==============
 * Second source file that also includes demo_header.h
 * Contains implementation of other functions declared in the header
 */

#include "demo_header.h"
#include <iostream>
using namespace std;

// This file also includes demo_header.h
// Without header guards, this would cause redefinition errors!

// Function implementations
double calculateCirclePerimeter(double radius)
{
    cout << "\nCalculating perimeter (from demo_file2.cpp)..." << endl;
    extern int globalCounter; // Access global variable from demo_file1.cpp
    globalCounter++;
    return 2 * PI * radius;
}

int multiply(int a, int b)
{
    extern int globalCounter;
    globalCounter++;
    return a * b;
}

void demonstrateHeaderGuards()
{
    cout << "\n========================================" << endl;
    cout << "   Header Guards Working Properly!" << endl;
    cout << "========================================" << endl;
    cout << "Both demo_file1.cpp and demo_file2.cpp" << endl;
    cout << "include demo_header.h without errors!" << endl;
    cout << "\nThis is only possible because of the" << endl;
    cout << "header guards: #ifndef, #define, #endif" << endl;
}
