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

    MyString(MyString &&other) noexcept : data(other.data)
    {
        other.data = nullptr;
    }

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

    void print(const char *label) const
    {
        std::cout << label << " [data@" << static_cast<const void *>(data)
                  << "] " << (data ? data : "null") << std::endl;
    }

    // Safe operation after move: reinitialize the object.
    void safeReset(const char *str)
    {
        delete[] data;
        data = new char[std::strlen(str) + 1];
        std::strcpy(data, str);
    }

    // Safe read helper: caller can check if meaningful content exists.
    bool hasValue() const
    {
        return data != nullptr;
    }
};

int main()
{
    MyString s1("hello");
    MyString s2 = std::move(s1);

    s1.print("s1 (moved-from):");
    s2.print("s2 (moved-to):");

    std::cout << "\nSafe operations on moved-from object:" << std::endl;
    s1.safeReset("reset ok");
    s1.print("s1 (after reset):");

    MyString s3("replacement");
    s1 = s3; // Safe: copy assign into previously moved-from object.
    s1.print("s1 (after copy assign):");

    std::cout << "\nUnsafe pattern (do not do this):" << std::endl;
    std::cout << "Do not dereference internal pointer of moved-from object directly." << std::endl;
    std::cout << "Example (commented out): // std::cout << s1.data[0];" << std::endl;
    std::cout << "Moved-from objects are valid for reset/assignment/destruction,"
              << " but content is unspecified." << std::endl;

    if (!s2.hasValue())
    {
        std::cout << "Note: moved-to/moved-from state can vary by implementation." << std::endl;
    }

    return 0;
}
