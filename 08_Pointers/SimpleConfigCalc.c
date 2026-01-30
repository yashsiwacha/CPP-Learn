/*
 * Simple Configurable Calculator - Function Pointer Demonstration
 *
 * This program demonstrates how to use function pointers to dynamically
 * select and call different arithmetic operations at runtime.
 *
 * Learning Objectives:
 * - Declare function pointer variables
 * - Assign function addresses to pointers
 * - Call functions indirectly through pointers
 * - Understand runtime function selection
 */

#include <stdio.h>
#include <stdlib.h>

// ==================== Arithmetic Function Definitions ====================

/*
 * Function: add
 * Purpose: Adds two integers
 * Parameters: a, b - integers to be added
 * Returns: Sum of a and b
 */
int add(int a, int b)
{
    return a + b;
}

/*
 * Function: subtract
 * Purpose: Subtracts second integer from first
 * Parameters: a, b - integers where b is subtracted from a
 * Returns: Difference of a and b
 */
int subtract(int a, int b)
{
    return a - b;
}

/*
 * Function: multiply
 * Purpose: Multiplies two integers
 * Parameters: a, b - integers to be multiplied
 * Returns: Product of a and b
 */
int multiply(int a, int b)
{
    return a * b;
}

/*
 * Function: divide
 * Purpose: Divides first integer by second (integer division)
 * Parameters: a, b - integers where a is divided by b
 * Returns: Quotient of a and b (0 if b is 0 to avoid division by zero)
 */
int divide(int a, int b)
{
    if (b == 0)
    {
        printf("Error: Division by zero!\n");
        return 0;
    }
    return a / b;
}

// ==================== Main Program ====================

int main()
{
    printf("=== Simple Configurable Calculator ===\n");
    printf("Demonstrating Function Pointers in C\n\n");

    // Test values for our calculations
    int num1 = 15;
    int num2 = 5;
    int result;

    // ==================== Step 1: Declare Function Pointer ====================
    /*
     * Declare a function pointer variable named 'operation'
     * Syntax: return_type (*pointer_name)(parameter_types)
     * This pointer can point to any function that:
     * - Takes two int parameters
     * - Returns an int
     */
    int (*operation)(int, int);

    printf("Step 1: Function Pointer Declared\n");
    printf("Pointer 'operation' can now point to functions with signature: int func(int, int)\n\n");

    // ==================== Step 2: Assign and Call - Addition ====================
    printf("Step 2: Assigning 'add' function to pointer\n");
    operation = add; // or operation = &add; (both are valid)

    printf("Calling: operation(%d, %d)\n", num1, num2);
    result = operation(num1, num2); // or result = (*operation)(num1, num2);
    printf("Result: %d + %d = %d\n\n", num1, num2, result);

    // ==================== Step 3: Reassign - Subtraction ====================
    printf("Step 3: Reassigning pointer to 'subtract' function\n");
    operation = subtract;

    printf("Calling: operation(%d, %d)\n", num1, num2);
    result = operation(num1, num2);
    printf("Result: %d - %d = %d\n\n", num1, num2, result);

    // ==================== Step 4: Reassign - Multiplication ====================
    printf("Step 4: Reassigning pointer to 'multiply' function\n");
    operation = multiply;

    printf("Calling: operation(%d, %d)\n", num1, num2);
    result = operation(num1, num2);
    printf("Result: %d * %d = %d\n\n", num1, num2, result);

    // ==================== Step 5: Reassign - Division ====================
    printf("Step 5: Reassigning pointer to 'divide' function\n");
    operation = divide;

    printf("Calling: operation(%d, %d)\n", num1, num2);
    result = operation(num1, num2);
    printf("Result: %d / %d = %d\n\n", num1, num2, result);

    // ==================== Advanced: User-Driven Selection ====================
    printf("\n=== Interactive Mode ===\n");
    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter choice (1-4): ");

    int choice;
    scanf("%d", &choice);

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Select function based on user choice
    switch (choice)
    {
    case 1:
        operation = add;
        printf("\nSelected: Addition\n");
        break;
    case 2:
        operation = subtract;
        printf("\nSelected: Subtraction\n");
        break;
    case 3:
        operation = multiply;
        printf("\nSelected: Multiplication\n");
        break;
    case 4:
        operation = divide;
        printf("\nSelected: Division\n");
        break;
    default:
        printf("\nInvalid choice! Defaulting to Addition.\n");
        operation = add;
    }

    // Execute the selected operation
    result = operation(num1, num2);
    printf("Result: %d\n", result);

    // ==================== Bonus: Dispatch Table (Array of Function Pointers) ====================
    printf("\n\n=== Bonus: Dispatch Table Demo ===\n");
    printf("Using an array of function pointers for cleaner code\n\n");

    // Create an array of function pointers
    int (*operations[4])(int, int) = {add, subtract, multiply, divide};
    const char *operation_names[] = {"Addition", "Subtraction", "Multiplication", "Division"};

    // Test all operations using the dispatch table
    int test_a = 20, test_b = 4;
    printf("Testing with numbers: %d and %d\n\n", test_a, test_b);

    for (int i = 0; i < 4; i++)
    {
        printf("%s: ", operation_names[i]);
        result = operations[i](test_a, test_b);
        printf("%d\n", result);
    }

    printf("\n=== Program Complete ===\n");
    printf("Key Takeaways:\n");
    printf("1. Function pointers enable runtime function selection\n");
    printf("2. Syntax: return_type (*pointer_name)(parameter_types)\n");
    printf("3. Assignment: pointer = function_name;\n");
    printf("4. Call: result = pointer(args);\n");
    printf("5. Arrays of function pointers create dispatch tables\n");

    return 0;
}
