#include <iostream>
#include <cstring>

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

    // Copy constructor: deep copy so each object owns a different buffer.
    // This avoids double-delete that happens with a shallow pointer copy.
    MyString(const MyString &other)
    {
        data = new char[std::strlen(other.data) + 1];
        std::strcpy(data, other.data);
    }

    // Copy assignment: Rule of Three member #2.
    // Steps: guard self-assignment, release old buffer, allocate/copy new buffer.
    MyString &operator=(const MyString &other)
    {
        if (this != &other)
        {
            delete[] data;
            data = new char[std::strlen(other.data) + 1];
            std::strcpy(data, other.data);
        }
        return *this;
    }

    // Destructor: Rule of Three member #3. Releases owned heap memory exactly once.
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
        std::cout << label << "String: " << data
                  << " (at: " << static_cast<const void *>(data) << ")" << std::endl;
    }
};

int main()
{
    MyString s1("hello");
    MyString s2("bye");

    std::cout << "Before assignment:" << std::endl;
    std::cout << "s1 object address: " << static_cast<const void *>(&s1)
              << ", internal buffer: " << s1.bufferAddress() << std::endl;
    std::cout << "s2 object address: " << static_cast<const void *>(&s2)
              << ", internal buffer: " << s2.bufferAddress() << std::endl;
    s1.print("s1: ");
    s2.print("s2: ");

    s2 = s1; // Copy assignment

    std::cout << "\nAfter s2 = s1:" << std::endl;
    std::cout << "s1 object address: " << static_cast<const void *>(&s1)
              << ", internal buffer: " << s1.bufferAddress() << std::endl;
    std::cout << "s2 object address: " << static_cast<const void *>(&s2)
              << ", internal buffer: " << s2.bufferAddress() << std::endl;
    s1.print("s1: ");
    s2.print("s2: ");

    // Self-assignment test: should keep object valid and unchanged.
    s1 = s1;
    std::cout << "\nAfter self-assignment (s1 = s1):" << std::endl;
    std::cout << "s1 object address: " << static_cast<const void *>(&s1)
              << ", internal buffer: " << s1.bufferAddress() << std::endl;

    s1.print("s1: ");

    return 0;
}
