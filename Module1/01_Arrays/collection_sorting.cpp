// Program demonstrating merge sort algorithm
#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted subarrays into one sorted array
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *leftArr = new int[n1];
    int *rightArr = new int[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }

    while (i < n1)
        arr[k++] = leftArr[i++];

    while (j < n2)
        arr[k++] = rightArr[j++];

    delete[] leftArr;
    delete[] rightArr;
}

// Recursively sort array using merge sort
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Vector version of merge function
void mergeVector(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }

    while (i < n1)
        arr[k++] = leftArr[i++];
    while (j < n2)
        arr[k++] = rightArr[j++];
}

// Vector version of merge sort
void mergeSortVector(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortVector(arr, left, mid);
        mergeSortVector(arr, mid + 1, right);
        mergeVector(arr, left, mid, right);
    }
}

// Print array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i < size - 1)
            cout << ", ";
    }
    cout << endl;
}

// Print vector
void printVector(const vector<int> &arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i < arr.size() - 1)
            cout << ", ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    vector<int> vec = {64, 34, 25, 12, 22, 11, 90};
    cout << "\nOriginal vector: ";
    printVector(vec);

    mergeSortVector(vec, 0, vec.size() - 1);

    cout << "Sorted vector: ";
    printVector(vec);

    return 0;
}
