# Structures in C

## 📋 Study Plan

**Time Needed:** 2-3 hours  
**Difficulty:** ⭐⭐ (Medium)  
**Prerequisites:** Variables, arrays, basic data types

**What you'll learn:** Group different types of data together!

---

## 🔷 Definition (Memorize This!)

```
┌──────────────────────────────────────────────────────────┐
│ STRUCTURE = User-defined datatype that groups            │
│             variables of DIFFERENT types                 │
│                                                          │
│ Purpose:                                                 │
│  • Organize related data together                        │
│  • Create complex data types                             │
│  • Model real-world entities                             │
│  • Better than multiple arrays                           │
└──────────────────────────────────────────────────────────┘
```

## 🎨 Memory Concept [Draw This!]

```
Structure: Student with 3 members

┌──────────────────────────────────┐
│ rollNo:  [  101  ]  (4 bytes)   │
│ name:    [John...]  (50 bytes)  │
│ marks:   [ 85.5 ]   (4 bytes)   │
└──────────────────────────────────┘
    All stored together in memory!
```

---

## Key Concepts

### Structure Basics ([Structure.c](../../Module1/07_Structure/Structure.c))

**Syntax:**

- Declaration: `struct Student { int rollNo; char name[50]; };`
- Variable creation: `struct Student s1;`
- Access members: `s1.rollNo = 101;`

**Important Points:**

- Groups different data types under one name
- Members accessed using dot operator (`.`)
- Use typedef to avoid `struct` keyword: `typedef struct { ... } Student;`
- Can be passed to functions
- Members stored sequentially (with padding)

### Member Access Operators

| Operator | Used With         | Example            |
| -------- | ----------------- | ------------------ |
| `.`      | Structure         | `s.rollNo = 1;`    |
| `->`     | Pointer to Struct | `ptr->rollNo = 1;` |

**Arrow operator:** `ptr->member` is same as `(*ptr).member`

### Nested Structures

- Structure can contain another structure as member
- Syntax: `struct Student { struct Date birthDate; };`
- Access: `s1.birthDate.day = 15;`

### Array of Structures

- Declare: `struct Student students[100];`
- Access: `students[0].rollNo = 101;`
- Efficient for storing multiple records

### Structure and Functions

**Pass by value:** Copies entire structure (slow for large structs)  
**Pass by pointer:** Efficient, allows modification

- Syntax: `void func(struct Student *s);`
- Access in function: `s->rollNo = 100;`

### Typedef Usage

| Without Typedef               | With Typedef         |
| ----------------------------- | -------------------- |
| `struct Student s1;`          | `Student s1;`        |
| Must use `struct` keyword     | Cleaner syntax       |
| `typedef struct { } Student;` | Recommended approach |

---

## Common Mistakes

```
┌──────────────────────────────────────────────────────────┐
│ ❌ Forgetting 'struct' keyword (in C without typedef)     │
│ ❌ Using = for string assignment (use strcpy instead)     │
│ ❌ Comparing structures with == (compare member by member)│
│ ❌ Not initializing members (garbage values)              │
│ ❌ Assuming size = sum of members (padding exists)        │
└──────────────────────────────────────────────────────────┘
```

---

## Structure vs Class

| Feature        | Structure (C) | Class (C++)           |
| -------------- | ------------- | --------------------- |
| Default Access | Public        | Private               |
| Methods        | Not supported | Supported             |
| Inheritance    | Not supported | Supported             |
| Constructors   | Not supported | Supported             |
| Usage          | Plain data    | Objects with behavior |

---

## 🎯 Key Takeaways

1. Structures group **different** data types; arrays group **same** type
2. Use typedef for cleaner syntax without `struct` keyword
3. Pass large structures by pointer for efficiency
4. Access members with `.` for variables, `->` for pointers
5. Always initialize structure members to avoid garbage values
6. Structure size may include padding bytes for alignment
