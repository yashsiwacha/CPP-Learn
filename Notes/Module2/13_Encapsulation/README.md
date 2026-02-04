# Encapsulation in C++

## Overview

Encapsulation is one of the fundamental principles of Object-Oriented Programming. It involves bundling data and methods that operate on that data within a single unit (class) and restricting direct access to some components.

## Topics Covered

### Files Reference:

- [BankAccount.cpp](../../Module2/13_Encapsulation/BankAccount.cpp)
- [Student.cpp](../../Module2/13_Encapsulation/Student.cpp)
- [Student.h](../../Module2/13_Encapsulation/Student.h)
- [Temperature.cpp](../../Module2/13_Encapsulation/Temerature.cpp)
- [main.cpp](../../Module2/13_Encapsulation/main.cpp)

## What is Encapsulation?

### Definition:

Encapsulation is the mechanism of:

1. **Bundling** data (attributes) and methods (functions) that operate on the data
2. **Hiding** internal state and requiring all interaction through an object's methods
3. **Protecting** data from unauthorized access and modification

### Analogy:

Think of a capsule - you can't see or directly access what's inside. You interact with it through a defined interface.

## Basic Encapsulation

### Without Encapsulation (Bad):

```cpp
class BankAccount {
public:
    double balance;  // Direct access - dangerous!
};

BankAccount acc;
acc.balance = -1000;  // Can set invalid value!
```

### With Encapsulation (Good):

```cpp
class BankAccount {
private:
    double balance;  // Hidden from outside

public:
    void deposit(double amount) {
        if(amount > 0)  // Validation
            balance += amount;
    }

    double getBalance() const {
        return balance;
    }
};

BankAccount acc;
// acc.balance = -1000;  // Error! Can't access private member
acc.deposit(500);        // Controlled access
```

## Access Specifiers

### Private:

- Default access level for class members
- Accessible only within the class
- Used for internal implementation details

```cpp
class MyClass {
private:
    int secret;         // Can't access from outside
    void helper() { }   // Internal helper method
};
```

### Public:

- Accessible from anywhere
- Used for the class interface
- Public methods provide controlled access

```cpp
class MyClass {
public:
    void publicMethod() { }  // Interface method
    int getSecret() const;   // Getter
    void setSecret(int s);   // Setter
};
```

### Protected:

- Accessible in class and derived classes
- Used in inheritance hierarchies

```cpp
class Base {
protected:
    int protectedData;  // Accessible in derived classes
};

class Derived : public Base {
    void method() {
        protectedData = 10;  // OK
    }
};
```

## Getters and Setters

### Purpose:

- Provide controlled access to private data
- Allow validation before modification
- Enable additional logic during access

### Getter (Accessor):

```cpp
class Student {
private:
    int age;
    string name;

public:
    // Getter - returns data
    int getAge() const {
        return age;
    }

    string getName() const {
        return name;
    }
};
```

### Setter (Mutator):

```cpp
class Student {
private:
    int age;

public:
    // Setter - validates and sets data
    void setAge(int a) {
        if(a >= 0 && a <= 150) {  // Validation
            age = a;
        } else {
            throw invalid_argument("Invalid age");
        }
    }
};
```

### Naming Conventions:

- `get...()` - Retrieve value
- `set...()` - Modify value
- `is...()` - Boolean properties

```cpp
bool isActive() const { return active; }
bool hasPermission() const { return permission; }
```

## Advantages of Encapsulation

### 1. Data Validation:

```cpp
class BankAccount {
private:
    double balance;

public:
    void deposit(double amount) {
        if(amount <= 0) {
            throw invalid_argument("Amount must be positive");
        }
        balance += amount;
    }

    bool withdraw(double amount) {
        if(amount <= 0 || amount > balance) {
            return false;  // Invalid operation
        }
        balance -= amount;
        return true;
    }
};
```

### 2. Data Hiding:

```cpp
class CreditCard {
private:
    string cardNumber;    // Hidden
    string cvv;           // Hidden

public:
    // Only show last 4 digits
    string getLastFourDigits() const {
        return cardNumber.substr(cardNumber.length() - 4);
    }
};
```

### 3. Flexibility:

```cpp
class Temperature {
private:
    double celsius;  // Internal storage

public:
    double getCelsius() const {
        return celsius;
    }

    double getFahrenheit() const {
        return celsius * 9.0/5.0 + 32;  // Calculated on demand
    }

    void setCelsius(double c) {
        celsius = c;
    }

    void setFahrenheit(double f) {
        celsius = (f - 32) * 5.0/9.0;  // Convert and store
    }
};
```

### 4. Maintainability:

```cpp
class User {
private:
    string password;  // Can change hashing algorithm without affecting users

public:
    bool verifyPassword(const string& pwd) {
        // Can change implementation (MD5 -> SHA256) without breaking code
        return hash(pwd) == password;
    }
};
```

### 5. Read-Only Properties:

```cpp
class Employee {
private:
    const int employeeId;  // Read-only
    int salary;

public:
    Employee(int id) : employeeId(id) { }

    int getEmployeeId() const {
        return employeeId;  // Only getter, no setter
    }

    void setSalary(int s) {
        if(s > 0) salary = s;
    }
};
```

## Encapsulation Patterns

### 1. Lazy Initialization:

```cpp
class DataManager {
private:
    vector<int>* data;

    void initializeData() {
        if(data == nullptr) {
            data = new vector<int>();
            // Load data...
        }
    }

public:
    vector<int>& getData() {
        initializeData();  // Initialize only when needed
        return *data;
    }
};
```

### 2. Computed Properties:

```cpp
class Rectangle {
private:
    double width;
    double height;

public:
    double getArea() const {
        return width * height;  // Computed, not stored
    }

    double getPerimeter() const {
        return 2 * (width + height);
    }
};
```

### 3. Cache Pattern:

```cpp
class ExpensiveCalculation {
private:
    mutable int cachedResult;
    mutable bool cacheValid;
    int inputData;

public:
    int getResult() const {
        if(!cacheValid) {
            cachedResult = expensiveComputation();
            cacheValid = true;
        }
        return cachedResult;
    }

    void setInputData(int data) {
        inputData = data;
        cacheValid = false;  // Invalidate cache
    }
};
```

### 4. Immutable Objects:

```cpp
class ImmutablePoint {
private:
    const int x;
    const int y;

public:
    ImmutablePoint(int x, int y) : x(x), y(y) { }

    int getX() const { return x; }
    int getY() const { return y; }

    // No setters - object can't be modified after creation
};
```

## Practical Examples

### 1. Bank Account:

```cpp
class BankAccount {
private:
    string accountNumber;
    string holderName;
    double balance;
    vector<string> transactionHistory;

public:
    BankAccount(string accNum, string name, double initialBalance = 0)
        : accountNumber(accNum), holderName(name), balance(initialBalance) {
        if(initialBalance < 0) {
            throw invalid_argument("Initial balance cannot be negative");
        }
    }

    bool deposit(double amount) {
        if(amount <= 0) return false;
        balance += amount;
        transactionHistory.push_back("Deposit: " + to_string(amount));
        return true;
    }

    bool withdraw(double amount) {
        if(amount <= 0 || amount > balance) return false;
        balance -= amount;
        transactionHistory.push_back("Withdraw: " + to_string(amount));
        return true;
    }

    double getBalance() const {
        return balance;
    }

    string getAccountNumber() const {
        return accountNumber;
    }

    // No direct access to balance or transactionHistory
};
```

### 2. Student Class:

```cpp
class Student {
private:
    int rollNumber;
    string name;
    float marks[5];
    float average;
    char grade;

    void calculateAverage() {
        float sum = 0;
        for(int i = 0; i < 5; i++)
            sum += marks[i];
        average = sum / 5;
    }

    void calculateGrade() {
        if(average >= 90) grade = 'A';
        else if(average >= 80) grade = 'B';
        else if(average >= 70) grade = 'C';
        else if(average >= 60) grade = 'D';
        else grade = 'F';
    }

public:
    Student(int roll, string n) : rollNumber(roll), name(n) {
        for(int i = 0; i < 5; i++)
            marks[i] = 0;
        average = 0;
        grade = 'F';
    }

    void setMarks(int subject, float mark) {
        if(subject >= 0 && subject < 5 && mark >= 0 && mark <= 100) {
            marks[subject] = mark;
            calculateAverage();
            calculateGrade();
        }
    }

    float getAverage() const { return average; }
    char getGrade() const { return grade; }
    string getName() const { return name; }
};
```

### 3. Temperature Converter:

```cpp
class Temperature {
private:
    double kelvin;  // Store in Kelvin internally

public:
    // Constructors
    void setCelsius(double c) {
        if(c < -273.15) {
            throw invalid_argument("Temperature below absolute zero");
        }
        kelvin = c + 273.15;
    }

    void setFahrenheit(double f) {
        setCelsius((f - 32) * 5.0/9.0);
    }

    void setKelvin(double k) {
        if(k < 0) {
            throw invalid_argument("Temperature below absolute zero");
        }
        kelvin = k;
    }

    // Getters
    double getCelsius() const {
        return kelvin - 273.15;
    }

    double getFahrenheit() const {
        return getCelsius() * 9.0/5.0 + 32;
    }

    double getKelvin() const {
        return kelvin;
    }
};
```

## Encapsulation with Header Files

### Student.h (Header):

```cpp
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    float marks;

public:
    // Constructor
    Student(int roll, string n, float m);

    // Getters
    int getRollNumber() const;
    string getName() const;
    float getMarks() const;

    // Setters
    void setName(string n);
    void setMarks(float m);

    // Other methods
    char getGrade() const;
    void display() const;
};

#endif
```

### Student.cpp (Implementation):

```cpp
#include "Student.h"
#include <iostream>

Student::Student(int roll, string n, float m)
    : rollNumber(roll), name(n), marks(m) {
}

int Student::getRollNumber() const {
    return rollNumber;
}

string Student::getName() const {
    return name;
}

float Student::getMarks() const {
    return marks;
}

void Student::setName(string n) {
    name = n;
}

void Student::setMarks(float m) {
    if(m >= 0 && m <= 100)
        marks = m;
}

char Student::getGrade() const {
    if(marks >= 90) return 'A';
    if(marks >= 80) return 'B';
    if(marks >= 70) return 'C';
    if(marks >= 60) return 'D';
    return 'F';
}

void Student::display() const {
    cout << "Roll: " << rollNumber << endl;
    cout << "Name: " << name << endl;
    cout << "Marks: " << marks << endl;
    cout << "Grade: " << getGrade() << endl;
}
```

## Best Practices

### 1. Keep Data Private:

```cpp
class Good {
private:
    int data;  // Good
public:
    int getData() const { return data; }
};

class Bad {
public:
    int data;  // Bad - no control
};
```

### 2. Const Correctness:

```cpp
class Student {
    string name;
public:
    string getName() const { return name; }  // Mark as const
};
```

### 3. Validate in Setters:

```cpp
void setAge(int a) {
    if(a >= 0 && a <= 150)  // Validate
        age = a;
    else
        throw invalid_argument("Invalid age");
}
```

### 4. Return by const Reference:

```cpp
const string& getName() const {
    return name;  // Efficient, safe
}
```

### 5. Minimal Interface:

```cpp
// Only expose what's necessary
class Account {
private:
    double balance;
    void updateDatabase() { }  // Private helper

public:
    void deposit(double amt);   // Public interface
    double getBalance() const;
};
```

## Common Pitfalls

### 1. Returning Private Data by Reference:

```cpp
class Bad {
    vector<int> data;
public:
    vector<int>& getData() {
        return data;  // Caller can modify private data!
    }
};

class Good {
    vector<int> data;
public:
    const vector<int>& getData() const {
        return data;  // Read-only access
    }
};
```

### 2. Exposing Implementation Details:

```cpp
class Bad {
public:
    list<int> items;  // Exposes implementation
};

class Good {
private:
    list<int> items;  // Hidden - can change to vector later
public:
    void addItem(int item);
    int getItem(int index) const;
};
```

### 3. No Validation:

```cpp
void setBankBalance(double b) {
    balance = b;  // Should validate b >= 0
}
```

## Related Concepts

- Abstraction
- Information hiding
- Data hiding
- Interface segregation
- Dependency inversion
- Immutability
