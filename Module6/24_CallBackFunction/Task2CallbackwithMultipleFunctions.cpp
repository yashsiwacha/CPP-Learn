#include <iostream>
#include <string>

// Callback variant 1.
void greetMorning(const std::string &name)
{
    std::cout << "Good morning, " << name << "!" << std::endl;
}

// Callback variant 2.
void greetEvening(const std::string &name)
{
    std::cout << "Good evening, " << name << "!" << std::endl;
}

// Receives a function pointer and invokes it with the provided name.
void invokeCallback(void (*callback)(const std::string &), const std::string &name)
{
    callback(name);
}

int main()
{
    // Same invoker, different callbacks: classic function-pointer polymorphism.
    invokeCallback(greetMorning, "Alice");
    invokeCallback(greetEvening, "Bob");

    return 0;
}
