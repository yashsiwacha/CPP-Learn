/*
 * Feature Toggle Using #ifdef and #else
 *
 * This program demonstrates conditional compilation for debug mode.
 * Compile with -DDEBUG flag to enable debug output.
 * Compile without -DDEBUG flag for production mode (no debug output).
 *
 * Compilation Examples:
 *   Debug Mode:      g++ -DDEBUG debug_toggle.cpp -o debug_toggle.exe
 *   Production Mode: g++ debug_toggle.cpp -o debug_toggle.exe
 */

#include <iostream>
#include <string>

// ============================================================
// DEBUG.H - Header Section (Feature Toggle Implementation)
// ============================================================

#ifndef DEBUG_H
#define DEBUG_H

// Check if DEBUG macro is defined
#ifdef DEBUG
// Debug mode: DEBUG_PRINT macro outputs debug information
#define DEBUG_PRINT(x) std::cout << "[DEBUG] " << x << std::endl
#define DEBUG_MODE_STATUS "ENABLED"
#else
// Production mode: DEBUG_PRINT macro does nothing (empty statement)
#define DEBUG_PRINT(x) ((void)0)
#define DEBUG_MODE_STATUS "DISABLED"
#endif

#endif // DEBUG_H

// ============================================================
// MAIN PROGRAM - Demonstrates Debug Feature Toggle
// ============================================================

// Sample function to demonstrate debug logging in functions
int calculateSum(int a, int b)
{
    DEBUG_PRINT("calculateSum called with a=" << a << ", b=" << b);
    int result = a + b;
    DEBUG_PRINT("Result: " << result);
    return result;
}

// Sample function to demonstrate debugging in complex operations
double divide(double numerator, double denominator)
{
    DEBUG_PRINT("divide called with numerator=" << numerator
                                                << ", denominator=" << denominator);

    if (denominator == 0)
    {
        DEBUG_PRINT("ERROR: Division by zero detected!");
        std::cerr << "Error: Cannot divide by zero!" << std::endl;
        return 0.0;
    }

    double result = numerator / denominator;
    DEBUG_PRINT("Division result: " << result);
    return result;
}

// Sample class to demonstrate debug logging in OOP
class Calculator
{
private:
    int operationCount;

public:
    Calculator() : operationCount(0)
    {
        DEBUG_PRINT("Calculator object created");
    }

    int multiply(int x, int y)
    {
        DEBUG_PRINT("multiply called with x=" << x << ", y=" << y);
        operationCount++;
        DEBUG_PRINT("Operation count: " << operationCount);
        return x * y;
    }

    int getOperationCount() const
    {
        return operationCount;
    }

    ~Calculator()
    {
        DEBUG_PRINT("Calculator destroyed. Total operations: " << operationCount);
    }
};

int main()
{
    std::cout << "==================================================" << std::endl;
    std::cout << "  Feature Toggle Demo: Debug Mode Control" << std::endl;
    std::cout << "==================================================" << std::endl;
    std::cout << "Debug Mode: " << DEBUG_MODE_STATUS << std::endl;
    std::cout << "==================================================" << std::endl;
    std::cout << std::endl;

    DEBUG_PRINT("Program started");
    DEBUG_PRINT("Initializing variables...");

    // Test 1: Simple arithmetic operations
    std::cout << "Test 1: Addition Operation" << std::endl;
    int num1 = 15, num2 = 25;
    DEBUG_PRINT("Declaring variables: num1=" << num1 << ", num2=" << num2);
    int sum = calculateSum(num1, num2);
    std::cout << "Result: " << num1 << " + " << num2 << " = " << sum << std::endl;
    std::cout << std::endl;

    // Test 2: Division with debug logging
    std::cout << "Test 2: Division Operation" << std::endl;
    double a = 100.0, b = 4.0;
    DEBUG_PRINT("Testing division: " << a << " / " << b);
    double quotient = divide(a, b);
    std::cout << "Result: " << a << " / " << b << " = " << quotient << std::endl;
    std::cout << std::endl;

    // Test 3: Division by zero (error handling)
    std::cout << "Test 3: Division by Zero (Error Case)" << std::endl;
    double c = 50.0, d = 0.0;
    DEBUG_PRINT("Testing division by zero: " << c << " / " << d);
    double invalidResult = divide(c, d);
    std::cout << std::endl;

    // Test 4: Using Calculator class with debug logging
    std::cout << "Test 4: Calculator Class Operations" << std::endl;
    {
        Calculator calc;
        DEBUG_PRINT("Created Calculator instance");

        int x = 7, y = 8;
        std::cout << "Calculating: " << x << " * " << y << std::endl;
        int product = calc.multiply(x, y);
        std::cout << "Result: " << product << std::endl;

        x = 12;
        y = 3;
        std::cout << "Calculating: " << x << " * " << y << std::endl;
        product = calc.multiply(x, y);
        std::cout << "Result: " << product << std::endl;

        std::cout << "Total operations performed: " << calc.getOperationCount() << std::endl;
        DEBUG_PRINT("About to destroy Calculator object");
    }
    std::cout << std::endl;

    // Test 5: Loop with debug information
    std::cout << "Test 5: Loop Operations" << std::endl;
    DEBUG_PRINT("Starting loop to calculate squares");
    for (int i = 1; i <= 5; i++)
    {
        DEBUG_PRINT("Iteration " << i << ": calculating " << i << "^2");
        int square = i * i;
        std::cout << i << "^2 = " << square << std::endl;
    }
    DEBUG_PRINT("Loop completed");
    std::cout << std::endl;

    // Program completion
    std::cout << "==================================================" << std::endl;
    std::cout << "  Program Execution Completed Successfully!" << std::endl;
    std::cout << "==================================================" << std::endl;

#ifdef DEBUG
    std::cout << "\n[INFO] Debug messages were displayed above." << std::endl;
    std::cout << "[INFO] Compile without -DDEBUG to disable them." << std::endl;
#else
    std::cout << "\n[INFO] Debug mode is OFF." << std::endl;
    std::cout << "[INFO] Compile with -DDEBUG flag to see debug messages." << std::endl;
#endif

    DEBUG_PRINT("Program terminated");

    return 0;
}
