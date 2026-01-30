/*
 * Dynamic Calculator Using Callbacks
 *
 * This program demonstrates the use of function pointers as callbacks to create
 * a flexible, modular calculator that can dynamically select operations at runtime.
 *
 * Key Concepts Demonstrated:
 * - Function pointers as callbacks
 * - Higher-order functions (functions that take functions as arguments)
 * - Strategy Pattern (runtime algorithm selection)
 * - Error handling with callbacks
 * - Modular and extensible code design
 */

#include <iostream>
#include <limits>
using namespace std;

// Error code for division by zero
const int DIV_BY_ZERO_ERROR = INT_MIN;

/*
 * Arithmetic Operation Functions
 * Each function takes two integers and returns their computed result
 */

// Addition operation
int add(int a, int b)
{
    return a + b;
}

// Subtraction operation
int subtract(int a, int b)
{
    return a - b;
}

// Multiplication operation
int multiply(int a, int b)
{
    return a * b;
}

// Division operation with error handling
int divide(int a, int b)
{
    if (b == 0)
    {
        cout << "ERROR: Division by zero is not allowed!" << endl;
        return DIV_BY_ZERO_ERROR;
    }
    return a / b;
}

/*
 * Generic Calculate Function (Callback Style)
 *
 * This function demonstrates the callback mechanism by accepting a function pointer
 * that determines which operation to perform.
 *
 * Parameters:
 *   a         - First operand
 *   b         - Second operand
 *   operation - Function pointer to the arithmetic operation to perform
 *
 * Returns:
 *   Result of the operation, or error code if operation fails
 */
int calculate(int a, int b, int (*operation)(int, int))
{
    // Invoke the callback function with the provided operands
    return operation(a, b);
}

/*
 * Helper function to print operation results
 */
void printResult(const char *operationName, int a, int b, int result)
{
    if (result == DIV_BY_ZERO_ERROR)
    {
        cout << operationName << ": " << a << " and " << b << " -> ERROR (Division by zero)" << endl;
    }
    else
    {
        cout << operationName << ": " << a << " and " << b << " = " << result << endl;
    }
}

/*
 * Demonstration function showing advanced usage with function pointer arrays
 * This creates a "dispatch table" for operations
 */
void demonstrateDispatchTable(int a, int b)
{
    // Array of function pointers (dispatch table)
    int (*operations[])(int, int) = {add, subtract, multiply, divide};
    const char *operationNames[] = {"Addition", "Subtraction", "Multiplication", "Division"};

    cout << "\n=== Dispatch Table Demonstration ===" << endl;
    cout << "Performing all operations on " << a << " and " << b << ":" << endl
         << endl;

    // Iterate through all operations
    for (int i = 0; i < 4; i++)
    {
        int result = calculate(a, b, operations[i]);
        printResult(operationNames[i], a, b, result);
    }
}

/*
 * Main Program
 */
int main()
{
    // Declare test operands
    int num1 = 20;
    int num2 = 5;
    int num3 = 0; // For testing division by zero

    cout << "=================================================" << endl;
    cout << "   Dynamic Calculator Using Function Pointers   " << endl;
    cout << "=================================================" << endl
         << endl;

    // Demonstrate each operation individually using callbacks
    cout << "=== Individual Operation Demonstrations ===" << endl
         << endl;

    // Addition
    int result = calculate(num1, num2, add);
    printResult("Addition", num1, num2, result);

    // Subtraction
    result = calculate(num1, num2, subtract);
    printResult("Subtraction", num1, num2, result);

    // Multiplication
    result = calculate(num1, num2, multiply);
    printResult("Multiplication", num1, num2, result);

    // Division (normal case)
    result = calculate(num1, num2, divide);
    printResult("Division", num1, num2, result);

    // Division by zero test
    cout << "\n=== Error Handling Test ===" << endl;
    result = calculate(num1, num3, divide);
    printResult("Division", num1, num3, result);

    // Demonstrate dispatch table approach
    demonstrateDispatchTable(100, 25);

    // Additional demonstration: changing operations at runtime
    cout << "\n=== Runtime Operation Selection ===" << endl;
    cout << "Simulating user-selected operation..." << endl
         << endl;

    // Simulate user selecting operation 3 (multiply)
    int operationChoice = 2; // 0=add, 1=subtract, 2=multiply, 3=divide
    int (*selectedOperation)(int, int);

    switch (operationChoice)
    {
    case 0:
        selectedOperation = add;
        break;
    case 1:
        selectedOperation = subtract;
        break;
    case 2:
        selectedOperation = multiply;
        break;
    case 3:
        selectedOperation = divide;
        break;
    default:
        cout << "Invalid operation choice!" << endl;
        return 1;
    }

    result = calculate(50, 7, selectedOperation);
    cout << "Selected Operation Result: 50 and 7 = " << result << endl;

    // Demonstrate chaining operations
    cout << "\n=== Chaining Operations ===" << endl;
    int chainResult = calculate(10, 5, add);           // 10 + 5 = 15
    chainResult = calculate(chainResult, 3, multiply); // 15 * 3 = 45
    chainResult = calculate(chainResult, 9, subtract); // 45 - 9 = 36
    chainResult = calculate(chainResult, 6, divide);   // 36 / 6 = 6
    cout << "Result of chained operations: ((10 + 5) * 3 - 9) / 6 = " << chainResult << endl;

    cout << "\n=================================================" << endl;
    cout << "Program completed successfully!" << endl;
    cout << "=================================================" << endl;

    return 0;
}
