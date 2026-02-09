# Abstraction in C++

## � Study Plan

**Time Needed:** 4-5 hours  
**Difficulty:** ⭐⭐⭐ (Medium-Hard)  
**Prerequisites:** Classes, inheritance, virtual functions

**What you'll learn:** Hide complexity and define contracts!

---

## 🔷 Definition (Memorize This!)

```
┌──────────────────────────────────────────────────────────┐
│ ABSTRACTION = Hiding implementation details              │
│               & showing only ESSENTIAL features          │
│                                                          │
│ Achieved By:                                             │
│  • Abstract Classes (at least 1 pure virtual function)   │
│  • Pure Virtual Function: virtual void func() = 0;       │
│                                                          │
│ Rules:                                                   │
│  • Cannot instantiate abstract class                     │
│  • Derived class MUST implement pure virtual functions   │
│  • Use base class pointer for polymorphism               │
└──────────────────────────────────────────────────────────┘
```

## 🎨 Abstraction Concept [Draw This!]

```
Abstract Class = Contract/Interface

        Shape (Abstract)
    ┌─────────────────┐
    │ + area() = 0    │  ← Pure virtual (MUST implement)
    │ + perimeter() = 0│
    └─────────────────┘
           ↑
    ┌──────┴──────┐
    │             │
  Circle      Rectangle   ← Concrete classes
(implements)  (implements)
```

---

## Key Concepts

### 1. Abstract Classes ([Shape.cpp](../../Module2/14_Abstraction/Shape.cpp))

**Definition:** Class with at least one pure virtual function

**Syntax:**

```cpp
class Shape {
public:
    virtual double area() const = 0;  // Pure virtual
    virtual ~Shape() { }               // Virtual destructor
};
```

**Cannot instantiate:** `Shape s;` ← ERROR!

### 2. Pure Virtual Functions

**Syntax:** `virtual void func() = 0;`

**Purpose:**

- Forces derived classes to provide implementation
- Defines contract/interface
- Makes class abstract

### 3. Concrete Classes

**Definition:** Classes that implement all pure virtual functions

**Example:**

```cpp
class Circle : public Shape {
    double radius;
public:
    double area() const override {
        return 3.14159 * radius * radius;
    }
};
```

**Can instantiate:** `Circle c;` ← OK!

### 4. Polymorphism with Abstraction

**Use base class pointer:**

```cpp
Shape *s1 = new Circle(5);
Shape *s2 = new Rectangle(4, 6);

s1->area();  // Calls Circle::area()
s2->area();  // Calls Rectangle::area()
```

### 5. Virtual Destructor

**Critical:** Always make destructor virtual in abstract class!

**Why?** Ensures proper cleanup of derived objects

**Syntax:** `virtual ~Shape() { }`

---

## Common Mistakes

```
┌──────────────────────────────────────────────────────────┐
│ ❌ Trying to instantiate abstract class                   │
│ ❌ Forgetting virtual destructor in base class            │
│ ❌ Not implementing all pure virtual functions            │
│ ❌ Confusing abstraction with encapsulation               │
│ ❌ Forgetting = 0 in pure virtual function                │
└──────────────────────────────────────────────────────────┘
```

---

## Abstraction vs Encapsulation

| Aspect      | Abstraction           | Encapsulation             |
| ----------- | --------------------- | ------------------------- |
| **What**    | Hide complexity       | Bundle & protect data     |
| **How**     | Abstract classes      | Access specifiers         |
| **Focus**   | "What" to do          | "How" to protect          |
| **Level**   | Design/Interface      | Implementation            |
| **Example** | `Shape` with `area()` | Private members + getters |

**Remember:** Both hide details, but abstraction focuses on interface, encapsulation on data protection!

---

## When to Use Abstraction

**Use abstract class when:**

- Define common interface for multiple classes
- Want to enforce implementation of certain methods
- Need polymorphic behavior
- Share some implementation, but not all

**Example scenarios:**

- Shape hierarchy (Circle, Square, Triangle)
- Payment methods (CreditCard, PayPal, Bitcoin)
- Database connections (MySQL, PostgreSQL, MongoDB)

---

## Abstract vs Concrete

| Type     | Pure Virtual? | Instantiate? | Purpose               |
| -------- | ------------- | ------------ | --------------------- |
| Abstract | ≥ 1           | No           | Interface/contract    |
| Concrete | 0             | Yes          | Actual implementation |

---

## 🎯 Key Takeaways

1.  **Abstraction** hides complexity, shows only essential features
2.  **Pure virtual function** (`= 0`) makes class abstract - cannot instantiate
3.  Derived classes **must implement** all pure virtual functions
4.  Always use **virtual destructor** in abstract base class
5.  Use **base class pointer** for polymorphism: `Shape* s = new Circle();`
6.  Abstraction defines **"what"** to do, derived classes define **"how"**

        // Setter for name
        void setName(const string &shapeName) { name = shapeName; }

        // Pure virtual functions - must be implemented by derived classes
        virtual double area() const = 0;
        virtual double perimeter() const = 0;

        // Virtual destructor
        virtual ~Shape() {}

    };

// Concrete class: Circle
class Circle : public Shape {
private:
double radius;

public:
Circle(double r) : radius(r) {
setName("Circle");
}

    double area() const override {
        return PI * radius * radius;
    }

    double perimeter() const override {
        return 2 * PI * radius;
    }

};

// Concrete class: Rectangle
class Rectangle : public Shape {
private:
double length;
double width;

public:
Rectangle(double l, double w) : length(l), width(w) {
setName("Rectangle");
}

    double area() const override {
        return length * width;
    }

    double perimeter() const override {
        return 2 * (length + width);
    }

};

// Concrete class: Triangle
class Triangle : public Shape {
private:
double side1, side2, side3;

public:
Triangle(double s1, double s2, double s3)
: side1(s1), side2(s2), side3(s3) {
setName("Triangle");
}

    double area() const override {
        // Heron's formula
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double perimeter() const override {
        return side1 + side2 + side3;
    }

};

int main() {
// Polymorphism: base class pointers to derived objects
vector<unique_ptr<Shape>> shapes;

    shapes.push_back(make_unique<Circle>(5));
    shapes.push_back(make_unique<Rectangle>(4, 6));
    shapes.push_back(make_unique<Triangle>(3, 4, 5));

    // Process all shapes uniformly through abstract interface
    for(const auto &shape : shapes) {
        cout << "Shape: " << shape->getName() << endl;
        cout << "Area: " << shape->area() << endl;
        cout << "Perimeter: " << shape->perimeter() << endl;
        cout << "------------------------" << endl;
    }

    return 0;

}

````

## Key Features of Abstraction

### 1. Interface Definition:

```cpp
class Database {
public:
    virtual void connect() = 0;
    virtual void disconnect() = 0;
    virtual void executeQuery(string query) = 0;
    virtual ~Database() {}
};

// Different implementations
class MySQL : public Database {
public:
    void connect() override { /* MySQL-specific connection */ }
    void disconnect() override { /* MySQL-specific disconnect */ }
    void executeQuery(string query) override { /* Execute in MySQL */ }
};

class MongoDB : public Database {
public:
    void connect() override { /* MongoDB-specific connection */ }
    void disconnect() override { /* MongoDB-specific disconnect */ }
    void executeQuery(string query) override { /* Execute in MongoDB */ }
};
````

### 2. Polymorphic Behavior:

```cpp
void processDatabase(Database* db) {
    db->connect();
    db->executeQuery("SELECT * FROM users");
    db->disconnect();
    // Works with any Database implementation
}

Database* db1 = new MySQL();
Database* db2 = new MongoDB();
processDatabase(db1);  // Uses MySQL implementation
processDatabase(db2);  // Uses MongoDB implementation
```

### 3. Flexibility and Extensibility:

```cpp
// Easy to add new shapes without changing existing code
class Pentagon : public Shape {
private:
    double side;
public:
    Pentagon(double s) : side(s) { setName("Pentagon"); }

    double area() const override {
        return 1.72 * side * side;  // Approximate formula
    }

    double perimeter() const override {
        return 5 * side;
    }
};

// Existing code works with new shape!
shapes.push_back(make_unique<Pentagon>(5));
```

## Benefits of Abstraction

### 1. Simplification:

```cpp
// User doesn't need to know implementation details
Shape* shape = new Circle(5);
double area = shape->area();  // Simple interface
```

### 2. Code Reusability:

```cpp
void printShapeInfo(Shape* shape) {
    cout << "Area: " << shape->area() << endl;
    // Works with any shape
}
```

### 3. Maintainability:

```cpp
// Can change Circle implementation without affecting users
class Circle : public Shape {
    // Changed from storing radius to storing diameter
    double diameter;
public:
    double area() const override {
        double r = diameter / 2;
        return PI * r * r;  // Users don't know about this change
    }
};
```

### 4. Loose Coupling:

```cpp
class Application {
    Database* db;  // Depends on abstract interface, not concrete class
public:
    Application(Database* database) : db(database) {}

    void run() {
        db->connect();  // Works with any Database implementation
        // ...
    }
};
```

### 5. Testing:

```cpp
// Easy to create mock objects for testing
class MockDatabase : public Database {
public:
    void connect() override { cout << "Mock connect\n"; }
    void disconnect() override { cout << "Mock disconnect\n"; }
    void executeQuery(string query) override { cout << "Mock query\n"; }
};

// Test with mock
Database* mockDb = new MockDatabase();
Application app(mockDb);
app.run();  // Tests without real database
```

## Abstract Class Rules

### 1. Cannot Instantiate:

```cpp
Shape s;  // Error! Shape is abstract
Shape* ptr = new Circle(5);  // OK - pointer to derived object
```

### 2. Must Override Pure Virtual Functions:

```cpp
class IncompleteShape : public Shape {
    // Error! Must override area() and perimeter()
};

class CompleteShape : public Shape {
    double area() const override { return 0; }      // OK
    double perimeter() const override { return 0; } // OK
};
```

### 3. Can Have Non-Virtual Functions:

```cpp
class Shape {
public:
    virtual double area() = 0;  // Pure virtual

    void display() {  // Regular function
        cout << "Area: " << area() << endl;
    }
};
```

### 4. Can Have Data Members:

```cpp
class Shape {
protected:
    string color;

public:
    virtual double area() = 0;

    void setColor(string c) { color = c; }
    string getColor() const { return color; }
};
```

### 5. Can Have Constructors:

```cpp
class Shape {
protected:
    string name;

public:
    Shape(string n) : name(n) {}  // Constructor
    virtual double area() = 0;
};

class Circle : public Shape {
public:
    Circle(double r) : Shape("Circle"), radius(r) {}
    double area() override { return PI * radius * radius; }
private:
    double radius;
};
```

### 6. Must Have Virtual Destructor:

```cpp
class Shape {
public:
    virtual double area() = 0;
    virtual ~Shape() {}  // Virtual destructor
};

// Without virtual destructor:
Shape* s = new Circle(5);
delete s;  // Only calls Shape destructor, not Circle! (Memory leak)

// With virtual destructor:
Shape* s = new Circle(5);
delete s;  // Calls Circle destructor, then Shape destructor (Correct)
```

## Abstraction Levels

### High-Level Abstraction:

```cpp
class Vehicle {
public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void accelerate() = 0;
};
```

### Mid-Level Abstraction:

```cpp
class Car : public Vehicle {
public:
    virtual void openDoor() = 0;
    virtual void closeDoor() = 0;
    // Implements some Vehicle methods
};
```

### Low-Level (Concrete):

```cpp
class Tesla : public Car {
public:
    void start() override { /* Specific implementation */ }
    void stop() override { /* Specific implementation */ }
    void accelerate() override { /* Specific implementation */ }
    void openDoor() override { /* Specific implementation */ }
    void closeDoor() override { /* Specific implementation */ }
};
```

## Interface Segregation

### Problem - Fat Interface:

```cpp
class Worker {
public:
    virtual void work() = 0;
    virtual void eat() = 0;
    virtual void sleep() = 0;
};

class Robot : public Worker {
    void work() override { /* OK */ }
    void eat() override { /* Robots don't eat! */ }
    void sleep() override { /* Robots don't sleep! */ }
};
```

### Solution - Segregated Interfaces:

```cpp
class Workable {
public:
    virtual void work() = 0;
};

class Eatable {
public:
    virtual void eat() = 0;
};

class Sleepable {
public:
    virtual void sleep() = 0;
};

class Human : public Workable, public Eatable, public Sleepable {
    void work() override { /* Implementation */ }
    void eat() override { /* Implementation */ }
    void sleep() override { /* Implementation */ }
};

class Robot : public Workable {
    void work() override { /* Implementation */ }
    // Only implements what it needs
};
```

## Design Patterns Using Abstraction

### 1. Strategy Pattern:

```cpp
class SortStrategy {
public:
    virtual void sort(vector<int>& arr) = 0;
    virtual ~SortStrategy() {}
};

class BubbleSort : public SortStrategy {
    void sort(vector<int>& arr) override { /* Bubble sort */ }
};

class QuickSort : public SortStrategy {
    void sort(vector<int>& arr) override { /* Quick sort */ }
};

class Sorter {
    SortStrategy* strategy;
public:
    void setStrategy(SortStrategy* s) { strategy = s; }
    void sort(vector<int>& arr) { strategy->sort(arr); }
};
```

### 2. Factory Pattern:

```cpp
class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class ShapeFactory {
public:
    static Shape* createShape(string type) {
        if(type == "circle") return new Circle();
        if(type == "rectangle") return new Rectangle();
        return nullptr;
    }
};
```

## Best Practices

### 1. Provide Virtual Destructor:

```cpp
class Base {
public:
    virtual ~Base() {}  // Always virtual
};
```

### 2. Use override Keyword:

```cpp
class Derived : public Base {
    void method() override { }  // Catches errors
};
```

### 3. Document Interface:

```cpp
/**
 * Abstract base class for all shapes.
 * Derived classes must implement area() and perimeter().
 */
class Shape {
public:
    /**
     * Calculate the area of the shape.
     * @return Area in square units
     */
    virtual double area() const = 0;
};
```

### 4. Keep Interface Minimal:

```cpp
// Good - minimal interface
class Reader {
public:
    virtual string read() = 0;
};

// Bad - too many methods
class Reader {
public:
    virtual string read() = 0;
    virtual void open() = 0;
    virtual void close() = 0;
    virtual bool isReady() = 0;
    // Too many implementation details exposed
};
```

### 5. Use Smart Pointers:

```cpp
vector<unique_ptr<Shape>> shapes;
shapes.push_back(make_unique<Circle>(5));
// Automatic memory management
```

## Common Pitfalls

### 1. Forgetting Virtual Destructor:

```cpp
class Base {
public:
    virtual void method() = 0;
    // Missing: virtual ~Base() {}
};

Base* ptr = new Derived();
delete ptr;  // Undefined behavior - only Base destructor called
```

### 2. Incomplete Implementation:

```cpp
class BadCircle : public Shape {
    // Error! Forgot to implement area()
    double perimeter() const override { return 0; }
};
```

### 3. Slicing Problem:

```cpp
void process(Shape s) {  // Pass by value - slicing occurs!
    s.area();  // Calls Shape::area(), not derived version
}

// Solution: Pass by reference or pointer
void process(Shape& s) {  // Correct
    s.area();
}
```

## Summary

### Key Takeaways:

1. **Hide Complexity** - Show only essential features, hide implementation details
2. **Pure Virtual Functions** - Use `= 0` to create abstract methods
3. **Abstract Classes** - Cannot be instantiated, serve as interfaces
4. **Virtual Destructor** - Always provide virtual destructor in abstract classes
5. **Override Keyword** - Use to catch mistakes at compile-time
6. **Polymorphism** - Base pointers can reference derived objects
7. **Interface Segregation** - Keep interfaces minimal and focused
8. **Derived Must Implement** - All pure virtual functions must be overridden
9. **Design Patterns** - Enable Strategy, Factory, Template Method patterns
10. **Flexibility** - Easy to add new implementations without changing existing code

### Abstraction vs Encapsulation:

| Aspect    | Abstraction        | Encapsulation           |
| --------- | ------------------ | ----------------------- |
| Focus     | Hide complexity    | Bundle and protect data |
| Purpose   | Simplify interface | Data security           |
| Mechanism | Abstract classes   | Access specifiers       |
| Level     | Design level       | Implementation level    |
| User sees | What to do         | Controlled interface    |

## Quick Reference

### Abstract Class:

```cpp
class AbstractClass {
public:
    // Pure virtual function
    virtual void method() = 0;

    // Virtual destructor (required)
    virtual ~AbstractClass() {}

    // Can have regular methods
    void helper() { }
};
```

### Implementation:

```cpp
class ConcreteClass : public AbstractClass {
public:
    // Must override pure virtual
    void method() override {
        // Implementation
    }
};
```

### Usage Pattern:

```cpp
// Cannot instantiate abstract class
// AbstractClass obj;  // ERROR

// Use pointers/references
AbstractClass* ptr = new ConcreteClass();
ptr->method();  // Polymorphic call

// Smart pointers
unique_ptr<AbstractClass> uptr =
    make_unique<ConcreteClass>();
```

### Interface Pattern:

```cpp
// Pure interface
class Interface {
public:
    virtual void operation() = 0;
    virtual ~Interface() {}
};

// Multiple interfaces
class MyClass : public Interface1,
                public Interface2 {
    void operation() override { }
    // Implement all pure virtuals
};
```

### Common Abstract Base Classes:

```cpp
// Shape hierarchy
class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual ~Shape() {}
};

// Database interface
class Database {
public:
    virtual void connect() = 0;
    virtual void query(string sql) = 0;
    virtual ~Database() {}
};

// Strategy interface
class Strategy {
public:
    virtual void execute() = 0;
    virtual ~Strategy() {}
};
```

## Related Concepts

- Polymorphism and dynamic binding
- Encapsulation and data hiding
- Inheritance hierarchies
- Interface design principles
- SOLID principles (especially ISP, DIP)
- Design patterns (Strategy, Factory, Template Method)
- Virtual functions and vtables
- Runtime polymorphism
