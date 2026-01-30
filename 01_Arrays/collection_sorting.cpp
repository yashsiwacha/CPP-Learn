/*
 * Merge Sort Algorithm Implementation in C++
 * 
 * Merge Sort is a Divide and Conquer algorithm that:
 * - Divides array into two halves
 * - Recursively sorts both halves
 * - Merges the sorted halves
 * 
 * Time Complexity: O(n log n) in all cases
 * Space Complexity: O(n) for temporary array
 * Stable Sort: Yes (maintains relative order of equal elements)
 */

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Global variable to track merge operations for visualization
int mergeCount = 0;

// ============================================================================
// Function to merge two sorted subarrays
// ============================================================================
// arr[left...mid] and arr[mid+1...right] are two sorted subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // Size of left subarray
    int n2 = right - mid;      // Size of right subarray
    
    // Create temporary arrays
    int* leftArr = new int[n1];
    int* rightArr = new int[n2];
    
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    
    // Merge the temporary arrays back into arr[left...right]
    int i = 0;      // Initial index of left subarray
    int j = 0;      // Initial index of right subarray
    int k = left;   // Initial index of merged subarray
    
    cout << "  Merge #" << ++mergeCount << ": Merging [";
    for (int x = 0; x < n1; x++) {
        cout << leftArr[x];
        if (x < n1 - 1) cout << ", ";
    }
    cout << "] with [";
    for (int x = 0; x < n2; x++) {
        cout << rightArr[x];
        if (x < n2 - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    // Merge the arrays by comparing elements
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    // Copy remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    
    // Print result of merge
    cout << "  Result: [";
    for (int x = left; x <= right; x++) {
        cout << arr[x];
        if (x < right) cout << ", ";
    }
    cout << "]" << endl << endl;
    
    // Free memory
    delete[] leftArr;
    delete[] rightArr;
}

// ============================================================================
// Recursive Merge Sort function
// ============================================================================
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;
        
        cout << "Dividing: indices [" << left << " to " << right << "]" << endl;
        
        // Recursively sort first half
        mergeSort(arr, left, mid);
        
        // Recursively sort second half
        mergeSort(arr, mid + 1, right);
        
        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// ============================================================================
// Vector version of merge function
// ============================================================================
void mergeVector(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<int> leftArr(n1);
    vector<int> rightArr(n2);
    
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }
    
    while (i < n1) arr[k++] = leftArr[i++];
    while (j < n2) arr[k++] = rightArr[j++];
}

// ============================================================================
// Vector version of merge sort
// ============================================================================
void mergeSortVector(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortVector(arr, left, mid);
        mergeSortVector(arr, mid + 1, right);
        mergeVector(arr, left, mid, right);
    }
}

// ============================================================================
// Utility function to print array
// ============================================================================
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << endl;
}

// ============================================================================
// Utility function to print vector
// ============================================================================
void printVector(const vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << endl;
}

// ============================================================================
// Demo 1: Basic Merge Sort with Visualization
// ============================================================================
void demo1_BasicMergeSort() {
    cout << "\n=== Demo 1: Basic Merge Sort with Visualization ===" << endl;
    
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "\nOriginal array: ";
    printArray(arr, n);
    
    cout << "\n--- Merge Sort Process ---\n" << endl;
    mergeCount = 0;
    mergeSort(arr, 0, n - 1);
    
    cout << "Sorted array: ";
    printArray(arr, n);
}

// ============================================================================
// Demo 2: Merge Sort on Vector
// ============================================================================
void demo2_VectorMergeSort() {
    cout << "\n=== Demo 2: Merge Sort on Vector ===" << endl;
    
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50};
    
    cout << "\nOriginal vector: ";
    printVector(arr);
    
    mergeSortVector(arr, 0, arr.size() - 1);
    
    cout << "Sorted vector: ";
    printVector(arr);
}

// ============================================================================
// Demo 3: Merge Sort on Sorted Array (Best Case)
// ============================================================================
void demo3_AlreadySorted() {
    cout << "\n=== Demo 3: Merge Sort on Already Sorted Array ===" << endl;
    
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "\nOriginal (already sorted): ";
    printArray(arr, n);
    
    mergeCount = 0;
    mergeSort(arr, 0, n - 1);
    
    cout << "After merge sort: ";
    printArray(arr, n);
    cout << "Total merge operations: " << mergeCount << endl;
}

// ============================================================================
// Demo 4: Merge Sort on Reverse Sorted Array (Worst Case)
// ============================================================================
void demo4_ReverseSorted() {
    cout << "\n=== Demo 4: Merge Sort on Reverse Sorted Array ===" << endl;
    
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "\nOriginal (reverse sorted): ";
    printArray(arr, n);
    
    mergeCount = 0;
    mergeSort(arr, 0, n - 1);
    
    cout << "After merge sort: ";
    printArray(arr, n);
    cout << "Total merge operations: " << mergeCount << endl;
}

// ============================================================================
// Demo 5: Merge Sort with Duplicates
// ============================================================================
void demo5_WithDuplicates() {
    cout << "\n=== Demo 5: Merge Sort with Duplicate Elements ===" << endl;
    
    int arr[] = {5, 2, 8, 2, 9, 1, 5, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "\nOriginal array: ";
    printArray(arr, n);
    
    mergeSort(arr, 0, n - 1);
    
    cout << "Sorted array (stable - duplicates maintain order): ";
    printArray(arr, n);
}

// ============================================================================
// Demo 6: Large Array Performance
// ============================================================================
void demo6_LargeArray() {
    cout << "\n=== Demo 6: Merge Sort on Large Array ===" << endl;
    
    const int SIZE = 20;
    int arr[SIZE] = {87, 34, 92, 11, 45, 78, 23, 56, 89, 12,
                     67, 43, 90, 21, 54, 76, 32, 65, 98, 10};
    
    cout << "\nOriginal array (" << SIZE << " elements): ";
    printArray(arr, SIZE);
    
    mergeSort(arr, 0, SIZE - 1);
    
    cout << "Sorted array: ";
    printArray(arr, SIZE);
}

// ============================================================================
// Main Function
// ============================================================================
int main() {
    cout << "========================================================" << endl;
    cout << "     Merge Sort Algorithm - Complete Implementation    " << endl;
    cout << "========================================================" << endl;
    
    demo1_BasicMergeSort();
    cout << "\n" << string(60, '-') << endl;
    
    demo2_VectorMergeSort();
    cout << "\n" << string(60, '-') << endl;
    
    demo3_AlreadySorted();
    cout << "\n" << string(60, '-') << endl;
    
    demo4_ReverseSorted();
    cout << "\n" << string(60, '-') << endl;
    
    demo5_WithDuplicates();
    cout << "\n" << string(60, '-') << endl;
    
    demo6_LargeArray();
    
    cout << "\n========================================================" << endl;
    cout << "                 Program Complete                       " << endl;
    cout << "========================================================" << endl;
    
    cout << "\n=== Merge Sort Characteristics ===" << endl;
    cout << "Time Complexity:" << endl;
    cout << "  - Best Case:    O(n log n)" << endl;
    cout << "  - Average Case: O(n log n)" << endl;
    cout << "  - Worst Case:   O(n log n)" << endl;
    cout << "\nSpace Complexity: O(n) - requires temporary arrays" << endl;
    cout << "\nStability: YES - maintains relative order of equal elements" << endl;
    cout << "\nAdvantages:" << endl;
    cout << "  1. Consistent O(n log n) performance" << endl;
    cout << "  2. Stable sorting algorithm" << endl;
    cout << "  3. Good for linked lists" << endl;
    cout << "  4. Predictable performance" << endl;
    cout << "\nDisadvantages:" << endl;
    cout << "  1. Requires additional O(n) space" << endl;
    cout << "  2. Slower than QuickSort on small arrays" << endl;
    cout << "  3. Not in-place sorting" << endl;
    
    return 0;
}

/*
 * HOW MERGE SORT WORKS:
 * 
 * 1. DIVIDE: Split array into two halves
 * 2. CONQUER: Recursively sort both halves
 * 3. COMBINE: Merge the sorted halves
 * 
 * Example: [38, 27, 43, 3]
 * 
 * Step 1: Divide
 *   [38, 27, 43, 3]
 *   [38, 27] [43, 3]
 *   [38] [27] [43] [3]
 * 
 * Step 2: Merge back up
 *   [27, 38] [3, 43]
 *   [3, 27, 38, 43]
 * 
 * COMPILATION & EXECUTION:
 * clang++ collection_sorting.cpp -o mergesort.exe
 * ./mergesort.exe
 */
