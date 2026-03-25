#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cstring>

// Rule of 0 example:
// This class owns only RAII-aware STL members (std::vector and std::string).
// Because those members already manage memory correctly, we do not write any
// special member functions here. Compiler-generated copy/move/destructor are safe.
class Wrapper
{
public:
    std::vector<int> data;
    std::string label;

    Wrapper(std::string l, std::initializer_list<int> il)
        : data(il), label(std::move(l))
    {
    }

    void print(const char *tag) const
    {
        std::cout << tag << " label: " << label << " data:";
        for (int x : data)
        {
            std::cout << ' ' << x;
        }
        std::cout << " [data@" << static_cast<const void *>(data.data()) << "]" << std::endl;
    }
};

// Manual Rule of 3 comparison:
// Raw pointers require explicit copy constructor, copy assignment, and destructor.
// Without these, shallow copy would cause double delete and dangling pointers.
class ManualRuleOf3
{
private:
    int *data;
    std::size_t size;

public:
    ManualRuleOf3(std::size_t n, int seed = 100) : data(new int[n]), size(n)
    {
        for (std::size_t i = 0; i < size; ++i)
        {
            data[i] = seed + static_cast<int>(i);
        }
        std::cout << "Manual ctor: allocated @ " << static_cast<const void *>(data) << std::endl;
    }

    ManualRuleOf3(const ManualRuleOf3 &other) : data(new int[other.size]), size(other.size)
    {
        std::memcpy(data, other.data, size * sizeof(int));
        std::cout << "Manual copy ctor: deep copy @ " << static_cast<const void *>(data) << std::endl;
    }

    ManualRuleOf3 &operator=(const ManualRuleOf3 &other)
    {
        if (this != &other)
        {
            delete[] data;
            size = other.size;
            data = new int[size];
            std::memcpy(data, other.data, size * sizeof(int));
            std::cout << "Manual copy assign: deep copy @ " << static_cast<const void *>(data) << std::endl;
        }
        else
        {
            std::cout << "Manual copy assign: self-assignment ignored" << std::endl;
        }
        return *this;
    }

    ~ManualRuleOf3()
    {
        std::cout << "Manual dtor: freeing @ " << static_cast<const void *>(data) << std::endl;
        delete[] data;
    }

    void print(const char *tag) const
    {
        std::cout << tag << " values:";
        for (std::size_t i = 0; i < size; ++i)
        {
            std::cout << ' ' << data[i];
        }
        std::cout << " [data@" << static_cast<const void *>(data) << "]" << std::endl;
    }
};

int main()
{
    std::cout << "Rule of 0 demo:" << std::endl;
    Wrapper w1("first", {1, 2, 3});
    w1.print("w1:");

    Wrapper w2 = w1; // Copy constructor (compiler-generated)
    w2.label = "copy";
    w2.print("w2:");

    Wrapper w3 = std::move(w1); // Move constructor (compiler-generated)
    w3.label = "moved";
    w3.print("w3:");
    w1.print("w1 after move:");

    Wrapper w4("temp", {9});
    w4 = w2; // Copy assignment (compiler-generated)
    w4.label = "copy-assigned";
    w4.print("w4:");

    Wrapper w5("temp2", {8, 8});
    w5 = std::move(w2); // Move assignment (compiler-generated)
    w5.label = "move-assigned";
    w5.print("w5:");
    w2.print("w2 after move-assign:");

    std::cout << "\nManual Rule of 3 comparison:" << std::endl;
    ManualRuleOf3 m1(4, 200);
    m1.print("m1:");

    ManualRuleOf3 m2 = m1;
    m2.print("m2 (copy ctor):");

    ManualRuleOf3 m3(2, 500);
    m3 = m1;
    m3.print("m3 (copy assign):");

    m3 = m3;

    // Why Rule of 0 is preferred:
    // 1) Less code and fewer ownership bugs.
    // 2) STL members provide strong exception safety and tested semantics.
    // 3) Copy/move behavior stays correct as members evolve.
    // Rule of 3/5 is still needed when directly owning raw resources.
    return 0;
}
