#include <iostream>
#include <cstring>
#include <utility>

class Buffer
{
private:
    int *data;
    std::size_t size;

public:
    // Regular constructor allocates and initializes owned memory.
    Buffer(std::size_t sz) : data(nullptr), size(sz)
    {
        data = new int[size];
        for (std::size_t i = 0; i < size; ++i)
        {
            data[i] = static_cast<int>(i * 10);
        }
        std::cout << "Constructor: allocated at " << static_cast<void *>(data) << std::endl;
    }

    // Copy constructor performs deep copy.
    Buffer(const Buffer &other) : data(nullptr), size(other.size)
    {
        if (other.data)
        {
            data = new int[size];
            std::memcpy(data, other.data, size * sizeof(int));
        }
        std::cout << "Copy ctor: copy to " << static_cast<void *>(data) << std::endl;
    }

    // Copy assignment performs deep copy with self-assignment check.
    Buffer &operator=(const Buffer &other)
    {
        if (this != &other)
        {
            delete[] data;
            size = other.size;
            if (other.data)
            {
                data = new int[size];
                std::memcpy(data, other.data, size * sizeof(int));
            }
            else
            {
                data = nullptr;
            }
            std::cout << "Copy assign: copy to " << static_cast<void *>(data) << std::endl;
        }
        return *this;
    }

    // Move constructor transfers ownership from source object.
    Buffer(Buffer &&other) noexcept : data(other.data), size(other.size)
    {
        other.data = nullptr;
        other.size = 0;
        std::cout << "Move ctor: take " << static_cast<void *>(data) << std::endl;
    }

    // Move assignment releases current resource and takes source resource.
    Buffer &operator=(Buffer &&other) noexcept
    {
        if (this != &other)
        {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
            std::cout << "Move assign: take " << static_cast<void *>(data) << std::endl;
        }
        return *this;
    }

    // Destructor frees owned memory (safe for nullptr in moved-from objects).
    ~Buffer()
    {
        std::cout << "Destructor: freeing " << static_cast<void *>(data) << std::endl;
        delete[] data;
    }

    void print(const char *label) const
    {
        std::cout << label << " [data@" << static_cast<const void *>(data)
                  << "] size=" << size << " values:";
        for (std::size_t i = 0; i < size; ++i)
        {
            std::cout << ' ' << data[i];
        }
        std::cout << std::endl;
    }
};

int main()
{
    Buffer a(3);  // Regular constructor
    Buffer b = a; // Copy constructor
    Buffer c(2);
    c = a; // Copy assignment

    Buffer d = std::move(a); // Move constructor
    Buffer e(1);
    e = std::move(c); // Move assignment

    std::cout << "\nFinal object states:" << std::endl;
    b.print("b");
    d.print("d");
    e.print("e");
    a.print("a (moved-from)");
    c.print("c (moved-from)");

    return 0; // Destructor order shows cleanup for live and moved-from objects.
}
