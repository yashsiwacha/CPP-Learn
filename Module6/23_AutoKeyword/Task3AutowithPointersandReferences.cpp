#include <iostream>

int main()
{
    // Base integer value used for pointer and reference demonstrations.
    int x = 10;

    // ptr stores the address of x.
    int *ptr = &x;

    // auto copies pointer type here, so p is deduced as int*.
    auto p = ptr;
    // auto& keeps reference semantics, so r is deduced as int&.
    auto &r = x;

    // Both p and r refer to the same underlying variable x.
    // Any write through p or r updates x itself.

    std::cout << "=== Task 3: Auto with Pointers and References ===\n";
    std::cout << "Initial State:\n";
    std::cout << "x: " << x << " | *p: " << *p << " | r: " << r << '\n';
    std::cout << "Address Check (all should refer to x):\n";
    std::cout << "&x: " << &x << " | p: " << p << " | &r: " << &r << "\n\n";

    // Step 1: Modify via reference.
    // Since r is an alias of x, assigning r changes x directly.
    r = 20;
    std::cout << "After r = 20:\n";
    std::cout << "x: " << x << " | *p: " << *p << " | r: " << r << "\n\n";

    // Step 2: Modify via pointer.
    // p points to x, so writing to *p also changes x.
    *p = 30;
    std::cout << "After *p = 30:\n";
    std::cout << "x: " << x << " | *p: " << *p << " | r: " << r << "\n\n";

    // Extra mini-example: auto with const pointer type deduction.
    // Here cp is deduced as const int* because cx is const.
    const int cx = 99;
    auto cp = &cx;
    std::cout << "Const Deduction Example:\n";
    std::cout << "cx: " << cx << " | *cp: " << *cp << "\n\n";

    // Final summary.
    std::cout << "Final Values:\n";
    std::cout << "x (original variable): " << x << '\n';
    std::cout << "*p (value via pointer): " << *p << '\n';
    std::cout << "r (value via reference): " << r << '\n';

    return 0;
}
