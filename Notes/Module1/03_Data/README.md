# Data Structures and Classes

## Overview

This section covers basic data organization using structures and classes in C++.

## Topics Covered

### 1. Student Class

**File Reference**: [student_class.cpp](../../Module1/03_Data/student_class.cpp)

#### Key Concepts:

- Class definition and implementation
- Member variables (attributes)
- Member functions (methods)
- Encapsulation basics
- Constructor and methods

#### Student Class Structure:

```cpp
class Student {
private:
    string name;
    int rollNo;
    float marks;

public:
    // Constructor
    Student(string n, int r, float m);

    // Methods
    void display();
    float getPercentage();
    char getGrade();
};
```

#### Concepts Demonstrated:

- **Constructor**: Initialize object when created
- **Getter Methods**: Retrieve private data
- **Business Logic**: Calculate percentage and grade
- **Display Method**: Output object information

### 2. Book Management

**File Reference**: [book_management.cpp](../../Module1/03_Data/book_management.cpp)

#### Key Concepts:

- Array of objects
- CRUD operations (Create, Read, Update, Delete)
- Search functionality
- Menu-driven application

#### Book Class Structure:

```cpp
class Book {
private:
    int bookId;
    string title;
    string author;
    float price;
    bool isAvailable;

public:
    // Constructor
    Book();
    Book(int id, string t, string a, float p);

    // Methods
    void display();
    void issueBook();
    void returnBook();
    bool search(int id);
};
```

#### Operations:

1. **Add Book**: Create new book entry
2. **Display Books**: Show all books
3. **Search Book**: Find by ID or title
4. **Issue Book**: Mark as unavailable
5. **Return Book**: Mark as available
6. **Delete Book**: Remove from system

## Class vs Structure

### Structure (C-style):

```cpp
struct Student {
    int id;
    string name;
    float marks;
};
```

- Members are public by default
- Used for plain data structures
- No methods typically

### Class (C++ OOP):

```cpp
class Student {
private:
    int id;
    string name;
    float marks;

public:
    void display();
    float getGrade();
};
```

- Members are private by default
- Encapsulation and data hiding
- Contains both data and functions

## Object-Oriented Principles

### 1. Encapsulation

- Bundle data and methods together
- Hide internal implementation
- Control access through public interface

### 2. Data Hiding

- Make data members private
- Provide public getters/setters
- Validate data before modification

### 3. Abstraction

- Show only essential features
- Hide complex implementation
- Provide simple interface

## Constructor Types

### Default Constructor:

```cpp
Student() {
    name = "";
    rollNo = 0;
    marks = 0.0;
}
```

### Parameterized Constructor:

```cpp
Student(string n, int r, float m) {
    name = n;
    rollNo = r;
    marks = m;
}
```

### Copy Constructor:

```cpp
Student(const Student &s) {
    name = s.name;
    rollNo = s.rollNo;
    marks = s.marks;
}
```

## Access Specifiers

### Public:

- Accessible from anywhere
- Used for interface methods

### Private:

- Accessible only within class
- Default for class members
- Used for data hiding

### Protected:

- Accessible in class and derived classes
- Used in inheritance

## Best Practices

1. **Data Members Private**: Always make data members private
2. **Public Interface**: Provide public methods for interaction
3. **Initialization**: Always initialize members in constructor
4. **Const Methods**: Mark methods that don't modify object as `const`
5. **Meaningful Names**: Use clear names for classes and members
6. **Single Responsibility**: Each class should have one purpose
7. **Validation**: Validate data in setters

## Common Pitfalls

1. **Uninitialized Members**: Always initialize in constructor
2. **Public Data**: Avoid making data members public
3. **Missing Const**: Forget to mark read-only methods as const
4. **Large Classes**: Classes doing too many things
5. **No Validation**: Not checking input in setters

## Memory Management

### Stack Allocation:

```cpp
Student s1("John", 101, 85.5);
```

- Automatic memory management
- Fast allocation
- Limited size

### Heap Allocation:

```cpp
Student* s1 = new Student("John", 101, 85.5);
delete s1; // Must manually delete
```

- Manual memory management
- Slower allocation
- Flexible size

## Related Concepts

- Inheritance
- Polymorphism
- Object lifecycle
- Dynamic memory allocation
- STL containers
