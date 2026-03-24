#include <iostream>
#include <functional>
#include <string>

// Regular callback function for comparison with lambda callbacks.
void welcomeUser(const std::string &userName)
{
    std::cout << "Regular callback says: Hello, " << userName << "!" << std::endl;
}

// Callback invoker that accepts any compatible callable wrapped in std::function.
void invokeCallback(std::function<void(const std::string &)> cb, const std::string &name)
{
    cb(name);
}

int main()
{
    // std::function lets the same API accept different callback styles.
    invokeCallback(welcomeUser, "LambdaUser");

    // Lambda passed directly as callback argument (inline, concise, and contextual).
    std::string messagePrefix = "Lambda callback says: Welcome";
    invokeCallback(
        [messagePrefix](const std::string &userName)
        {
            std::cout << messagePrefix << ", " << userName << "!" << std::endl;
        },
        "LambdaUser");

    return 0;
}
