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
        std::cout << "Constructed: " << data
                  << " at " << static_cast<const void *>(data) << std::endl;
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
        std::cout << "Copied: " << (data ? data : "null")
                  << " at " << static_cast<const void *>(data) << std::endl;
    }

    MyString(MyString &&other) noexcept : data(other.data)
    {
        other.data = nullptr;
        std::cout << "Moved! at " << static_cast<const void *>(data) << std::endl;
    }

    ~MyString()
    {
        std::cout << "Destructed " << (data ? data : "null")
                  << " at " << static_cast<const void *>(data) << std::endl;
        delete[] data;
    }

    const void *bufferAddress() const
    {
        return static_cast<const void *>(data);
    }

    void print(const char *msg = "") const
    {
        std::cout << msg << " buffer@" << static_cast<const void *>(data) << std::endl;
    }
};

// Required rvalue overload for the task.
void printAddress(MyString &&s)
{
    std::cout << "printAddress(MyString&&) receives buffer@"
              << s.bufferAddress() << std::endl;
}

// Extra lvalue overload so forwardToPrint can demonstrate category preservation.
void printAddress(const MyString &s)
{
    std::cout << "printAddress(const MyString&) receives buffer@"
              << s.bufferAddress() << std::endl;
}

template <typename T>
void forwardToPrint(T &&str)
{
    printAddress(std::forward<T>(str));
}

int main()
{
    std::cout << "=== std::move with named object ===" << std::endl;
    MyString obj("lvalue-object");
    obj.print("obj before move:");
    printAddress(std::move(obj));
    obj.print("obj after std::move call (still valid):");

    std::cout << "\n=== Direct temporary rvalue ===" << std::endl;
    printAddress(MyString("temp-rvalue"));

    std::cout << "\n=== perfect forwarding with std::forward ===" << std::endl;
    MyString lv("forward-lvalue");
    forwardToPrint(lv);                       // Preserved as lvalue
    forwardToPrint(std::move(lv));            // Forwarded as rvalue
    forwardToPrint(MyString("forward-temp")); // Forwarded temporary rvalue

    std::cout << "\nDone." << std::endl;
    return 0;
}
