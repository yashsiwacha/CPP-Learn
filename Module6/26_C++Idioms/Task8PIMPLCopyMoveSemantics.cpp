// Task8PIMPLCopyMoveSemantics.cpp
// Single-file submission version with clear header/source/main sections.
// Note: In a real project, these sections are separate physical files.

// ===== widget.h (interface) =====
#include <memory>
#include <string>

class Widget
{
public:
    Widget();
    ~Widget();

    // Rule of 5 for a PIMPL class.
    Widget(const Widget &other);                // Copy ctor (deep copy)
    Widget &operator=(const Widget &other);     // Copy assign (deep copy)
    Widget(Widget &&other) noexcept;            // Move ctor
    Widget &operator=(Widget &&other) noexcept; // Move assign

    void setName(const std::string &name);
    void printData() const;
    const void *bufferAddress() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

// ===== widget.cpp (implementation) =====
#include <cstring>
#include <iostream>
#include <utility>

struct Widget::Impl
{
    std::string name;
    char *buffer;

    Impl() : buffer(new char[100])
    {
        buffer[0] = '\0';
        std::cout << "[Impl] Default ctor, allocated buffer at " << static_cast<void *>(buffer) << std::endl;
    }

    Impl(const Impl &other) : name(other.name), buffer(new char[100])
    {
        std::strncpy(buffer, other.buffer, 99);
        buffer[99] = '\0';
        std::cout << "[Impl] Copy ctor, allocated buffer at " << static_cast<void *>(buffer) << std::endl;
    }

    Impl &operator=(const Impl &other)
    {
        if (this != &other)
        {
            name = other.name;
            std::strncpy(buffer, other.buffer, 99);
            buffer[99] = '\0';
        }
        return *this;
    }

    ~Impl()
    {
        std::cout << "[Impl] Deleting buffer at " << static_cast<void *>(buffer) << std::endl;
        delete[] buffer;
    }
};

Widget::Widget() : impl(std::make_unique<Impl>())
{
}

Widget::~Widget() = default;

Widget::Widget(const Widget &other)
    : impl(other.impl ? std::make_unique<Impl>(*other.impl) : nullptr)
{
}

Widget &Widget::operator=(const Widget &other)
{
    if (this != &other)
    {
        if (!other.impl)
        {
            impl.reset();
        }
        else if (!impl)
        {
            impl = std::make_unique<Impl>(*other.impl);
        }
        else
        {
            *impl = *other.impl;
        }
    }
    return *this;
}

Widget::Widget(Widget &&other) noexcept
    : impl(std::move(other.impl))
{
}

Widget &Widget::operator=(Widget &&other) noexcept
{
    if (this != &other)
    {
        impl = std::move(other.impl);
    }
    return *this;
}

void Widget::setName(const std::string &name)
{
    if (!impl)
    {
        impl = std::make_unique<Impl>();
    }

    impl->name = name;
    std::strncpy(impl->buffer, name.c_str(), 99);
    impl->buffer[99] = '\0';
}

void Widget::printData() const
{
    if (!impl)
    {
        std::cout << "Widget is empty (moved-from)." << std::endl;
        return;
    }

    std::cout << "Widget name: " << impl->name
              << ", buffer: " << impl->buffer
              << ", buffer address: " << static_cast<void *>(impl->buffer)
              << std::endl;
}

const void *Widget::bufferAddress() const
{
    return impl ? static_cast<void *>(impl->buffer) : nullptr;
}

// ===== main.cpp (demo) =====
int main()
{
    Widget w1;
    w1.setName("PIMPL RuleOf5 Widget");
    w1.printData();

    std::cout << "--- copy constructor ---" << std::endl;
    Widget w2(w1);
    w2.printData();
    std::cout << "Distinct buffers after copy? "
              << (w1.bufferAddress() != w2.bufferAddress() ? "Yes" : "No")
              << std::endl;

    std::cout << "--- copy assignment ---" << std::endl;
    Widget w3;
    w3 = w1;
    w3.printData();
    std::cout << "Distinct buffers after copy assign? "
              << (w1.bufferAddress() != w3.bufferAddress() ? "Yes" : "No")
              << std::endl;

    std::cout << "--- move constructor ---" << std::endl;
    Widget w4(std::move(w1));
    w4.printData();
    w1.printData(); // moved-from object shown as empty

    std::cout << "--- move assignment ---" << std::endl;
    Widget w5;
    w5 = std::move(w2);
    w5.printData();
    w2.printData(); // moved-from object shown as empty

    return 0;
}
