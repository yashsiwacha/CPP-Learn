#include <iostream>
#include <vector>
#include <set>

int main()
{
    // Uniform initialization (C++11): braces {} let us provide values directly and consistently.
    // It is concise, readable, and avoids older, verbose construction styles.
    std::vector<int> vec{1, 2, 3, 4, 5};

    std::cout << "Elements in vec (initialized with {}): ";
    for (const auto &x : vec)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // The same initializer-list style also works with other STL containers.
    std::set<int> uniq{5, 3, 3, 1};
    std::cout << "Elements in set (also initialized with {}): ";
    for (const auto &x : uniq)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
