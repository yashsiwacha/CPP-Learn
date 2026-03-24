#include <iostream>
#include <string>

// A callback function: prints a greeting for the provided name.
void greet(const std::string &name)
{
    std::cout << "Hello, " << name << "!" << std::endl;
}

// Another callback function to show that invokeCallback can accept different behaviors.
void sayGoodbye(const std::string &name)
{
    std::cout << "Goodbye, " << name << "!" << std::endl;
}

// invokeCallback receives a function pointer and calls it with the same name.
// This demonstrates classic callback flow in C++ using function pointers.
void invokeCallback(void (*callback)(const std::string &), const std::string &name)
{
    callback(name);
}

int main()
{
    // First callback invocation.
    invokeCallback(greet, "Alice");

    // Swapping callback function changes behavior without changing invokeCallback.
    invokeCallback(sayGoodbye, "Alice");

    return 0;
}
