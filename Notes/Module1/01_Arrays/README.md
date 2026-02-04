# Arrays in C++

## Overview

Arrays are collections of elements of the same data type stored in contiguous memory locations.

## Topics Covered

### 1. Array Basics

**File Reference**: [array_basics.cpp](../../Module1/01_Arrays/array_basics.cpp)

#### Key Concepts:

- **Declaration**: `int arr[5];` - Creates array of 5 integers
- **Initialization**: `int arr[] = {1, 2, 3, 4, 5};`
- **Access**: `arr[0]` - Zero-based indexing
- **Size**: Arrays have fixed size determined at compile time

#### Important Points:

- Array elements are stored in contiguous memory
- Index starts from 0 and goes to (size-1)
- Accessing out-of-bounds index causes undefined behavior
- Array name represents the address of first element

### 2. Array Searching

**File Reference**: [array_searching.cpp](../../Module1/01_Arrays/array_searching.cpp)

#### Linear Search:

- Time Complexity: O(n)
- Checks each element sequentially
- Works on unsorted arrays

```cpp
for(int i = 0; i < n; i++) {
    if(arr[i] == target) return i;
}
```

#### Binary Search:

- Time Complexity: O(log n)
- Requires sorted array
- Divides search space in half each iteration

```cpp
while(low <= high) {
    mid = (low + high) / 2;
    if(arr[mid] == target) return mid;
    else if(arr[mid] < target) low = mid + 1;
    else high = mid - 1;
}
```

### 3. Array Sorting

**File Reference**: [array_sorting.cpp](../../Module1/01_Arrays/array_sorting.cpp)

#### Bubble Sort:

- Time Complexity: O(n²)
- Compares adjacent elements
- Simplest sorting algorithm
- Good for small datasets or nearly sorted arrays

#### Selection Sort:

- Time Complexity: O(n²)
- Finds minimum element and places it at beginning
- Performs fewer swaps than bubble sort

#### Insertion Sort:

- Time Complexity: O(n²) worst case, O(n) best case
- Efficient for small or nearly sorted arrays
- Builds sorted array one element at a time

### 4. Collection Sorting

**File Reference**: [collection_sorting.cpp](../../Module1/01_Arrays/collection_sorting.cpp)

#### Using STL sort():

```cpp
#include <algorithm>
sort(arr, arr + n); // Ascending order
sort(arr, arr + n, greater<int>()); // Descending order
```

- Time Complexity: O(n log n)
- Uses Introsort (hybrid of quicksort, heapsort, insertion sort)
- Much more efficient than manual implementations

### 5. Matrix Operations

**File Reference**: [matrix_operations.cpp](../../Module1/01_Arrays/matrix_operations.cpp)

#### 2D Array Declaration:

```cpp
int matrix[3][4]; // 3 rows, 4 columns
int matrix[][3] = {{1,2,3}, {4,5,6}}; // Auto size first dimension
```

#### Common Operations:

- **Traversal**: Nested loops to access each element
- **Addition**: Add corresponding elements
- **Multiplication**: Row × Column multiplication
- **Transpose**: Swap rows and columns

#### Memory Layout:

- 2D arrays stored in row-major order in memory
- `matrix[i][j]` = `*(*(matrix + i) + j)`

## Best Practices

1. **Array Bounds**: Always check array bounds to prevent overflow
2. **Size Parameter**: Pass array size as parameter to functions
3. **Initialization**: Initialize arrays to avoid garbage values
4. **STL Containers**: Consider `std::vector` for dynamic sizing
5. **Const**: Use `const` for arrays that shouldn't be modified

## Common Pitfalls

1. **Buffer Overflow**: Accessing beyond array bounds
2. **Uninitialized Arrays**: Using garbage values
3. **Size Decay**: Array size information lost when passed to functions
4. **No Bounds Checking**: C++ doesn't check array bounds at runtime
5. **Fixed Size**: Cannot resize arrays after declaration

## Related Concepts

- Pointers (arrays are closely related to pointers)
- Dynamic memory allocation (`new[]`, `delete[]`)
- STL vectors (dynamic arrays)
- Memory management
