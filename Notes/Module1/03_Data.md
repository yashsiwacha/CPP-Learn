# Data Structures and Classes

## 📋 Study Plan

**Time Needed:** 3-4 hours  
**Difficulty:** ⭐⭐⭐ (Medium-Hard)  
**Prerequisites:** Variables, functions, basic data types

**What you'll learn:** How to organize related data together!

---

## 🔷 Definition (Memorize This!)

```
┌──────────────────────────────────────────────────────────┐
│ STRUCTURE/CLASS = User-defined data type that groups    │
│                    variables and functions together      │
│                                                          │
│ Purpose:                                                 │
│  • Organize related data together                        │
│  • Create complex data types                             │
│  • Model real-world entities                             │
└──────────────────────────────────────────────────────────┘
```

## Key Concepts

### 1. Student Class ([student_class.cpp](../../Module1/03_Data/student_class.cpp))

**Features:**

- Class definition with private data
- Constructor: Initialize objects
- Getter/Setter methods
- Business logic: Calculate grades
- Display method

### 2. Book Management ([book_management.cpp](../../Module1/03_Data/book_management.cpp))

**CRUD Operations:**

1. Add Book
2. Display Books
3. Search Book
4. Issue/Return Book
5. Delete Book

---

## Class vs Structure

| Feature        | Structure  | Class (C++)     |
| -------------- | ---------- | --------------- |
| Default access | Public     | Private         |
| Purpose        | Plain data | Data + behavior |
| Encapsulation  | Minimal    | Strong          |

## OOP Principles

**Encapsulation:** Bundle data and methods together  
**Data Hiding:** Make data private, provide public interface  
**Abstraction:** Hide complexity, show only essentials

## Constructor Types

- **Default**: `Student() { }` - No parameters
- **Parameterized**: `Student(string n, int r)` - With values
- **Copy**: `Student(const Student &s)` - Copy existing object

## Access Specifiers

| Specifier | Access Level            | Use Case               |
| --------- | ----------------------- | ---------------------- |
| Public    | Anywhere                | Interface methods      |
| Private   | Within class only       | Data members (default) |
| Protected | Class + derived classes | Inheritance            |

---

## Common Mistakes

```
┌──────────────────────────────────────────────────────────┐
│ ❌ Uninitialized members in constructor                   │
│ ❌ Public data members (breaks encapsulation)             │
│ ❌ Missing const on read-only methods                     │
│ ❌ Large classes doing too many things                    │
│ ❌ No validation in setters                               │
└──────────────────────────────────────────────────────────┘
```

## Key Takeaways

1. **Data Private** - Always make data members private
2. **Public Interface** - Provide public methods for access
3. **Initialize** - Always initialize in constructor
4. **Const Methods** - Mark non-modifying methods as const
5. **Single Responsibility** - One class, one purpose
6. **Validate** - Check input in setters
