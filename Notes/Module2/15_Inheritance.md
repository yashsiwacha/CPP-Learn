# Inheritance in C++

## � Study Plan

**Time Needed:** 6-8 hours  
**Difficulty:** ⭐⭐⭐⭐ (Hard)  
**Prerequisites:** Classes, polymorphism, virtual functions

**What you'll learn:** Create classes from existing classes!

---

## 🔷 Definition (Memorize This!)

```
┌──────────────────────────────────────────────────────────┐
│ INHERITANCE = Mechanism where a class DERIVES            │
│               properties from another class              │
│                                                          │
│ Terminology:                                             │
│  • Base/Parent/Super Class   - Original class            │
│  • Derived/Child/Sub Class   - New class                 │
│                                                          │
│ Types:                                                   │
│  1. Single      - A → B                                  │
│  2. Multilevel  - A → B → C                              │
│  3. Multiple    - A, B → C                               │
│  4. Hierarchical - A → B, C, D                           │
│  5. Hybrid      - Combination                            │
└──────────────────────────────────────────────────────────┘
```

## 🎨 Inheritance Hierarchy [Draw This!]

```
Single:            Multilevel:       Hierarchical:
  Animal              Animal             Animal
    ↓                   ↓                  ↓
   Dog                 Mammal         ┌───┼───┐
                        ↓            Dog  Cat Bird
                       Dog

Multiple:          Diamond Problem (Virtual):
 Terrestrial         Animal
    ↘                ↙  ↘
     Animal        Land  Water
    ↗              ↘    ↙
  Aquatic           Amphibian
```

---

## Key Concepts

### 1. Single Inheritance ([SingleInheritance.cpp](../../Module2/15_Inheritance/SingleInheritance.cpp))

**Most common type:** One base, one derived

**Syntax:** `class Derived : public Base { };`

**Example:**

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
d.eat();   // Inherited
d.bark();  // Own method
```

### 2. Multilevel Inheritance ([MultiLevelInheritance.cpp](../../Module2/15_Inheritance/MultiLevelInheritance.cpp))

**Chain of inheritance:** A → B → C

**Example:**

```cpp
class Animal { };
class Mammal : public Animal { };
class Dog : public Mammal { };
// Dog inherits from Mammal AND Animal
```

**See also:** [DocumentMultilevel.cpp](../../Module2/15_Inheritance/DocumentMultilevel.cpp)

### 3. Hierarchical Inheritance ([HierachicalInhertance.cpp](../../Module2/15_Inheritance/HierachicalInhertance.cpp))

**One parent, multiple children:** A → B, C, D

**Example:**

```cpp
class Animal { };
class Dog : public Animal { };
class Cat : public Animal { };
class Bird : public Animal { };
// Multiple classes inherit from Animal
```

### 4. Multiple Inheritance

**Multiple parents, one child:** A, B → C

**Example:**

```cpp
class Terrestrial { };
class Aquatic { };
class Amphibian : public Terrestrial, public Aquatic { };
```

**⚠️ Warning:** Can cause diamond problem!

### 5. Diamond Problem ([DiamondInheritance.cpp](../../Module2/15_Inheritance/DiamondInheritance.cpp))

**Problem:** Ambiguous member access when two paths to same base

**Solution:** Use **virtual inheritance**

**Syntax:**

```cpp
class Animal { int age; };
class Land : virtual public Animal { };
class Water : virtual public Animal { };
class Amphibian : public Land, public Water { };
// Only ONE copy of Animal, no ambiguity!
```

### 6. Access Control in Inheritance

| Base Access | Public Inheritance | Protected Inheritance | Private Inheritance |
| ----------- | ------------------ | --------------------- | ------------------- |
| Public      | Public             | Protected             | Private             |
| Protected   | Protected          | Protected             | Private             |
| Private     | Not accessible     | Not accessible        | Not accessible      |

**Most common:** `class Derived : public Base { };` (public inheritance)

### 7. Constructor and Destructor Order

**Construction:** Base → Derived (top to bottom)  
**Destruction:** Derived → Base (bottom to top)

**Example:**

```cpp
class Base {
public:
    Base() { cout << "Base constructor\n"; }
    ~Base() { cout << "Base destructor\n"; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived constructor\n"; }
    ~Derived() { cout << "Derived destructor\n"; }
};

Derived d;
// Output:
// Base constructor
// Derived constructor
// Derived destructor
// Base destructor
```

### 8. Virtual Destructor

**Critical:** Always make base class destructor virtual!

**Why?** Ensures proper cleanup when deleting derived object via base pointer

**Syntax:**

```cpp
class Base {
public:
    virtual ~Base() { }
};
```

### 9. Member Access

**protected:** Accessible in derived classes (use for inheritance)  
**private:** Not accessible in derived classes  
**public:** Accessible everywhere

---

## Common Mistakes

```
┌──────────────────────────────────────────────────────────┐
│ ❌ Diamond problem without virtual inheritance            │
│ ❌ Forgetting virtual destructor in base class            │
│ ❌ Using private inheritance by default                   │
│ ❌ Not calling base constructor explicitly                │
│ ❌ Confusing IS-A (inheritance) with HAS-A (composition)  │
└──────────────────────────────────────────────────────────┘
```

---

## IS-A vs HAS-A

| Relationship | Use         | Example          |
| ------------ | ----------- | ---------------- |
| **IS-A**     | Inheritance | Dog IS-A Animal  |
| **HAS-A**    | Composition | Car HAS-A Engine |

**Rule:** Only use inheritance for true IS-A relationships!

---

## Inheritance Types Summary

| Type         | Structure           | Use Case                        |
| ------------ | ------------------- | ------------------------------- |
| Single       | A → B               | Most common, simple             |
| Multilevel   | A → B → C           | Deep hierarchies                |
| Hierarchical | A → B, C, D         | Common parent, diverse children |
| Multiple     | A, B → C            | Rare, careful with diamond      |
| Diamond      | Virtual inheritance | Resolve ambiguity               |

---

## Constructor Chaining

**Initialize base class first:**

**Syntax:** `Derived() : Base(args) { }`

**Example:**

```cpp
class Base {
    int x;
public:
    Base(int val) : x(val) { }
};

class Derived : public Base {
    int y;
public:
    Derived(int a, int b) : Base(a), y(b) { }
};
```

---

## 🎯 Key Takeaways

1. **Inheritance** enables code reuse through IS-A relationships
2. **Types:** Single (most common), Multilevel, Hierarchical, Multiple, Diamond
3. Use **virtual inheritance** to solve diamond problem
4. Always use **virtual destructor** in base classes
5. **public inheritance** most common (keeps base class interface public)
6. Construction order: **Base → Derived**; Destruction: **Derived → Base**

### 2. Multiple Inheritance

One derived class inherits from multiple base classes.

```
    Printable    Savable
         \        /
          Document
```

```cpp
// INTERFACE 1
class Printable {
public:
    virtual void print() const = 0;
};

// INTERFACE 2
class Savable {
public:
    virtual void save() const = 0;
};

// DERIVED CLASS (implements both interfaces)
class Document : public Printable, public Savable {
    string content;
public:
    void print() const override {
        cout << "Printing: " << content << endl;
    }

    void save() const override {
        cout << "Saving: " << content << endl;
    }
};

Document doc("Report");
doc.print();  // From Printable
doc.save();   // From Savable
```

**Key Points:**

- Inherit from multiple base classes separated by commas
- Useful for implementing multiple interfaces
- Can lead to ambiguity (resolved by scope resolution)
- Watch for diamond problem

### 3. Multilevel Inheritance

Inheritance chain through multiple levels (grandparent → parent → child).

```
    Vehicle (Level 1)
       ↓
    Car (Level 2)
       ↓
    ElectricCar (Level 3)
```

```cpp
// LEVEL 1: Base
class Vehicle {
protected:
    string make;
public:
    Vehicle(string m) : make(m) {}
};

// LEVEL 2: Intermediate
class Car : public Vehicle {
protected:
    int doors;
public:
    Car(string m, int d) : Vehicle(m), doors(d) {}
};

// LEVEL 3: Derived
class ElectricCar : public Car {
    double batteryCapacity;
public:
    ElectricCar(string m, int d, double battery)
        : Car(m, d), batteryCapacity(battery) {}
    // Inherits from both Car and Vehicle
};

ElectricCar tesla("Tesla", 4, 100.0);
// Has access to: make (Vehicle), doors (Car), batteryCapacity (own)
```

**Constructor Chaining:**

```
Vehicle() → Car() → ElectricCar()
```

**Key Points:**

- Forms a hierarchy chain
- Each level adds specific functionality
- Constructor calls propagate up the hierarchy
- Most-derived class controls initialization
- Protected members accessible through levels

### 4. Hierarchical Inheritance

Multiple derived classes inherit from single base class.

```
        Shape (Base)
       /   |   \
   Circle Square Rectangle
```

```cpp
// BASE CLASS
class Shape {
protected:
    string name;
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

// DERIVED CLASS 1
class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) { name = "Circle"; }
    double area() const override {
        return 3.14 * radius * radius;
    }
    double perimeter() const override {
        return 2 * 3.14 * radius;
    }
};

// DERIVED CLASS 2
class Square : public Shape {
    double side;
public:
    Square(double s) : side(s) { name = "Square"; }
    double area() const override {
        return side * side;
    }
    double perimeter() const override {
        return 4 * side;
    }
};

// DERIVED CLASS 3
class Rectangle : public Shape {
    double length, width;
public:
    Rectangle(double l, double w)
        : length(l), width(w) { name = "Rectangle"; }
    double area() const override {
        return length * width;
    }
    double perimeter() const override {
        return 2 * (length + width);
    }
};
```

**Key Points:**

- One parent, multiple children
- Each child shares common base features
- Children add their specific implementation
- Excellent for polymorphism
- Common base interface for different types

### 5. Hybrid Inheritance

Combination of two or more inheritance types.

```
        Device
       /      \
    Phone    Camera
       \      /
      Smartphone
```

**Leads to Diamond Problem** (see below)

## Diamond Problem & Virtual Inheritance

### The Problem:

When a class inherits from two classes that both inherit from the same base class:

```
        Device
       /      \
    Phone    Camera
       \      /
      Smartphone
```

**Without virtual inheritance:**

- Smartphone has TWO copies of Device
- Ambiguous member access
- Data duplication
- Memory waste

### The Solution: Virtual Inheritance

```cpp
// BASE CLASS
class Device {
protected:
    string deviceName;
    int deviceId;
public:
    Device(string name = "Unknown", int id = 0)
        : deviceName(name), deviceId(id) {
        cout << "Device Constructor" << endl;
    }
};

// INTERMEDIATE CLASS 1 - Uses 'virtual' keyword
class Phone : virtual public Device {
protected:
    string phoneNumber;
public:
    Phone(string name, int id, string number)
        : Device(name, id), phoneNumber(number) {
        cout << "Phone Constructor" << endl;
    }

    void makeCall(string num) const {
        cout << "Calling " << num << endl;
    }
};

// INTERMEDIATE CLASS 2 - Uses 'virtual' keyword
class Camera : virtual public Device {
protected:
    int megapixels;
public:
    Camera(string name, int id, int mp)
        : Device(name, id), megapixels(mp) {
        cout << "Camera Constructor" << endl;
    }

    void takePhoto() const {
        cout << "Taking photo with " << megapixels << "MP" << endl;
    }
};

// MOST-DERIVED CLASS
class Smartphone : public Phone, public Camera {
    string operatingSystem;
public:
    // MUST explicitly initialize virtual base (Device)
    Smartphone(string name, int id, string number, int mp, string os)
        : Device(name, id),        // ONLY this call executes
          Phone(name, id, number), // Device() call ignored
          Camera(name, id, mp),    // Device() call ignored
          operatingSystem(os) {
        cout << "Smartphone Constructor" << endl;
    }

    void useFeatures() const {
        cout << "Device: " << deviceName << endl;  // No ambiguity!
        cout << "Phone: " << phoneNumber << endl;
        cout << "Camera: " << megapixels << "MP" << endl;
        cout << "OS: " << operatingSystem << endl;
    }
};

Smartphone phone("Samsung", 12345, "555-1234", 108, "Android");
phone.makeCall("555-9999");     // From Phone
phone.takePhoto();              // From Camera
cout << phone.getDeviceName();  // From Device - No ambiguity!
```

### Constructor Call Order with Virtual Inheritance:

```
1. Device (virtual base - constructed FIRST)
2. Phone (left parent)
3. Camera (right parent)
4. Smartphone (most-derived)
```

### Destructor Call Order:

```
Reverse of construction:
1. Smartphone
2. Camera
3. Phone
4. Device (virtual base - destroyed LAST)
```

### Key Rules:

1. **Use `virtual` keyword** in intermediate classes:

   ```cpp
   class Phone : virtual public Device
   class Camera : virtual public Device
   ```

2. **Most-derived class initializes virtual base**:

   ```cpp
   Smartphone(...) : Device(...), Phone(...), Camera(...) { }
   ```

3. **Only ONE instance** of virtual base class exists

4. **No ambiguity** in member access

5. **Memory efficient** - shared virtual base

## Access Specifiers in Inheritance

### Syntax:

```cpp
class Derived : <access-specifier> Base {
    // ...
};
```

### Types:

#### 1. Public Inheritance (Most Common)

```cpp
class Base {
public:
    int pub;
protected:
    int prot;
private:
    int priv;
};

class Derived : public Base {
    // pub    → public
    // prot   → protected
    // priv   → not accessible
};
```

**Use Case:** "IS-A" relationship (Student IS-A Person)

#### 2. Protected Inheritance

```cpp
class Derived : protected Base {
    // pub    → protected
    // prot   → protected
    // priv   → not accessible
};
```

**Use Case:** Implementation detail (rare in practice)

#### 3. Private Inheritance

```cpp
class Derived : private Base {
    // pub    → private
    // prot   → private
    // priv   → not accessible
};
```

**Use Case:** Implementation inheritance (composition often better)

### Access Table:

| Base Member | Public Inheritance | Protected Inheritance | Private Inheritance |
| ----------- | ------------------ | --------------------- | ------------------- |
| Public      | Public             | Protected             | Private             |
| Protected   | Protected          | Protected             | Private             |
| Private     | Not Accessible     | Not Accessible        | Not Accessible      |

## Protected Access Specifier

### Purpose:

Provides middle ground between `public` and `private` for inheritance.

```cpp
class Person {
protected:  // Accessible in derived classes
    string name;
    int age;
private:    // Not accessible in derived classes
    string ssn;
public:     // Accessible everywhere
    void setName(string n) { name = n; }
};

class Student : public Person {
public:
    void display() {
        cout << name;  // OK - protected member accessible
        cout << age;   // OK - protected member accessible
        // cout << ssn;  // ERROR - private member not accessible
    }
};
```

**When to Use:**

- Data needed by derived classes
- Still want to hide from outside world
- Enable derived class customization

## Constructor and Destructor in Inheritance

### Constructor Rules:

1. **Base class constructor called first**
2. **Then derived class constructor**
3. **Use initialization list to pass parameters**

```cpp
class Base {
public:
    Base(int x) {
        cout << "Base Constructor: " << x << endl;
    }
};

class Derived : public Base {
public:
    Derived(int x, int y) : Base(x) {  // Call base constructor
        cout << "Derived Constructor: " << y << endl;
    }
};

Derived d(10, 20);
// Output:
// Base Constructor: 10
// Derived Constructor: 20
```

### Destructor Rules:

1. **Derived class destructor called first**
2. **Then base class destructor**
3. **Automatic - no explicit call needed**

```cpp
class Base {
public:
    ~Base() {
        cout << "Base Destructor" << endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        cout << "Derived Destructor" << endl;
    }
};

{
    Derived d;
}  // Object destroyed here
// Output:
// Derived Destructor
// Base Destructor
```

### Order Summary:

**Construction:** Base → Derived  
**Destruction:** Derived → Base

## Method Overriding

### Definition:

Derived class provides its own implementation of base class method.

```cpp
class Animal {
public:
    virtual void makeSound() {
        cout << "Some generic sound" << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {  // Override base implementation
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Meow!" << endl;
    }
};

Animal* a1 = new Dog();
Animal* a2 = new Cat();
a1->makeSound();  // "Woof!" - polymorphism in action
a2->makeSound();  // "Meow!"
```

### Requirements for Overriding:

1. Base class method must be `virtual`
2. Same function signature (name + parameters)
3. Use `override` keyword (C++11) for safety
4. Return type must match (or be covariant)

### `override` Keyword Benefits:

```cpp
class Base {
public:
    virtual void func(int x) { }
};

class Derived : public Base {
public:
    // Compiler catches mistakes
    void func(int x) override { }     // OK
    // void func(double x) override { }  // ERROR - not overriding!
};
```

## Calling Base Class Methods

### Using Scope Resolution Operator:

```cpp
class Base {
public:
    void display() {
        cout << "Base display" << endl;
    }
};

class Derived : public Base {
public:
    void display() {
        Base::display();  // Call base version
        cout << "Derived display" << endl;
    }
};

Derived d;
d.display();
// Output:
// Base display
// Derived display
```

### Common Use Cases:

1. **Extend base behavior** (add to, not replace)
2. **Reuse base implementation** (avoid duplication)
3. **Access hidden base members**

## Polymorphism Through Inheritance

### Runtime Polymorphism:

```cpp
class Shape {
public:
    virtual void draw() { cout << "Drawing Shape" << endl; }
    virtual ~Shape() { }
};

class Circle : public Shape {
public:
    void draw() override { cout << "Drawing Circle" << endl; }
};

class Square : public Shape {
public:
    void draw() override { cout << "Drawing Square" << endl; }
};

// Polymorphic behavior
vector<Shape*> shapes;
shapes.push_back(new Circle());
shapes.push_back(new Square());

for(Shape* s : shapes) {
    s->draw();  // Calls appropriate derived class method
}
// Output:
// Drawing Circle
// Drawing Square
```

**Key Requirements:**

- Base class pointer/reference
- Virtual functions in base class
- Override in derived classes

## Abstract Base Classes in Inheritance

### Pure Virtual Functions:

```cpp
class Shape {
public:
    // Pure virtual - must be implemented by derived classes
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    virtual ~Shape() { }
};

// Cannot instantiate: Shape s;  // ERROR!

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) { }

    // Must implement pure virtual functions
    double area() const override {
        return 3.14159 * radius * radius;
    }

    double perimeter() const override {
        return 2 * 3.14159 * radius;
    }
};

Circle c(5.0);  // OK - concrete class
```

**Benefits:**

- Enforce interface contract
- Cannot instantiate abstract class
- Clear design intent
- Polymorphism foundation

## Complete Practical Example: Game Characters ([Character.cpp](../../Module2/15_Inheritance/Character.cpp))

### Combining Encapsulation, Abstraction, and Inheritance:

This example demonstrates all OOP principles working together:

```cpp
// Abstract Base Class - Character
class Character {
private:
    int health;
    int mana;
    static const int MAX_HEALTH = 100;
    static const int MAX_MANA = 100;

public:
    Character(int h, int m) {
        setHealth(h);
        setMana(m);
    }

    virtual ~Character() {}  // Virtual destructor

    // ENCAPSULATION: Validated setters
    void setHealth(int h) {
        if (h < 0) health = 0;
        else if (h > MAX_HEALTH) health = MAX_HEALTH;
        else health = h;
    }

    void setMana(int m) {
        if (m < 0) mana = 0;
        else if (m > MAX_MANA) mana = MAX_MANA;
        else mana = m;
    }

    // Getters
    int getHealth() const { return health; }
    int getMana() const { return mana; }

    // ABSTRACTION: Pure virtual function
    virtual void attack() = 0;
};

// INHERITANCE: Derived Class - Warrior
class Warrior : public Character {
public:
    Warrior(int health, int mana) : Character(health, mana) {}

    void attack() override {
        cout << "Warrior attacks with a powerful sword strike!" << endl;
    }
};

// INHERITANCE: Derived Class - Mage
class Mage : public Character {
public:
    Mage(int health, int mana) : Character(health, mana) {}

    void attack() override {
        if (getMana() > 0) {
            cout << "Mage casts a fireball spell!" << endl;
        } else {
            cout << "Mage is out of mana!" << endl;
        }
    }
};

// POLYMORPHISM: Using base class pointers
int main() {
    Warrior warrior(80, 20);
    Mage mage(50, 90);

    // Polymorphic container
    vector<Character*> characters;
    characters.push_back(&warrior);
    characters.push_back(&mage);
    characters.push_back(new Warrior(90, 30));
    characters.push_back(new Mage(60, 100));

    // Polymorphic behavior
    for (size_t i = 0; i < characters.size(); i++) {
        characters[i]->attack();
    }

    // Cleanup
    delete characters[2];
    delete characters[3];

    return 0;
}
```

**Key Features Demonstrated:**

- ✅ **Encapsulation**: Private data with validated setters
- ✅ **Abstraction**: Pure virtual `attack()` function
- ✅ **Inheritance**: Warrior and Mage inherit from Character
- ✅ **Polymorphism**: Base class pointers call derived class methods
- ✅ **Validation**: Input bounds checking (0-100 for health/mana)
- ✅ **Virtual Destructor**: Proper cleanup through base pointer

## Common Patterns and Use Cases

### 1. Template Method Pattern:

```cpp
class Game {
public:
    void play() {  // Template method
        initialize();
        startPlay();
        endPlay();
    }
protected:
    virtual void initialize() = 0;
    virtual void startPlay() = 0;
    virtual void endPlay() = 0;
};

class Cricket : public Game {
protected:
    void initialize() override { cout << "Cricket Game Initialized" << endl; }
    void startPlay() override { cout << "Cricket Game Started" << endl; }
    void endPlay() override { cout << "Cricket Game Finished" << endl; }
};
```

### 2. Strategy Pattern:

```cpp
class SortStrategy {
public:
    virtual void sort(vector<int>& data) = 0;
    virtual ~SortStrategy() { }
};

class QuickSort : public SortStrategy {
public:
    void sort(vector<int>& data) override {
        // Quick sort implementation
    }
};

class MergeSort : public SortStrategy {
public:
    void sort(vector<int>& data) override {
        // Merge sort implementation
    }
};
```

### 3. Interface Implementation:

```cpp
// Interface pattern using abstract class
class Drawable {
public:
    virtual void draw() = 0;
    virtual ~Drawable() { }
};

class Clickable {
public:
    virtual void onClick() = 0;
    virtual ~Clickable() { }
};

class Button : public Drawable, public Clickable {
public:
    void draw() override { /* draw button */ }
    void onClick() override { /* handle click */ }
};
```

## Best Practices

### 1. Prefer Composition Over Inheritance:

```cpp
// ❌ Poor: Using inheritance for code reuse
class Stack : public vector<int> {
    // Exposes all vector methods - breaking encapsulation
};

// ✅ Better: Using composition
class Stack {
    vector<int> data;  // Has-a relationship
public:
    void push(int x) { data.push_back(x); }
    int pop() { int val = data.back(); data.pop_back(); return val; }
};
```

### 2. Always Use Virtual Destructors:

```cpp
class Base {
public:
    virtual ~Base() { }  // ✅ ALWAYS virtual in base class
};

class Derived : public Base {
    int* ptr;
public:
    ~Derived() { delete ptr; }  // Will be called through base pointer
};

Base* b = new Derived();
delete b;  // Correctly calls Derived destructor, then Base
```

### 3. Use `override` Keyword:

```cpp
class Base {
public:
    virtual void func(int x) { }
};

class Derived : public Base {
public:
    void func(int x) override { }  // ✅ Compiler verifies override
};
```

### 4. Initialize Base Class Properly:

```cpp
class Derived : public Base {
public:
    // ✅ Use initialization list
    Derived(int x, int y) : Base(x), derivedMember(y) { }

    // ❌ Avoid: Base(); derivedMember = y;
};
```

### 5. Keep Inheritance Hierarchies Shallow:

```cpp
// ✅ Good: 2-3 levels max
Vehicle → Car → SportsCar

// ❌ Poor: Deep hierarchies are hard to maintain
A → B → C → D → E → F → G
```

### 6. Design for Extension:

```cpp
class Base {
protected:
    // Protected for derived class use
    virtual void customBehavior() { }

public:
    void templateMethod() {
        // Fixed algorithm
        step1();
        customBehavior();  // Extension point
        step2();
    }
};
```

## Common Pitfalls and Solutions

### 1. Slicing Problem:

```cpp
class Base {
public:
    int x;
};

class Derived : public Base {
public:
    int y;
};

// ❌ Problem: Object slicing
Derived d;
d.x = 10;
d.y = 20;

Base b = d;  // Slicing! y is lost
cout << b.x;  // 10 (OK)
// cout << b.y;  // ERROR - y doesn't exist in Base

// ✅ Solution: Use pointers/references
Base* ptr = &d;  // No slicing
Base& ref = d;   // No slicing
```

### 2. Forgetting Virtual Destructor:

```cpp
// ❌ Problem
class Base {
public:
    ~Base() { }  // NOT virtual
};

class Derived : public Base {
    int* data;
public:
    Derived() { data = new int[100]; }
    ~Derived() { delete[] data; }  // Never called!
};

Base* b = new Derived();
delete b;  // Memory leak! Only ~Base() called

// ✅ Solution
class Base {
public:
    virtual ~Base() { }  // Virtual destructor
};
```

### 3. Hidden Base Methods:

```cpp
class Base {
public:
    void func(int x) { }
};

class Derived : public Base {
public:
    void func(double x) { }  // Hides Base::func(int)
};

Derived d;
d.func(10);    // Calls func(double) - int converted!
// d.func(10);    // ERROR if expecting Base::func(int)

// ✅ Solution: Use 'using' declaration
class Derived : public Base {
public:
    using Base::func;  // Bring base version into scope
    void func(double x) { }
};
```

### 4. Diamond Problem Without Virtual:

```cpp
// ❌ Problem
class Device { int id; };
class Phone : public Device { };
class Camera : public Device { };
class Smartphone : public Phone, public Camera { };
// Smartphone has TWO Device::id members!

// ✅ Solution: Virtual inheritance
class Phone : virtual public Device { };
class Camera : virtual public Device { };
class Smartphone : public Phone, public Camera { };
// Now only ONE Device::id
```

### 5. Constructor Order Issues:

```cpp
class Base {
    int x;
public:
    Base(int val) : x(val) { }
};

// ❌ Problem: Base not initialized
class Derived : public Base {
public:
    Derived(int val) { }  // ERROR: Base() needs parameter
};

// ✅ Solution: Call base constructor explicitly
class Derived : public Base {
public:
    Derived(int val) : Base(val) { }
};
```

## Inheritance vs Composition

### When to Use Inheritance:

✅ **Use Inheritance when:**

- True "IS-A" relationship exists
- Need polymorphic behavior
- Derived class is a specialized version of base
- Want to reuse interface, not just implementation

```cpp
// Good use of inheritance
class Animal { };
class Dog : public Animal { };  // Dog IS-AN Animal
```

### When to Use Composition:

✅ **Use Composition when:**

- "HAS-A" relationship exists
- Need implementation reuse only
- Want more flexibility
- Avoid coupling to base class implementation

```cpp
// Good use of composition
class Engine { };
class Car {
    Engine engine;  // Car HAS-AN Engine
};
```

### Comparison:

| Aspect       | Inheritance                 | Composition                  |
| ------------ | --------------------------- | ---------------------------- |
| Relationship | IS-A                        | HAS-A                        |
| Coupling     | Tight (subclass knows base) | Loose (owner doesn't expose) |
| Flexibility  | Less (fixed at compile)     | More (change at runtime)     |
| Reuse        | Interface + Implementation  | Implementation only          |
| Override     | Can override methods        | Cannot override              |
| Polymorphism | Supports                    | Doesn't support directly     |

## Advanced Topics

### 1. Covariant Return Types:

```cpp
class Base {
public:
    virtual Base* clone() {
        return new Base(*this);
    }
};

class Derived : public Base {
public:
    Derived* clone() override {  // Different return type!
        return new Derived(*this);
    }
};
```

### 2. Multiple Inheritance Ambiguity:

```cpp
class A {
public:
    void func() { cout << "A" << endl; }
};

class B {
public:
    void func() { cout << "B" << endl; }
};

class C : public A, public B {
public:
    void resolve() {
        A::func();  // Explicitly call A's version
        B::func();  // Explicitly call B's version
    }
};
```

### 3. Private Inheritance (Implementation Inheritance):

```cpp
class Engine {
public:
    void start() { }
};

class Car : private Engine {  // Implementation detail
public:
    void drive() {
        start();  // Can use privately
    }
};

Car c;
// c.start();  // ERROR - not part of public interface
```

## Memory Layout

### Single Inheritance:

```
Derived Object:
+------------------+
|  Base Members    |  ← Base class subobject
+------------------+
|  Derived Members |  ← Additional members
+------------------+
```

### Multiple Inheritance:

```
Derived Object:
+------------------+
|  Base1 Members   |
+------------------+
|  Base2 Members   |
+------------------+
|  Derived Members |
+------------------+
```

### Virtual Inheritance:

```
Derived Object:
+------------------+
|  vptr (Phone)    |
+------------------+
|  Phone Members   |
+------------------+
|  vptr (Camera)   |
+------------------+
|  Camera Members  |
+------------------+
|  Device Members  |  ← Shared virtual base (ONE copy)
+------------------+
|  Derived Members |
+------------------+
```

## Additional Practical Examples

### 1. Employee Payroll System ([EmployeePayroll.cpp](../../Module2/15_Inheritance/EmployeePayroll.cpp))

**Demonstrates:** Inheritance + Encapsulation + Abstraction + Polymorphism

**Key Features:**

- Abstract base class `Employee` with pure virtual `calculatePay()`
- Derived classes: `SalariedEmployee` and `HourlyEmployee`
- Private data members with validated getters/setters
- Polymorphic pay calculation through base class pointers
- Real-world business logic for different employee types

**Use Case:** Managing different types of employees with varied payment structures

### 2. Library Management System ([LibraryManagement.cpp](../../Module2/15_Inheritance/LibraryManagement.cpp))

**Demonstrates:** Hierarchical inheritance with abstraction

**Key Features:**

- Abstract base class `Item` for all library items
- Derived classes: `Book`, `Magazine`, `DVD`
- Each derived class has specific attributes (pages, issue date, duration)
- Pure virtual `display()` function enforces consistent interface
- Demonstrates data validation and encapsulation

**Use Case:** Managing diverse items in a library with common operations

## Summary

### Key Takeaways:

1. **Inheritance enables code reuse** through IS-A relationships
2. **Five types**: Single, Multiple, Multilevel, Hierarchical, Hybrid
3. **Virtual inheritance** solves diamond problem
4. **Protected members** enable derived class access
5. **Constructor order**: Base → Derived
6. **Destructor order**: Derived → Base
7. **Virtual destructors** essential for proper cleanup
8. **Override keyword** catches mistakes at compile-time
9. **Prefer composition** over inheritance when appropriate
10. **Keep hierarchies shallow** for maintainability

### Decision Tree:

```
Need code reuse?
  ├─ IS-A relationship? → Use Inheritance
  └─ HAS-A relationship? → Use Composition

Need polymorphism?
  └─ Use Inheritance with virtual functions

Multiple base classes?
  ├─ Same ultimate base? → Use Virtual Inheritance
  └─ Different bases? → Use Multiple Inheritance

Deep hierarchy?
  └─ Refactor to use Composition
```

## Related Concepts

- **Polymorphism** - Enabled by inheritance and virtual functions
- **Abstraction** - Abstract base classes define interfaces
- **Encapsulation** - Protected members for derived classes
- **SOLID Principles** - Liskov Substitution Principle
- **Design Patterns** - Factory, Strategy, Template Method
- **Virtual Tables** - Runtime polymorphism mechanism
- **Dynamic Binding** - Late binding through virtual functions

## Quick Reference

### Inheritance Syntax:

```cpp
class Derived : <access> Base1, <access> Base2 {
    // Members
};
```

### Access Specifiers:

- `public` - IS-A relationship
- `protected` - Rare, implementation detail
- `private` - Implementation inheritance

### Virtual Inheritance:

```cpp
class Derived : virtual public Base { };
```

### Override:

```cpp
ReturnType function() override { }
```

### Call Base Method:

```cpp
Base::method();
```

### Virtual Destructor:

```cpp
virtual ~ClassName() { }
```
