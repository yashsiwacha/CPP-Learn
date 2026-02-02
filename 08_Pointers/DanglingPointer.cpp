// Program to demonstrate Dangling Pointer in C++
// A dangling pointer points to memory that has been freed/deallocated
#include <iostream>
using namespace std;

// Function allocates memory dynamically and returns pointer to it
int *allocateInteger()
{
    int *ptr = new int(100); // Allocate memory on heap and initialize with 100
    return ptr;              // Return the pointer to allocated memory
}

int main()
{
    // Step 1: Allocate memory and get pointer
    int *numberPtr = allocateInteger();
    cout << "Step 1 - Memory allocated at address: " << numberPtr << endl;
    cout << "Initial value: " << *numberPtr << endl;

    // Step 2: Modify the value at allocated memory
    *numberPtr = 25; // Dereference pointer to change value
    cout << "\nStep 2 - Value modified to: " << *numberPtr << endl;

    // Step 3: Free the memory - pointer becomes dangling
    delete numberPtr; // Memory is freed, but pointer still holds the address
    cout << "\nStep 3 - Memory deleted (numberPtr is now a dangling pointer)" << endl;

    // Step 4: Accessing dangling pointer - UNDEFINED BEHAVIOR
    // The pointer still holds the address but memory is freed - very dangerous!
    cout << "WARNING: Attempting to access dangling pointer (undefined behavior)" << endl;
    cout << "Dangling pointer address: " << numberPtr << endl;
    cout << "Dangling pointer value (garbage): " << *numberPtr << endl;

    // Step 5: Set pointer to nullptr to prevent accidental access
    // Best practice: always set pointers to nullptr after deleting
    numberPtr = nullptr;
    cout << "\nStep 5 - Pointer set to nullptr for safety: " << numberPtr << endl;

    // Step 6: Safe way to check before accessing pointer
    if (numberPtr != nullptr)
    {
        cout << "Value: " << *numberPtr << endl;
    }
    else
    {
        cout << "Pointer is null - safe to skip access (prevents undefined behavior)" << endl;
    }

    return 0;
}