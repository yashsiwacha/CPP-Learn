#include <iostream>

// Function template: T is a placeholder type resolved at compile time.
template <typename T>
T add(T a, T b)
{
    return a + b;
}

int main()
{
    // The compiler deduces T from the argument types in each call.
    int i = add(2, 3);         // int
    double d = add(2.1, 3.9);  // double
    float f = add(1.5f, 2.5f); // float

    // Each result uses the matching deduced type.
    std::cout << "int: " << i << std::endl;
    std::cout << "double: " << d << std::endl;
    std::cout << "float: " << f << std::endl;

    return 0;
}
