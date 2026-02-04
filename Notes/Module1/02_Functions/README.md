# Functions in C++

## Overview

Functions are reusable blocks of code that perform specific tasks. They help in code modularity, reusability, and organization.

## Topics Covered

### 1. Function Basics

#### Function Structure:

```cpp
return_type function_name(parameter_list) {
    // function body
    return value;
}
```

#### Key Components:

- **Return Type**: Data type of value returned (void if nothing)
- **Function Name**: Identifier following naming rules
- **Parameters**: Input values (formal parameters)
- **Arguments**: Actual values passed when calling
- **Return Statement**: Sends value back to caller

### 2. Parameter Passing Methods

#### Pass by Value:

```cpp
void func(int x) { x = 10; } // Original unchanged
```

- Copy of argument is passed
- Changes don't affect original
- Default method in C++

#### Pass by Reference:

```cpp
void func(int &x) { x = 10; } // Original modified
```

- Reference to original variable
- Changes affect original
- More efficient for large objects

#### Pass by Pointer:

```cpp
void func(int *x) { *x = 10; } // Original modified
```

- Address of variable passed
- Can modify original through dereferencing
- Can pass NULL/nullptr

### 3. Temperature Converter

**File Reference**: [temperature_converter.cpp](../../Module1/02_Functions/temperature_converter.cpp)

#### Concepts Demonstrated:

- Multiple functions for different conversions
- Formula implementation
- User input handling
- Menu-driven program

#### Formulas:

- Celsius to Fahrenheit: `F = (C × 9/5) + 32`
- Fahrenheit to Celsius: `C = (F - 32) × 5/9`
- Celsius to Kelvin: `K = C + 273.15`

### 4. Temperature Converter V2

**File Reference**: [temperature_converter_v2.cpp](../../Module1/02_Functions/temperature_converter_v2.cpp)

Improved version with:

- Better error handling
- Input validation
- More conversion options
- Cleaner code structure

### 5. Banking System

**File Reference**: [banking_system.cpp](../../Module1/02_Functions/banking_system.cpp)

#### Concepts Demonstrated:

- Multiple functions working together
- State management (account balance)
- Transaction processing
- Menu-driven interface

#### Key Functions:

- `deposit()`: Add money to account
- `withdraw()`: Remove money with validation
- `checkBalance()`: Display current balance
- `displayMenu()`: User interface

## Function Features

### 1. Function Overloading

```cpp
int add(int a, int b);
double add(double a, double b);
int add(int a, int b, int c);
```

- Same name, different parameters
- Compile-time polymorphism
- Different number or types of parameters

### 2. Default Parameters

```cpp
void func(int a, int b = 10, int c = 20);
```

- Provide default values
- Must be rightmost parameters
- Can be omitted when calling

### 3. Inline Functions

```cpp
inline int square(int x) { return x * x; }
```

- Hint to compiler to insert code directly
- Reduces function call overhead
- Best for small, frequently called functions

### 4. Recursion

```cpp
int factorial(int n) {
    if(n <= 1) return 1;
    return n * factorial(n-1);
}
```

- Function calling itself
- Needs base case to stop
- Uses call stack

## Best Practices

1. **Single Responsibility**: One function = one task
2. **Meaningful Names**: Use descriptive function names
3. **Short Functions**: Keep functions concise (< 50 lines)
4. **Const Parameters**: Use `const` for parameters that shouldn't change
5. **Documentation**: Comment complex functions
6. **Error Handling**: Validate inputs and handle errors
7. **Return Values**: Prefer return values over output parameters

## Common Pitfalls

1. **Missing Return**: Non-void functions must return a value
2. **Parameter Mismatch**: Arguments must match parameter types
3. **Scope Issues**: Variables defined inside function are local
4. **Infinite Recursion**: Missing or incorrect base case
5. **Pass by Value for Large Objects**: Inefficient for large structures
6. **Default Parameter Position**: Must be rightmost parameters

## Function Call Stack

When a function is called:

1. Arguments are evaluated
2. Control transfers to function
3. Parameters are initialized
4. Local variables created
5. Function body executes
6. Return value (if any) is sent back
7. Local variables destroyed
8. Control returns to caller

## Related Concepts

- Scope and lifetime of variables
- Function pointers
- Lambda expressions (C++11)
- Function templates
- Standard library functions
