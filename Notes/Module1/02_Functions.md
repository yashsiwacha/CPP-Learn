# Functions in C++

## 📋 Study Plan

**Time Needed:** 3-4 hours  
**Difficulty:** ⭐⭐ (Medium)  
**Prerequisites:** Basic C++ syntax, variables

**Why important:** Functions are the building blocks of modular programming!

---

## 🔷 Definition (Memorize This!)

```
┌──────────────────────────────────────────────────────────┐
│ FUNCTION = Reusable block of code that performs a        │
│            specific task                                 │
│                                                          │
│ Benefits:                                                │
│  • Code reusability (write once, use many times)         │
│  • Modularity (break complex problems into parts)        │
│  • Easy debugging and maintenance                        │
│  • Reduces code duplication                              │
└──────────────────────────────────────────────────────────┘
```

## 🎨 Function Structure [Draw This!]

```
┌──────────────────────────────────────────┐
│  return_type function_name(parameters)   │
│  {                                       │
│      // Function body                    │
│      return value;                       │
│  }                                       │
└──────────────────────────────────────────┘
        ↓           ↓           ↓
   What type   Identifier   Input values
   to return                (optional)
```

---

## Key Concepts

### 1. Function Basics

**Syntax:** `return_type function_name(parameters) { ... }`

**Components:**

- **Return Type**: Data type of value returned (void if nothing)
- **Function Name**: Identifier following naming rules
- **Parameters**: Input values (formal parameters)
- **Arguments**: Actual values passed when calling

### 2. Parameter Passing Methods

| Method          | Syntax              | Changes Original? | Use When                |
| --------------- | ------------------- | ----------------- | ----------------------- |
| Pass by Value   | `void func(int x)`  | No                | Small data types        |
| Pass by Ref     | `void func(int &x)` | Yes               | Need to modify original |
| Pass by Pointer | `void func(int *x)` | Yes               | Arrays, dynamic memory  |

### 3. Temperature Converter ([temperature_converter.cpp](../../Module1/02_Functions/temperature_converter.cpp))

**Concepts:**

- Multiple conversion functions
- Formula implementation: `F = C * 9/5 + 32`
- Menu-driven program structure

### 4. Banking System ([banking_system.cpp](../../Module1/02_Functions/banking_system.cpp))

**Key Functions:**

- `deposit()` - Add money
- `withdraw()` - Remove money with validation
- `checkBalance()` - Display current balance
- `displayMenu()` - User interface

---

## Function Features

**Function Overloading:**

- Same name, different parameters
- Compile-time polymorphism

**Default Parameters:**

- Syntax: `void func(int a, int b = 10)`
- Must be rightmost parameters

**Inline Functions:**

- Syntax: `inline int square(int x) { return x * x; }`
- Hint to compiler for optimization
- Best for small, frequently called functions

**Recursion:**

- Function calling itself
- Needs base case to stop

---

## Common Mistakes

```
┌──────────────────────────────────────────────────────────┐
│ ❌ Missing return in non-void functions                   │
│ ❌ Parameter type mismatch                                │
│ ❌ Scope issues - variables are local                     │
│ ❌ Infinite recursion - missing base case                 │
│ ❌ Default parameters not at end                          │
└──────────────────────────────────────────────────────────┘
```

## Key Takeaways

1. **Single Responsibility** - One function, one task
2. **Meaningful Names** - Use descriptive function names
3. **Keep Functions Short** - Prefer < 50 lines
4. **Pass by Reference** - For large objects to avoid copying
5. **Const Parameters** - Use const for read-only parameters
