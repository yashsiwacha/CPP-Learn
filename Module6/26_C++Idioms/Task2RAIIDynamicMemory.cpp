// RAII with Dynamic Memory – Managing Heap Allocations Safely
//
// RAII (Resource Acquisition Is Initialization) is a C++ idiom that ensures resources
// such as dynamic memory are acquired and released automatically by objects.
// This guarantees deterministic cleanup, even in the presence of exceptions or early returns.
//
// Modern C++ best practice: Prefer using standard library containers (like std::vector)
// or smart pointers (like std::unique_ptr) for resource management, as they implement RAII.
//
// This example demonstrates classic RAII with manual new/delete, and then with std::unique_ptr and std::vector.

#include <iostream>
#include <stdexcept>
#include <memory> // For std::unique_ptr
#include <vector> // For std::vector

// Classic RAII: IntArray manages a dynamic int array using new/delete
class IntArray
{
    int *arr;
    size_t size;

public:
    IntArray(size_t n) : size(n), arr(new int[n])
    {
        std::cout << "Allocated array of size " << size << " at " << static_cast<void *>(arr) << std::endl;
        for (size_t i = 0; i < size; ++i)
            arr[i] = static_cast<int>(i * 10); // Fill with sample values
    }
    ~IntArray()
    {
        std::cout << "Destructor called, freeing array at " << static_cast<void *>(arr) << std::endl;
        delete[] arr;
    }
    int &operator[](size_t i) { return arr[i]; }
    size_t getSize() const { return size; }
};

// Test function: early return
void testEarlyReturn()
{
    IntArray a(5);
    a[0] = 42;
    std::cout << "testEarlyReturn: value[0] = " << a[0] << std::endl;
    return; // Destructor will be called automatically
}

// Test function: exception thrown
void testException()
{
    try
    {
        IntArray a(5);
        throw std::runtime_error("Oops! Exception triggered.");
    }
    catch (...)
    {
        std::cout << "testException: exception caught, IntArray destructor should have run above.\n";
        throw; // rethrow for main to catch
    }
}

int main()
{
    // Normal usage: destructor called at end of scope
    try
    {
        IntArray arr(3);
        std::cout << "Normal usage: value[1] = " << arr[1] << std::endl;
    }
    catch (...)
    {
    }

    std::cout << "-- Testing early return --\n";
    testEarlyReturn();

    try
    {
        std::cout << "-- Testing exception --\n";
        testException();
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Caught exception: " << ex.what() << std::endl;
    }

    std::cout << "\n-- Modern C++: std::unique_ptr example --\n";
    {
        // std::unique_ptr automatically deletes memory, even on exception
        std::unique_ptr<int[]> smartArr(new int[4]);
        for (int i = 0; i < 4; ++i)
            smartArr[i] = i * 100;
        std::cout << "smartArr[2] = " << smartArr[2] << std::endl;
    } // smartArr memory freed here

    std::cout << "\n-- Modern C++: std::vector example --\n";
    {
        // std::vector manages memory and is exception safe
        std::vector<int> vec = {1, 2, 3, 4, 5};
        std::cout << "vec[3] = " << vec[3] << std::endl;
    } // vec memory freed here

    std::cout << "\nEnd of main reached.\n";
    return 0;
}
