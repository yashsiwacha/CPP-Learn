# Conditional Statements in C++

## 📋 Study Plan

**Time Needed:** 2-3 hours  
**Difficulty:** ⭐ (Easy - Foundation)  
**Prerequisites:** Basic C++ syntax, operators

**Start here if:** You need to make decisions in your programs!

---

## 🔷 Definition (Memorize This!)

```
┌──────────────────────────────────────────────────────────┐
│ CONDITIONAL STATEMENTS = Control flow based on           │
│                          conditions (true/false)         │
│                                                          │
│ Purpose:                                                 │
│  • Make decisions in programs                            │
│  • Execute different code based on conditions            │
│  • Control program flow                                  │
└──────────────────────────────────────────────────────────┘
```

## Key Concepts

### 1. Types of Conditionals

| Statement   | Syntax                        | Use When                   |
| ----------- | ----------------------------- | -------------------------- |
| if          | `if(condition) { }`           | Single condition           |
| if-else     | `if(c) { } else { }`          | Two-way branching          |
| if-else-if  | `if...else if...else`         | Multiple conditions        |
| switch-case | `switch(var) { case 1: ... }` | Multiple equal comparisons |
| Ternary     | `result = (c) ? val1 : val2;` | Simple inline condition    |

### 2. Practice Files

- [calculator.cpp](../../Module1/04_Conditionals/calculator.cpp) - Switch-case for operations
- [grade_calculator.cpp](../../Module1/04_Conditionals/grade_calculator.cpp) - If-else ladder for grading
- [shipping_cost.cpp](../../Module1/04_Conditionals/shipping_cost.cpp) - Complex conditions
- [student_performance.cpp](../../Module1/04_Conditionals/student_performance.cpp) - Multi-criteria analysis

### 3. Operators

**Relational:** `==`, `!=`, `<`, `>`, `<=`, `>=`  
**Logical:** `&&` (AND), `||` (OR), `!` (NOT)  
**Ternary:** `(condition) ? true_val : false_val`

### 4. Short-Circuit Evaluation

- `&&` - If first is false, second not evaluated
- `||` - If first is true, second not evaluated
- Prevents errors: `if(ptr != nullptr && ptr->value > 0)`

---

## Common Mistakes

```
┌──────────────────────────────────────────────────────────┐
│ ❌ Using = instead of == (assignment vs comparison)       │
│ ❌ Missing break in switch cases (fall-through)           │
│ ❌ Comparing floats with == (use epsilon)                 │
│ ❌ Deep nesting (keep to 3-4 levels max)                  │
│ ❌ Not using braces for single-line statements            │
└──────────────────────────────────────────────────────────┘
```

## Key Takeaways

1. **Use Braces** - Always, even for single statements
2. **Switch Needs Break** - Prevent fall-through
3. **Order Matters** - Put most likely conditions first
4. **Keep Simple** - Avoid deep nesting
5. **Default Case** - Always include in switch statements
