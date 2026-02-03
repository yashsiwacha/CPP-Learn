// Program demonstrating 2D array using pointers
#include <iostream>
using namespace std;

int main()
{
    // Static 2D array
    cout << "Method 1: Static 2D Array\n";
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }

    // Pointer to first row
    int (*ptr)[4] = arr;
    cout << "\nptr[0][0] = " << ptr[0][0] << "\n";
    cout << "ptr[1][2] = " << ptr[1][2] << "\n";

    // Dynamic 2D array
    cout << "\nMethod 2: Dynamic 2D Array\n";
    int (*dynArr)[4] = new int[3][4];

    int value = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            dynArr[i][j] = value++;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << dynArr[i][j] << " ";
        cout << "\n";
    }

    delete[] dynArr;

    // Double pointer
    cout << "\nMethod 3: Double Pointer\n";
    int **arr2 = new int *[3];
    for (int i = 0; i < 3; i++)
        arr2[i] = new int[4];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            arr2[i][j] = (i + 1) * 10 + j;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << arr2[i][j] << " ";
        cout << "\n";
    }

    // Clean up
    for (int i = 0; i < 3; i++)
        delete[] arr2[i];
    delete[] arr2;

    return 0;
}