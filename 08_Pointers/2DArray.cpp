// Program to demonstrate 2D array using pointers in C++
#include <iostream>
using namespace std;

int main()
{
    cout << "========================================" << endl;
    cout << "   2D ARRAY POINTERS - SIMPLE GUIDE" << endl;
    cout << "========================================\n"
         << endl;

    // ===== METHOD 1: Static 2D Array =====
    cout << "METHOD 1: Static 2D Array\n"
         << endl;

    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    cout << "Array contents:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Pointer to first row
    int (*ptr)[4] = arr;

    cout << "\nUsing pointer:" << endl;
    cout << "ptr[0][0] = " << ptr[0][0] << endl;
    cout << "ptr[1][2] = " << ptr[1][2] << endl;
    cout << "ptr[2][3] = " << ptr[2][3] << endl;

    // ===== METHOD 2: Dynamic 2D Array using new =====
    cout << "\n\nMETHOD 2: Dynamic 2D Array\n"
         << endl;

    int rows = 3, cols = 4;
    int (*dynArr)[4] = new int[3][4];

    // Fill array
    int value = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            dynArr[i][j] = value++;
        }
    }

    cout << "Dynamic array contents:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << dynArr[i][j] << " ";
        }
        cout << endl;
    }

    delete[] dynArr;

    // ===== METHOD 3: Using Double Pointer =====
    cout << "\n\nMETHOD 3: Using Double Pointer\n"
         << endl;

    int **arr2 = new int *[3];
    for (int i = 0; i < 3; i++)
    {
        arr2[i] = new int[4];
    }

    // Fill array
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr2[i][j] = (i + 1) * 10 + j;
        }
    }

    cout << "Double pointer array:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    // Clean up
    for (int i = 0; i < 3; i++)
    {
        delete[] arr2[i];
    }
    delete[] arr2;

    // ===== ACCESSING ELEMENTS - Different Ways =====
    cout << "\n\nACCESSING ELEMENTS - Different Ways\n"
         << endl;

    int testArr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int (*p)[3] = testArr;

    cout << "Array: 1 2 3" << endl;
    cout << "       4 5 6" << endl;

    cout << "\nAccessing element at [1][2] (value = 6):" << endl;
    cout << "p[1][2] = " << p[1][2] << endl;
    cout << "*(p[1] + 2) = " << *(p[1] + 2) << endl;
    cout << "*(*(p + 1) + 2) = " << *(*(p + 1) + 2) << endl;

    // ===== SHALLOW vs DEEP COPY =====
    cout << "\n\nSHALLOW vs DEEP COPY\n"
         << endl;

    int (*original)[3] = new int[2][3];
    original[0][0] = 10;
    original[0][1] = 20;
    original[1][0] = 30;

    // Shallow copy - points to same memory
    int (*shallow)[3] = original;

    // Deep copy - new memory
    int (*deep)[3] = new int[2][3];
    deep[0][0] = original[0][0];
    deep[0][1] = original[0][1];
    deep[1][0] = original[1][0];

    cout << "Before change:" << endl;
    cout << "original[0][0] = " << original[0][0] << endl;
    cout << "shallow[0][0] = " << shallow[0][0] << endl;
    cout << "deep[0][0] = " << deep[0][0] << endl;

    // Modify original
    original[0][0] = 999;

    cout << "\nAfter changing original[0][0] to 999:" << endl;
    cout << "original[0][0] = " << original[0][0] << endl;
    cout << "shallow[0][0] = " << shallow[0][0] << " (changed!)" << endl;
    cout << "deep[0][0] = " << deep[0][0] << " (not changed)" << endl;

    delete[] original;
    delete[] deep;

    // ===== SUMMARY =====
    cout << "\n\nSUMMARY" << endl;
    cout << "-------" << endl;
    cout << "1. Static array: int arr[3][4]" << endl;
    cout << "2. Dynamic array: int (*ptr)[4] = new int[3][4]" << endl;
    cout << "3. Double pointer: int **arr (most flexible)" << endl;
    cout << "4. Shallow copy = same memory" << endl;
    cout << "5. Deep copy = different memory" << endl;

    return 0;
}