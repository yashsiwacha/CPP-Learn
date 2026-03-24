#include <iostream>
#include <string>
#include <functional>

// Regular callback function.
void greet(const std::string &name)
{
    std::cout << "Hello, " << name << "!" << std::endl;
}

// std::function allows any compatible callable (function, lambda, functor, etc.).
// Compared to raw function pointers, it is more flexible but may have small overhead.
void invokeCallback(std::function<void(const std::string &)> callback, const std::string &name)
{
    callback(name);
}

int main()
{
    // 1) Regular function callback.
    invokeCallback(greet, "Alice");

    // 2) Non-capturing lambda callback.
    invokeCallback([](const std::string &n)
                   { std::cout << "Lambda says hi to " << n << "!" << std::endl; },
                   "Bob");

    // 3) Capturing lambda callback (captures a prefix message).
    std::string prefix = "Captured lambda greets";
    invokeCallback([prefix](const std::string &n)
                   { std::cout << prefix << " " << n << "!" << std::endl; },
                   "Charlie");

    return 0;
}
