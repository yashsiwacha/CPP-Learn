#include <iostream>

int main()
{
    // Stateless lambda that returns the sum of two integers.
    auto add = [](int a, int b)
    {
        return a + b;
    };

    int result = add(5, 10);
    std::cout << "Sum: " << result << std::endl;

    return 0;
}
