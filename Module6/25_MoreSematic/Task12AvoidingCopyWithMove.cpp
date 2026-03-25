#include <iostream>
#include <vector>
#include <chrono>
#include <utility>

class LargeArray
{
private:
    std::vector<int> data;

public:
    explicit LargeArray(std::size_t n) : data(n, 42)
    {
        std::cout << "Constructed LargeArray with " << n << " elements" << std::endl;
    }

    LargeArray(const LargeArray &other) : data(other.data)
    {
        std::cout << "Copied LargeArray (deep copy)" << std::endl;
    }

    LargeArray(LargeArray &&other) noexcept : data(std::move(other.data))
    {
        std::cout << "Moved LargeArray (efficient ownership transfer)" << std::endl;
    }

    std::size_t size() const
    {
        return data.size();
    }
};

int main()
{
    const std::size_t n = 10'000'000;
    LargeArray arr1(n);

    auto start = std::chrono::high_resolution_clock::now();
    LargeArray arr2 = arr1; // Copy
    auto end = std::chrono::high_resolution_clock::now();
    const auto copyMs = std::chrono::duration<double, std::milli>(end - start).count();

    start = std::chrono::high_resolution_clock::now();
    LargeArray arr3 = std::move(arr1); // Move
    end = std::chrono::high_resolution_clock::now();
    const auto moveMs = std::chrono::duration<double, std::milli>(end - start).count();

    std::cout << "Copy time: " << copyMs << " ms" << std::endl;
    std::cout << "Move time: " << moveMs << " ms" << std::endl;
    std::cout << "arr2 size after copy: " << arr2.size() << std::endl;
    std::cout << "arr3 size after move: " << arr3.size() << std::endl;
    std::cout << "arr1 size after move (typically 0): " << arr1.size() << std::endl;

    return 0;
}
