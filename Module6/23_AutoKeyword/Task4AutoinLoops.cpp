#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5};

    std::cout << "=== Task 4: Auto in Loops ===\n\n";

    // 1) auto deduces the iterator type returned by v.begin().
    // This avoids writing std::vector<int>::iterator explicitly.
    std::cout << "1) Iterator Loop (auto it = v.begin()): ";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << "\n";

    // 2) Cleaner read-only loop using const auto&.
    // No copying, and values cannot be modified in this loop.
    std::cout << "2) Read-Only Range Loop (const auto&): ";
    for (const auto &value : v)
    {
        std::cout << value << ' ';
    }
    std::cout << "\n";

    // 3) Mutable range loop using auto& to modify elements in-place.
    std::cout << "3) Mutable Range Loop (auto&) -> multiply by 10: ";
    for (auto &value : v)
    {
        value *= 10;
        std::cout << value << ' ';
    }
    std::cout << "\n";

    // Final container state after in-place modification.
    std::cout << "\nFinal vector state: ";
    for (const auto &value : v)
    {
        std::cout << value << ' ';
    }
    std::cout << "\n";

    return 0;
}
