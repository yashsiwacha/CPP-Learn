#include <iostream>
#include <vector>
#include <initializer_list>

class Numbers
{
private:
    std::vector<int> data;

public:
    // Accept values in braces and forward them directly into the vector.
    Numbers(std::initializer_list<int> list) : data(list) {}

    void print() const
    {
        std::cout << "Numbers: ";
        for (const auto &x : data)
        {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    Numbers nums{10, 20, 30, 40, 50};
    nums.print();

    return 0;
}
