// Program to demonstrate dynamic memory allocation, shallow vs deep copy

#include <iostream>
using namespace std;

int main()
{
    // Single integer allocation
    int *p = new int(10);
    cout << *p << " at " << p << endl;
    delete p;

    // Array allocation with initialization
    int *arr = new int[5]{1, 2, 3, 4, 5};
    for (int *p = arr; p < arr + 5; p++)
    {
        cout << *p << " at " << p << endl;
    }
    delete[] arr; // Use delete[] for arrays

    cout << "\nShallow Copy (UNSAFE)\n";
    // Shallow copy: both pointers point to same memory location
    int *p1 = new int(12);
    int *p2 = p1; // Only copies address, not the value
    cout << "*p1 = " << *p1 << " at " << p1 << "\n";
    cout << "*p2 = " << *p2 << " at " << p2 << "\n";
    delete p1; // Frees memory
    // Now p2 points to freed memory (dangling pointer)
    cout << "After delete p1, p2 is dangling pointer at: " << p2 << "\n";
    p1 = nullptr;
    p2 = nullptr;

    cout << "\nDeep Copy (SAFE)\n";
    // Deep copy: each pointer has its own memory
    int *p3 = new int(25);
    int *p4 = new int(*p3); // Allocates new memory and copies the value
    cout << "*p3 = " << *p3 << " at " << p3 << "\n";
    cout << "*p4 = " << *p4 << " at " << p4 << "\n";
    delete p3; // Safe to delete p3
    // p4 still valid because it has its own memory
    cout << "After delete p3, p4 still valid: " << *p4 << " at " << p4 << "\n";
    delete p4;

    cout << "\nArray Deep Copy\n";
    // Deep copy for arrays: allocate separate memory and copy elements
    int *arr1 = new int[3]{10, 20, 30};
    int *arr2 = new int[3]; // Allocate new array
    for (int i = 0; i < 3; i++)
    {
        arr2[i] = arr1[i]; // Copy each element
    }
    delete[] arr1; // Safe to delete arr1
    cout << "After deleting arr1, arr2 still has: ";
    for (int i = 0; i < 3; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    delete[] arr2;
}