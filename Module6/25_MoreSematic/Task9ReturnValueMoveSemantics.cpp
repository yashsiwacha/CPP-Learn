#include <iostream>
#include <cstring>
#include <utility>

class MyString
{
private:
    char *data;

public:
    // Constructor acquires heap memory (resource ownership starts here).
    MyString(const char *str)
    {
        data = new char[std::strlen(str) + 1];
        std::strcpy(data, str);
        std::cout << "Constructor for: " << data
                  << " [buffer@" << static_cast<const void *>(data) << "]" << std::endl;
    }

    // Copy constructor performs deep copy (independent buffer).
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
        std::cout << "Copy constructor for: " << (data ? data : "null")
                  << " [buffer@" << static_cast<const void *>(data) << "]" << std::endl;
    }

    // Move constructor transfers ownership; source becomes nullptr.
    MyString(MyString &&other) noexcept : data(other.data)
    {
        other.data = nullptr;
        std::cout << "Move constructor: ownership transferred"
                  << " [buffer@" << static_cast<const void *>(data) << "]" << std::endl;
    }

    // Rule of Five completeness: copy assignment.
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
            std::cout << "Copy assignment"
                      << " [buffer@" << static_cast<const void *>(data) << "]" << std::endl;
        }
        return *this;
    }

    // Rule of Five completeness: move assignment.
    MyString &operator=(MyString &&other) noexcept
    {
        if (this != &other)
        {
            delete[] data;
            data = other.data;
            other.data = nullptr;
            std::cout << "Move assignment: ownership transferred"
                      << " [buffer@" << static_cast<const void *>(data) << "]" << std::endl;
        }
        return *this;
    }

    ~MyString()
    {
        std::cout << "Destructor for: " << (data ? data : "null")
                  << " [buffer@" << static_cast<const void *>(data) << "]" << std::endl;
        delete[] data;
    }

    void print() const
    {
        std::cout << "MyString: " << (data ? data : "null")
                  << " [buffer@" << static_cast<const void *>(data) << "]" << std::endl;
    }
};

// Named local return: compiler may apply NRVO (no move/copy call),
// otherwise move constructor is typically used.
MyString makeString()
{
    MyString temp("Hello from makeString!");
    std::cout << "makeString(): returning local 'temp' by value" << std::endl;
    return temp;
}

// Conditional return often prevents NRVO and makes move/copy behavior visible.
MyString makeStringConditional(bool chooseFirst)
{
    MyString first("Hello from first branch");
    MyString second("Hello from second branch");
    std::cout << "makeStringConditional(): returning one of two locals by value" << std::endl;
    if (chooseFirst)
    {
        return first;
    }
    return second;
}

int main()
{
    std::cout << "=== Test 1: Return named local (NRVO may happen) ===" << std::endl;
    MyString s = makeString();
    s.print();

    std::cout << "\n=== Test 2: Conditional return (often shows move) ===" << std::endl;
    MyString t = makeStringConditional(true);
    t.print();

    std::cout << "\n=== Test 3: Assignment checks (Rule of Five completeness) ===" << std::endl;
    MyString u("initial");
    u = t;            // copy assignment
    u = std::move(t); // move assignment
    u.print();
    t.print();

    std::cout << "End of main." << std::endl;
    return 0;
}
