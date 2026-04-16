// Task7PIMPLWithDynamicResource.cpp
// Single-file submission version with clear header/source/main sections.
// Note: In a real project, these sections are separate physical files.

// ===== Widget.h (interface) =====
#include <memory>
#include <string>

class Widget
{
public:
    Widget();
    ~Widget();

    Widget(const Widget &) = delete;
    Widget &operator=(const Widget &) = delete;
    Widget(Widget &&) noexcept = default;
    Widget &operator=(Widget &&) noexcept = default;

    void setName(const std::string &name);
    void printData() const;

private:
    struct Impl;                // Forward declaration
    std::unique_ptr<Impl> impl; // PIMPL pointer
};

// ===== Widget.cpp (implementation) =====
#include <cstring>
#include <iostream>

// Full definition hidden from users of the interface.
struct Widget::Impl
{
    std::string name;
    char *buffer;

    Impl() : buffer(new char[100])
    {
        std::cout << "[Impl] Allocated buffer at " << static_cast<void *>(buffer) << std::endl;
        buffer[0] = '\0';
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

void Widget::setName(const std::string &name)
{
    impl->name = name;
    std::strncpy(impl->buffer, name.c_str(), 99);
    impl->buffer[99] = '\0'; // Ensure null termination.
}

void Widget::printData() const
{
    std::cout << "Widget name: " << impl->name << ", buffer: " << impl->buffer << std::endl;
}

// ===== main.cpp (demo) =====
int main()
{
    {
        Widget w;
        w.setName("PIMPL+RAII Example");
        w.printData();
    } // Widget and Impl destructors run here; cleanup log is printed.

    return 0;
}
