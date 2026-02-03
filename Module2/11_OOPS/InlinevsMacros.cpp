/*
 * Program to demonstrate the difference between inline functions and macros.
 *
 * KEY DIFFERENCES:
 * 1. Type Safety: Inline functions provide type checking, macros do not
 * 2. Debugging: Inline functions can be debugged, macros are harder to debug
 * 3. Expression Handling: Macros can cause unexpected behavior without proper parentheses
 * 4. Scope: Inline functions follow C++ scope rules, macros do not
 *
 * RISKS OF MACROS:
 * - No type checking (can lead to runtime errors)
 * - Text substitution can cause operator precedence issues
 * - Multiple evaluation of arguments (side effects)
 * - Harder to debug (expanded during preprocessing)
 *
 * ADVANTAGES OF INLINE FUNCTIONS:
 * - Type safety with compile-time checking
 * - Proper scope and namespace support
 * - Easier to debug
 * - No unexpected side effects
 * - Arguments evaluated only once
 */

#include <iostream>
using namespace std;

// UNSAFE MACRO: Without proper parentheses
// This will cause issues with expressions due to operator precedence
#define SQUARE_UNSAFE(x) x *x

// SAFE MACRO: With proper parentheses to handle expressions correctly
// Always wrap the parameter and the entire expression in parentheses
#define SQUARE_SAFE(x) ((x) * (x))

// INLINE FUNCTION: Type-safe alternative to macros
// Provides compile-time type checking and evaluates arguments only once
inline int square(int x)
{
    return x * x;
}

// Overloaded inline function for double type
// Demonstrates type safety advantage over macros
inline double square(double x)
{
    return x * x;
}

int main()
{
    cout << "Inline Functions vs Macros\n\n";

    // Test 1: Simple integer value
    cout << "--- Test 1: Simple Integer Value ---" << endl;
    int x = 11;
    cout << "Input: " << x << endl;
    cout << "Unsafe Macro Result: " << SQUARE_UNSAFE(x) << endl;
    cout << "Safe Macro Result:   " << SQUARE_SAFE(x) << endl;
    cout << "Inline Function:     " << square(x) << endl;
    cout << "✓ All methods work correctly with simple values\n"
         << endl;

    // Test 2: Expression (demonstrates the problem with unsafe macros)
    cout << "--- Test 2: Expression (1+2) ---" << endl;
    cout << "Expected Result: (1+2)*(1+2) = 9" << endl;
    cout << "Unsafe Macro Result: " << SQUARE_UNSAFE(1 + 2) << " ✗ WRONG!" << endl;
    cout << "  Explanation: Expands to 1+2*1+2 = 1+2+2 = 5 (operator precedence issue)" << endl;
    cout << "Safe Macro Result:   " << SQUARE_SAFE(1 + 2) << " ✓ Correct!" << endl;
    cout << "Inline Function:     " << square(1 + 2) << " ✓ Correct!" << endl;
    cout << "✓ Proper parentheses in macros prevent operator precedence issues\n"
         << endl;

    // Test 3: Type safety with double
    cout << "--- Test 3: Type Safety with Double ---" << endl;
    double d = 3.5;
    cout << "Input: " << d << endl;
    cout << "Safe Macro Result:   " << SQUARE_SAFE(d) << " (no type checking)" << endl;
    cout << "Inline Function:     " << square(d) << " (type-safe, uses overloaded version)" << endl;
    cout << "✓ Inline functions provide type safety and overloading\n"
         << endl;

    // Test 4: Side effects demonstration
    cout << "--- Test 4: Side Effects (Increment) ---" << endl;
    int y = 5;
    int z = 5;
    cout << "Initial value: y = " << y << ", z = " << z << endl;
    cout << "Macro SQUARE_SAFE(++y): " << SQUARE_SAFE(++y) << " (y is now: " << y << ")" << endl;
    cout << "  Warning: Macro evaluates ++y twice! Result: (++y)*(++y) = 6*7 = 42" << endl;
    cout << "Inline square(++z): " << square(++z) << " (z is now: " << z << ")" << endl;
    cout << "  Inline function evaluates ++z only once! Result: square(6) = 36" << endl;
    cout << "✓ Inline functions avoid multiple argument evaluation\n"
         << endl;

    cout << "=== CONCLUSION ===" << endl;
    cout << "Prefer inline functions over macros for:" << endl;
    cout << "  • Type safety and compile-time checking" << endl;
    cout << "  • Predictable behavior with expressions" << endl;
    cout << "  • Avoiding side effects from multiple evaluation" << endl;
    cout << "  • Better debugging experience" << endl;

    return 0;
}