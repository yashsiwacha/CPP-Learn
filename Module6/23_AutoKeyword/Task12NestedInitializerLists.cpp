#include <iostream>
#include <vector>

int main()
{
    // Nested initializer lists create a 2D vector (matrix) in a compact form.
    std::vector<std::vector<int>> mat{{1, 2}, {3, 4}};

    std::cout << "Matrix elements:" << std::endl;
    // const auto& avoids copying each row vector while iterating.
    for (const auto &row : mat)
    {
        // const auto& avoids copying each element (especially useful for heavier types).
        for (const auto &val : row)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
