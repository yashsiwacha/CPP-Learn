/*
 * DEMO_FILE1.CPP
 * ==============
 * First source file that includes demo_header.h
 * Contains implementation of some functions declared in the header
 */

#include "demo_header.h"
#include <iostream>
using namespace std;

// Global variable definition
int globalCounter = 0;

// Function implementations
void printWelcomeMessage()
{
    cout << "========================================" << endl;
    cout << "   Welcome to Header Guards Demo!" << endl;
    cout << "========================================" << endl;
    cout << "This function is implemented in demo_file1.cpp" << endl;
    globalCounter++;
}

void displayVersion()
{
    cout << "\nProgram Version: " << VERSION << endl;
    cout << "Implemented in: demo_file1.cpp" << endl;
    globalCounter++;
}

double calculateCircleArea(double radius)
{
    cout << "\nCalculating area (from demo_file1.cpp)..." << endl;
    globalCounter++;
    return PI * square(radius); // Using inline function from header
}

int add(int a, int b)
{
    globalCounter++;
    return a + b;
}
