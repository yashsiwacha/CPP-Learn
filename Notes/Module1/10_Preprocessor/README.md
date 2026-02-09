# Preprocessor Directives in C/C++

## 📋 Study Plan

**Time Needed:** 3-4 hours  
**Difficulty:** ⭐⭐⭐ (Medium)  
**Prerequisites:** Basic C++ syntax, functions, compilation process

**What you'll learn:** Control compilation before it happens!

---

## 🔷 Definition (Memorize This!)

```
┌──────────────────────────────────────────────────────────┐
│ PREPROCESSOR = Program that processes source code       │
│                BEFORE compilation begins                 │
│                                                          │
│ Characteristics:                                         │
│  • All directives start with # (hash)                    │
│  • Executed before compilation                           │
│  • Text substitution (no type checking)                  │
│  • No semicolon at end                                   │
└──────────────────────────────────────────────────────────┘
```

## 🎨 Compilation Process [Draw This!]

```
Source Code (.cpp)
       ↓
  PREPROCESSOR (#include, #define, #ifdef)
       ↓
Expanded Source Code
       ↓
   COMPILER
       ↓
  Object Code (.obj/.o)
       ↓
    LINKER
       ↓
Executable (.exe)
```

---

## Key Concepts

### 1. #include Directive

**Purpose:** Insert content of another file

- System headers: `#include <iostream>`
- User headers: `#include "myheader.h"`
- `< >` searches system paths, `" "` searches current directory first

### 2. #define Macros ([AdvanceMacros.cpp](../../Module1/10_Preprocessor/AdvanceMacros.cpp))

**Simple constants:**

- Syntax: `#define PI 3.14159`
- Text replacement before compilation
- No type checking (use `const` in modern C++)

**Function-like macros:**

- Syntax: `#define SQUARE(x) ((x) * (x))`
- **CRITICAL:** Always use parentheses around parameters
- Bad: `#define SQUARE(x) x * x` → `SQUARE(2+3)` = 11, not 25!

### 3. Conditional Compilation ([debug_toggle.cpp](../../Module1/10_Preprocessor/debug_toggle.cpp), [debugifdef.cpp](../../Module1/10_Preprocessor/debugifdef.cpp))

**Purpose:** Include/exclude code based on conditions

| Directive | Purpose               |
| --------- | --------------------- |
| `#ifdef`  | If macro defined      |
| `#ifndef` | If macro NOT defined  |
| `#if`     | If condition true     |
| `#elif`   | Else if               |
| `#else`   | Otherwise             |
| `#endif`  | End conditional block |

**Example usage:**

```cpp
#ifdef DEBUG
    // Debug code only
#endif
```

### 4. Header Guards ([HeaderGaurd.cpp](../../Module1/10_Preprocessor/HeaderGaurd.cpp))

**Problem:** Prevent multiple inclusion of same header

**Method 1 - Traditional:**

```cpp
#ifndef MYHEADER_H
#define MYHEADER_H
// header content
#endif
```

**Method 2 - Modern (recommended):**

```cpp
#pragma once
```

### 5. Predefined Macros

| Macro      | Value                 |
| ---------- | --------------------- |
| `__FILE__` | Current file name     |
| `__LINE__` | Current line number   |
| `__DATE__` | Compilation date      |
| `__TIME__` | Compilation time      |
| `__func__` | Current function name |

### 6. Platform Detection ([OS.cpp](../../Module1/10_Preprocessor/OS.cpp))

**Detect operating system:**

- Windows: `#ifdef _WIN32`
- Linux: `#ifdef __linux__`
- macOS: `#ifdef __APPLE__`

### 7. Environment Configuration ([environment_config.cpp](../../Module1/10_Preprocessor/environment_config.cpp), [env_example.cpp](../../Module1/10_Preprocessor/env_example.cpp))

**Different builds:**

```cpp
#ifdef PRODUCTION
    #define API_URL "https://production.com"
#else
    #define API_URL "http://localhost"
#endif
```

### 8. Version Control ([version_control.cpp](../../Module1/10_Preprocessor/version_control.cpp), [test_version.cpp](../../Module1/10_Preprocessor/test_version.cpp))

**Check C++ version:**

```cpp
#if __cplusplus >= 201703L
    // C++17 features
#endif
```

### 9. #pragma Directive ([pragma.cpp](../../Module1/10_Preprocessor/pragma.cpp))

**Compiler-specific instructions:**

- `#pragma once` - Header guard (simpler than #ifndef)
- `#pragma pack(1)` - Structure packing
- Compiler-dependent, not portable

### 10. Debug Logging ([debugpractice.cpp](../../Module1/10_Preprocessor/debugpractice.cpp))

**Conditional debugging:**

```cpp
#ifdef DEBUG
    #define LOG(x) cout << x << endl
#else
    #define LOG(x)  // Does nothing in release
#endif
```

---

## Common Mistakes

```
┌──────────────────────────────────────────────────────────┐
│ ❌ Missing parentheses in macros: #define SQ(x) x*x      │
│ ❌ Forgetting header guards (multiple definition errors) │
│ ❌ Using macros instead of const/constexpr               │
│ ❌ Multiple evaluation: MAX(x++, y++) evaluates twice    │
│ ❌ Not using #pragma once or #ifndef guards in headers   │
└──────────────────────────────────────────────────────────┘
```

---

## Macros vs Modern C++

| Feature     | Macro `#define`         | Modern C++                 |
| ----------- | ----------------------- | -------------------------- |
| Type Safety | None                    | Yes (`const`, `constexpr`) |
| Debugging   | Difficult               | Normal debugging           |
| Scope       | Global                  | Respects scope             |
| When to Use | Conditional compilation | Constants, functions       |

**Recommendation:** Use macros only for conditional compilation and header guards. Use `const`/`constexpr` for constants, and inline functions for function-like behavior.

---

## 🎯 Key Takeaways

1. Preprocessor runs **before** compilation - text substitution only
2. Use `#pragma once` for header guards (simpler than #ifndef)
3. **Always parenthesize** macro parameters: `#define SQ(x) ((x)*(x))`
4. Prefer `const`/`constexpr` over `#define` for constants (type safety)
5. Use conditional compilation (`#ifdef DEBUG`) for debug builds
6. Predefined macros (`__FILE__`, `__LINE__`) useful for logging/debugging

#### #if defined():

```cpp
#if defined(DEBUG) && defined(VERBOSE)
    cout << "Debug and verbose mode" << endl;
#endif

#if defined(WINDOWS) || defined(LINUX)
    // Platform-specific code
#endif
```

### 5. #pragma

Compiler-specific directives.

#### Common Pragmas:

**Pragma Once** (Header guard):

```cpp
#pragma once  // Ensures file included only once
```

**Pack** (Structure packing):

```cpp
#pragma pack(1)  // No padding
struct Data {
    char c;
    int i;
};
#pragma pack()  // Restore default
```

**Warning Control**:

```cpp
#pragma warning(disable: 4996)  // Disable specific warning
#pragma warning(push)           // Save warning state
#pragma warning(pop)            // Restore warning state
```

### 6. #error

Generate compilation error with message.

```cpp
#ifndef REQUIRED_MACRO
    #error "REQUIRED_MACRO must be defined!"
#endif
```

### 7. #warning

Generate compilation warning (GCC/Clang).

```cpp
#warning "This feature is deprecated"
```

## Header Guards

Prevents multiple inclusion of same header file.

### Traditional Method:

```cpp
// myheader.h
#ifndef MYHEADER_H
#define MYHEADER_H

// Header contents here
class MyClass {
    // ...
};

#endif  // MYHEADER_H
```

### Modern Method:

```cpp
// myheader.h
#pragma once

// Header contents here
class MyClass {
    // ...
};
```

**Comparison:**

- `#pragma once` - Simpler, less error-prone, faster
- `#ifndef` guards - Portable, standard-compliant

## Predefined Macros

### Standard Macros:

```cpp
__FILE__     // Current file name
__LINE__     // Current line number
__DATE__     // Compilation date (MMM DD YYYY)
__TIME__     // Compilation time (HH:MM:SS)
__func__     // Current function name (C99/C++11)
__FUNCTION__ // Current function name (compiler-specific)
```

### Usage Example:

```cpp
#define DEBUG_LOG(msg) \
    cout << __FILE__ << ":" << __LINE__ << " - " << msg << endl

DEBUG_LOG("Value of x: " << x);
// Output: main.cpp:42 - Value of x: 10
```

### Platform Detection:

```cpp
#ifdef _WIN32
    // Windows (32-bit or 64-bit)
#endif

#ifdef _WIN64
    // Windows 64-bit only
#endif

#ifdef __linux__
    // Linux
#endif

#ifdef __APPLE__
    // macOS/iOS
#endif

#ifdef __unix__
    // Unix-like systems
#endif
```

### Compiler Detection:

```cpp
#ifdef __GNUC__
    // GCC compiler
#endif

#ifdef _MSC_VER
    // Microsoft Visual C++
#endif

#ifdef __clang__
    // Clang compiler
#endif
```

### C++ Version:

```cpp
#if __cplusplus >= 201703L
    // C++17 or later
#elif __cplusplus >= 201402L
    // C++14
#elif __cplusplus >= 201103L
    // C++11
#else
    // Before C++11
#endif
```

## Debugging with Preprocessor

### Debug Mode:

```cpp
#define DEBUG

#ifdef DEBUG
    #define LOG(x) cout << x << endl
#else
    #define LOG(x)  // Does nothing in release
#endif

LOG("Debug message");  // Only prints in debug mode
```

### Verbose Logging:

```cpp
#ifdef VERBOSE
    #define VERBOSE_LOG(x) cout << __func__ << ": " << x << endl
#else
    #define VERBOSE_LOG(x)
#endif
```

### Assertions:

```cpp
#ifdef DEBUG
    #define ASSERT(cond) \
        if(!(cond)) { \
            cerr << "Assertion failed: " << #cond \
                 << " at " << __FILE__ << ":" << __LINE__ << endl; \
            abort(); \
        }
#else
    #define ASSERT(cond)
#endif

ASSERT(x > 0);  // Checks in debug, ignored in release
```

## Advanced Macro Techniques

### 1. Stringification (#):

Converts macro argument to string.

```cpp
#define TO_STRING(x) #x

cout << TO_STRING(Hello);  // Prints: Hello
cout << TO_STRING(123);    // Prints: 123
```

### 2. Token Pasting (##):

Concatenates tokens.

```cpp
#define CONCAT(a, b) a##b

int CONCAT(var, 123) = 10;  // Creates: var123
cout << var123;             // Prints: 10
```

### 3. Variadic Macros:

Accept variable number of arguments.

```cpp
#define LOG(format, ...) \
    printf("%s:%d - " format "\n", __FILE__, __LINE__, ##__VA_ARGS__)

LOG("Error occurred");
LOG("Value: %d", x);
LOG("Values: %d, %f", x, y);
```

### 4. X-Macros:

For generating repetitive code.

```cpp
#define COLORS \
    X(RED, 0xFF0000) \
    X(GREEN, 0x00FF00) \
    X(BLUE, 0x0000FF)

// Generate enum
enum Color {
    #define X(name, value) COLOR_##name,
    COLORS
    #undef X
};

// Generate array
const char* colorNames[] = {
    #define X(name, value) #name,
    COLORS
    #undef X
};
```

## Configuration Management

### Environment-based Configuration:

```cpp
// config.h
#ifdef PRODUCTION
    #define API_URL "https://api.production.com"
    #define DEBUG_MODE 0
#elif defined(STAGING)
    #define API_URL "https://api.staging.com"
    #define DEBUG_MODE 1
#else  // Development
    #define API_URL "http://localhost:3000"
    #define DEBUG_MODE 1
#endif
```

### Version Control:

```cpp
#define VERSION_MAJOR 1
#define VERSION_MINOR 2
#define VERSION_PATCH 3

#define VERSION_STRING "1.2.3"

#if VERSION_MAJOR >= 2
    // New features for version 2.x
#endif
```

### Feature Flags:

```cpp
#define FEATURE_LOGIN
#define FEATURE_PAYMENT
// #define FEATURE_BETA  // Commented out - disabled

#ifdef FEATURE_LOGIN
    void loginUser() { /* ... */ }
#endif

#ifdef FEATURE_PAYMENT
    void processPayment() { /* ... */ }
#endif
```

## Macros vs Inline Functions

### Macros:

```cpp
#define SQUARE(x) ((x) * (x))
```

**Pros:**

- Can work with any type
- No function call overhead
- Can use ## and # operators

**Cons:**

- No type checking
- Can cause unexpected behavior
- Harder to debug
- Multiple evaluation of arguments

### Inline Functions:

```cpp
inline int square(int x) { return x * x; }
```

**Pros:**

- Type safe
- Proper scoping
- Can debug normally
- Arguments evaluated once

**Cons:**

- Specific type only (use templates for generic)
- May not be inlined by compiler

**Recommendation**: Prefer inline functions or constexpr in C++.

## Best Practices

1. **Use UPPERCASE** for macros:

```cpp
#define MAX_SIZE 100  // Good
#define maxSize 100   // Confusing
```

2. **Parenthesize** macro arguments:

```cpp
#define SQUARE(x) ((x) * (x))  // Good
#define SQUARE(x) x * x        // Bad
```

3. **Prefer const/constexpr** over #define:

```cpp
const int MAX_SIZE = 100;      // Better than #define
constexpr double PI = 3.14159; // C++11
```

4. **Use #pragma once** for header guards:

```cpp
#pragma once  // Simpler than #ifndef
```

5. **Namespace macros**:

```cpp
#define MYPROJECT_MAX_SIZE 100  // Avoid name conflicts
```

6. **Document macros**:

```cpp
// Calculates square of x
// WARNING: Evaluates x twice
#define SQUARE(x) ((x) * (x))
```

## Common Pitfalls

1. **Missing Parentheses**:

```cpp
#define DOUBLE(x) x + x
int y = DOUBLE(3) * 2;  // Expands to: 3 + 3 * 2 = 9 (not 12!)
```

2. **Multiple Evaluation**:

```cpp
#define MAX(a,b) ((a) > (b) ? (a) : (b))
int x = 5;
int y = MAX(x++, 10);  // x incremented twice!
```

3. **Semicolon Issues**:

```cpp
#define SWAP(a,b) {int temp=a; a=b; b=temp;}  // Bad
if(condition)
    SWAP(x, y);  // Error! Extra semicolon
else
    // ...

// Better:
#define SWAP(a,b) do {int temp=a; a=b; b=temp;} while(0)
```

4. **Macro Name Conflicts**:

```cpp
#define MAX 100
std::vector<int> v;
int m = std::max(v[0], v[1]);  // Error! MAX expands here too
```

5. **Debugging Difficulty**:

```cpp
// Macro errors show expanded code, not original
```

## Related Concepts

- Compiler optimization
- Conditional compilation
- Build systems (Make, CMake)
- Header file organization
- Link-time optimization
