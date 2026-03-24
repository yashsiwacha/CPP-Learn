#include <iostream>
#include <vector>

std::vector<int> getNumbers()
{
    return {7, 14, 21, 28, 35};
}

int main()
{
    auto nums = getNumbers(); // auto deduces std::vector<int> from the function return type.

    std::cout << "Returned numbers: ";
    for (auto n : nums)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
