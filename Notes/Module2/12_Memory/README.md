# Memory Management in C++

## Overview

Memory management is crucial in C++ as it provides manual control over memory allocation and deallocation, unlike garbage-collected languages.

## Topics Covered

### Files Reference:

- [ArrayPointer.cpp](../../Module2/12_Memory/ArrayPointer.cpp)
- [Delete[].cpp](../../Module2/12_Memory/Delete[].cpp)
- [MemoryLeak.cpp](../../Module2/12_Memory/MemoryLeak.cpp)
- [MemoryLeakinLoop.cpp](../../Module2/12_Memory/MemoryLeakinLoop.cpp)
- [MemoryLeakTest.cpp](../../Module2/12_Memory/MemoryLeakTest.cpp)
- [New[]anddelete[].cpp](../../Module2/12_Memory/New[]anddelete[].cpp)

## Memory Segments

### 1. Stack Memory:

- Automatic allocation/deallocation
- Fast access
- Limited size (typically 1-8 MB)
- LIFO (Last In First Out)
- Stores local variables, function parameters

```cpp
void function() {
    int x = 10;        // Allocated on stack
    char arr[100];     // Allocated on stack
}  // Automatically deallocated
```

### 2. Heap Memory:

- Manual allocation/deallocation
- Slower access than stack
- Large size (limited by system RAM)
- Flexible lifetime
- Allocated using `new` / `delete`

```cpp
int *ptr = new int(10);     // Allocated on heap
delete ptr;                  // Must manually deallocate
```

### 3. Static/Global Memory:

- Exists for entire program lifetime
- Initialized before main()
- Deallocated after main()

```cpp
int globalVar = 100;  // Global memory

void function() {
    static int staticVar = 50;  // Static memory
}
```

### 4. Code/Text Segment:

- Stores compiled program code
- Read-only
- Shared between processes

## Dynamic Memory Allocation

### Single Object Allocation:

#### Using new:

```cpp
int *ptr = new int;         // Uninitialized
int *ptr2 = new int(10);    // Initialized to 10
int *ptr3 = new int();      // Zero-initialized

// Check allocation
if(ptr == nullptr) {
    cerr << "Allocation failed";
}
```

#### Using delete:

```cpp
delete ptr;
ptr = nullptr;  // Good practice
```

### Array Allocation:

#### Using new[]:

```cpp
int *arr = new int[10];           // Uninitialized
int *arr2 = new int[5]{1,2,3,4,5}; // Initialized (C++11)
int *arr3 = new int[10]();         // Zero-initialized
```

#### Using delete[]:

```cpp
delete[] arr;  // MUST use delete[] for arrays
arr = nullptr;
```

**Critical**: Match `new` with `delete` and `new[]` with `delete[]`.

### 2D Arrays:

#### Method 1: Array of Pointers:

```cpp
int rows = 3, cols = 4;
int **arr = new int*[rows];

for(int i = 0; i < rows; i++) {
    arr[i] = new int[cols];
}

// Use: arr[i][j]

// Cleanup
for(int i = 0; i < rows; i++) {
    delete[] arr[i];
}
delete[] arr;
```

#### Method 2: Single Contiguous Block:

```cpp
int rows = 3, cols = 4;
int *arr = new int[rows * cols];

// Access: arr[i * cols + j]

delete[] arr;
```

## Memory Leaks

### Definition:

Memory allocated but never freed, leading to wasted memory that can't be reclaimed.

### Example 1: Basic Leak:

```cpp
void function() {
    int *ptr = new int(10);
    // Forgot delete - memory leaked!
}
```

### Example 2: Leak in Loop:

```cpp
for(int i = 0; i < 1000; i++) {
    int *ptr = new int(i);
    // Memory allocated 1000 times, never freed
}
```

### Example 3: Lost Reference:

```cpp
int *ptr = new int(10);
ptr = new int(20);  // Lost reference to first allocation!
delete ptr;         // Only frees second allocation
```

### Example 4: Exception Safety:

```cpp
void function() {
    int *ptr = new int(10);
    // If exception thrown here, delete never reached
    someFunction();  // May throw
    delete ptr;
}
```

### Detecting Memory Leaks:

#### Tools:

- **Valgrind** (Linux)
- **Dr. Memory** (Windows/Linux)
- **AddressSanitizer** (GCC/Clang)
- **Visual Studio Diagnostic Tools** (Windows)

#### Example with AddressSanitizer:

```bash
g++ -fsanitize=address -g program.cpp -o program
./program
```

## Common Memory Issues

### 1. Dangling Pointer:

Pointer to memory that has been freed.

```cpp
int *ptr = new int(10);
delete ptr;
// ptr now dangling
*ptr = 20;  // Undefined behavior!

// Solution:
delete ptr;
ptr = nullptr;
if(ptr != nullptr) {
    *ptr = 20;
}
```

### 2. Double Delete:

Deleting same memory twice.

```cpp
int *ptr = new int(10);
delete ptr;
delete ptr;  // Undefined behavior!

// Solution:
delete ptr;
ptr = nullptr;
delete ptr;  // Safe - deleting nullptr does nothing
```

### 3. Use After Free:

Using memory after it's been freed.

```cpp
int *ptr = new int(10);
delete ptr;
cout << *ptr;  // Undefined behavior!
```

### 4. Buffer Overflow:

Writing beyond allocated memory.

```cpp
int *arr = new int[10];
arr[15] = 100;  // Out of bounds!
delete[] arr;
```

### 5. Memory Fragmentation:

Allocating and freeing in patterns that leave unusable gaps.

```cpp
// Many allocations of varying sizes
// Leaves fragmented memory
```

### 6. Wild Pointer:

Uninitialized pointer.

```cpp
int *ptr;      // Wild pointer
*ptr = 10;     // Undefined behavior!

// Solution:
int *ptr = nullptr;  // Initialize
```

## Smart Pointers (C++11)

### Benefits:

- Automatic memory management
- Exception safe
- Prevent memory leaks
- No manual delete needed

### 1. unique_ptr:

Exclusive ownership, cannot be copied.

```cpp
#include <memory>

unique_ptr<int> ptr = make_unique<int>(10);
cout << *ptr;  // 10

// Automatically deleted when out of scope
// No need for manual delete

// Move ownership
unique_ptr<int> ptr2 = std::move(ptr);  // ptr becomes nullptr
```

#### Array with unique_ptr:

```cpp
unique_ptr<int[]> arr = make_unique<int[]>(10);
arr[0] = 5;
```

### 2. shared_ptr:

Shared ownership, reference counted.

```cpp
shared_ptr<int> ptr1 = make_shared<int>(10);
{
    shared_ptr<int> ptr2 = ptr1;  // Reference count = 2
    cout << ptr1.use_count();      // 2
}  // ptr2 destroyed, count = 1
// Memory still valid because ptr1 exists

// Memory deleted when last shared_ptr destroyed
```

### 3. weak_ptr:

Non-owning reference to shared_ptr.

```cpp
shared_ptr<int> sptr = make_shared<int>(10);
weak_ptr<int> wptr = sptr;  // Doesn't increase ref count

if(auto ptr = wptr.lock()) {  // Get shared_ptr if still valid
    cout << *ptr;
}
```

**Use Case**: Breaking circular dependencies.

```cpp
class Node {
public:
    shared_ptr<Node> next;  // Strong reference
    weak_ptr<Node> prev;    // Weak reference (breaks cycle)
};
```

## RAII (Resource Acquisition Is Initialization)

### Principle:

Resource lifetime tied to object lifetime.

```cpp
class FileHandler {
    FILE *file;
public:
    FileHandler(const char *filename) {
        file = fopen(filename, "r");
    }

    ~FileHandler() {
        if(file) fclose(file);  // Automatic cleanup
    }
};

{
    FileHandler fh("data.txt");
    // Use file
}  // Automatic cleanup when fh destroyed
```

### Benefits:

- Exception safe
- No resource leaks
- Clear ownership
- Automatic cleanup

## Memory Allocation Functions

### C Style (Not Recommended in C++):

#### malloc:

```c
int *ptr = (int*)malloc(sizeof(int) * 10);
if(ptr == NULL) {
    // Allocation failed
}
free(ptr);
```

#### calloc (Zero-initialized):

```c
int *ptr = (int*)calloc(10, sizeof(int));
free(ptr);
```

#### realloc (Resize):

```c
int *ptr = (int*)malloc(sizeof(int) * 10);
ptr = (int*)realloc(ptr, sizeof(int) * 20);
free(ptr);
```

### C++ Style (Recommended):

```cpp
int *ptr = new int[10];
delete[] ptr;

// Better: Use smart pointers or STL containers
vector<int> v(10);  // Automatic memory management
```

## Performance Considerations

### 1. Allocation Cost:

- Stack allocation: Very fast
- Heap allocation: Slower (requires system call)
- Pool allocation: Fast (pre-allocated)

### 2. Cache Locality:

```cpp
// Better cache performance
int arr[1000];  // Contiguous memory

// Worse cache performance
int *arr[1000];
for(int i = 0; i < 1000; i++)
    arr[i] = new int;  // Scattered memory
```

### 3. Memory Pools:

Pre-allocate large block, manage manually.

```cpp
class MemoryPool {
    char *pool;
    size_t used;
public:
    MemoryPool(size_t size) {
        pool = new char[size];
        used = 0;
    }

    void* allocate(size_t size) {
        void *ptr = pool + used;
        used += size;
        return ptr;
    }

    ~MemoryPool() {
        delete[] pool;
    }
};
```

## Best Practices

1. **Initialize Pointers**:

```cpp
int *ptr = nullptr;  // Not: int *ptr;
```

2. **Set to nullptr After Delete**:

```cpp
delete ptr;
ptr = nullptr;
```

3. **Match new/delete**:

```cpp
int *p = new int;     delete p;
int *arr = new int[]; delete[] arr;
```

4. **Use Smart Pointers**:

```cpp
unique_ptr<int> ptr = make_unique<int>(10);  // Preferred
```

5. **Prefer STL Containers**:

```cpp
vector<int> v;  // Instead of new int[]
```

6. **Check Allocation Success**:

```cpp
int *ptr = new(nothrow) int[huge_size];
if(ptr == nullptr) {
    // Handle failure
}
```

7. **RAII**:
   Wrap resources in classes with automatic cleanup.

## Common Pitfalls

1. **Mixing new/malloc with delete/free**:

```cpp
int *ptr = (int*)malloc(sizeof(int));
delete ptr;  // Wrong! Use free()
```

2. **Forgetting delete[]**:

```cpp
int *arr = new int[10];
delete arr;  // Wrong! Should be delete[]
```

3. **Returning Stack Address**:

```cpp
int* func() {
    int x = 10;
    return &x;  // Wrong! x destroyed after return
}
```

4. **Shallow Copy**:

```cpp
class Array {
    int *data;
public:
    // Need custom copy constructor for deep copy
};
```

5. **Exception Between new and delete**:

```cpp
int *ptr = new int;
riskyFunction();  // May throw
delete ptr;        // May not reach here
```

## Tools and Techniques

### Debugging:

- **Valgrind**: `valgrind --leak-check=full ./program`
- **AddressSanitizer**: `-fsanitize=address`
- **Visual Studio**: Memory diagnostic tools

### Code Review:

- Check every `new` has corresponding `delete`
- Look for pointers that might lose references
- Verify exception safety

### Static Analysis:

- Clang-Tidy
- Cppcheck
- PVS-Studio

## Related Concepts

- Smart pointers
- Move semantics
- Copy elision
- Placement new
- Custom allocators
- Garbage collection concepts
