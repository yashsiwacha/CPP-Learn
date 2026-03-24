#include <iostream>

int main()
{
    int counter = 0;

    // Capture by value + mutable: lambda updates its own internal copy of counter.
    auto next = [counter]() mutable
    {
        counter++;
        return counter;
    };

    std::cout << "next(): " << next() << std::endl;
    std::cout << "next(): " << next() << std::endl;
    std::cout << "next(): " << next() << std::endl;

    // Outer counter remains unchanged because the lambda modified only its captured copy.
    std::cout << "Outer counter: " << counter << std::endl;

    return 0;
}
