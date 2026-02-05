# Object-Oriented Programming (OOP) in C++

## 📖 How to Study This Topic

**Recommended Approach:**

1. Start with the Four Pillars overview - understand the concepts before code
2. Practice each constructor type with simple examples
3. Draw diagrams for access specifiers and inheritance
4. Code along with examples - don't just read
5. Focus on "why" (purpose) not just "how" (syntax)

**Time Investment:** 4-6 hours for initial learning, practice daily

**Common Struggles:**

- Understanding the difference between access specifiers
- When to use const member functions
- Static vs instance members

**Pro Tip:** Create a simple class (like Person or BankAccount) and implement all concepts in it.

---

## Overview

OOP is a programming paradigm based on the concept of "objects" that contain data and code. C++ supports all major OOP principles.

## Topics Covered

### Files Reference:

- [AccessSpecifier.cpp](../../Module2/11_OOPS/AccessSpecifier.cpp)
- [CopyConstructor.cpp](../../Module2/11_OOPS/CopyConstructor.cpp)
- [Destructors.cpp](../../Module2/11_OOPS/Destructors.cpp)
- [InlinevsMacros.cpp](../../Module2/11_OOPS/InlinevsMacros.cpp)
- [mutablekeyword.cpp](../../Module2/11_OOPS/mutablekeyword.cpp)
- [StaticDemo.cpp](../../Module2/11_OOPS/StaticDemo.cpp)
- [StuctANDclass.cpp](../../Module2/11_OOPS/StuctANDclass.cpp)
- [Task3Constructor.cpp](../../Module2/11_OOPS/Task3Constructor.cpp)
- [ThisPointer.cpp](../../Module2/11_OOPS/ThisPointer.cpp)

## Four Pillars of OOP

### OOP Pillars Comparison:

| Pillar        | Purpose               | Mechanism                    | Example                   |
| ------------- | --------------------- | ---------------------------- | ------------------------- |
| Encapsulation | Bundle & protect data | Access specifiers            | Private members + getters |
| Abstraction   | Hide complexity       | Abstract classes, interfaces | Pure virtual functions    |
| Inheritance   | Code reuse            | Base → Derived               | Animal → Dog              |
| Polymorphism  | Multiple forms        | Virtual functions            | Shape\* → Circle/Square   |

### 1. Encapsulation

Bundling data and methods that operate on that data within a single unit (class).

```cpp
class BankAccount {
private:
    double balance;  // Hidden data

public:
    void deposit(double amount) {
        if(amount > 0)
            balance += amount;
    }

    double getBalance() const {
        return balance;
    }
};
```

**Benefits:**

- Data hiding
- Controlled access
- Maintainability
- Flexibility to change implementation

### 2. Abstraction

Hiding complex implementation details and showing only essential features.

```cpp
class Shape {
public:
    virtual double area() = 0;  // Abstract method
    virtual double perimeter() = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    double area() { return 3.14 * radius * radius; }
    double perimeter() { return 2 * 3.14 * radius; }
};
```

**Benefits:**

- Reduces complexity
- Improves code readability
- Easier maintenance
- Focus on what, not how

### 3. Inheritance

Creating new classes from existing classes, inheriting properties and methods.

```cpp
class Animal {
protected:
    string name;
public:
    void eat() { cout << "Eating..."; }
};

class Dog : public Animal {
public:
    void bark() { cout << "Woof!"; }
};

Dog d;
d.eat();   // Inherited from Animal
d.bark();  // Own method
```

**Types:**

- Single inheritance
- Multiple inheritance
- Multilevel inheritance
- Hierarchical inheritance
- Hybrid inheritance

### 4. Polymorphism

Ability to take many forms. Same interface, different implementations.

```cpp
class Shape {
public:
    virtual void draw() { cout << "Drawing shape"; }
};

class Circle : public Shape {
public:
    void draw() override { cout << "Drawing circle"; }
};

class Rectangle : public Shape {
public:
    void draw() override { cout << "Drawing rectangle"; }
};

Shape* s1 = new Circle();
Shape* s2 = new Rectangle();
s1->draw();  // Calls Circle::draw()
s2->draw();  // Calls Rectangle::draw()
```

**Types:**

- Compile-time (function/operator overloading)
- Runtime (virtual functions)

## Access Specifiers

### 1. Public:

```cpp
class MyClass {
public:
    int publicVar;
    void publicMethod() { }
};
```

- Accessible from anywhere
- No restrictions

### 2. Private:

```cpp
class MyClass {
private:
    int privateVar;
    void privateMethod() { }
};
```

- Accessible only within the class
- Default for class members
- Provides encapsulation

### 3. Protected:

```cpp
class Base {
protected:
    int protectedVar;
};

class Derived : public Base {
    void func() {
        protectedVar = 10;  // OK - accessible in derived class
    }
};
```

- Accessible in the class and derived classes
- Not accessible from outside

### Access in Inheritance:

| Base Access | Public Inheritance | Protected Inheritance | Private Inheritance |
| ----------- | ------------------ | --------------------- | ------------------- |
| Public      | Public             | Protected             | Private             |
| Protected   | Protected          | Protected             | Private             |
| Private     | Not accessible     | Not accessible        | Not accessible      |

## Constructors

### Definition:

Special member function called when object is created.

### Types:

#### 1. Default Constructor:

```cpp
class Student {
public:
    Student() {  // No parameters
        roll = 0;
        name = "";
    }
private:
    int roll;
    string name;
};
```

#### 2. Parameterized Constructor:

```cpp
class Student {
public:
    Student(int r, string n) {
        roll = r;
        name = n;
    }
private:
    int roll;
    string name;
};

Student s1(101, "John");
```

#### 3. Copy Constructor:

```cpp
class Student {
public:
    Student(const Student &s) {
        roll = s.roll;
        name = s.name;
    }
private:
    int roll;
    string name;
};

Student s1(101, "John");
Student s2 = s1;  // Copy constructor called
Student s3(s1);   // Also calls copy constructor
```

#### 4. Constructor Initialization List:

```cpp
class Student {
    const int roll;
    string name;
public:
    Student(int r, string n) : roll(r), name(n) {
        // More efficient, especially for const members
    }
};
```

#### 5. Delegating Constructor (C++11):

```cpp
class Student {
public:
    Student() : Student(0, "") { }  // Delegates to another constructor

    Student(int r, string n) {
        roll = r;
        name = n;
    }
};
```

### Constructor Rules:

- Same name as class
- No return type
- Can be overloaded
- Automatically called
- Can't be virtual

## Destructors

### Definition:

Special member function called when object is destroyed.

```cpp
class Student {
public:
    ~Student() {  // Destructor
        cout << "Object destroyed" << endl;
        // Cleanup code
    }
};
```

### Properties:

- Name: `~ClassName()`
- No parameters
- No return type
- Only one destructor per class
- Automatically called
- Called in reverse order of construction

### Virtual Destructor:

```cpp
class Base {
public:
    virtual ~Base() {
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        cout << "Derived destructor" << endl;
    }
};

Base* ptr = new Derived();
delete ptr;  // Calls both destructors (Derived, then Base)
```

**Important**: Always make destructor virtual in base class when using polymorphism.

## This Pointer

### Definition:

Implicit pointer to the current object.

```cpp
class Student {
    int roll;
public:
    void setRoll(int roll) {
        this->roll = roll;  // Disambiguate between parameter and member
    }

    Student& setName(string name) {
        this->name = name;
        return *this;  // Return reference to current object
    }
};

// Method chaining
Student s;
s.setRoll(101).setName("John");  // Possible due to returning *this
```

### Uses:

1. Resolve name conflicts
2. Return current object
3. Pass current object to other functions
4. Check for self-assignment in copy assignment

```cpp
Student& operator=(const Student& s) {
    if(this != &s) {  // Check for self-assignment
        // Copy members
    }
    return *this;
}
```

## Static Members

### Static Data Members:

Shared by all objects of the class.

```cpp
class Counter {
    static int count;  // Declaration
public:
    Counter() { count++; }
    static int getCount() { return count; }
};

int Counter::count = 0;  // Definition (outside class)

Counter c1, c2, c3;
cout << Counter::getCount();  // 3
```

### Static Member Functions:

Can be called without creating object.

```cpp
class Math {
public:
    static int add(int a, int b) {
        return a + b;
    }
};

int sum = Math::add(5, 3);  // No object needed
```

**Restrictions:**

- Can only access static members
- No `this` pointer
- Can't be virtual
- Can't be const

## Mutable Keyword

Allows modification of member in const member function.

```cpp
class Cache {
    mutable int accessCount;  // Can be modified in const functions
    int data;

public:
    int getData() const {
        accessCount++;  // OK - mutable
        // data++;      // Error - can't modify in const function
        return data;
    }
};
```

## Friend Function

Non-member function with access to private members.

```cpp
class Box {
    int width;

    friend void printWidth(Box b);  // Friend declaration

public:
    Box(int w) : width(w) { }
};

void printWidth(Box b) {
    cout << b.width;  // Can access private member
}
```

### Friend Class:

```cpp
class A {
    int secret;
    friend class B;  // B can access private members of A
};

class B {
    void func(A &a) {
        cout << a.secret;  // OK
    }
};
```

## Const Member Functions

Functions that don't modify object state.

```cpp
class Student {
    int roll;
    string name;

public:
    int getRoll() const {  // Const member function
        // roll = 10;  // Error! Can't modify
        return roll;    // OK - read only
    }

    void setRoll(int r) {  // Non-const
        roll = r;
    }
};

const Student s(101, "John");
s.getRoll();  // OK
// s.setRoll(102);  // Error! Can't call non-const on const object
```

## Inline Functions

Suggest compiler to insert function code at call site.

```cpp
class Math {
public:
    inline int square(int x) {  // Inline keyword
        return x * x;
    }

    int cube(int x) {  // Implicitly inline (defined in class)
        return x * x * x;
    }
};
```

### Inline vs Macros:

| Feature      | Inline Function | Macro           |
| ------------ | --------------- | --------------- |
| Type safety  | Yes             | No              |
| Debugging    | Easy            | Difficult       |
| Scope        | Has scope       | No scope        |
| Side effects | Safe            | Can have issues |
| Evaluation   | Once            | Multiple times  |

**Recommendation**: Prefer inline functions over macros in C++.

## Struct vs Class

### Similarities:

- Both can have members and methods
- Both support access specifiers
- Both support inheritance

### Differences:

| Feature             | Struct     | Class                 |
| ------------------- | ---------- | --------------------- |
| Default access      | Public     | Private               |
| Inheritance default | Public     | Private               |
| Usage convention    | Plain data | Objects with behavior |

```cpp
struct Point {
    int x, y;  // Public by default
};

class Point {
    int x, y;  // Private by default
};
```

## Best Practices

1. **Encapsulation**: Keep data members private

```cpp
class Good {
private:
    int data;
public:
    int getData() const { return data; }
    void setData(int d) { data = d; }
};
```

2. **Constructor Initialization Lists**:

```cpp
Student(int r) : roll(r) { }  // Better than assignment in body
```

3. **Const Correctness**:

```cpp
int getData() const { return data; }  // Mark getters as const
```

4. **Virtual Destructor** in base classes:

```cpp
class Base {
public:
    virtual ~Base() { }
};
```

5. **Rule of Three/Five**:
   If you define one of: destructor, copy constructor, copy assignment operator, define all three (or five with move semantics).

## Common Pitfalls

1. **Forgetting to initialize**:

```cpp
class Bad {
    int *ptr;
public:
    Bad() { }  // ptr not initialized!
};
```

2. **Shallow copy issues**:

```cpp
class Array {
    int *data;
public:
    Array(int size) { data = new int[size]; }
    // Default copy constructor does shallow copy - dangerous!
    // Need custom copy constructor
};
```

3. **Memory leaks**:

```cpp
class BadClass {
    int *ptr;
public:
    BadClass() { ptr = new int; }
    // No destructor - memory leak!
};
```

4. **Calling virtual functions in constructor/destructor**:

```cpp
// Virtual function calls in constructor don't work as expected
```

## Summary

### Key Takeaways:

1. **Four Pillars** - Encapsulation, Abstraction, Inheritance, Polymorphism
2. **Access Specifiers** - private (default), protected (inheritance), public (interface)
3. **Constructors** - Default, parameterized, copy, initialization lists
4. **Destructors** - Clean up resources, virtual for base classes
5. **This Pointer** - Points to current object, enables method chaining
6. **Static Members** - Shared across all instances, accessed without objects
7. **Const Functions** - Cannot modify object state, called on const objects
8. **Inline Functions** - Compiler optimization, prefer over macros
9. **Friend Functions** - Non-member functions with private access
10. **Mutable** - Allows modification in const functions

### OOP Principles Quick Reference:

```
Encapsulation → Bundle data + methods, hide implementation
Abstraction   → Hide complexity, show essential features
Inheritance   → Code reuse through IS-A relationship
Polymorphism  → Same interface, different implementations
```

## Quick Reference

### Class Declaration:

```cpp
class MyClass {
private:         // Default for class
    int data;

protected:       // For derived classes
    int shared;

public:          // Public interface
    MyClass();                    // Constructor
    ~MyClass();                   // Destructor
    MyClass(const MyClass& obj);  // Copy constructor

    void setData(int d);          // Setter
    int getData() const;          // Getter (const)

    static int count;             // Static member
    static void func();           // Static function

    friend void friendFunc(MyClass& obj);  // Friend
};

int MyClass::count = 0;  // Static initialization
```

### Constructor Types:

```cpp
// Default
MyClass() : data(0) { }

// Parameterized
MyClass(int d) : data(d) { }

// Copy
MyClass(const MyClass& obj) : data(obj.data) { }

// Delegating (C++11)
MyClass() : MyClass(0) { }
```

### Access Specifiers in Inheritance:

```cpp
class Derived : public Base { };     // Most common
class Derived : protected Base { };  // Rare
class Derived : private Base { };    // Implementation detail
```

### This Pointer Usage:

```cpp
void setName(string name) {
    this->name = name;  // Disambiguate
}

MyClass& setData(int d) {
    data = d;
    return *this;  // Method chaining
}
```

### Static Members:

```cpp
class Counter {
    static int count;
public:
    Counter() { count++; }
    static int getCount() { return count; }
};

int Counter::count = 0;
int n = Counter::getCount();  // No object needed
```

## Related Concepts

- SOLID principles (Single Responsibility, Open/Closed, Liskov Substitution, Interface Segregation, Dependency Inversion)
- Design patterns (Singleton, Factory, Strategy, Observer)
- Templates and generic programming
- STL containers and algorithms
- Smart pointers (unique_ptr, shared_ptr)
- Move semantics and rvalue references (C++11)
- Lambda expressions (C++11)
- RAII (Resource Acquisition Is Initialization)
