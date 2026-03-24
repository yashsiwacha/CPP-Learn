#include <iostream>

int &funcReturningReference()
{
    static int val = 42; // Static storage duration: safe to return by reference.
    return val;
}

int &funcReturningDanglingReference()
{
    int local = 50;
    return local; // Undefined behavior: local is destroyed when function returns.
}

int main()
{
    auto x = funcReturningReference();  // x is int (copy)
    auto &y = funcReturningReference(); // y is int& (reference)

    std::cout << "x = " << x << " (address: " << &x << ")" << std::endl;
    std::cout << "y = " << y << " (address: " << &y << ")" << std::endl;

    y = 100; // Modifies the original static variable.
    std::cout << "After y = 100, x = " << x << ", y = " << y << std::endl;

    std::cout << "funcReturningReference() now returns: " << funcReturningReference() << std::endl;

    int stable = 500;
    auto &safeRef = stable; // Safe: stable outlives safeRef in this scope.
    safeRef = 700;
    std::cout << "Safe long-lived reference -> stable = " << stable << ", safeRef = " << safeRef << std::endl;

    // Danger note:
    // If this function returned a reference to a NON-static local variable,
    // that reference would dangle after the function returns, causing undefined behavior.
    // In that case, auto& would bind to invalid memory, and reading/writing through it is unsafe.
    // Consequences can include garbage values, crashes, or behavior that appears to work by accident.

    // Active dangling-reference demonstration:
    // badRef is dangling immediately because funcReturningDanglingReference() returns
    // a reference to a dead local variable.
    [[maybe_unused]] auto &badRef = funcReturningDanglingReference();
    std::cout << "Danger demo: auto& badRef is now dangling; using it would be undefined behavior." << std::endl;

    return 0;
}
