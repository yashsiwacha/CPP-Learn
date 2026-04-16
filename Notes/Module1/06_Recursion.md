# Recursion in C++

## 📋 Study Plan

**Time Needed:** 4-5 hours  
**Difficulty:** ⭐⭐⭐⭐ (Hard - Master this!)  
**Prerequisites:** Functions, loops, problem-solving

**⚠️ CRITICAL:** One of the toughest concepts. Practice many examples!

---

## 🔷 Definition (Memorize This!)

```
┌──────────────────────────────────────────────────────────┐
│ RECURSION = Function that calls ITSELF to solve         │
│             a problem by breaking it into smaller        │
│             subproblems                                  │
│                                                          │
│ Two Essential Parts:                                     │
│  1. BASE CASE: Stopping condition (no more recursion)   │
│  2. RECURSIVE CASE: Function calls itself               │
└──────────────────────────────────────────────────────────┘
```

## Key Concepts

### 1. Directory Traversal ([directory_traversal.cpp](../../Module1/06_Recursion/directory_traversal.cpp))

**Concepts:**

- Recursive directory exploration
- Tree structure traversal
- Depth-first search pattern
- Base case: invalid/empty path
- Recursive case: process subdirectories

### 2. Staircase Problem ([staircase_problem.cpp](../../Module1/06_Recursion/staircase_problem.cpp))

**Problem:** Count ways to climb n stairs (1, 2, or 3 steps at a time)

**Recurrence:** `ways(n) = ways(n-1) + ways(n-2) + ways(n-3)`

**Optimization:** Use memoization to avoid redundant calculations

---

## Classic Recursive Problems

| Problem   | Formula                      | Base Case | Time (naive) |
| --------- | ---------------------------- | --------- | ------------ |
| Factorial | n! = n × (n-1)!              | n ≤ 1 → 1 | O(n)         |
| Fibonacci | F(n) = F(n-1) + F(n-2)       | n ≤ 1 → n | O(2^n)       |
| Power     | x^n = x × x^(n-1)            | n = 0 → 1 | O(n)         |
| Sum Array | sum(n) = arr[n-1] + sum(n-1) | n = 0 → 0 | O(n)         |

## Recursion vs Iteration

| Aspect      | Recursion                       | Iteration     |
| ----------- | ------------------------------- | ------------- |
| Readability | More intuitive                  | More verbose  |
| Memory      | Uses call stack (O(n))          | Constant O(1) |
| Performance | Slower (function calls)         | Faster        |
| Risk        | Stack overflow                  | Infinite loop |
| Best for    | Trees, graphs, divide & conquer | Simple loops  |

**Use recursion when:**

1. **Problem has recursive structure**
   - Problem can be broken into smaller similar subproblems
   - Examples: factorial, Fibonacci, power calculation

2. **Working with tree or graph structures**
   - Binary trees, file systems, directory traversal
   - Depth-first search, breadth-first search

3. **Divide and conquer algorithms**
   - Merge sort, quick sort, binary search
   - Problem splits into independent subproblems

4. **Backtracking problems**
   - N-Queens, Sudoku solver, maze solving
   - Need to explore all possible solutions

5. **Mathematical problems with recurrence relations**
   - Tower of Hanoi, combinations, permutations
   - Problems naturally defined recursively

**Avoid recursion when:**

- Simple iterative solution exists
- Very deep recursion (risk of stack overflow)
- Performance is critical (iteration is faster)
- Memory is limited (recursion uses call stack)

## Optimization Techniques

**1. Memoization (Top-Down):**

- Cache computed results
- Use map/array to store values
- Check cache before computing

**2. Dynamic Programming (Bottom-Up):**

- Build solution from base cases
- Iterative approach
- Better space efficiency

**3. Tail Recursion:**

- Last operation is recursive call
- Compiler can optimize to iteration
- Example: `factorial(n, acc)`

---

## Common Mistakes

```
┌──────────────────────────────────────────────────────────┐
│ ❌ Missing base case (infinite recursion)                 │
│ ❌ Wrong base case (doesn't cover all cases)              │
│ ❌ No progress toward base case                           │
│ ❌ Stack overflow from deep recursion                     │
│ ❌ Inefficient - redundant calculations without memoization│
└──────────────────────────────────────────────────────────┘
```

## Key Takeaways

1. **Always Define Base Case** - Prevents infinite recursion
2. **Make Progress** - Each call should move toward base case
3. **Memoize** - Cache results to avoid redundant calculations
4. **Consider Stack Limit** - Deep recursion may overflow
5. **Think Iterative** - Sometimes iteration is simpler and faster
