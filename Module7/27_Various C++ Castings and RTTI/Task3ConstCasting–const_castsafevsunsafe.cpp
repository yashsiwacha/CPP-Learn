#include <iostream>

void unsafe_modify_const(const int *ptr)
{
    int *modPtr = const_cast<int *>(ptr);
    std::cout << "[unsafe] Trying to modify a truly const object..." << std::endl;

    // Undefined behavior: original object is truly const.
    *modPtr = 20;
}

void safe_modify_nonconst(const int *ptr)
{
    int *modPtr = const_cast<int *>(ptr);
    std::cout << "[safe] Modifying original non-const variable." << std::endl;

    // Safe: original object is non-const, only viewed through const int*.
    *modPtr = 99;
}

int main()
{
    const int x = 10;
    std::cout << "[main] x before = " << x << std::endl;
    unsafe_modify_const(&x); // Demonstration only: this is undefined behavior.
    std::cout << "[main] x after = " << x << " (result is undefined)" << std::endl;

    int y = 123;
    const int *py = &y;
    std::cout << "[main] y before = " << y << std::endl;
    safe_modify_nonconst(py);
    std::cout << "[main] y after = " << y << std::endl;

    std::cout << "\nSummary:" << std::endl;
    std::cout << "- Writing through const_cast is only safe when original object is non-const." << std::endl;
    std::cout << "- Writing to truly const objects after const_cast is undefined behavior." << std::endl;
    std::cout << "- Use const_cast rarely (typically for legacy APIs), not to break const-correctness." << std::endl;

    return 0;
}
