#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

int main()
{
    auto i = 42;                 // Deduces int
    auto d = 3.14;               // Deduces double
    auto s = std::string("abc"); // Deduces std::string

    std::cout << "auto i = 42; type: " << typeid(i).name() << ", value: " << i << std::endl;
    std::cout << "auto d = 3.14; type: " << typeid(d).name() << ", value: " << d << std::endl;
    std::cout << "auto s = std::string(\"abc\"); type: " << typeid(s).name() << ", value: " << s << std::endl;

    // Explicit type declarations for comparison
    int i2 = 42;
    double d2 = 3.14;
    std::string s2 = "abc";

    std::cout << "int i2 = 42; type: " << typeid(i2).name() << ", value: " << i2 << std::endl;
    std::cout << "double d2 = 3.14; type: " << typeid(d2).name() << ", value: " << d2 << std::endl;
    std::cout << "std::string s2 = \"abc\"; type: " << typeid(s2).name() << ", value: " << s2 << std::endl;

    return 0;
}
