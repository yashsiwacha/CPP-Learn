#include <iostream>

// BAD example: returns a lambda that captures a local variable by reference.
auto makeLambda()
{
    int temp = 5;

    // Dangling reference risk: temp is destroyed when makeLambda returns.
    return [&temp]()
    {
        return temp * 2;
    };
}

// SAFE example: returns a lambda that captures the local variable by value.
auto makeSafeLambda()
{
    int temp = 5;

    // Safe: lambda stores its own copy of temp.
    return [temp]()
    {
        return temp * 2;
    };
}

int main()
{
    auto lambda = makeLambda();
    auto safeLambda = makeSafeLambda();

    // Undefined behavior: lambda uses a reference to a dead local variable.
    // Result is unpredictable: it may print garbage, crash, or appear to work by accident.
    std::cout << "Calling lambda after temp is gone: " << lambda() << std::endl;

    // Safe comparison: value-captured lambda remains valid after function return.
    std::cout << "Calling safe lambda (value capture): " << safeLambda() << std::endl;

    // Prevention summary:
    // Avoid returning lambdas that capture locals by reference.
    // Prefer value capture when the lambda outlives the creating function.

    return 0;
}
