// Program to demonstrate the double delete error in C++
#include <iostream>
using namespace std;

int main()
{
    int *ptr = new int[5]{1, 2, 3, 4, 5};
    cout << "Value at ptr: " << ptr[0] << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Value at ptr[" << i << "]: " << ptr[i] << endl; // Output: 1, 2, 3, 4, 5
    }
    delete[] ptr;  // Deleting the allocated array
    ptr = nullptr; // Set to nullptr after deletion
    // delete[] ptr; // Now safe (deleting nullptr is well-defined as no-op)
    return 0;
}