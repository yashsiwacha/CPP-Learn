#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>

/*
====================
Rule of 0 vs Rule of 5: Modern C++ Resource Management
====================

Rule of 0:
    - If all members are STL containers, std::string, or smart pointers (RAII types),
        you do NOT need to write any destructor, copy/move constructor, or assignment operator.
    - This avoids errors like double delete, memory leaks, and object slicing.
    - The compiler generates all special member functions, ensuring exception safety and maintainability.
    - Example: ModernResourceCopyable and ModernResourceMoveOnly below.

Rule of 5:
    - If you manage raw resources (e.g., raw pointers, file handles), you MUST write all five special member functions:
        destructor, copy constructor, copy assignment, move constructor, move assignment.
    - Manual management is error-prone: easy to forget deep copies, double delete, or leak memory.
    - Example: ManualResource below.

RAII (Resource Acquisition Is Initialization):
    - Resources are acquired and released by objects whose lifetimes are automatically managed.
    - STL containers and smart pointers are RAII types: they acquire resources in constructors and release them in destructors.
    - Prefer RAII types to avoid manual cleanup and bugs.

Pitfalls of Manual Resource Management (Rule of 5):
    - Forgetting to delete[] in destructor → memory leak
    - Forgetting deep copy in copy constructor/assignment → double delete or use-after-free
    - Not nulling moved-from pointers → double delete
    - Exception safety is hard to guarantee

Prefer Rule of 0 and RAII whenever possible for safer, cleaner, and more maintainable code.
*/

// Rule of 0: All members are copyable STL/RAII types, so copy/move/assign are defaulted and safe.
class ModernResourceCopyable
{
public:
    std::vector<int> data;
    std::string name;
    int meta;

    ModernResourceCopyable(std::string n, std::initializer_list<int> d)
        : data(d), name(std::move(n)), meta(123) {}

    void print(const char *tag) const
    {
        std::cout << tag << " " << name << ":";
        for (int x : data)
            std::cout << " " << x;
        std::cout << " | meta=" << meta << std::endl;
    }
};

// Rule of 0: Move-only version (contains unique_ptr, so copy is deleted, move is defaulted)
class ModernResourceMoveOnly
{
public:
    std::vector<int> data;
    std::string name;
    std::unique_ptr<int> meta;

    ModernResourceMoveOnly(std::string n, std::initializer_list<int> d)
        : data(d), name(std::move(n)), meta(std::make_unique<int>(123)) {}

    void print(const char *tag) const
    {
        std::cout << tag << " " << name << ":";
        for (int x : data)
            std::cout << " " << x;
        std::cout << " | meta=" << (meta ? std::to_string(*meta) : "null") << std::endl;
    }
};

// Rule of 5: Manual resource management for comparison.
class ManualResource
{
    int *arr;
    size_t n;

public:
    ManualResource(size_t sz) : arr(new int[sz]), n(sz) { std::fill(arr, arr + n, 0); }
    ManualResource(const ManualResource &o) : arr(new int[o.n]), n(o.n)
    {
        std::copy(o.arr, o.arr + o.n, arr);
    }
    ManualResource &operator=(const ManualResource &o)
    {
        if (this != &o)
        {
            delete[] arr;
            n = o.n;
            arr = new int[n];
            std::copy(o.arr, o.arr + n, arr);
        }
        return *this;
    }
    ManualResource(ManualResource &&o) noexcept : arr(o.arr), n(o.n)
    {
        o.arr = nullptr;
        o.n = 0;
    }
    ManualResource &operator=(ManualResource &&o) noexcept
    {
        if (this != &o)
        {
            delete[] arr;
            arr = o.arr;
            n = o.n;
            o.arr = nullptr;
            o.n = 0;
        }
        return *this;
    }
    ~ManualResource() { delete[] arr; }
};

int main()
{
    std::cout << "====================\n";
    std::cout << "Rule of 0 vs Rule of 5 Demo\n";
    std::cout << "====================\n";

    std::cout << "\n--- Rule of 0: ModernResourceCopyable (all STL/RAII types, copyable) ---\n";
    ModernResourceCopyable m1("first", {1, 2, 3});
    ModernResourceCopyable m2 = m1; // copy
    ModernResourceCopyable m3("third", {3, 4});
    m3 = std::move(m1); // move
    m2.print("m2:");
    m3.print("m3:");
    std::cout << "(No manual destructor/copy/move needed! No leaks, no double delete possible.)\n";

    std::cout << "\n--- Rule of 0: ModernResourceMoveOnly (contains unique_ptr, move-only) ---\n";
    ModernResourceMoveOnly mo1("move1", {7, 8, 9});
    ModernResourceMoveOnly mo2 = std::move(mo1); // move
    mo2.print("mo2:");
    std::cout << "(Copying is disabled by compiler, but move works. Still no leaks or double delete.)\n";
    // Uncommenting the next line would cause a compile error (copy is deleted):
    // ModernResourceMoveOnly mo3 = mo2;

    std::cout << "\n--- Rule of 5: ManualResource (raw pointer, manual management) ---\n";
    ManualResource r1(5);
    ManualResource r2 = r1; // copy
    ManualResource r3(3);
    r3 = std::move(r1); // move
    std::cout << "(ManualResource requires destructor, copy/move constructor, and assignment.\n";
    std::cout << "If you forget any, you risk leaks, double delete, or undefined behavior!)\n";
    std::cout << "ManualResource test complete.\n";

    std::cout << "\nSummary: Prefer Rule of 0 and RAII types (STL containers, smart pointers) for safe,\n";
    std::cout << "maintainable code. Use Rule of 5 only when you must manage raw resources.\n";
    return 0;
}
