#include <iostream>
#include <string>

// Class template: T is a placeholder type, so Box can store any type
// that supports copying and output with std::cout.
template <typename T>
class Box
{
    T value;

public:
    // Constructor initializes the stored value.
    Box(T v) : value(v) {}
    // const means print() does not modify the object.
    // label keeps output explicit for assignment-style clarity.
    void print(const std::string &label) const
    {
        std::cout << label << value << std::endl;
    }
};

int main()
{
    // Template parameter is specified at instantiation:
    // Box<int> uses T = int, Box<std::string> uses T = std::string.
    Box<int> intBox(42);
    Box<std::string> strBox("Hello, Templates!");

    intBox.print("Box<int>: ");         // Output: Box<int>: 42
    strBox.print("Box<std::string>: "); // Output: Box<std::string>: Hello, Templates!

    return 0;
}
