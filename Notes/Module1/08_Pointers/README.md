# Pointers in C/C++

## Overview

Pointers are variables that store memory addresses of other variables. They are one of the most powerful and complex features in C/C++.

## Topics Covered

### Files Reference:

- [PointerBasics.c](../../Module1/08_Pointers/PointerBasics.c)
- [2DArray.cpp](../../Module1/08_Pointers/2DArray.cpp)
- [DanglingPointer.cpp](../../Module1/08_Pointers/DanglingPointer.cpp)
- [DynamicCalc.c](../../Module1/08_Pointers/DynamicCalc.c)
- [DynamicScorecard.c](../../Module1/08_Pointers/DynamicScorecard.c)
- [DynamicString.c](../../Module1/08_Pointers/DynamicString.c)
- [EmployeeRecordEditor.c](../../Module1/08_Pointers/EmployeeRecordEditor.c)
- [PhoneDirectory.c](../../Module1/08_Pointers/PhoneDirectory.c)
- [SimpleConfigCalc.c](../../Module1/08_Pointers/SimpleConfigCalc.c)

## Pointer Basics

### Declaration and Initialization:

```cpp
int x = 10;
int *ptr;        // Declaration
ptr = &x;        // Assignment
int *ptr2 = &x;  // Declaration + Initialization
```

### Operators:

- `&` (Address-of): Gets memory address
- `*` (Dereference): Gets value at address

### Example:

```cpp
int x = 10;
int *ptr = &x;

cout << x;     // 10 (value of x)
cout << &x;    // 0x7fff... (address of x)
cout << ptr;   // 0x7fff... (address stored in ptr)
cout << *ptr;  // 10 (value at address ptr points to)
```

## Pointer Types

### 1. Null Pointer:

```cpp
int *ptr = nullptr;  // C++11
int *ptr = NULL;     // C/C++
int *ptr = 0;        // C/C++

if(ptr == nullptr) {
    // Handle null pointer
}
```

### 2. Void Pointer:

```cpp
void *ptr;           // Generic pointer
int x = 10;
ptr = &x;
int *iptr = (int*)ptr;  // Type casting needed
```

### 3. Wild Pointer:

```cpp
int *ptr;           // Uninitialized (dangerous!)
*ptr = 10;          // Undefined behavior!
```

### 4. Dangling Pointer:

```cpp
int *ptr = new int(10);
delete ptr;
// ptr is now dangling (points to freed memory)
ptr = nullptr;  // Good practice
```

## Pointer Arithmetic

### Operations:

```cpp
int arr[] = {10, 20, 30, 40};
int *ptr = arr;

ptr++;      // Move to next element
ptr--;      // Move to previous element
ptr += 2;   // Move forward by 2 elements
ptr -= 1;   // Move backward by 1 element

int diff = ptr2 - ptr1;  // Number of elements between
```

### Size Depends on Type:

```cpp
int *iptr;
iptr++;     // Increments by 4 bytes (size of int)

char *cptr;
cptr++;     // Increments by 1 byte (size of char)

double *dptr;
dptr++;     // Increments by 8 bytes (size of double)
```

## Pointers and Arrays

### Array Name as Pointer:

```cpp
int arr[5] = {1, 2, 3, 4, 5};
int *ptr = arr;  // arr is address of first element

arr[i] == *(arr + i)  // Equivalent
ptr[i] == *(ptr + i)  // Equivalent
```

### Differences:

```cpp
sizeof(arr)  // Size of entire array
sizeof(ptr)  // Size of pointer (4 or 8 bytes)

arr++;       // Error! Can't modify array name
ptr++;       // OK! Pointer can be modified
```

## 2D Arrays and Pointers

### Method 1: Array of Pointers:

```cpp
int rows = 3, cols = 4;
int **arr = new int*[rows];
for(int i = 0; i < rows; i++) {
    arr[i] = new int[cols];
}

// Access: arr[i][j]

// Cleanup
for(int i = 0; i < rows; i++) {
    delete[] arr[i];
}
delete[] arr;
```

### Method 2: Single Block:

```cpp
int rows = 3, cols = 4;
int *arr = new int[rows * cols];

// Access: arr[i * cols + j]

delete[] arr;
```

## Dynamic Memory Allocation

### C Style (malloc/free):

```c
int *ptr = (int*)malloc(sizeof(int) * 10);
if(ptr == NULL) {
    // Allocation failed
}
free(ptr);
ptr = NULL;
```

### C++ Style (new/delete):

```cpp
// Single variable
int *ptr = new int;
int *ptr2 = new int(10);  // Initialize to 10
delete ptr;
delete ptr2;

// Array
int *arr = new int[10];
delete[] arr;  // Must use delete[]

// Check allocation
try {
    int *ptr = new int[1000000000];
} catch(bad_alloc &e) {
    cout << "Allocation failed: " << e.what();
}
```

## Pointers and Functions

### Pass by Pointer:

```cpp
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int x = 5, y = 10;
swap(&x, &y);  // Pass addresses
```

### Return Pointer:

```cpp
int* createArray(int size) {
    int *arr = new int[size];
    return arr;
}

int *arr = createArray(10);
delete[] arr;
```

### Pointer to Function:

```cpp
int add(int a, int b) { return a + b; }

int (*funcPtr)(int, int) = add;
int result = funcPtr(5, 3);  // Calls add(5, 3)
```

## Common Pointer Problems

### 1. Dangling Pointer:

```cpp
int *ptr = new int(10);
delete ptr;
// ptr still holds address of deleted memory
*ptr = 20;  // Undefined behavior!

// Solution:
delete ptr;
ptr = nullptr;
```

### 2. Memory Leak:

```cpp
int *ptr = new int(10);
ptr = new int(20);  // Lost reference to first allocation!

// Solution: Delete before reassigning
delete ptr;
ptr = new int(20);
```

### 3. Double Delete:

```cpp
int *ptr = new int(10);
delete ptr;
delete ptr;  // Error! Double delete

// Solution: Set to nullptr after delete
delete ptr;
ptr = nullptr;
delete ptr;  // Safe (deleting nullptr does nothing)
```

### 4. Using Freed Memory:

```cpp
int *ptr = new int(10);
delete ptr;
cout << *ptr;  // Undefined behavior!
```

## Smart Pointers (C++11)

### unique_ptr:

```cpp
#include <memory>

unique_ptr<int> ptr = make_unique<int>(10);
// Automatically deleted when out of scope
// Cannot be copied, only moved
```

### shared_ptr:

```cpp
shared_ptr<int> ptr1 = make_shared<int>(10);
shared_ptr<int> ptr2 = ptr1;  // Reference count = 2
// Deleted when last shared_ptr is destroyed
```

### weak_ptr:

```cpp
shared_ptr<int> sptr = make_shared<int>(10);
weak_ptr<int> wptr = sptr;  // Doesn't increase ref count
// Breaks circular dependencies
```

## Pointer Best Practices

1. **Initialize**: Always initialize pointers

```cpp
int *ptr = nullptr;  // Good
int *ptr;            // Bad (wild pointer)
```

2. **Check for NULL**:

```cpp
if(ptr != nullptr) {
    *ptr = 10;
}
```

3. **Set to nullptr After Delete**:

```cpp
delete ptr;
ptr = nullptr;
```

4. **Use Smart Pointers**: Prefer smart pointers in C++

```cpp
unique_ptr<int> ptr = make_unique<int>(10);
```

5. **Const Correctness**:

```cpp
const int *ptr;        // Can't modify data
int *const ptr;        // Can't modify pointer
const int *const ptr;  // Can't modify either
```

## Common Pitfalls

1. **Dereferencing NULL**:

```cpp
int *ptr = nullptr;
*ptr = 10;  // Crash!
```

2. **Returning Local Variable Address**:

```cpp
int* func() {
    int x = 10;
    return &x;  // Wrong! x is destroyed after function
}
```

3. **Array vs Pointer Confusion**:

```cpp
void func(int arr[]) {  // Actually int *arr
    sizeof(arr);  // Size of pointer, not array!
}
```

4. **Mismatched new/delete**:

```cpp
int *arr = new int[10];
delete arr;    // Wrong! Should be delete[]

int *ptr = new int;
delete[] ptr;  // Wrong! Should be delete
```

5. **Pointer Arithmetic on Wrong Type**:

```cpp
void *ptr = malloc(10);
ptr++;  // Error! Can't do arithmetic on void*
```

## Memory Visualization

```
Memory Address:  0x1000    0x1004    0x1008
                   |          |          |
Variable:         [x=10]    [y=20]    [z=30]
                   ↑
                   |
Pointer ptr:    [0x1000]

*ptr = 10  (value at address ptr points to)
ptr = 0x1000  (address stored in ptr)
&ptr = 0x2000  (address of ptr itself)
```

## Related Concepts

- References (C++)
- Dynamic memory allocation
- Memory management
- Data structures (linked lists, trees)
- Function pointers
- Smart pointers
