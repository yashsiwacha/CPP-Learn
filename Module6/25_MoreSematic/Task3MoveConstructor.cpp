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

    // Copy constructor (Rule of Three/Five): deep copy for independent ownership.
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

    // Copy assignment (Rule of Three/Five): deep copy with self-assignment guard.
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

    // Move constructor: transfer buffer ownership, then null out source pointer.
    MyString(MyString &&other) noexcept : data(other.data)
    {
        other.data = nullptr;
    }

    // Move assignment (Rule of Five): release current buffer, steal source buffer,
    // then null out source so destructor is always safe and no double delete occurs.
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

    std::cout << "Before move:" << std::endl;
    std::cout << "s1 object address: " << static_cast<const void *>(&s1)
              << ", internal buffer: " << s1.bufferAddress() << std::endl;
    s1.print("s1: ");

    MyString s2 = std::move(s1); // Move constructor transfer

    std::cout << "\nAfter move (MyString s2 = std::move(s1)):\n";
    std::cout << "s1 object address: " << static_cast<const void *>(&s1)
              << ", internal buffer: " << s1.bufferAddress() << std::endl;
    std::cout << "s2 object address: " << static_cast<const void *>(&s2)
              << ", internal buffer: " << s2.bufferAddress() << std::endl;
    s1.print("s1: ");
    s2.print("s2: ");
    std::cout << "s1 is now valid but empty after move (null buffer)." << std::endl;

    MyString s3("bye");
    s3 = std::move(s2); // Move assignment transfer
    std::cout << "\nAfter move assignment (s3 = std::move(s2)):\n";
    s2.print("s2: ");
    s3.print("s3: ");

    // Self-move test through pointer alias to keep the runtime test explicit.
    // operator=(MyString&&) guard prevents accidental self-destruction.
    MyString *self = &s3;
    s3 = std::move(*self);
    std::cout << "\nAfter self-move (s3 = std::move(s3)):\n";
    s3.print("s3: ");

    // Chained move test: ownership hops from a -> b -> c.
    MyString a("chain");
    MyString b = std::move(a);
    MyString c = std::move(b);
    std::cout << "\nAfter chained moves (a -> b -> c):\n";
    a.print("a: ");
    b.print("b: ");
    c.print("c: ");

    return 0;
}
