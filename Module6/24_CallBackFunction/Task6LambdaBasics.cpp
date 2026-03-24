#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5};

    // Captureless lambda used as an inline callback to modify each element in-place.
    std::for_each(v.begin(), v.end(), [](int &x)
                  { x *= 2; });

    std::cout << "Updated vector: ";
    // Range-based loop prints the transformed values.
    for (auto x : v)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
