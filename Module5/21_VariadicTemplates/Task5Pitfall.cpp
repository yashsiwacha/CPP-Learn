#include <iostream>

// ── THE PITFALL ───────────────────────────────────────────────────────────────
// Variadic templates resolve the base-case overload at *template definition*
// time, not at instantiation time. If the base case appears AFTER the template,
// the compiler cannot find it when processing the recursive call and emits:
//   "no matching function for call to 'printAll()'"
//
// ── THE FIX ──────────────────────────────────────────────────────────────────
// Declare the base-case overload BEFORE the template so it is already visible
// when the template body is compiled.

// Base case: called with no arguments (when the pack Args... is fully expanded).
void printAll()
{
    std::cout << "\n";
}

// Recursive case: prints the first argument, then recurses on the rest.
// 'int a' peels off one argument per call; Args... holds the remainder.
// When Args... becomes empty, the call resolves to the base case above.
template <typename... Args>
void printAll(int a, Args... args)
{
    std::cout << a << " ";
    printAll(args...); // OK: base case is visible because it was declared first
}

int main()
{
    std::cout << "--- Test 1: multiple ints (1, 2, 3) ---\n";
    std::cout << "Output: ";
    printAll(1, 2, 3); // expands: printAll(1,{2,3}) → printAll(2,{3}) → printAll(3,{}) → printAll()

    std::cout << "--- Test 2: single int (42) ---\n";
    std::cout << "Output: ";
    printAll(42); // expands: printAll(42,{}) → printAll()

    std::cout << "--- Test 3: no arguments ---\n";
    std::cout << "Output: ";
    printAll(); // calls base case directly — works fine with correct ordering
}