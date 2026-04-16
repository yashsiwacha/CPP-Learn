# Object-Oriented Programming (OOP) in C++

## � Study Plan

**Time Needed:** 4-6 hours  
**Difficulty:** ⭐⭐⭐ (Medium-Hard)  
**Prerequisites:** Structures, functions, pointers

**What you'll learn:** Organize code using objects and classes!

---

## 🔷 Definition (Memorize This!)

```
┌──────────────────────────────────────────────────────────┐
│ OOP = Programming paradigm based on "OBJECTS"            │
│       that contain DATA (attributes) and                 │
│       CODE (methods) together                            │
│                                                          │
│ 4 Pillars:                                               │
│  • ENCAPSULATION - Bundle data & protect it              │
│  • ABSTRACTION   - Hide complexity, show essentials      │
│  • INHERITANCE   - Create classes from existing ones     │
│  • POLYMORPHISM  - One interface, many forms             │
└──────────────────────────────────────────────────────────┘
```

## 🎨 Class vs Object [Draw This!]

```
CLASS = Blueprint         OBJECTS = Instances
┌────────────┐           ┌────────────┐  ┌────────────┐
│   Car      │           │   Car1     │  │   Car2     │
│            │  creates  │ color:red  │  │ color:blue │
│ -color     │  ─────→   │ speed:80   │  │ speed:100  │
│ -speed     │           └────────────┘  └────────────┘
│ +drive()   │
└────────────┘
```

---

## Key Concepts

### 1. Four Pillars of OOP

| Pillar            | Purpose               | Mechanism                          |
| ----------------- | --------------------- | ---------------------------------- |
| **Encapsulation** | Bundle & protect data | Access specifiers (private/public) |
| **Abstraction**   | Hide complexity       | Abstract classes, interfaces       |
| **Inheritance**   | Code reuse            | Base → Derived classes             |
| **Polymorphism**  | Multiple forms        | Virtual functions, overloading     |

### 2. Access Specifiers ([AccessSpecifier.cpp](../../Module2/11_OOPS/AccessSpecifier.cpp))

| Specifier   | Accessible From              | Use Case              |
| ----------- | ---------------------------- | --------------------- |
| `private`   | Same class only              | Data hiding (default) |
| `protected` | Same class + derived classes | For inheritance       |
| `public`    | Anywhere                     | Public interface      |

**Syntax:** `class MyClass { private: int x; public: void func(); };`

### 3. Constructors ([Task3Constructor.cpp](../../Module2/11_OOPS/Task3Constructor.cpp))

**Purpose:** Initialize objects when created

| Type                | Syntax                            | When Called            |
| ------------------- | --------------------------------- | ---------------------- |
| Default             | `MyClass() { }`                   | `MyClass obj;`         |
| Parameterized       | `MyClass(int x) { }`              | `MyClass obj(10);`     |
| Copy                | `MyClass(const MyClass& obj) { }` | `MyClass obj2 = obj1;` |
| Initialization List | `MyClass(int x) : data(x) { }`    | More efficient         |

**Rules:**

- Same name as class, no return type
- Can be overloaded
- Automatically called

### 4. Destructors ([Destructors.cpp](../../Module2/11_OOPS/Destructors.cpp))

**Purpose:** Clean up when object destroyed

- Syntax: `~MyClass() { }`
- Called automatically when object goes out of scope
- Use `virtual ~MyClass()` in base classes for polymorphism
- Only one destructor per class (no parameters)

### 5. Copy Constructor ([CopyConstructor.cpp](../../Module2/11_OOPS/CopyConstructor.cpp))

**Purpose:** Create object as copy of another

- Default performs **shallow copy** (dangerous with pointers!)
- Define custom copy constructor for **deep copy**
- Syntax: `MyClass(const MyClass& other)`

### 6. This Pointer ([ThisPointer.cpp](../../Module2/11_OOPS/ThisPointer.cpp))

**Purpose:** Points to current object

**Uses:**

- Disambiguate: `this->name = name;`
- Return current object: `return *this;`
- Method chaining: `obj.setX(5).setY(10);`

### 7. Static Members ([StaticDemo.cpp](../../Module2/11_OOPS/StaticDemo.cpp))

**Static data:**

- Shared by all objects of class
- Declaration: `static int count;`
- Definition outside class: `int MyClass::count = 0;`

**Static functions:**

- Can be called without object: `MyClass::func();`
- Can only access static members
- No `this` pointer

### 8. Const Member Functions

**Purpose:** Functions that don't modify object

- Syntax: `int getData() const { return data; }`
- Can be called on const objects
- Cannot modify member variables (except mutable)

### 9. Mutable Keyword ([mutablekeyword.cpp](../../Module2/11_OOPS/mutablekeyword.cpp))

**Purpose:** Allow modification in const functions

- Syntax: `mutable int cacheCount;`
- Useful for caching, debugging counters

### 10. Inline Functions vs Macros ([InlinevsMacros.cpp](../../Module2/11_OOPS/InlinevsMacros.cpp))

| Feature        | Inline Function        | Macro                |
| -------------- | ---------------------- | -------------------- |
| Type Safety    | Yes                    | No                   |
| Debugging      | Easy                   | Difficult            |
| Syntax         | `inline int sq(int x)` | `#define SQ(x) x*x`  |
| Recommendation | Prefer for C++         | Use only when needed |

### 11. Struct vs Class ([StuctANDclass.cpp](../../Module2/11_OOPS/StuctANDclass.cpp))

| Feature        | Struct         | Class           |
| -------------- | -------------- | --------------- |
| Default Access | Public         | Private         |
| Usage          | Plain data     | Objects         |
| In C++         | Same as class! | Same as struct! |

**Note:** In C++, struct and class are identical except default access!

---

## Common Mistakes

```
┌──────────────────────────────────────────────────────────┐
│ ❌ Not initializing pointer members in constructor        │
│ ❌ Forgetting virtual destructor in base class            │
│ ❌ Shallow copy with pointer members (use deep copy)      │
│ ❌ Calling virtual functions in constructor/destructor    │
│ ❌ Not using const for functions that don't modify        │
│ ❌ Making everything public (breaks encapsulation)        │
└──────────────────────────────────────────────────────────┘
```

---

## Rule of Three

**If you define ANY of these, define ALL:**

1. Destructor: `~MyClass()`
2. Copy Constructor: `MyClass(const MyClass&)`
3. Copy Assignment: `MyClass& operator=(const MyClass&)`

**Why?** If you need custom cleanup, you likely need custom copying too!

---

## Constructor Initialization List

**Prefer this:** `MyClass(int x) : data(x) { }`  
**Over this:** `MyClass(int x) { data = x; }`

**Benefits:**

- More efficient (initialization vs assignment)
- Required for const members, references
- Required for base class initialization

---

## 🎯 Key Takeaways

1. OOP organizes code into **objects** containing data + behavior
2. **Encapsulation**: Hide data (private), expose interface (public)
3. **Constructor** initializes, **Destructor** cleans up (use virtual in base)
4. **this** pointer refers to current object, enables method chaining
5. **static** members shared by all objects, accessed without instance
6. Always define **copy constructor** when class has pointer members (deep copy)

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
