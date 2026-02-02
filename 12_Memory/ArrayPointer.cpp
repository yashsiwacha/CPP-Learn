// Program to demonstrate memory allocation

#include <iostream>
using namespace std;

int main()
{
    int *p = new int(10);
    cout << *p << " at " << p << endl;
    delete p;

    int *arr = new int[5]{1, 2, 3, 4, 5};
    for (int *p = arr; p < arr + 5; p++)
    {
        cout << *p << " at " << p << endl;
    }
    delete[] arr;

    cout << "\n=== Shallow Copy (UNSAFE) ===" << endl;
    int *p1 = new int(12);
    int *p2 = p1;
    cout << "*p1 = " << *p1 << " at " << p1 << endl;
    cout << "*p2 = " << *p2 << " at " << p2 << endl;
    delete p1;
    // DANGER: p2 is now a dangling pointer
    cout << "After delete p1, p2 still points to: " << p2 << " (but memory is freed!)" << endl;
    p1 = nullptr;
    p2 = nullptr;

    cout << "\n=== Deep Copy (SAFE) ===" << endl;
    int *p3 = new int(25);
    int *p4 = new int(*p3);
    cout << "*p3 = " << *p3 << " at " << p3 << endl;
    cout << "*p4 = " << *p4 << " at " << p4 << endl;
    delete p3;
    cout << "After delete p3, p4 is still valid!" << endl;
    cout << "*p4 = " << *p4 << " at " << p4 << endl;
    delete p4;

    cout << "\n=== Array Deep Copy ===" << endl;
    int *arr1 = new int[3]{10, 20, 30};
    int *arr2 = new int[3];
    for (int i = 0; i < 3; i++)
    {
        arr2[i] = arr1[i];
    }
    delete[] arr1;
    cout << "After deleting arr1, arr2 still has: ";
    for (int i = 0; i < 3; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    delete[] arr2;
}