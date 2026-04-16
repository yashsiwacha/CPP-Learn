#include <iostream>
#include <memory>
#include <string>

class FileHandler
{
public:
    FileHandler()
    {
        std::cout << "File opened." << std::endl;
    }

    void write(const std::string &message) const
    {
        std::cout << "Writing: " << message << std::endl;
    }

    ~FileHandler()
    {
        std::cout << "File closed." << std::endl;
    }
};

std::unique_ptr<FileHandler> createFileHandler()
{
    // Factory creates and returns unique ownership to caller.
    return std::make_unique<FileHandler>();
}

void processFileHandler(std::unique_ptr<FileHandler> handler)
{
    // Ownership is now inside this function.
    if (handler)
    {
        handler->write("Processed in processFileHandler().");
    }

    // handler goes out of scope here, so FileHandler is destroyed automatically.
}

int main()
{
    // Step 1: Acquire unique ownership from factory.
    std::unique_ptr<FileHandler> filePtr = createFileHandler();
    filePtr->write("Initial log from main().");

    // Step 2: Transfer ownership to processing function using std::move.
    processFileHandler(std::move(filePtr));

    // Step 3: filePtr is now moved-from (expected nullptr).
    std::cout << "After move, filePtr is " << (filePtr ? "not null" : "nullptr") << std::endl;

    // Step 4: Trying to use moved-from pointer must be guarded.
    if (filePtr)
    {
        filePtr->write("This should not run.");
    }
    else
    {
        std::cout << "Cannot write: ownership already transferred." << std::endl;
    }

    std::cout << "Program complete." << std::endl;
    return 0;
}
