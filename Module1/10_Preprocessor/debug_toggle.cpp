// Program demonstrating conditional compilation for debug mode
#include <iostream>
#include <string>

#ifndef DEBUG_H
#define DEBUG_H

#ifdef DEBUG
#define DEBUG_PRINT(x) cout << "[DEBUG] " << x << endl
#define DEBUG_MODE_STATUS "ENABLED"
#else
#define DEBUG_PRINT(x) ((void)0)
#define DEBUG_MODE_STATUS "DISABLED"
#endif

#endif

int calculateSum(int a, int b)
{
    DEBUG_PRINT("calculateSum called with a=" << a << ", b=" << b);
    int result = a + b;
    DEBUG_PRINT("Result: " << result);
    return result;
}

double divide(double numerator, double denominator)
{
    DEBUG_PRINT("divide called with numerator=" << numerator
                                                << ", denominator=" << denominator);

    if (denominator == 0)
    {
        DEBUG_PRINT("ERROR: Division by zero detected!");
        cerr << "Error: Cannot divide by zero!" << endl;
        return 0.0;
    }

    double result = numerator / denominator;
    DEBUG_PRINT("Division result: " << result);
    return result;
}

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
    cout << "Debug Mode: " << DEBUG_MODE_STATUS << "\n\n";

    DEBUG_PRINT("Program started");
    DEBUG_PRINT("Initializing variables...");

    // Test 1: Simple arithmetic operations
    cout << "Test 1: Addition Operation" << endl;
    int num1 = 15, num2 = 25;
    DEBUG_PRINT("Declaring variables: num1=" << num1 << ", num2=" << num2);
    int sum = calculateSum(num1, num2);
    cout << "Result: " << num1 << " + " << num2 << " = " << sum << endl;
    cout << endl;

    // Test 2: Division with debug logging
    cout << "Test 2: Division Operation" << endl;
    double a = 100.0, b = 4.0;
    DEBUG_PRINT("Testing division: " << a << " / " << b);
    double quotient = divide(a, b);
    cout << "Result: " << a << " / " << b << " = " << quotient << endl;
    cout << endl;

    // Test 3: Division by zero (error handling)
    cout << "Test 3: Division by Zero (Error Case)" << endl;
    double c = 50.0, d = 0.0;
    DEBUG_PRINT("Testing division by zero: " << c << " / " << d);
    double invalidResult = divide(c, d);
    cout << endl;

    // Test 4: Using Calculator class with debug logging
    cout << "Test 4: Calculator Class Operations" << endl;
    {
        Calculator calc;
        DEBUG_PRINT("Created Calculator instance");

        int x = 7, y = 8;
        cout << "Calculating: " << x << " * " << y << endl;
        int product = calc.multiply(x, y);
        cout << "Result: " << product << endl;

        x = 12;
        y = 3;
        cout << "Calculating: " << x << " * " << y << endl;
        product = calc.multiply(x, y);
        cout << "Result: " << product << endl;

        cout << "Total operations performed: " << calc.getOperationCount() << endl;
        DEBUG_PRINT("About to destroy Calculator object");
    }
    cout << endl;

    // Test 5: Loop with debug information
    cout << "Test 5: Loop Operations" << endl;
    DEBUG_PRINT("Starting loop to calculate squares");
    for (int i = 1; i <= 5; i++)
    {
        DEBUG_PRINT("Iteration " << i << ": calculating " << i << "^2");
        int square = i * i;
        cout << i << "^2 = " << square << endl;
    }
    DEBUG_PRINT("Loop completed");
    cout << endl;

    // Program completion
    cout << "==================================================" << endl;
    cout << "  Program Execution Completed Successfully!" << endl;
    cout << "==================================================" << endl;

#ifdef DEBUG
    cout << "\n[INFO] Debug messages were displayed above." << endl;
    cout << "[INFO] Compile without -DDEBUG to disable them." << endl;
#else
    cout << "\n[INFO] Debug mode is OFF." << endl;
    cout << "[INFO] Compile with -DDEBUG flag to see debug messages." << endl;
#endif

    DEBUG_PRINT("Program terminated");

    return 0;
}
