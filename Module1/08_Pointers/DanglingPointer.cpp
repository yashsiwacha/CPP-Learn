// Program demonstrating dangling pointer behavior
#include <iostream>
using namespace std;

int *allocateInteger()
{
    int *ptr = new int(100);
    return ptr;
}

int main()
{
    int *numberPtr = allocateInteger();
    cout << "Initial value: " << *numberPtr << "\n";

    *numberPtr = 25;
    cout << "Modified value: " << *numberPtr << "\n";

    // Delete memory - pointer becomes dangling
    delete numberPtr;
    cout << "Memory freed\n";

    // Accessing dangling pointer causes undefined behavior
    cout << "Dangling pointer value (garbage): " << *numberPtr << "\n";

    // Set to nullptr for safety
    numberPtr = nullptr;

    if (numberPtr != nullptr)
        cout << "Value: " << *numberPtr << "\n";
    else
        cout << "Pointer is now null\n";

    return 0;
}