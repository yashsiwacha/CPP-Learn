#include <iostream>
#include <string>

// Default template parameter: if no type is provided, T becomes int.
// This keeps usage simple for common cases while still allowing custom types.
template <typename T = int>
class Number
{
    T value;

public:
    Number(T v) : value(v) {}
    // Prints a clear label with the stored value.
    void print(const std::string &label) const
    {
        std::cout << label << value << std::endl;
    }
};

int main()
{
    // Uses default template argument: Number<int>
    Number<> n1(12);
    // Explicitly sets template argument to double.
    Number<double> n2(12.04);

    n1.print("Number<int>: ");
    n2.print("Number<double>: ");
    return 0;
}