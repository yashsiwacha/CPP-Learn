#include <iostream>
#include <vector>
#include <algorithm>

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
    int factor = 3;
    std::vector<int> v{1, 2, 3};

    // Value capture: lambda gets its own copy of factor (3 at capture time).
    std::for_each(v.begin(), v.end(), [factor](int &x)
                  { x *= factor; });
    printVector(v, "After value-capture lambda (factor=3): ");

    // Reference capture: lambda uses the current outer variable factor.
    factor = 10;
    std::for_each(v.begin(), v.end(), [&factor](int &x)
                  { x *= factor; });
    printVector(v, "After reference-capture lambda (factor=10): ");

    return 0;
}
