#include <iostream>
#include <vector>
#include <algorithm>

struct Square
{
    void operator()(int &x) const
    {
        x *= x;
    }
};

void printVector(const std::vector<int> &v, const std::string &label)
{
    std::cout << label;
    for (const auto x : v)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> v1{1, 2, 3, 4, 5};
    std::vector<int> v2{1, 2, 3, 4, 5};

    std::for_each(v1.begin(), v1.end(), Square{});
    std::for_each(v2.begin(), v2.end(), [](int &x)
                  { x *= x; });

    printVector(v1, "Squared by functor: ");
    printVector(v2, "Squared by lambda:  ");

    // Comparison notes:
    // - Lambdas are concise and ideal for one-off local behavior.
    // - Functors are reusable, can carry state, and make behavior explicit by type.
    // - In simple cases like this, both approaches produce equivalent results.

    return 0;
}
