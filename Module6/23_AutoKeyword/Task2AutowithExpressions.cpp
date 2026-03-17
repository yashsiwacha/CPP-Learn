#include <iostream>
#include <typeinfo>

struct Point
{
    double x;
    double y;
};

Point operator+(const Point &lhs, const Point &rhs)
{
    return {lhs.x + rhs.x, lhs.y + rhs.y};
}

int main()
{
    // Expected type: double (int is promoted to double).
    auto a = 5 + 2.5;

    // Expected type: float (int is promoted to float).
    auto b = 3 * 1.5f;

    // Expected type: int (char participates in integer arithmetic promotions).
    auto c = 'A' + 1;

    // Expected type: double (long long + double -> double).
    auto d = 10000000000LL + 0.25;

    // User-defined type example: operator+ returns Point, so auto deduces Point.
    auto p = Point{1.5, 2.0} + Point{3.0, 4.5};

    // Note: typeid(...).name() is implementation-defined and may differ by compiler.
    std::cout << "auto a = 5 + 2.5; value: " << a << ", type: " << typeid(a).name() << std::endl;
    std::cout << "auto b = 3 * 1.5f; value: " << b << ", type: " << typeid(b).name() << std::endl;
    std::cout << "auto c = 'A' + 1; value: " << c << ", type: " << typeid(c).name() << std::endl;
    std::cout << "auto d = 10000000000LL + 0.25; value: " << d << ", type: " << typeid(d).name() << std::endl;
    std::cout << "auto p = Point{1.5, 2.0} + Point{3.0, 4.5}; value: (" << p.x << ", " << p.y
              << "), type: " << typeid(p).name() << std::endl;

    return 0;
}
