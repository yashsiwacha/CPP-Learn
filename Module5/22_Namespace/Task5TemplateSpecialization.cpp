#include <iostream>
#include <cctype>
#include <string>
#include <utility>

// Primary template: default behavior for most types.
// This generic version is reused for any T unless a specialization is provided.
template <typename T>
class Box
{
    T value;

public:
    Box(T v) : value(v) {}
    void print(const std::string &label) const
    {
        std::cout << label << value << std::endl;
    }
};

// Full specialization for std::string:
// A specialization replaces the generic template for one exact type.
// Useful when that type needs custom behavior (here: uppercase output).
template <>
class Box<std::string>
{
    std::string value;

public:
    Box(std::string v) : value(std::move(v)) {}
    void print(const std::string &label) const
    {
        std::cout << label;
        for (char c : value)
            std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
        std::cout << std::endl;
    }
};

int main()
{
    Box<std::string> boxStr("hello, Templates!");
    // Note: letters are uppercased; punctuation and spaces remain unchanged.
    boxStr.print("Box<std::string> (UPPERCASE): "); // Prints: Box<std::string> (UPPERCASE): HELLO, TEMPLATES!
    Box<int> box(12);
    box.print("Box<int>: "); // Prints: Box<int>: 12
    return 0;
}
