// Program to reverse an array to another array
#include <iostream>
using namespace std;

void mirrorArrayElements(int sourceArr[], int reversedArr[], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        reversedArr[i] = sourceArr[arrayLength - 1 - i];
    }
}

void populateArrayFromUser(int arr[], int arrayLength)
{
    cout << "Enter " << arrayLength << " elements: ";
    for (int i = 0; i < arrayLength; i++)
    {
        cin >> arr[i];
    }
}

void displayArrayElements(int arr[], int arrayLength, string label = "Array")
{
    cout << label << ": ";
    for (int i = 0; i < arrayLength; i++)
    {
        cout << arr[i];
        if (i < arrayLength - 1)
            cout << " -> ";
    }
    cout << endl;
}

int getValidArraySize()
{
    int size;
    do
    {
        cout << "Enter the size of the array (must be > 0): ";
        cin >> size;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Please enter a valid integer!\n";
            size = 0;
        }
        else if (size <= 0)
        {
            cout << "Error: Size must be a positive number. Please try again.\n";
        }
    } while (size <= 0);

    return size;
}

int main()
{
    int arraySize = getValidArraySize();

    int originalArray[arraySize], reversedArray[arraySize];

    populateArrayFromUser(originalArray, arraySize);
    displayArrayElements(originalArray, arraySize, "Original Array");

    mirrorArrayElements(originalArray, reversedArray, arraySize);
    displayArrayElements(reversedArray, arraySize, "Reversed Array");

    return 0;
}