#include <iostream>

int main()
#include <iostream>

    int main()
{
    int a = 10;
    double b = 3.7;

    // C-style casts
    double d1 = (double)a; // int to double
    int i1 = (int)b;       // double to int (truncates fractional part)

    // C++-style casts
    double d2 = static_cast<double>(a);
    int i2 = static_cast<int>(b); // truncates fractional part

    std::cout << "Original values: a = " << a << ", b = " << b << std::endl;
    std::cout << "C-style cast int to double: d1 = " << d1 << std::endl;
    std::cout << "C-style cast double to int: i1 = " << i1 << " (truncates)" << std::endl;
    std::cout << "static_cast int to double: d2 = " << d2 << std::endl;
    std::cout << "static_cast double to int: i2 = " << i2 << " (truncates)" << std::endl;

    std::cout << "\nWhy prefer static_cast?" << std::endl;
    std::cout << "- It is explicit and easier to search/review in code." << std::endl;
    std::cout << "- It makes intent clear and avoids overly permissive C-style cast behavior." << std::endl;

    return 0;
}
