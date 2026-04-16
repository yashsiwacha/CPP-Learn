# Memory Management in C++

## � Study Plan

**Time Needed:** 6-8 hours  
**Difficulty:** ⭐⭐⭐⭐ (Hard)  
**Prerequisites:** Pointers, dynamic allocation

**⚠️ CRITICAL:** This is one of the hardest C++ topics. Be patient and practice extensively!

---

## 🔷 Definition (Memorize This!)

```
┌──────────────────────────────────────────────────────────┐
│ MEMORY MANAGEMENT = Control over allocation &            │
│                     deallocation of memory               │
│                                                          │
│ Two Regions:                                             │
│  • STACK   - Automatic, fast, limited (local variables) │
│  • HEAP    - Manual, slower, large (dynamic allocation)  │
│                                                          │
│ Key Operators:                                           │
│  • new     - Allocate memory on heap                     │
│  • delete  - Free single object                          │
│  • delete[] - Free array                                 │
└──────────────────────────────────────────────────────────┘
```

## 🎨 Memory Layout [Draw This!]

```
High Address
┌──────────────┐
│    Stack     │  ← Local variables, function calls
│      ↓       │     (Automatic, fast, limited)
│              │
│      ↑       │
│    Heap      │  ← new/delete allocations
└──────────────┘     (Manual, flexible, large)
│ Global/Static│  ← Global variables
│    Code      │  ← Program instructions
└──────────────┘
Low Address
```

---

## Key Concepts

### 1. Stack vs Heap Memory

| Aspect       | Stack            | Heap                      |
| ------------ | ---------------- | ------------------------- |
| Allocation   | Automatic        | Manual (`new`)            |
| Deallocation | Automatic        | Manual (`delete`)         |
| Speed        | Very fast        | Slower                    |
| Size         | Limited (1-8 MB) | Large (system RAM)        |
| Lifetime     | Function scope   | Until deleted             |
| Example      | `int x = 10;`    | `int *ptr = new int(10);` |

### 2. Dynamic Memory Allocation

**Single object:**

- Allocate: `int *ptr = new int(10);`
- Free: `delete ptr;`
- Always set to nullptr: `ptr = nullptr;`

**Arrays:**

- Allocate: `int *arr = new int[10];`
- Free: `delete[] arr;` (MUST use delete[], not delete!)

**Critical:** Match `new` with `delete`, and `new[]` with `delete[]`

### 3. Memory Leaks ([MemoryLeak.cpp](../../Module2/12_Memory/MemoryLeak.cpp), [MemoryLeakinLoop.cpp](../../Module2/12_Memory/MemoryLeakinLoop.cpp))

**Definition:** Memory allocated but never freed

**Common causes:**

- Forgetting to delete
- Losing pointer reference
- Exception thrown before delete
- Loop allocations without deallocation

**Example:**

```cpp
int *ptr = new int(10);
// Forgot delete - MEMORY LEAK!
```

### 4. Common Memory Issues

| Issue            | Description                 | Solution                    |
| ---------------- | --------------------------- | --------------------------- |
| Dangling Pointer | Points to freed memory      | Set to nullptr after delete |
| Memory Leak      | Allocated but never freed   | Always delete what you new  |
| Double Delete    | Deleting same pointer twice | Set to nullptr after delete |
| Wild Pointer     | Uninitialized pointer       | Initialize to nullptr       |
| Use After Free   | Using freed memory          | Don't access after delete   |

### 5. Arrays and Pointers ([ArrayPointer.cpp](../../Module2/12_Memory/ArrayPointer.cpp), [New[]anddelete[].cpp](../../Module2/12_Memory/New[]anddelete[].cpp))

**Dynamic arrays:**

- Syntax: `int *arr = new int[size];`
- Cleanup: `delete[] arr;` (notice the [])
- **CRITICAL:** Using `delete arr;` instead of `delete[] arr;` is undefined behavior!

**Example:** [Delete[].cpp](../../Module2/12_Memory/Delete[].cpp)

### 6. 2D Dynamic Arrays

**Method 1 - Array of pointers:**

```cpp
int **arr = new int*[rows];
for(int i = 0; i < rows; i++)
    arr[i] = new int[cols];

// Cleanup: delete each row, then main array
for(int i = 0; i < rows; i++)
    delete[] arr[i];
delete[] arr;
```

**Method 2 - Single block:** `int *arr = new int[rows * cols];`

### 7. Smart Pointers (C++11)

**Purpose:** Automatic memory management - no manual delete needed!

| Type         | Ownership          | Copy | Use When                  |
| ------------ | ------------------ | ---- | ------------------------- |
| `unique_ptr` | Exclusive          | No   | Single owner              |
| `shared_ptr` | Shared (ref count) | Yes  | Multiple owners           |
| `weak_ptr`   | Non-owning         | Yes  | Break circular references |

**Syntax:**

- `unique_ptr<int> ptr = make_unique<int>(10);`
- `shared_ptr<int> ptr = make_shared<int>(10);`
- Automatically deleted when out of scope!

### 8. RAII Pattern

**Resource Acquisition Is Initialization**

**Concept:** Tie resource lifetime to object lifetime

**Benefits:**

- Automatic cleanup
- Exception safe
- No memory leaks

**Example:**

```cpp
{
    unique_ptr<int> ptr = make_unique<int>(10);
    // Use ptr
} // Automatically deleted here!
```

---

## Common Mistakes

```
┌──────────────────────────────────────────────────────────┐
│ ❌ Using delete instead of delete[] for arrays            │
│ ❌ Forgetting to delete allocated memory (leak)           │
│ ❌ Double delete (deleting same pointer twice)            │
│ ❌ Using pointer after delete (dangling pointer)          │
│ ❌ Not initializing pointers to nullptr (wild pointer)    │
│ ❌ Losing pointer reference before freeing                │
└──────────────────────────────────────────────────────────┘
```

---

## Memory Leak Detection

**Tools:**

- **AddressSanitizer:** `g++ -fsanitize=address -g program.cpp`
- **Valgrind (Linux):** `valgrind --leak-check=full ./program`
- **Visual Studio:** Built-in memory diagnostics

**See:** [MemoryLeakTest.cpp](../../Module2/12_Memory/MemoryLeakTest.cpp)

---

## Best Practices

| Practice                    | Example                                |
| --------------------------- | -------------------------------------- |
| Initialize pointers         | `int *ptr = nullptr;`                  |
| Set to nullptr after delete | `delete ptr; ptr = nullptr;`           |
| Match new/delete correctly  | `new` ↔ `delete`, `new[]` ↔ `delete[]` |
| Prefer smart pointers       | `unique_ptr<int> ptr = ...`            |
| Prefer STL containers       | `vector<int>` instead of `new int[]`   |
| Check allocation success    | `if(ptr != nullptr)`                   |

---

## Modern C++ Recommendations

**❌ Avoid:**

```cpp
int *arr = new int[100];
// ... use arr ...
delete[] arr;
```

**✅ Prefer:**

```cpp
vector<int> arr(100);
// Automatic cleanup!
```

**❌ Avoid:**

```cpp
int *ptr = new int(10);
// ... use ptr ...
delete ptr;
```

**✅ Prefer:**

```cpp
unique_ptr<int> ptr = make_unique<int>(10);
// Automatic cleanup!
```

---

## 🎯 Key Takeaways

1. **Stack** is fast but limited; **heap** is flexible but needs manual management
2. **Always** match `new` with `delete`, and `new[]` with `delete[]`
3. **Memory leak** = allocated but never freed (use tools to detect)
4. Set pointers to **nullptr** after delete to avoid dangling pointers
5. **Smart pointers** automate memory management (use them in modern C++!)
6. **Prefer** STL containers (`vector`, `string`) over manual allocation
   └─ YES → Size known at compile time?
   │
   ├─ YES → Array size fixed?
   │ │
   │ ├─ Small (<1KB) → Stack array: int arr[100];
   │ └─ Large → STL vector or heap array
   │
   └─ NO → Use heap allocation
   │
   ├─ Simple data?
   │ └─ Use STL containers (vector, string)
   │
   └─ Complex management?
   ├─ Exclusive ownership → unique_ptr
   ├─ Shared ownership → shared_ptr
   └─ Manual control → raw pointers (careful!)

````

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
````

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

## Summary

### Key Takeaways:

1. **Stack vs Heap** - Stack is fast but limited, heap is flexible but requires manual management
2. **new/delete** - Must match new with delete, new[] with delete[]
3. **Memory Leaks** - Occur when allocated memory is never freed
4. **Smart Pointers** - Modern C++ solution for automatic memory management
5. **RAII** - Tie resource lifetime to object lifetime for safety
6. **Common Issues** - Dangling pointers, double delete, use after free, buffer overflow
7. **Tools** - Use Valgrind, AddressSanitizer for leak detection
8. **Best Practice** - Prefer smart pointers and STL containers over raw pointers
9. **Initialize** - Always initialize pointers to nullptr
10. **Exception Safety** - Use RAII for automatic cleanup on exceptions

### Memory Management Hierarchy:

```
Best Practices:
1. STL Containers (vector, string) - Best
2. Smart Pointers (unique_ptr, shared_ptr) - Good
3. RAII Wrappers - Good
4. Raw new/delete - Use with caution
5. malloc/free - Avoid in C++
```

## Quick Reference

### Memory Allocation:

```cpp
// Stack
int x = 10;
int arr[100];

// Heap - Single object
int* ptr = new int(10);
delete ptr;

// Heap - Array
int* arr = new int[10];
delete[] arr;

// Smart pointers
auto ptr = make_unique<int>(10);
auto arr = make_unique<int[]>(10);
auto shared = make_shared<int>(10);
```

### Common Patterns:

```cpp
// RAII
class Resource {
    int* data;
public:
    Resource() { data = new int[100]; }
    ~Resource() { delete[] data; }
};

// Check allocation
int* ptr = new(nothrow) int[size];
if(ptr == nullptr) { /* handle */ }

// Safe deletion
delete ptr;
ptr = nullptr;
```

### Memory Leak Detection:

```bash
# Valgrind (Linux)
valgrind --leak-check=full ./program

# AddressSanitizer (GCC/Clang)
g++ -fsanitize=address -g program.cpp
```

## Related Concepts

- Smart pointers (unique_ptr, shared_ptr, weak_ptr)
- Move semantics and rvalue references
- Copy elision and RVO
- Placement new
- Custom allocators
- Memory pools
- Garbage collection concepts
- RAII and scope guards
