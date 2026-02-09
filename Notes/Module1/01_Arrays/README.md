# Arrays in C++

## 📋 Study Plan

**Time Needed:** 4-5 hours  
**Difficulty:** ⭐⭐ (Medium - Foundation)  
**Prerequisites:** Basic C++ syntax, loops

**Start here if:** You're new to programming or C++!

---

## 🔷 Definition (Memorize This!)

```
┌──────────────────────────────────────────────────────────┐
│ ARRAY = Collection of elements of SAME type             │
│         stored in CONTIGUOUS memory locations            │
│                                                          │
│ Key Features:                                            │
│  • Fixed size (cannot grow/shrink)                       │
│  • Same data type for all elements                       │
│  • Zero-based indexing (starts at 0)                     │
│  • Direct access by index (O(1) time)                    │
└──────────────────────────────────────────────────────────┘
```

## 🎨 Memory Layout [Draw This!]

```
Array: int arr[5] = {10, 20, 30, 40, 50};

Memory:
┌────┬────┬────┬────┬────┐
│ 10 │ 20 │ 30 │ 40 │ 50 │
└────┴────┴────┴────┴────┘
  ↑    ↑    ↑    ↑    ↑
 [0]  [1]  [2]  [3]  [4]  ← Indices
```

---

## 🧠 Memory Allocation: Stack vs Heap

### Stack Memory Allocation (Static Arrays)

**Syntax:**

```cpp
int arr[5] = {1, 2, 3, 4, 5};
```

**Characteristics:**
\*Pros:

- ✅ **Automatic** - memory managed automatically
- ✅ **Fast** - allocation/deallocation is instant
- ✅ **Safer** - no memory leaks, automatic cleanup

\*Cons:

- ❌ **Fixed size** - size must be constant at compile time
- ❌ **Limited space** - stack is small (usually 1-8 MB)
- ❌ **Scope-bound** - destroyed when function exits

### Heap Memory Allocation (Dynamic Arrays)

**Syntax:**

```cpp
// C++ way
int* arr = new int[5];          // Allocate
arr[0] = 10;                    // Use
delete[] arr;                   // Must deallocate!

// C way (also works in C++)
int* arr = (int*)malloc(5 * sizeof(int));
free(arr);
```

**Characteristics:**

- ✅ **Dynamic size** - size can be determined at runtime
- ✅ **Large space** - heap is much larger than stack
- ✅ **Flexible lifetime** - persists until manually deleted
- ❌ **Manual management** - must delete/free memory
- ❌ **Slower** - allocation takes more time
- ❌ **Memory leaks** - forgetting to delete causes leaks

### Stack vs Heap Comparison

```
┌─────────────────┬──────────────────┬──────────────────┐
│    Feature      │      Stack       │       Heap       │
├─────────────────┼──────────────────┼──────────────────┤
│ Size            │ Fixed at compile │ Runtime decision │
│ Speed           │ Very Fast        │ Slower           │
│ Management      │ Automatic        │ Manual           │
│ Memory Size     │ Small (~1-8 MB)  │ Large (GBs)      │
│ Lifetime        │ Function scope   │ Until deleted    │
│ Access          │ arr[i]           │ arr[i]           │
│ Declaration     │ int arr[5];      │ new int[5];      │
│ Cleanup         │ Automatic        │ delete[] arr;    │
│ Fragmentation   │ No               │ Yes (over time)  │
│ Memory Leaks    │ Impossible       │ Possible         │
└─────────────────┴──────────────────┴──────────────────┘
```

### Memory Diagram

```
STACK (Small, Fast, Auto-managed)
┌────────────────────────────────┐
│  Function 1                    │ ← Grows downward
│  int arr[5] = {1,2,3,4,5};     │
│  ┌──┬──┬──┬──┬──┐              │
│  │1 │2 │3 │4 │5 │              │
│  └──┴──┴──┴──┴──┘              │
├────────────────────────────────┤
│  Function 2                    │
│  int x = 10;                   │
└────────────────────────────────┘
         ↓ (Auto cleaned when function exits)

HEAP (Large, Slower, Manual)
┌────────────────────────────────┐
│  int* arr = new int[5];        │ ← Grows upward
│  ┌──┬──┬──┬──┬──┐              │
│  │  │  │  │  │  │              │
│  └──┴──┴──┴──┴──┘              │
│         ↑                      │
│    (Must delete[] manually!)   │
│                                │
│  (Large space available)       │
└────────────────────────────────┘
```

### When to Use Each?

**Use Stack (Static) When:**

- Size is known at compile time
- Array size is small (< 1 MB)
- Need fast allocation/deallocation
- Don't need array outside function scope
- Example: `int scores[254];`

**Use Heap (Dynamic) When:**

- Size determined at runtime (user input)
- Need large arrays (> 1 MB)
- Array should persist across functions
- Building data structures (linked lists, trees)
- Example: `int* arr = new int[userInput];`

### Dynamic Array Example

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    // Allocate on heap - size from user input
    int* arr = new int[n];

    // Use the array
    for(int i = 0; i < n; i++) {
        arr[i] = i * 10;
    }

    // Print
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // MUST deallocate to prevent memory leak!
    delete[] arr;

    return 0;
}
```

### Important: Memory Leak Prevention

```cpp
// ❌ MEMORY LEAK - allocated but never freed
void badFunction() {
    int* arr = new int[1000];
    // Function ends, but memory not freed!
}

// ✅ CORRECT - properly deallocated
void goodFunction() {
    int* arr = new int[1000];
    // ... use array ...
    delete[] arr;  // Free the memory!
}

// ⭐ BEST - Use smart pointers (C++11+)
#include <memory>
void bestFunction() {
    unique_ptr<int[]> arr(new int[1000]);
    // Automatically deleted when scope ends!
}
```

---

## Key Concepts

### 1. Array Basics ([array_basics.cpp](../../Module1/01_Arrays/array_basics.cpp))

**Syntax:**

- Declaration: `int arr[5];`
- Initialization: `int arr[] = {1, 2, 3, 4, 5};`
- Access: `arr[0]`, `arr[1]`, etc.

**Important Points:**

- **Zero-based indexing** - first element at index 0
- **Fixed size** - cannot change after declaration
- **Contiguous memory** - elements stored next to each other
- **Array name** = address of first element
- **Size calculation:** `sizeof(arr) / sizeof(arr[0])`

### 2. Array Searching ([array_searching.cpp](../../Module1/01_Arrays/array_searching.cpp))

| Method        | Time     | Condition        |
| ------------- | -------- | ---------------- |
| Linear Search | O(n)     | Any array        |
| Binary Search | O(log n) | **Sorted** array |

### 3. Sorting ([array_sorting.cpp](../../Module1/01_Arrays/array_sorting.cpp))

| Algorithm      | Time Complexity | Best For           |
| -------------- | --------------- | ------------------ |
| Bubble Sort    | O(n²)           | Small datasets     |
| Selection Sort | O(n²)           | Fewer swaps        |
| Insertion Sort | O(n²)           | Nearly sorted data |
| STL sort()     | O(n log n)      | General use        |

### 4. Collections ([collection_sorting.cpp](../../Module1/01_Arrays/collection_sorting.cpp))

- Use STL `sort(arr, arr + n);` for efficient sorting

### 5. Matrix/2D Arrays ([matrix_operations.cpp](../../Module1/01_Arrays/matrix_operations.cpp))

**Syntax:** `int matrix[3][4];`

**Operations:**

- Traversal, Addition, Multiplication, Transpose
- Stored in row-major order

---

## Common Mistakes

```
┌──────────────────────────────────────────────────────────┐
│ ❌ Array index out of bounds (arr[n] for size n)          │
│ ❌ Forgetting zero-based indexing                         │
│ ❌ Not initializing arrays (garbage values)               │
│ ❌ Returning local stack array from function              │
│ ❌ Forgetting delete[] for heap arrays (memory leak!)     │
│ ❌ Using delete instead of delete[] for arrays            │
│ ❌ Accessing array after delete[] (dangling pointer)      │
│ ❌ Double deletion (deleting same array twice)            │
└──────────────────────────────────────────────────────────┘
```

## 🎯 Key Takeaways

1. Fixed-size collection of same data type
2. Zero-based indexing (0 to n-1)
3. O(1) access time - very fast!
4. Searching: Linear O(n), Binary O(log n)
5. **Stack arrays**: Fast, automatic, fixed size at compile time
6. **Heap arrays**: Flexible size, manual management, use `new`/`delete[]`
7. Array name stores address of first element
8. Always `delete[]` heap arrays to prevent memory leaks!
