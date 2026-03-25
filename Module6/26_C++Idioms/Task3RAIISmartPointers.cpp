// Task3RAIISmartPointers.cpp
// RAII with Smart Pointers: compare std::unique_ptr and manual new/delete.
#include <iostream>
#include <memory>
#include <stdexcept>

class Widget
{
public:
    Widget() { std::cout << "Widget constructed at " << this << std::endl; }
    ~Widget() { std::cout << "Widget destructed at " << this << std::endl; }

    void greet() const { std::cout << "Hello from Widget at " << this << std::endl; }
};

// Returns ownership to caller via move semantics.
std::unique_ptr<Widget> makeWidget()
{
    auto ptr = std::make_unique<Widget>();
    ptr->greet();
    return ptr;
}

// Demonstrates exception safety with unique_ptr.
void uniquePtrExceptionDemo()
{
    auto local = std::make_unique<Widget>();
    local->greet();
    throw std::runtime_error("Exception after creating unique_ptr-managed Widget");
}

// Demonstrates early-return safety with unique_ptr.
void uniquePtrEarlyReturnDemo()
{
    auto local = std::make_unique<Widget>();
    local->greet();
    std::cout << "Early return now; unique_ptr will still clean up." << std::endl;
    return;
}

int main()
{
    std::cout << "== Smart pointer (unique_ptr) example ==" << std::endl;
    {
        auto widgetPtr = makeWidget();
        widgetPtr->greet();
    } // unique_ptr goes out of scope and deletes Widget automatically.

    std::cout << "== unique_ptr early return safety ==" << std::endl;
    uniquePtrEarlyReturnDemo();

    std::cout << "== unique_ptr exception safety ==" << std::endl;
    try
    {
        uniquePtrExceptionDemo();
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Caught exception: " << ex.what() << std::endl;
    }

    std::cout << "== Manual new/delete (anti-pattern) ==" << std::endl;
    {
        Widget *w = new Widget();
        w->greet();
        delete w; // Forgetting this line causes a leak.
    }

    std::cout << "Program end." << std::endl;
    return 0;
}
