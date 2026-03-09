#include <iostream>
#include <string>

void printAll() {}

template <typename T, typename... Args>
void printAll(T first, Args... args)
{
    std::cout << first << " ";
    printAll(args...);
}

int main()
{
    printAll(1, 2.5, "Hello");
    std::cout << std::endl;
    return 0;
}
