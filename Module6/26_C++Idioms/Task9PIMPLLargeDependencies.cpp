// Task9PIMPLLargeDependencies.cpp
// Single-file submission version with clear header/source/main sections.
// Note: In a real project, these sections are separate physical files.

// ===== bigdata.h (public interface) =====
#include <cstddef>
#include <memory>

class BigData
{
public:
    BigData();
    ~BigData();

    void process();
    std::size_t getSize() const;

private:
    struct Impl;                // Forward declaration only.
    std::unique_ptr<Impl> impl; // No heavy includes in the interface.
};

// ===== bigdata.cpp (implementation with heavy includes) =====
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct BigData::Impl
{
    std::vector<int> bigVector;
    std::map<std::string, int> bigMap;
    std::string name;

    Impl()
    {
        bigVector.resize(1'000'000, 42);
        name = "BigData resource";
        bigMap["test"] = 99;
        std::cout << "[BigData::Impl] constructed with heavy data" << std::endl;
    }

    ~Impl()
    {
        std::cout << "[BigData::Impl] destroyed" << std::endl;
    }
};

BigData::BigData() : impl(std::make_unique<Impl>())
{
}

BigData::~BigData() = default;

void BigData::process()
{
    ++impl->bigVector[0];
    impl->bigMap["process"] = impl->bigVector[0];
    std::cout << "Processing " << impl->name << ": " << impl->bigVector[0] << std::endl;
}

std::size_t BigData::getSize() const
{
    return impl->bigVector.size();
}

// ===== main.cpp (user code) =====
// In a real multi-file project, main.cpp would include only bigdata.h and iostream.
int main()
{
    BigData bd;
    bd.process();
    std::cout << "BigData size: " << bd.getSize() << std::endl;
    return 0;
}
