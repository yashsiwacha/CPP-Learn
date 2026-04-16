// Task6PIMPLBasicsSingleFile.cpp
// Single-file submission version with clear header/source/main sections.
// Note: In a real project, these sections are separate physical files.

// ===== widget.h (interface) =====
#include <memory>
#include <string>

// PIMPL keeps implementation details out of the public interface.
// Benefits: better encapsulation, fewer compile-time dependencies, and ABI stability.
// Real-world use: shared libraries/SDKs expose stable headers while internals evolve.
// Client code includes only this interface and does not depend on private member layout.
class Widget
{
public:
    Widget();
    ~Widget();

    // Rule-of-5 intent for a unique_ptr-owned implementation object.
    Widget(const Widget &) = delete;
    Widget &operator=(const Widget &) = delete;
    Widget(Widget &&) noexcept = default;
    Widget &operator=(Widget &&) noexcept = default;

    void setName(const std::string &name);
    void printName() const;

private:
    struct Impl;                // Forward declaration
    std::unique_ptr<Impl> impl; // PIMPL pointer
};

// ===== widget.cpp (implementation) =====
#include <iostream>

// Full implementation is hidden from users of the interface.
// You can freely change this struct (add/remove fields, change helper types/algorithms)
// without changing Widget's public method signatures in the header.
// That reduces rebuild impact and helps preserve binary compatibility across releases.
struct Widget::Impl
{
    std::string name;
    // Example private data that can change later without touching widget.h.
    int internalRevision = 1;
};

Widget::Widget() : impl(std::make_unique<Impl>())
{
}

Widget::~Widget() = default;

void Widget::setName(const std::string &name)
{
    // Only implementation code knows the concrete data layout.
    impl->name = name;
}

void Widget::printName() const
{
    std::cout << "Widget name: " << impl->name << std::endl;
}

// ===== main.cpp (demo) =====
int main()
{
    // Users interact only with Widget's public API.
    // They do not see Impl and are unaffected by private implementation refactors.
    Widget w;
    w.setName("PIMPL Example");
    w.printName();

    // If internalRevision or other Impl internals change, this usage code stays the same.
    return 0;
}
