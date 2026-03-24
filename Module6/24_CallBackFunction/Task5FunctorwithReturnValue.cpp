#include <iostream>

// A functor (function object): calling an Add instance behaves like a function.
struct Add
{
    // operator() lets objects of Add be called with (a, b) and return their sum.
    int operator()(int a, int b) const
    {
        return a + b;
    }
};

int main()
{
    Add add;
    int a = 10;
    int b = 20;
    int result = add(a, b);

    std::cout << "Sum (" << a << " + " << b << "): " << result << std::endl;
    return 0;
}
