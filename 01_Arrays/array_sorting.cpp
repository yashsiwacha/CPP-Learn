#include <iostream>
#include <algorithm> // for sort function
using namespace std;

// Function to input array elements from user
void inputArray(int arr[], int size)
{
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << (i + 1) << ": ";
        cin >> arr[i];
    }
}

// Function to display array elements
void displayArray(int arr[], int size)
{
    cout << "Array elements: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to check if array is sorted
bool isSorted(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

// Linear Search Algorithm
// Traverses array element by element to find the key
// Time Complexity: O(n)
// Works with both sorted and unsorted arrays
int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i; // Return index if key is found
        }
    }
    return -1; // Return -1 if key is not found
}

// Binary Search Algorithm
// Efficiently searches in a sorted array by dividing search interval in half
// Time Complexity: O(log n)
// Requires array to be sorted
int binarySearch(int arr[], int size, int key)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2; // Calculate middle index

        if (arr[mid] == key)
        {
            return mid; // Key found at mid index
        }
        else if (arr[mid] < key)
        {
            low = mid + 1; // Search in right half
        }
        else
        {
            high = mid - 1; // Search in left half
        }
    }

    return -1; // Key not found
}

// Function to print search result
void printResult(int index, int key)
{
    if (index != -1)
    {
        cout << "\n✓ Key " << key << " found at index " << index << " (position " << (index + 1) << ")" << endl;
    }
    else
    {
        cout << "\n✗ Key " << key << " not found in the array" << endl;
    }
}

int main()
{
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size, key, choice;

    cout << "========================================\n";
    cout << "  ARRAY SEARCH PROGRAM\n";
    cout << "  Linear & Binary Search Implementation\n";
    cout << "========================================\n\n";

    // Input array size with validation
    do
    {
        cout << "Enter the size of the array (1-" << MAX_SIZE << "): ";
        cin >> size;

        if (size <= 0 || size > MAX_SIZE)
        {
            cout << "Invalid size! Please enter a value between 1 and " << MAX_SIZE << ".\n";
        }
    } while (size <= 0 || size > MAX_SIZE);

    // Input array elements
    inputArray(arr, size);

    // Display the array
    cout << "\n";
    displayArray(arr, size);

    // Input search key
    cout << "\nEnter the value to search for: ";
    cin >> key;

    // Display search method menu
    cout << "\n========================================\n";
    cout << "  SELECT SEARCH METHOD\n";
    cout << "========================================\n";
    cout << "1. Linear Search (works with any array)\n";
    cout << "2. Binary Search (requires sorted array)\n";
    cout << "========================================\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    int index = -1;

    switch (choice)
    {
    case 1:
        // Linear Search
        cout << "\nPerforming Linear Search...\n";
        index = linearSearch(arr, size, key);
        printResult(index, key);
        break;

    case 2:
        // Binary Search
        cout << "\nPerforming Binary Search...\n";

        // Check if array is sorted
        if (!isSorted(arr, size))
        {
            cout << "Array is not sorted. Sorting the array...\n";
            sort(arr, arr + size); // Sort the array
            cout << "Array sorted successfully!\n";
            displayArray(arr, size);
        }
        else
        {
            cout << "Array is already sorted.\n";
        }

        index = binarySearch(arr, size, key);
        printResult(index, key);
        break;

    default:
        cout << "\nInvalid choice! Please select 1 or 2.\n";
        return 1;
    }

    // Display algorithm comparison information
    cout << "\n========================================\n";
    cout << "  ALGORITHM COMPARISON\n";
    cout << "========================================\n";
    cout << "Linear Search:\n";
    cout << "  • Time Complexity: O(n)\n";
    cout << "  • Works with unsorted arrays\n";
    cout << "  • Simple implementation\n";
    cout << "  • Best for small arrays\n\n";
    cout << "Binary Search:\n";
    cout << "  • Time Complexity: O(log n)\n";
    cout << "  • Requires sorted array\n";
    cout << "  • More efficient for large arrays\n";
    cout << "  • Uses divide-and-conquer approach\n";
    cout << "========================================\n";

    return 0;
}
