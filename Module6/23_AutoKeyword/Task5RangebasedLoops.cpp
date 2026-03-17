#include <iostream>
#include <vector>

int main() {
    std::vector<int> v{1, 2, 3, 4, 5};

    // Range-based for loop
    std::cout << "Range-based for: ";
    for (auto x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Traditional iterator-based loop
    std::cout << "Iterator-based for: ";
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
