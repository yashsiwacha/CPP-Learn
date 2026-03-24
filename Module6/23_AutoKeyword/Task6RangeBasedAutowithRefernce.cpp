#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5};

    // auto& binds x to the actual element, so changes update the vector in-place.
    for (auto &x : v)
    {
        x *= 2;
    }

    std::cout << "Modified vector (by reference): ";
    for (auto x : v)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Reset vector and use value iteration; x is a copy, so container stays unchanged.
    v = {1, 2, 3, 4, 5};
    for (auto x : v)
    {
        x *= 2;
    }

    std::cout << "Value-based loop (no modification): ";
    for (auto x : v)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
