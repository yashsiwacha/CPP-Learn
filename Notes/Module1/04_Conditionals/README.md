# Conditional Statements in C++

## Overview

Conditional statements control the flow of program execution based on conditions. They enable decision-making in programs.

## Topics Covered

### 1. Calculator

**File Reference**: [calculator.cpp](../../Module1/04_Conditionals/calculator.cpp)

#### Concepts Demonstrated:

- Switch-case statement
- Operator selection
- Basic arithmetic operations
- Menu-driven program

#### Switch Statement Syntax:

```cpp
switch(choice) {
    case 1:
        // code
        break;
    case 2:
        // code
        break;
    default:
        // code
}
```

### 2. Grade Calculator

**File Reference**: [grade_calculator.cpp](../../Module1/04_Conditionals/grade_calculator.cpp)

#### Concepts Demonstrated:

- If-else ladder
- Nested conditions
- Range checking
- Grade assignment logic

#### Typical Grading Logic:

```cpp
if(marks >= 90) grade = 'A';
else if(marks >= 80) grade = 'B';
else if(marks >= 70) grade = 'C';
else if(marks >= 60) grade = 'D';
else grade = 'F';
```

### 3. Shipping Cost Calculator

**File Reference**: [shipping_cost.cpp](../../Module1/04_Conditionals/shipping_cost.cpp)

#### Concepts Demonstrated:

- Multiple condition checking
- Weight-based calculations
- Distance-based pricing
- Discount application
- Complex business logic

### 4. Student Performance

**File Reference**: [student_performance.cpp](../../Module1/04_Conditionals/student_performance.cpp)

#### Concepts Demonstrated:

- Analyzing multiple criteria
- Performance categorization
- Statistical calculations
- Conditional feedback

## Conditional Statements

### 1. If Statement

```cpp
if(condition) {
    // executes if condition is true
}
```

- Single condition check
- Executes block if true
- Optional else

### 2. If-Else Statement

```cpp
if(condition) {
    // executes if true
} else {
    // executes if false
}
```

- Two-way branching
- One block always executes
- Mutually exclusive

### 3. If-Else-If Ladder

```cpp
if(condition1) {
    // block 1
} else if(condition2) {
    // block 2
} else if(condition3) {
    // block 3
} else {
    // default block
}
```

- Multiple conditions checked sequentially
- First true condition executes
- Optional final else

### 4. Nested If

```cpp
if(condition1) {
    if(condition2) {
        // both conditions true
    }
}
```

- If inside another if
- Used for complex logic
- Can reduce readability

### 5. Switch-Case

```cpp
switch(expression) {
    case constant1:
        // code
        break;
    case constant2:
        // code
        break;
    default:
        // code
}
```

- Multiple equal comparisons
- Works with integers, chars, enums
- Faster than if-else for many cases

## Conditional Operators

### Relational Operators:

- `==` Equal to
- `!=` Not equal to
- `<` Less than
- `>` Greater than
- `<=` Less than or equal to
- `>=` Greater than or equal to

### Logical Operators:

- `&&` AND (both must be true)
- `||` OR (at least one true)
- `!` NOT (inverts condition)

### Ternary Operator:

```cpp
result = (condition) ? value_if_true : value_if_false;
max = (a > b) ? a : b;
```

- Shorthand for simple if-else
- Returns a value
- Single line decision

## Best Practices

1. **Braces**: Always use braces even for single statements
2. **Readability**: Keep conditions simple and readable
3. **Order**: Put most likely conditions first in if-else
4. **Switch Break**: Always include break in switch cases
5. **Default Case**: Include default case in switch
6. **Boolean Variables**: Use meaningful boolean names
7. **Avoid Deep Nesting**: Limit nesting depth (max 3-4 levels)

## Common Pitfalls

1. **Assignment vs Comparison**: `=` vs `==`

```cpp
if(x = 5)  // Wrong! Assigns 5 to x
if(x == 5) // Correct! Compares x with 5
```

2. **Missing Break**: Causes fall-through in switch

```cpp
switch(x) {
    case 1:
        cout << "One";
        // Missing break - falls through!
    case 2:
        cout << "Two";
        break;
}
```

3. **Floating Point Comparison**:

```cpp
if(f == 0.1)  // Unreliable due to precision
if(fabs(f - 0.1) < 0.0001) // Better approach
```

4. **Dangling Else**:

```cpp
if(condition1)
    if(condition2)
        statement1;
else  // Belongs to if(condition2), not if(condition1)
    statement2;
```

5. **Logical Operator Misuse**:

```cpp
if(x > 5 && < 10)  // Wrong!
if(x > 5 && x < 10) // Correct!
```

## Short-Circuit Evaluation

### AND Operator (&&):

```cpp
if(ptr != nullptr && ptr->value > 0)
```

- If first condition false, second not evaluated
- Prevents null pointer access

### OR Operator (||):

```cpp
if(x == 0 || y/x > 10)
```

- If first condition true, second not evaluated
- Prevents division by zero

## Advanced Techniques

### 1. Guard Clauses:

```cpp
if(!valid) return;  // Exit early
// Main logic here
```

- Check error conditions first
- Reduces nesting
- Cleaner code

### 2. Lookup Tables:

```cpp
const int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int days = daysInMonth[month-1];
```

- Replace complex if-else
- Faster execution
- Easier maintenance

### 3. Function Pointers:

```cpp
typedef double (*Operation)(double, double);
Operation ops[] = {add, subtract, multiply, divide};
result = ops[choice](a, b);
```

- Replace switch statements
- More flexible
- Cleaner code

## Related Concepts

- Loops (while, for, do-while)
- Boolean algebra
- Control flow
- Functions
- Error handling
