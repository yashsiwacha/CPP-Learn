#include <iostream>

// Base case for an empty argument list.
int sumAll()
{
    return 0;
}

// C++17 fold expression: expands to ((a1 + a2) + a3) + ...
// This avoids recursive template instantiations and is shorter/clearer.
// Compared to recursion, this reduces boilerplate (no recursive overload chain)
// and improves readability by expressing the intent in one line.
template <typename... Args>
auto sumAll(Args... args)
{
    return (args + ...);
}

int main()
{
    // Requires C++17 or newer for fold expressions.
    std::cout << "Test 1 (ints): " << sumAll(1, 2, 3, 4, 5) << '\n';
    std::cout << "Test 2 (mixed int/double): " << sumAll(1, 2, 3, 4, 5.7) << '\n';
    std::cout << "Test 3 (single value): " << sumAll(42) << '\n';
    std::cout << "Test 4 (no arguments): " << sumAll() << '\n';
    std::cout << "Test 5 (floating-point only): " << sumAll(1.5, 2.25, 3.125) << '\n';
    std::cout << "Test 6 (negative numbers): " << sumAll(-10, -20, 5, 2) << '\n';
}