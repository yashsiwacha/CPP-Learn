// Program to demonstrate polymorphism using the BaseLogger class and virtual destructor concept.
//
// IMPORTANCE OF VIRTUAL DESTRUCTORS:
// When a derived class object is deleted through a base class pointer, the destructor
// of the base class MUST be virtual. Otherwise, only the base class destructor will be called,
// leading to:
// 1. Resource leaks (if derived class allocated memory/resources)
// 2. Undefined behavior
// 3. Incomplete object destruction
//
// DEMONSTRATION OF THE DIFFERENCE:
//
// WITHOUT virtual destructor (~BaseLogger() instead of virtual ~BaseLogger()):
//   Output when deleting FileLogger:
//     -> BaseLogger destructor called (base cleanup)
//   Output when deleting ConsoleLogger:
//     -> BaseLogger destructor called (base cleanup)
//
//   PROBLEM: FileLogger and ConsoleLogger destructors are NEVER called!
//   This means any resources allocated by derived classes (files, memory, sockets, etc.)
//   will NOT be released, causing memory leaks and resource leaks.
//
// WITH virtual destructor (virtual ~BaseLogger()):
//   Output when deleting FileLogger:
//     -> FileLogger destructor called (derived cleanup)
//     -> BaseLogger destructor called (base cleanup)
//   Output when deleting ConsoleLogger:
//     -> ConsoleLogger destructor called (derived cleanup)
//     -> BaseLogger destructor called (base cleanup)
//
//   CORRECT: Complete destruction chain - derived first, then base.
//   All resources are properly cleaned up in the correct order.

#include <iostream>

// BaseLogger: Abstract base class for different logging mechanisms
// Uses a VIRTUAL destructor to ensure proper cleanup in polymorphic hierarchies
//
// The 'virtual' keyword here is CRITICAL for polymorphic deletion.
// Without it, deleting a FileLogger* through a BaseLogger* pointer would only
// call ~BaseLogger(), skipping ~FileLogger() entirely!
class BaseLogger
{
public:
    virtual ~BaseLogger() // MUST be virtual for proper polymorphic behavior
    {
        std::cout << "  -> BaseLogger destructor called (base cleanup)" << std::endl;
    }
};

// FileLogger: Derived class that writes logs to files
// Destructor is automatically virtual due to base class virtual destructor
//
// IMPORTANT: If BaseLogger's destructor wasn't virtual, this destructor would
// NEVER be called when deleting through a BaseLogger* pointer!
// This would cause file handles to remain open and memory to leak.
class FileLogger : public BaseLogger
{
public:
    ~FileLogger()
    {
        std::cout << "  -> FileLogger destructor called (derived cleanup)" << std::endl;
        // In a real implementation, this would close file handles, flush buffers, etc.
    }
};

// ConsoleLogger: Derived class that writes logs to console
// Demonstrates proper destruction order in polymorphic deletion
//
// IMPORTANT: Without a virtual destructor in BaseLogger, this destructor would
// be skipped during polymorphic deletion, leaving console resources unreleased.
class ConsoleLogger : public BaseLogger
{
public:
    ~ConsoleLogger()
    {
        std::cout << "  -> ConsoleLogger destructor called (derived cleanup)" << std::endl;
        // In a real implementation, this would release console resources, flush output, etc.
    }
};

int main()
{
    // Create derived class objects through base class pointers (polymorphism)
    BaseLogger *fl = new FileLogger();
    BaseLogger *cl = new ConsoleLogger();

    // Polymorphic deletion: Deleting derived objects through base class pointers
    // Note the destruction order: Derived destructor first, then base destructor
    //
    // TO SEE THE PROBLEM: Try removing 'virtual' from BaseLogger's destructor and recompile.
    // You'll notice that ONLY BaseLogger's destructor is called, skipping FileLogger
    // and ConsoleLogger destructors entirely. This demonstrates why virtual destructors
    // are essential in polymorphic hierarchies!

    std::cout << "\n--- Deleting FileLogger object ---" << std::endl;
    delete fl;

    std::cout << "\n--- Deleting ConsoleLogger object ---" << std::endl;
    delete cl;

    std::cout << "\nDestruction complete. Notice how derived destructors are called before base destructor." << std::endl;

    return 0;
}