// Program demonstrating linear and binary search algorithms
#include <iostream>
#include <algorithm>
using namespace std;

// Input array from user
void inputArray(int arr[], int size)
{
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << (i + 1) << ": ";
        cin >> arr[i];
    }
}

// Display array
void displayArray(int arr[], int size)
{
    cout << "Array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Check if array is sorted
bool isSorted(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1])
            return false;
    return true;
}

// Linear search - O(n) complexity
int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

// Binary search - O(log n) complexity, requires sorted array
int binarySearch(int arr[], int size, int key)
{
    int low = 0, high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Print search result
void printResult(int index, int key)
{
    if (index != -1)
        cout << "\nKey " << key << " found at index " << index << " (position " << (index + 1) << ")\n";
    else
        cout << "\nKey " << key << " not found\n";
}

int main()
{
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size, key, choice;

    cout << "ARRAY SEARCH PROGRAM\n\n";

    // Input array size
    do
    {
        cout << "Enter array size (1-" << MAX_SIZE << "): ";
        cin >> size;

        if (size <= 0 || size > MAX_SIZE)
            cout << "Invalid size!\n";
    } while (size <= 0 || size > MAX_SIZE);

    // Input array elements
    inputArray(arr, size);
    cout << "\n";
    displayArray(arr, size);

    // Input search key
    cout << "\nEnter value to search: ";
    cin >> key;

    // Select search method
    cout << "\nSearch methods:\n";
    cout << "1. Linear Search\n";
    cout << "2. Binary Search\n";
    cout << "Choice: ";
    cin >> choice;

    int index = -1;

    switch (choice)
    {
    case 1:
        cout << "\nPerforming Linear Search...\n";
        index = linearSearch(arr, size, key);
        printResult(index, key);
        break;

    case 2:
        cout << "\nPerforming Binary Search...\n";

        if (!isSorted(arr, size))
        {
            cout << "Sorting array...\n";
            sort(arr, arr + size);
            displayArray(arr, size);
        }

        index = binarySearch(arr, size, key);
        printResult(index, key);
        break;

    default:
        cout << "\nInvalid choice!\n";
        return 1;
    }

    return 0;
}
