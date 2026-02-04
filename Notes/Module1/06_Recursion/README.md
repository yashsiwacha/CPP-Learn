# Recursion in C++

## Overview

Recursion is a programming technique where a function calls itself to solve a problem by breaking it down into smaller subproblems.

## Topics Covered

### 1. Directory Traversal

**File Reference**: [directory_traversal.cpp](../../Module1/06_Recursion/directory_traversal.cpp)

#### Concepts Demonstrated:

- Recursive directory exploration
- File system navigation
- Tree structure traversal
- Depth-first search
- Base case and recursive case

#### Typical Implementation:

```cpp
void traverseDirectory(string path, int level) {
    // Base case: invalid path
    if(!isDirectory(path)) return;

    // Process current directory
    printIndent(level);
    cout << path << endl;

    // Recursive case: process subdirectories
    for(each file in directory) {
        if(isDirectory(file))
            traverseDirectory(file, level + 1);
    }
}
```

### 2. Staircase Problem

**File Reference**: [staircase_problem.cpp](../../Module1/06_Recursion/staircase_problem.cpp)

#### Problem Statement:

Count the number of ways to climb n stairs if you can take 1, 2, or 3 steps at a time.

#### Mathematical Relation:

```
ways(n) = ways(n-1) + ways(n-2) + ways(n-3)
```

#### Implementation:

```cpp
int countWays(int n) {
    // Base cases
    if(n == 0) return 1;
    if(n < 0) return 0;

    // Recursive case
    return countWays(n-1) + countWays(n-2) + countWays(n-3);
}
```

#### Optimized with Memoization:

```cpp
int countWays(int n, vector<int>& memo) {
    if(n == 0) return 1;
    if(n < 0) return 0;
    if(memo[n] != -1) return memo[n];

    memo[n] = countWays(n-1, memo) +
              countWays(n-2, memo) +
              countWays(n-3, memo);
    return memo[n];
}
```

## Recursion Fundamentals

### Essential Components:

#### 1. Base Case:

```cpp
if(n == 0) return 1;  // Stop condition
```

- Termination condition
- Prevents infinite recursion
- Returns a direct answer

#### 2. Recursive Case:

```cpp
return n * factorial(n-1);  // Calls itself
```

- Problem decomposition
- Moves towards base case
- Combines results

#### 3. Progress Towards Base Case:

- Each recursive call should get closer to base case
- Usually smaller input or simpler problem

### How Recursion Works:

1. **Function Call**: Pushes onto call stack
2. **Save State**: Parameters and local variables saved
3. **Recursive Call**: Function calls itself with new parameters
4. **Return**: Pops from stack, returns to caller
5. **Combine Results**: Use returned value in computation

## Classic Recursive Problems

### 1. Factorial:

```cpp
int factorial(int n) {
    if(n <= 1) return 1;        // Base case
    return n * factorial(n-1);   // Recursive case
}
```

- Mathematical: n! = n × (n-1)!
- Time: O(n), Space: O(n)

### 2. Fibonacci:

```cpp
int fibonacci(int n) {
    if(n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}
```

- Mathematical: F(n) = F(n-1) + F(n-2)
- Time: O(2^n), Space: O(n)
- Can optimize with memoization

### 3. Power:

```cpp
double power(double x, int n) {
    if(n == 0) return 1;
    if(n < 0) return 1 / power(x, -n);
    return x * power(x, n-1);
}
```

- Optimized version uses divide-and-conquer
- Time: O(log n) with optimization

### 4. Sum of Array:

```cpp
int sum(int arr[], int n) {
    if(n == 0) return 0;
    return arr[n-1] + sum(arr, n-1);
}
```

- Process array recursively
- Reduces problem size by 1

### 5. Binary Search:

```cpp
int binarySearch(int arr[], int left, int right, int target) {
    if(left > right) return -1;

    int mid = left + (right - left) / 2;
    if(arr[mid] == target) return mid;
    if(arr[mid] > target)
        return binarySearch(arr, left, mid-1, target);
    return binarySearch(arr, mid+1, right, target);
}
```

- Divide and conquer approach
- Time: O(log n)

## Recursion vs Iteration

### Recursion:

**Pros:**

- More intuitive for certain problems
- Cleaner code
- Natural for tree/graph problems
- Easier to prove correctness

**Cons:**

- Stack overflow risk
- More memory usage
- Slower due to function call overhead
- May have redundant calculations

### Iteration:

**Pros:**

- More efficient (memory and time)
- No stack overflow
- Better for simple repetitive tasks
- Faster execution

**Cons:**

- More complex for some problems
- May need explicit stack
- Less intuitive for recursive structures

### Conversion:

Most recursive functions can be converted to iterative using a stack:

```cpp
// Recursive
void printReverse(int n) {
    if(n == 0) return;
    cout << n << " ";
    printReverse(n-1);
}

// Iterative
void printReverse(int n) {
    stack<int> s;
    while(n > 0) {
        s.push(n--);
    }
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}
```

## Tail Recursion

### Definition:

Recursive call is the last operation in the function.

### Example:

```cpp
// Tail recursive
int factorial(int n, int acc = 1) {
    if(n == 0) return acc;
    return factorial(n-1, n * acc);
}

// Not tail recursive
int factorial(int n) {
    if(n == 0) return 1;
    return n * factorial(n-1);  // Multiplication after call
}
```

### Benefits:

- Can be optimized by compiler
- Converted to iteration automatically
- No stack growth

## Recursion Tree

### Visualization:

```
fibonacci(4)
├── fibonacci(3)
│   ├── fibonacci(2)
│   │   ├── fibonacci(1) → 1
│   │   └── fibonacci(0) → 0
│   └── fibonacci(1) → 1
└── fibonacci(2)
    ├── fibonacci(1) → 1
    └── fibonacci(0) → 0
```

### Analysis:

- Shows function calls
- Identifies redundant calculations
- Helps understand complexity
- Guides optimization

## Optimization Techniques

### 1. Memoization (Top-Down):

```cpp
unordered_map<int, int> memo;

int fibonacci(int n) {
    if(n <= 1) return n;
    if(memo.find(n) != memo.end()) return memo[n];

    memo[n] = fibonacci(n-1) + fibonacci(n-2);
    return memo[n];
}
```

- Cache computed results
- Avoid redundant calculations
- Top-down approach

### 2. Dynamic Programming (Bottom-Up):

```cpp
int fibonacci(int n) {
    if(n <= 1) return n;

    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}
```

- Build solution from base cases
- Iterative approach
- Better space efficiency possible

### 3. Tail Recursion Optimization:

```cpp
int sum(int arr[], int n, int acc = 0) {
    if(n == 0) return acc;
    return sum(arr, n-1, acc + arr[n-1]);
}
```

- Last operation is recursive call
- Compiler can optimize
- No stack growth

## Best Practices

1. **Always Define Base Case**: Prevents infinite recursion
2. **Make Progress**: Each call should move toward base case
3. **Avoid Redundant Calls**: Use memoization if needed
4. **Consider Stack Limit**: Deep recursion may overflow
5. **Document Complexity**: Note time and space complexity
6. **Test Edge Cases**: Empty input, single element, etc.
7. **Consider Iteration**: May be more efficient

## Common Pitfalls

1. **Missing Base Case**:

```cpp
int factorial(int n) {
    return n * factorial(n-1);  // Infinite recursion!
}
```

2. **Wrong Base Case**:

```cpp
int factorial(int n) {
    if(n == 1) return 1;  // Fails for n=0
    return n * factorial(n-1);
}
```

3. **No Progress**:

```cpp
int bad(int n) {
    if(n == 0) return 0;
    return bad(n);  // Never reaches base case!
}
```

4. **Stack Overflow**:

```cpp
factorial(1000000);  // Too deep, stack overflow
```

5. **Inefficient Recursion**:

```cpp
// Exponential time without memoization
int fibonacci(int n) {
    if(n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}
```

## Related Concepts

- Stack data structure
- Dynamic programming
- Backtracking
- Tree traversal
- Graph traversal
- Divide and conquer
