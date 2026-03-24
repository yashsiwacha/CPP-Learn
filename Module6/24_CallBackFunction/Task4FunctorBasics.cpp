#include <iostream>
#include <vector>
#include <algorithm>

// Functor: stores a factor and multiplies each element passed to operator().
struct MultiplyBy
{
    int factor;

    void operator()(int &x) const
    {
        x *= factor;
    }
};

void printVector(const std::vector<int> &v, const std::string &label)
{
    std::cout << label;
    for (const int n : v)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5};

    printVector(v, "Original vector: ");

    // Apply a stateful callback object to each element.
    std::for_each(v.begin(), v.end(), MultiplyBy{3});
    printVector(v, "Modified vector (x3): ");

    // Demonstrates easy parameter change by using a different factor.
    std::for_each(v.begin(), v.end(), MultiplyBy{2});
    printVector(v, "Modified vector again (x2): ");

    return 0;
}
