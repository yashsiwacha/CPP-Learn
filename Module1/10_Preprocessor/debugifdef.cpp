/*
 * Debug Macro Demonstration Program
 *
 * This program demonstrates:
 * - Conditional compilation using #ifdef
 * - Macro definitions and usage
 * - Debug vs Release mode compilation
 *
 * To compile:
 * - Debug mode:   g++ -DDEBUG debugifdef.cpp -o debugifdef.exe
 * - Release mode: g++ debugifdef.cpp -o debugifdef.exe
 */

#include <iostream>

// Define DEBUG to enable debug printing (or use -DDEBUG compiler flag)
#define DEBUG

#include "debug.h"
using namespace std;

int main()
{
    cout << "Program started." << endl;

    // This will print only if DEBUG is defined
    DEBUG_PRINT("Debugging is enabled.");
    DEBUG_PRINT("This is a debug message.");

    // Regular C++ code
    int x = 42;
    cout << "Value of x: " << x << endl;

#ifdef DEBUG
    cout << "[DEBUG]: Value of x: " << x << endl;
#endif

    cout << "Program finished." << endl;

    return 0;
}