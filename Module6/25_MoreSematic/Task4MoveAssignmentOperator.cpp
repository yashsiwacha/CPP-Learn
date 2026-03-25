#include <iostream>
#include <cstring>
#include <utility>

class MyString
{
private:
    char *data;

public:
    MyString(const char *str)
    {
        data = new char[std::strlen(str) + 1];
        std::strcpy(data, str);
    }

    // Copy constructor: deep copy so each object owns independent memory.
    MyString(const MyString &other)
    {
        if (other.data)
        {
            data = new char[std::strlen(other.data) + 1];
            std::strcpy(data, other.data);
        }
        else
        {
            data = nullptr;
        }
    }

    // Copy assignment: deep copy with self-assignment guard.
    MyString &operator=(const MyString &other)
    {
        if (this != &other)
        {
            delete[] data;
            if (other.data)
            {
                data = new char[std::strlen(other.data) + 1];
                std::strcpy(data, other.data);
            }
            else
            {
                data = nullptr;
            }
        }
        return *this;
    }

    // Move constructor: transfer ownership from source object.
    MyString(MyString &&other) noexcept : data(other.data)
    {
        other.data = nullptr;
    }

    // Move assignment: release current buffer, steal source buffer, null source.
    MyString &operator=(MyString &&other) noexcept
    {
        if (this != &other)
        {
            delete[] data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    ~MyString()
    {
        delete[] data;
    }

    const void *bufferAddress() const
    {
        return static_cast<const void *>(data);
    }

    void print(const char *label) const
    {
        std::cout << label << "String: " << (data ? data : "null")
                  << " (at: " << static_cast<const void *>(data) << ")" << std::endl;
    }
};

int main()
{
    MyString s1("hello");
    MyString s2("world");

    std::cout << "Before move assignment:" << std::endl;
    std::cout << "s1 object address: " << static_cast<const void *>(&s1)
              << ", internal buffer: " << s1.bufferAddress() << std::endl;
    std::cout << "s2 object address: " << static_cast<const void *>(&s2)
              << ", internal buffer: " << s2.bufferAddress() << std::endl;
    s1.print("s1: ");
    s2.print("s2: ");

    s2 = std::move(s1); // Move assignment

    std::cout << "\nAfter move assignment (s2 = std::move(s1)):" << std::endl;
    std::cout << "s1 object address: " << static_cast<const void *>(&s1)
              << ", internal buffer: " << s1.bufferAddress() << std::endl;
    std::cout << "s2 object address: " << static_cast<const void *>(&s2)
              << ", internal buffer: " << s2.bufferAddress() << std::endl;
    s1.print("s1: ");
    s2.print("s2: ");
    std::cout << "s1 is valid but empty after move assignment." << std::endl;

    return 0;
}
