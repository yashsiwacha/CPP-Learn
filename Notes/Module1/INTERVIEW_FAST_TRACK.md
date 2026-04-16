# Module 1 - Fast Learning + Interview Notes

High-yield revision for fundamentals.

Companion Q&A bank: [ALL_MODULES_INTERVIEW_QA.md](../ALL_MODULES_INTERVIEW_QA.md)

## 1. Arrays and Strings

- Arrays are contiguous memory blocks; O(1) indexed access.
- Common patterns: prefix/suffix, two pointers, sliding window.
- String in C++: use `std::string` for safety and easier operations.

Interview points:

- Array vs vector: fixed-size vs dynamic resizing.
- Why contiguous memory matters for cache performance.

## 2. Functions and Parameter Passing

- Pass by value: copies data.
- Pass by reference: no copy, allows mutation.
- Pass by const reference: no copy, read-only.

Interview points:

- When to use `const T&` for large objects.
- Return by value and modern copy elision/move optimizations.

## 3. Conditionals and Control Flow

- Keep branch logic simple and test edge cases.
- Avoid deeply nested `if` when guard clauses improve readability.

Interview points:

- Off-by-one bugs in loops and bounds.

## 4. Recursion Basics

- Must have correct base case.
- Think in terms of smaller subproblems.
- Watch recursion depth and stack limits.

Interview points:

- Convert recursion to iteration when stack depth is risky.
- Memoization for overlapping subproblems.

## 5. Structures and Data Modeling

- `struct` default access is public; `class` default is private.
- Use structs for simple data bundles; classes for behavior-rich models.

## 6. Pointers and Memory

- Pointer stores address, reference is alias.
- `new/delete` for dynamic memory; avoid manual memory where possible.
- Prefer RAII containers (`std::vector`, smart pointers).

Interview points:

- Dangling pointer, null pointer, wild pointer, memory leak.
- `new[]` pairs with `delete[]`.

## 7. File Handling

- `ifstream`, `ofstream`, `fstream`.
- Always check stream state before read/write.

Interview points:

- Text vs binary I/O and common failure handling.

## 8. Preprocessor

- `#include`, macros, conditional compilation.
- Prefer `constexpr`, inline functions, templates over macros when possible.

Interview points:

- Header guards vs `#pragma once`.

## Quick Practice Set (Module 1)

- Reverse array in-place
- Find duplicate element
- Longest subarray with given sum (positive and mixed variants)
- Recursive power function (fast exponentiation)
- File read and parse line-by-line
