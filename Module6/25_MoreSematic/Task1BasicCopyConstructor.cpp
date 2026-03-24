#include <iostream>
#include <cstring>

class MyString
{
private:
    char *data;

public:
    // Constructor allocates memory and copies the incoming C-string.
    MyString(const char *str)
    {
        data = new char[std::strlen(str) + 1];
        std::strcpy(data, str);
    }

    // Copy constructor performs a deep copy so each object owns separate memory.
    MyString(const MyString &other)
    {
        data = new char[std::strlen(other.data) + 1];
        std::strcpy(data, other.data);
    }

    // Destructor is required with dynamic memory to avoid leaks.
    // If copy were shallow, both objects would delete the same pointer (dangerous).
    ~MyString()
    {
        delete[] data;
    }

    void setFirstChar(char c)
    {
        if (data[0] != '\0')
        {
            data[0] = c;
        }
    }

    const void *bufferAddress() const
    {
        return static_cast<const void *>(data);
    }

    void print() const
    {
        std::cout << "String: " << data << " (at: " << static_cast<const void *>(data) << ")" << std::endl;
    }
};

int main()
{
    MyString s1("hello");
    MyString s2 = s1;

    std::cout << "Before modification:" << std::endl;
    std::cout << "s1 object address: " << static_cast<const void *>(&s1) << ", internal buffer: " << s1.bufferAddress() << std::endl;
    std::cout << "s2 object address: " << static_cast<const void *>(&s2) << ", internal buffer: " << s2.bufferAddress() << std::endl;
    s1.print();
    s2.print();

    // Deep-copy proof: changing s1 content should not affect s2 content.
    s1.setFirstChar('H');
    std::cout << "After modifying s1:" << std::endl;
    s1.print();
    s2.print();
    // Internal buffer addresses should stay different throughout.

    return 0;
}
