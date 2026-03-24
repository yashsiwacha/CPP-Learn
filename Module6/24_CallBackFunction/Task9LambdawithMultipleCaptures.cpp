#include <iostream>

int main()
{
    int a = 2;
    int b = 3;

    // Mixed capture: a is captured by value (frozen copy), b by reference (live variable).
    // So changing b later affects lambda output, while changing a later does not.
    auto op = [a, &b](int x)
    {
        return x * a + b;
    };

    std::cout << "Initial values -> a=" << a << ", b=" << b << std::endl;
    std::cout << "op(5) with [a, &b]: " << op(5) << std::endl;

    // Changing b affects future lambda calls because b was captured by reference.
    b = 100;
    std::cout << "After b=100, op(5) with [a, &b]: " << op(5) << std::endl;

    // Edit test: capture BOTH a and b by reference to show live updates for both values.
    auto opRef = [&a, &b](int x)
    {
        return x * a + b;
    };

    a = 4;
    b = 1;
    std::cout << "After a=4, b=1, opRef(5) with [&a, &b]: " << opRef(5) << std::endl;

    return 0;
}
