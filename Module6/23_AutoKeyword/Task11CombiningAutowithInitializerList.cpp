#include <iostream>
#include <initializer_list>

class Numbers
{
public:
    std::initializer_list<int> list;

    // Store the brace-initialized values in an initializer_list member.
    Numbers(std::initializer_list<int> ilist) : list(ilist) {}
};

int main()
{
    Numbers nums{1, 2, 3, 4, 5};

    std::cout << "Numbers: ";
    // auto deduces x as int here, and x is a copy of each element from nums.list.
    for (auto x : nums.list)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
