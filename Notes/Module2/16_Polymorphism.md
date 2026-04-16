# 16. Polymorphism in C++

## Overview

Polymorphism is one of the core concepts of Object-Oriented Programming (OOP) that allows objects of different classes to be treated as objects of a common base class. The word "polymorphism" means "many forms" - it allows one interface to be used for a general class of actions.

## Types of Polymorphism

### 1. Compile-Time Polymorphism (Static Polymorphism)

Resolved during compilation.

#### Function Overloading

Multiple functions with the same name but different parameters.

```cpp
class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};
```

#### Operator Overloading

Giving special meaning to operators for user-defined types.

```cpp
class Complex {
    float real, imag;
public:
    Complex operator + (Complex const &obj) {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
};
```

### 2. Runtime Polymorphism (Dynamic Polymorphism)

Resolved during runtime using virtual functions.

#### Virtual Functions

Functions declared with `virtual` keyword in base class.

```cpp
class Shape {
public:
    virtual void draw() {
        cout << "Drawing Shape" << endl;
    }

    virtual double area() = 0;  // Pure virtual function
};

class Circle : public Shape {
    double radius;
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }

    double area() override {
        return 3.14159 * radius * radius;
    }
};
```

## Key Concepts

### Virtual Functions

- Declared with `virtual` keyword in base class
- Can be overridden in derived classes
- Enable runtime polymorphism
- Use `override` keyword in C++11+ for clarity

### Pure Virtual Functions

```cpp
virtual void functionName() = 0;
```

- Makes a class abstract
- Must be implemented by derived classes
- Cannot instantiate abstract classes

### Virtual Destructors

```cpp
class Base {
public:
    virtual ~Base() {
        // Cleanup code
    }
};
```

- Always make destructors virtual in base classes
- Ensures proper cleanup of derived class objects
- Prevents memory leaks

## Function Overriding Rules

1. Function signature must be identical
2. Return type should be same (or covariant)
3. Access specifier can be different but usually kept same
4. Base class function should be virtual
5. Cannot override static functions

## Virtual Table (vtable)

- Compiler creates a virtual table for classes with virtual functions
- Contains function pointers to virtual functions
- Each object has a vptr (virtual pointer) pointing to vtable
- Used for runtime function binding

## Abstract Classes

```cpp
class AbstractClass {
public:
    virtual void pureVirtualFunc() = 0;  // Pure virtual

    virtual void virtualFunc() {         // Virtual
        // Default implementation
    }

    void normalFunc() {                  // Normal
        // Implementation
    }
};
```

Characteristics:

- Has at least one pure virtual function
- Cannot create objects directly
- Used as interface/base class
- Derived classes must implement pure virtual functions

## Best Practices

1. **Use virtual destructors** in base classes with virtual functions
2. **Use `override` keyword** to catch errors at compile time
3. **Use `final` keyword** to prevent further overriding
4. **Prefer interfaces** (pure virtual functions) for flexibility
5. **Avoid calling virtual functions** in constructors/destructors
6. **Use smart pointers** with polymorphic objects

## Common Patterns

### Strategy Pattern

```cpp
class Strategy {
public:
    virtual void execute() = 0;
};

class Context {
    Strategy* strategy;
public:
    void setStrategy(Strategy* s) { strategy = s; }
    void executeStrategy() { strategy->execute(); }
};
```

### Factory Pattern

```cpp
class Product {
public:
    virtual void operation() = 0;
};

class Factory {
public:
    static Product* createProduct(string type);
};
```

## Performance Considerations

- Virtual function calls have slight overhead (vtable lookup)
- Inline optimization not possible for virtual functions
- Use only when runtime polymorphism is needed
- Consider compile-time polymorphism (templates) for performance-critical code

## Common Pitfalls

1. **Slicing Problem**: Assigning derived object to base class object by value
2. **Forgetting virtual destructor**: Leads to memory leaks
3. **Calling virtual functions in constructor**: Doesn't call derived version
4. **Not using override keyword**: Miss spelling errors in function names

## Example Use Cases

- **Graphics Systems**: Different shapes with common interface
- **GUI Frameworks**: Event handlers, widgets
- **Game Development**: Character classes, AI behaviors
- **Plugin Systems**: Dynamic loading of functionality
- **Database Drivers**: Common interface for different databases

## Related Concepts

- Inheritance
- Abstract Classes
- Interfaces
- RTTI (Run-Time Type Information)
- Dynamic Binding
- Late Binding

## Summary

Polymorphism provides:

- **Flexibility**: Write code that works with base class references
- **Extensibility**: Add new derived classes without changing existing code
- **Maintainability**: Single interface for related classes
- **Code Reusability**: Share common interface across types

It's a powerful feature that enables designing flexible and extensible systems through abstraction and runtime behavior selection.
