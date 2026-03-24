#include <iostream>

int main()
{
    int counter = 0;

    // Pitfall: many expect this to increment outer counter, but it does NOT.
    // mutable only allows changing the lambda's internal value-captured copy.
    auto inc = [counter]() mutable
    {
        counter++;
    };
    inc();
    std::cout << "After inc() (by value): counter = " << counter << std::endl;

    // Reference capture: modifies the original outer counter.
    auto incRef = [&counter]()
    {
        counter++;
    };
    incRef();
    std::cout << "After incRef() (by reference): counter = " << counter << std::endl;

    // Extra variation test: mutable lambda keeps its own evolving internal state.
    auto incState = [counter]() mutable
    {
        counter++;
        return counter;
    };
    std::cout << "incState() first call (internal copy): " << incState() << std::endl;
    std::cout << "incState() second call (internal copy): " << incState() << std::endl;
    std::cout << "Outer counter still: " << counter << std::endl;

    return 0;
}
