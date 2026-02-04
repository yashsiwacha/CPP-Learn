# Structures in C

## Overview

Structures (structs) are user-defined data types that allow grouping variables of different types under a single name.

## Topics Covered

### Structure Basics

**File Reference**: [Structure.c](../../Module1/07_Structure/Structure.c)

## What is a Structure?

A structure is a collection of variables (can be of different types) grouped together under a single name.

### Declaration Syntax:

```c
struct StudentClass {
    int rollNo;
    char name[50];
    float marks;
    char grade;
};
```

### Creating Structure Variables:

```c
// Method 1: After declaration
struct Student s1, s2;

// Method 2: During declaration
struct Student {
    int rollNo;
    char name[50];
} s1, s2;

// Method 3: Using typedef
typedef struct {
    int rollNo;
    char name[50];
} Student;

Student s1, s2;  // No need for 'struct' keyword
```

## Accessing Structure Members

### Dot Operator (.):

```c
struct Student s1;
s1.rollNo = 101;
strcpy(s1.name, "John");
s1.marks = 85.5;
```

### Arrow Operator (->):

Used with pointers to structures

```c
struct Student *ptr = &s1;
ptr->rollNo = 101;
ptr->marks = 85.5;

// Equivalent to:
(*ptr).rollNo = 101;
```

## Structure Operations

### 1. Initialization:

```c
// During declaration
struct Student s1 = {101, "John", 85.5, 'A'};

// Designated initializers (C99)
struct Student s2 = {
    .rollNo = 102,
    .name = "Mary",
    .marks = 90.0,
    .grade = 'A'
};
```

### 2. Assignment:

```c
struct Student s1 = {101, "John", 85.5, 'A'};
struct Student s2;
s2 = s1;  // Copies all members
```

### 3. Comparison:

```c
// Cannot compare directly
if(s1 == s2)  // ERROR!

// Must compare member by member
if(s1.rollNo == s2.rollNo &&
   strcmp(s1.name, s2.name) == 0)
```

### 4. Passing to Functions:

```c
// Pass by value (copy)
void display(struct Student s) {
    printf("%d %s", s.rollNo, s.name);
}

// Pass by reference (pointer)
void modify(struct Student *s) {
    s->rollNo = 200;
}
```

## Nested Structures

```c
struct Date {
    int day;
    int month;
    int year;
};

struct Student {
    int rollNo;
    char name[50];
    struct Date birthDate;  // Nested structure
};

// Usage
struct Student s1;
s1.birthDate.day = 15;
s1.birthDate.month = 8;
s1.birthDate.year = 2000;
```

## Array of Structures

```c
struct Student students[100];

// Accessing
students[0].rollNo = 101;
strcpy(students[0].name, "John");

// Loop through
for(int i = 0; i < 100; i++) {
    printf("%d %s\n", students[i].rollNo, students[i].name);
}
```

## Structure and Functions

### Returning Structure:

```c
struct Student createStudent(int roll, char *name) {
    struct Student s;
    s.rollNo = roll;
    strcpy(s.name, name);
    return s;
}

struct Student s1 = createStudent(101, "John");
```

### Structure Pointer Parameter:

```c
void updateMarks(struct Student *s, float marks) {
    s->marks = marks;
}

struct Student s1;
updateMarks(&s1, 85.5);
```

## Typedef with Structures

### Traditional Way:

```c
struct Student {
    int rollNo;
    char name[50];
};

struct Student s1;  // Must use 'struct' keyword
```

### Using Typedef:

```c
typedef struct {
    int rollNo;
    char name[50];
} Student;

Student s1;  // No 'struct' keyword needed
```

### Named Struct with Typedef:

```c
typedef struct StudentStruct {
    int rollNo;
    char name[50];
} Student;

// Can use either:
struct StudentStruct s1;
Student s2;
```

## Structure Memory Layout

### Memory Alignment:

```c
struct Example {
    char c;    // 1 byte
    int i;     // 4 bytes
    char d;    // 1 byte
};
// Size may be 12 bytes due to padding, not 6
```

### Packed Structures:

```c
#pragma pack(1)
struct Packed {
    char c;
    int i;
    char d;
};
#pragma pack()
// Now size is exactly 6 bytes
```

### Finding Size:

```c
printf("Size: %zu bytes\n", sizeof(struct Student));
```

## Structure vs Class (C++)

### Similarities:

- Both group data members
- Both can have functions (methods in C++)
- Both support access control in C++

### Differences:

| Feature        | Structure (C) | Class (C++)           |
| -------------- | ------------- | --------------------- |
| Default Access | Public        | Private               |
| Methods        | Not supported | Supported             |
| Inheritance    | Not supported | Supported             |
| Constructors   | Not supported | Supported             |
| Usage          | Plain data    | Objects with behavior |

## Best Practices

1. **Use typedef**: Makes code cleaner

```c
typedef struct {
    // members
} Name;
```

2. **Initialize**: Always initialize structure variables

```c
struct Student s = {0};  // Initialize all to 0
```

3. **Pass by Pointer**: For large structures

```c
void func(struct Student *s);  // Efficient
// vs
void func(struct Student s);   // Copies entire structure
```

4. **Const for Read-Only**:

```c
void display(const struct Student *s);  // Cannot modify
```

5. **Meaningful Names**: Use descriptive structure names

```c
struct EmployeeRecord  // Good
struct Data            // Bad
```

## Common Pitfalls

1. **Forgetting 'struct' Keyword** (in C):

```c
Student s1;  // Error! Need: struct Student s1;
```

2. **Uninitialized Members**:

```c
struct Student s;
printf("%d", s.rollNo);  // Garbage value!
```

3. **String Assignment**:

```c
s.name = "John";  // Error! Cannot assign to array
strcpy(s.name, "John");  // Correct
```

4. **Comparison**:

```c
if(s1 == s2)  // Error! Cannot compare directly
```

5. **Size Assumptions**:

```c
// Don't assume sizeof(struct) = sum of member sizes
// Padding may be added
```

## Self-Referential Structures

Used for linked lists, trees, etc.:

```c
struct Node {
    int data;
    struct Node *next;  // Pointer to same type
};
```

## Bit Fields

For packing flags:

```c
struct Flags {
    unsigned int flag1 : 1;  // 1 bit
    unsigned int flag2 : 1;  // 1 bit
    unsigned int value : 6;  // 6 bits
};  // Total: 1 byte instead of 3 ints (12 bytes)
```

## Related Concepts

- Unions
- Enumerations
- Classes (C++)
- Dynamic memory allocation
- Linked lists
- File I/O with structures
