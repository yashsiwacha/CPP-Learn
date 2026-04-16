#include <iostream>
#include <memory>
#include <string>
#include <utility>

class Logger
{
private:
    std::string name;
    bool isOpen = true;

public:
    explicit Logger(const std::string &loggerName) : name(loggerName)
    {
        std::cout << "Logger '" << name << "' created." << std::endl;
    }

    void log(const std::string &message) const
    {
        if (isOpen)
        {
            std::cout << "[" << name << "]: " << message << std::endl;
        }
    }

    // Idempotent close: only close once even if called repeatedly.
    void close()
    {
        if (isOpen)
        {
            isOpen = false;
            std::cout << "Logger '" << name << "' closing." << std::endl;
        }
    }

    std::string getName() const
    {
        return name;
    }

    ~Logger()
    {
        close();
        std::cout << "Logger '" << name << "' destroyed." << std::endl;
    }
};

int main()
{
    std::cout << "--- Basic Creation ---" << std::endl;
    std::unique_ptr<Logger> logger = std::make_unique<Logger>("MainLogger");
    logger->log("Hello from MainLogger");

    std::cout << "\n--- Assignment Replacement ---" << std::endl;
    logger = std::make_unique<Logger>("SecondaryLogger");
    logger->log("Hello from SecondaryLogger");

    std::cout << "\n--- Reset with New Object ---" << std::endl;
    logger.reset(new Logger("TemporaryLogger"));
    logger->log("I replaced the previous logger");

    std::cout << "\n--- Reset to Null ---" << std::endl;
    logger.reset();
    std::cout << "Logger is now " << (logger ? "not null" : "nullptr") << std::endl;

    std::cout << "\n--- Null Assignment ---" << std::endl;
    logger = nullptr;
    std::cout << "Logger after nullptr assignment is " << (logger ? "not null" : "nullptr") << std::endl;

    std::cout << "\n--- Reassignment ---" << std::endl;
    logger = std::make_unique<Logger>("NewLogger");
    logger->log("Back in business");

    std::cout << "\n--- Move Semantics ---" << std::endl;
    auto logger2 = std::make_unique<Logger>("Logger2");
    logger = std::move(logger2);
    logger->log("Now I own Logger2's resource");
    std::cout << "logger2 is " << (logger2 ? "not null" : "nullptr") << std::endl;

    std::cout << "\n--- Self-Move ---" << std::endl;
    logger = std::move(logger);
    logger->log("Self-move didn't destroy me!");

    std::cout << "\n--- End of main ---" << std::endl;
    return 0;
}
