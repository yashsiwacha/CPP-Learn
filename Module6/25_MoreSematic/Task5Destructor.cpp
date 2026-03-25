#include <iostream>
#include <cstring>
#include <utility>

class MyString
{
private:
    char *data;
    int id;
    static int nextId;

public:
    MyString(const char *str) : id(nextId++)
    {
        data = new char[std::strlen(str) + 1];
        std::strcpy(data, str);
    }

    MyString(const MyString &other) : id(nextId++)
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

    MyString(MyString &&other) noexcept : data(other.data), id(nextId++)
    {
        other.data = nullptr;
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
        std::cout << "Destructing object #" << id << ": "
                  << (data ? data : "null")
                  << " at " << static_cast<const void *>(data) << std::endl;
        delete[] data;
    }

    void print(const char *label) const
    {
        std::cout << label << (data ? data : "null")
                  << " (at " << static_cast<const void *>(data) << ")" << std::endl;
    }
};

int MyString::nextId = 1;

int main()
{
    std::cout << "Creating objects..." << std::endl;
    MyString s1("test");
    MyString s2 = s1;            // Copy constructor
    MyString s3 = std::move(s1); // Move constructor

    std::cout << "\nObject state before scope ends:" << std::endl;
    s1.print("s1: ");
    s2.print("s2: ");
    s3.print("s3: ");

    std::cout << "\nExiting main, destructors will run in reverse creation order:" << std::endl;
    return 0;
}
