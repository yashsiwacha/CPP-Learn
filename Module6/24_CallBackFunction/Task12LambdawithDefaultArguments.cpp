#include <iostream>

int main()
{
    // C++14+ allows default arguments in lambda parameter lists.
    // If factor is not provided by the caller, factor = 2 is used.
    auto multiply = [](int x, int factor = 2)
    {
        return x * factor;
    };

    // Uses default factor (2): 10 * 2 = 20.
    std::cout << "multiply(10): " << multiply(10) << std::endl;

    // Uses explicit factor (5): 10 * 5 = 50.
    std::cout << "multiply(10, 5): " << multiply(10, 5) << std::endl;

    // Variation example (left commented to keep required output unchanged):
    // std::cout << "multiply(7): " << multiply(7) << std::endl; // 14

    return 0;
}
