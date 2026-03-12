#include <iostream>
#include <type_traits>
#include <typeinfo>

// Function template: T is deduced from the argument passed to showType.
template <typename T>
void showType(T t)
{
    std::cout << "Value: " << t << '\n';
    // typeid(T).name() shows the compiler's runtime type name representation.
    // The exact text is compiler-dependent (e.g., i/d on GCC, full names on MSVC).
    std::cout << "Deduced type (typeid(T).name()): " << typeid(T).name() << '\n';

    // For pass-by-value parameters, decltype(t) is the same type as T.
    std::cout << "decltype(t) same as T: "
              << (std::is_same_v<decltype(t), T> ? "true" : "false") << "\n\n";
}

int main()
{
    // Literal 10 deduces T as int.
    showType(10); // int
    // Literal 3.14 deduces T as double.
    showType(3.14); // double
    return 0;
}
