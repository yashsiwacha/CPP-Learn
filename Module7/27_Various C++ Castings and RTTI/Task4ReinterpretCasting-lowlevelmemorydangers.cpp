#include <cstdint>
#include <iomanip>
#include <iostream>

int main()
{
    int value = 0x12345678;
    std::cout << "int value = 0x" << std::hex << value << std::dec << std::endl;

    // Reinterpret the int storage as bytes to inspect machine endianness.
    unsigned char *pbyte = reinterpret_cast<unsigned char *>(&value);
    std::cout << "Bytes of value: ";
    for (std::size_t i = 0; i < sizeof(value); ++i)
    {
        std::cout << "0x" << std::hex << std::setw(2) << std::setfill('0')
                  << static_cast<unsigned int>(pbyte[i]) << " ";
    }
    std::cout << std::dec << std::setfill(' ') << std::endl;

    // Unsafe reinterpretation demo between unrelated pointer types.
    // We use aligned storage to avoid size/alignment crashes, but this is still UB.
    alignas(double) unsigned char raw[sizeof(double)]{};
    int *pi = reinterpret_cast<int *>(raw);
    *pi = 42;
    double *pd = reinterpret_cast<double *>(pi);

    std::cout << "Reading int memory as double (UB): " << *pd << std::endl;
    *pd = 1.23; // UB: writing through unrelated type view
    std::cout << "After writing through double* (UB), int view = " << *pi << std::endl;

    std::cout << "\nDiscussion:" << std::endl;
    std::cout << "- reinterpret_cast only reinterprets bits; it does not provide type safety." << std::endl;
    std::cout << "- Unrelated pointer casts can violate aliasing/lifetime rules (undefined behavior)." << std::endl;
    std::cout << "- Endianness, type size, and alignment differ across platforms, so code is non-portable." << std::endl;
    std::cout << "- Prefer static_cast/const_cast/dynamic_cast for normal C++ code." << std::endl;
    std::cout << "- Use reinterpret_cast only in rare low-level systems or hardware-facing code." << std::endl;

    return 0;
}
