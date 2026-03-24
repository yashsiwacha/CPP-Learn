#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5};

    // const auto& avoids copying and prevents accidental modification.
    std::cout << "Elements (const ref): ";
    for (const auto &x : v)
    {
        std::cout << x << " ";

        // Uncomment to see compile-time safety in action:
        // x = 42; // error: assignment of read-only reference
    }
    std::cout << std::endl;

    return 0;
}
