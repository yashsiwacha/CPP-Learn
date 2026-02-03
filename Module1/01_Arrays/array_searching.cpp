// Program to reverse an array
#include <iostream>
using namespace std;

// Reverse array elements
void mirrorArrayElements(int sourceArr[], int reversedArr[], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
        reversedArr[i] = sourceArr[arrayLength - 1 - i];
}

// Get user input for array
void populateArrayFromUser(int arr[], int arrayLength)
{
    cout << "Enter " << arrayLength << " elements: ";
    for (int i = 0; i < arrayLength; i++)
        cin >> arr[i];
}

// Display array elements
void displayArrayElements(int arr[], int arrayLength, string label = "Array")
{
    cout << label << ": ";
    for (int i = 0; i < arrayLength; i++)
    {
        cout << arr[i];
        if (i < arrayLength - 1)
            cout << " -> ";
    }
    cout << "\n";
}

// Get valid array size with error handling
int getValidArraySize()
{
    int size;
    do
    {
        cout << "Enter array size (> 0): ";
        cin >> size;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Invalid input!\n";
            size = 0;
        }
        else if (size <= 0)
            cout << "Error: Size must be positive!\n";
    } while (size <= 0);

    return size;
}

int main()
{
    int arraySize = getValidArraySize();
    int originalArray[arraySize], reversedArray[arraySize];

    populateArrayFromUser(originalArray, arraySize);
    displayArrayElements(originalArray, arraySize, "Original");

    mirrorArrayElements(originalArray, reversedArray, arraySize);
    displayArrayElements(reversedArray, arraySize, "Reversed");

    return 0;
}