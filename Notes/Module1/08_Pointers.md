# Pointers in C/C++

## 📋 Study Plan

**Time Needed:** 6-7 hours  
**Difficulty:** ⭐⭐⭐⭐ (Hard - Master this!)  
**Prerequisites:** Variables, arrays, functions, memory basics

**⚠️ CRITICAL:** This is one of the hardest topics. Take your time!

---

## 🔷 Definition (Memorize This!)

```
┌──────────────────────────────────────────────────────────┐
│ POINTER = Variable that stores MEMORY ADDRESS            │
│           of another variable                            │
│                                                          │
│ Key Points:                                              │
│  • Pointer stores address, not value                     │
│  • Every variable has an address in memory               │
│  • Pointers enable dynamic memory allocation             │
│  • Most powerful feature in C/C++                        │
└──────────────────────────────────────────────────────────┘
```

## 🎨 Memory Concept [Draw This!]

```
Variable in Memory:
┌─────────────────┬─────────────┐
│  Address: 1000  │  Value: 42  │  ← int x = 42;
└─────────────────┴─────────────┘
        ↑
        │
┌───────┴────────┬─────────────┐
│ Address: 2000  │ Value: 1000 │  ← int *ptr = &x;
└────────────────┴─────────────┘
                      (stores address of x)
```

---

## Key Concepts

### 1. Pointer Basics ([PointerBasics.c](../../Module1/08_Pointers/PointerBasics.c))

**Syntax:**

- Declaration: `int *ptr;`
- Get address: `ptr = &x;`
- Access value: `*ptr` (dereference)

**Operators:**

- `&` = Address-of operator
- `*` = Dereference operator

**Important:**

- Pointer stores address, not value
- Always initialize: `int *ptr = nullptr;`
- Check before use: `if(ptr != nullptr)`

### 2. Pointer Types

| Type             | Declaration           | Description                 |
| ---------------- | --------------------- | --------------------------- |
| Null Pointer     | `int *ptr = nullptr;` | Points to nothing (safe)    |
| Void Pointer     | `void *ptr;`          | Generic, needs type casting |
| Wild Pointer     | `int *ptr;`           | Uninitialized (dangerous!)  |
| Dangling Pointer | After `delete ptr;`   | Points to freed memory      |

### 3. Pointer Arithmetic

**Operations:**

- `ptr++` moves to next element
- `ptr--` moves to previous element
- `ptr + n` moves forward by n elements
- Increment size depends on type: `int*` +4 bytes, `char*` +1 byte

### 4. Pointers and Arrays

**Key Points:**

- Array name = address of first element
- `arr[i]` is equivalent to `*(arr + i)`
- Cannot modify array name: `arr++` is error
- Can modify pointer: `ptr++` is valid

### 5. Dynamic Memory ([DynamicCalc.c](../../Module1/08_Pointers/DynamicCalc.c), [DynamicScorecard.c](../../Module1/08_Pointers/DynamicScorecard.c))

**C++ Style:**

- Allocate: `int *ptr = new int(10);`
- Allocate array: `int *arr = new int[10];`
- Free: `delete ptr;`
- Free array: `delete[] arr;`

**C Style:**

- Allocate: `int *ptr = (int*)malloc(sizeof(int) * 10);`
- Free: `free(ptr);`

### 6. 2D Dynamic Arrays ([2DArray.cpp](../../Module1/08_Pointers/2DArray.cpp))

**Method 1 - Array of pointers:**

```
int **arr = new int*[rows];
for(int i = 0; i < rows; i++)
    arr[i] = new int[cols];
```

**Method 2 - Single block:** `int *arr = new int[rows * cols];`

### 7. Pointers and Functions

**Pass by pointer:** Allows function to modify original variable

- Syntax: `void swap(int *a, int *b);`
- Call: `swap(&x, &y);`

**Function pointer:** `int (*funcPtr)(int, int) = add;`

### 8. Common Issues

**Dangling Pointer** ([DanglingPointer.cpp](../../Module1/08_Pointers/DanglingPointer.cpp))

- Pointer to freed memory
- Solution: Set to `nullptr` after delete

**Memory Leak:**

- Losing reference to allocated memory
- Always `delete` before reassigning

---

## Common Mistakes

```
┌──────────────────────────────────────────────────────────┐
│ ❌ Dereferencing NULL pointer (*ptr without checking)     │
│ ❌ Memory leak (new without delete)                       │
│ ❌ Dangling pointer (using after delete)                  │
│ ❌ Double delete (deleting same pointer twice)            │
│ ❌ Using delete instead of delete[] for arrays            │
│ ❌ Returning address of local variable                    │
└──────────────────────────────────────────────────────────┘
```

---

## Dynamic vs Stack Memory

| Aspect       | Stack (`int x;`) | Heap (`new int;`)   |
| ------------ | ---------------- | ------------------- |
| Allocation   | Automatic        | Manual              |
| Deallocation | Automatic        | Must use delete     |
| Speed        | Fast             | Slower              |
| Size         | Limited (1-8 MB) | Large (system RAM)  |
| Lifetime     | Function scope   | Until delete called |

---

## Smart Pointers (C++11)

| Type         | Ownership          | Copy | Use Case            |
| ------------ | ------------------ | ---- | ------------------- |
| `unique_ptr` | Exclusive          | No   | Single owner        |
| `shared_ptr` | Shared (ref count) | Yes  | Multiple owners     |
| `weak_ptr`   | Non-owning         | Yes  | Break circular refs |

**Syntax:** `unique_ptr<int> ptr = make_unique<int>(10);`

---

## 🎯 Key Takeaways

1. Pointer stores **address**, not value - use `&` to get address, `*` to get value
2. Always initialize pointers to `nullptr` to avoid wild pointers
3. Match allocation/deallocation: `new`↔`delete`, `new[]`↔`delete[]`
4. Set pointer to `nullptr` after delete to avoid dangling pointers
5. Use smart pointers in modern C++ to prevent memory leaks
6. Check for `nullptr` before dereferencing to avoid crashes
