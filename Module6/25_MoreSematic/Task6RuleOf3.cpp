#include <iostream>
#include <cstring>

class ResourceHolder
{
private:
    int *data;
    std::size_t size;

public:
    // Constructor allocates and initializes owned heap memory.
    ResourceHolder(std::size_t sz) : data(nullptr), size(sz)
    {
        data = new int[size];
        for (std::size_t i = 0; i < size; ++i)
        {
            data[i] = static_cast<int>(i * 11);
        }
        std::cout << "Constructor: allocated at " << static_cast<void *>(data) << std::endl;
    }

    // Copy constructor performs deep copy so both objects own distinct arrays.
    ResourceHolder(const ResourceHolder &other) : data(nullptr), size(other.size)
    {
        data = new int[size];
        std::memcpy(data, other.data, size * sizeof(int));
        std::cout << "Copy ctor: copied to " << static_cast<void *>(data) << std::endl;
    }

    // Copy assignment performs deep copy with self-assignment protection.
    ResourceHolder &operator=(const ResourceHolder &other)
    {
        if (this != &other)
        {
            delete[] data;
            size = other.size;
            data = new int[size];
            std::memcpy(data, other.data, size * sizeof(int));
            std::cout << "Copy assign: copied to " << static_cast<void *>(data) << std::endl;
        }
        else
        {
            std::cout << "Copy assign: self-assignment detected, no action taken" << std::endl;
        }
        return *this;
    }

    // Destructor releases owned memory exactly once.
    ~ResourceHolder()
    {
        std::cout << "Destructor: freeing " << static_cast<void *>(data) << std::endl;
        delete[] data;
    }

    void print(const char *label) const
    {
        std::cout << label << " data at " << static_cast<const void *>(data) << ": [ ";
        for (std::size_t i = 0; i < size; ++i)
        {
            std::cout << data[i] << ' ';
        }
        std::cout << "]" << std::endl;
    }
};

int main()
{
    ResourceHolder a(5);
    a.print("a:");

    ResourceHolder b = a; // Copy constructor
    b.print("b:");

    ResourceHolder c(3);
    c = a; // Copy assignment
    c.print("c (after = a):");

    // Extra safety check for copy assignment self-check branch.
    c = c;

    return 0;
}
