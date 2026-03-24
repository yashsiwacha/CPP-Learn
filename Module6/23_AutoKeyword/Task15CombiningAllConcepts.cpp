#include <iostream>
#include <vector>
#include <initializer_list>

class Matrix
{
private:
    std::vector<std::vector<int>> data;

public:
    // initializer_list enables clean 2D brace initialization for custom classes.
    Matrix(std::initializer_list<std::initializer_list<int>> list)
    {
        // const auto& avoids copying each source row from the initializer list.
        for (const auto &row : list)
        {
            data.emplace_back(row);
        }
    }

    // auto& gives write access to each element so values can be changed in-place.
    void doubleInPlace()
    {
        for (auto &row : data)
        {
            for (auto &col : row)
            {
                col *= 2;
            }
        }
    }

    // const auto& keeps traversal read-only while still avoiding copies.
    void print() const
    {
        std::cout << "Matrix elements:" << std::endl;
        for (const auto &row : data)
        {
            for (const auto &col : row)
            {
                std::cout << col << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

int main()
{
    Matrix mat{{1, 2},
               {3, 4}};

    mat.print();
    mat.doubleInPlace();
    std::cout << "After doubling:" << std::endl;
    mat.print();

    return 0;
}
