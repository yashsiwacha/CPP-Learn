# Mathematical Programming

## Study Plan

Time Needed: 3-4 hours  
Difficulty: Medium-Hard  
Prerequisites: Loops, functions, basic math

What you'll learn: Convert mathematical formulas into programs

## Definition

Mathematical Programming means writing code to calculate mathematical formulas and series.

Applications:

- Scientific calculations
- Engineering simulations
- Financial modeling
- Physics and chemistry

## Key Concepts

### 1. Exponential Series

File: exponential_series.cpp

Formula: e^x = 1 + x + x^2/2! + x^3/3! + ...

Key Ideas:

- Add terms one by one using loops
- Calculate each new term from the previous one
- Use factorial in calculations
- More terms give better accuracy

### 2. Sine Series

File: sine_series.cpp

Formula: sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...

Key Ideas:

- Signs alternate between plus and minus
- Only use odd powers: x, x^3, x^5
- Input must be in radians
- Each term multiplies by negative x squared divided by factorials

## Common Series Formulas

Function e^x: Works for all x values
Function sin(x): Works for all x values
Function cos(x): Works for all x values
Function ln(1+x): Works only when -1 < x <= 1

## Optimization Techniques

1. Avoid Recalculation: Build each term from the previous one instead of starting from scratch
2. Early Termination: Stop when the term becomes very small
3. Use Built-in Functions: Standard library has exp(), sin(), cos() already implemented
4. Double Precision: Use double data type instead of float for better accuracy

## Common Mistakes

- ❌ Integer division (1/2 = 0, use 1.0/2.0)
- ❌ Overflow with large factorials
- ❌ Wrong units (degrees vs radians for trig)
- ❌Using too few terms gives poor results
- ❌Precision loss from too many operations

## Key Takeaways

1. Incremental Calculation: Build each term from the previous one
2. Convergence: More terms give better accuracy
3. Use Double: Always use double type for math calculations
4. Validate: Compare your results with standard library functions
5. Handle Overflow: Be careful with

**File Reference**: [exponential_series.cpp](../../Module1/05_Mathematical/exponential_series.cpp)

#### Mathematical Formula:

File Reference: exponential_series.cpp

Mathematical Formula: e^x = 1 + x + x^2/2! + x^3/3! + x^4/4! + ...

Key Concepts:

- Series expansion
- Factorial calculation
- Power calculation
- Convergence and precision
- Loop-based accumulation

Implementation Approach:

Use a step-by-step method:

- Start with result equals 1.0 (this is the first term)
- Set term to 1.0
- For each step: multiply term by x divided by i to get the next term
- Add each term to the result
- This calculates x to the power i divided by i factorial

What This Demonstrates:

- Step by step calculation
- Adding values together
- Getting precise math results
- Computing one term at a timeseries.cpp](../../Module1/05_Mathematical/sine_series.cpp)

#### Mathematical Formula:

$$\sin(x) = x - \frac{x^3}{3!} + \frac{x^5}{5!} - \frac{x^7}{7!} + ...$$
File Reference: sine_series.cpp

Mathematical Formula: sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...

Key Concepts:

- Alternating series (signs switch between plus and minus)
- Odd power terms (x, x^3, x^5, x^7)
- Sign alternation
- Radian conversion
- Taylor series

ouble term = x;

    for(int i = 0; i < terms; i++) {

Use an alternating series where:

- Start with result = 0 and term = x
- For each iteration: add term to result
- Update term by multiplying: -x * x / ((2*i+2) * (2*i+3))
- This automatically handles alternating signs and odd powersnly odd powers: x, x³, x⁵, x⁷, ...
- Converges for all x

## Mathematical Concepts

### 1. Series Expansequals 0 and term equals x

- For each step: add term to result
- Update term by multiplying by negative x squared divided by specific factorials
- This automatically handles switching signs and odd powers

Important Points:

- Input should be in radians
- Signs switch: plus, minus, plus, minus
- Only odd powers: x, x^3, x^5, x^7
- Works for all x values accuracy

### 2. Factorial

- Definition: n! = n × (n-1) × ... × 2 × 1
- Special case: 0! = 1
- Grows very rapidly

### 3. Power Calculation

````cpp
double power(double base, int exp) {
    double result = 1.0;
    for(int i = 0; i < exp; i++)
        result *= base;
    return result;
}
**Algorithm:**
- Initialize result to 1.0
- Multiply result by base exp times using a loop
- Return the final result
- Series approaches actual value
- More terms = closer to actual
- Some series converge faster
- Stop when desired accuracy reached

Taylor series is a way to represent functions as infinite sums.

Common Series:

e^x (Exponential):
- Sum of x^n divided by n factorial for n from 0 to infinity
- Works for all x values

sin(x) (Sine):
- Sum of alternating terms with odd powers and factorials
- Works for all x values

cos(x) (Cosine):
- Sum of alternating terms with even powers and factorials
- Works for all x values

ln(1+x) (Natural Log):
- Sum of alternating terms with powers divided by n
- Works only when -1 < x <=
- $\ln(1+x) = \sum_{n=1}^{\infty} \frac{(-1)^{n+1} x^n}{n}$
- Converges for -1 < x ≤ 1

## Optimization Techniques

### 1. Avoid Repeated Calculations:

```cpp
// Instead of calculating power and factorial separately
term = term * x / i;  // Incremental calculation
````

**Technique:** Instead of calculating power and factorial separately, use incremental calculation:

- Calculate next term from previous: term = term \* x / i
- Avoids recomputing factorials and powers from scratch
- Much more efficient

### 2. Early Termination:

**Technique:** Check if absolute value of term is less than threshold, then break

### 3. Precomputation:

````cpp
// Precompute factorials if needed multiple times
int fact[20];
**Technique:** Precompute factorials if needed multiple times
- Create an array to store factorials
- Set fact[0] = 1
- Calculate each subsequent factorial using previous: fact[i] = fact[i-1] * i
- Access precomputed values instead of recalculating

### 4. Use Built-in Functions:

**Standard Library Functions from <cmath>:**
- exp(x) - Exponential function
- sin(x) - Sine function
- cos(x) - Cosine function
- pow(x,y) - Power function
- Use these in production code for reliability and performance
### 1. Floating Point Issues:


- Limited precision (typically 6-7 digits for float)
- Use double for better precision
- Be aware of rounding errors

### 2. Large Numbers

- Factorials grow very fast
- May cause overflow
- Use long long or special libraries for big numbers

### 3. Small Numbers

- Terms may become too small
- May lose significance
- Use threshold for stopping

## Best Practices

1. Precision: Use double instead of float
2. Validation: Check input ranges
3. Convergence: Set appropriate number of terms
4. Efficiency: Optimize calculations
5. Testing: Compare with standard library functions
6. Documentation: Explain mathematical formulas
7. Constants: Use const for mathematical constants

## Common Pitfalls

1. Integer Division: 1/2 equals 0, use 1.0/2.0
2. Overflow: Large factorials or powers
3. Precision Loss: Too many operations
4. Wrong Units: Degrees vs radians
5. Insufficient Terms
## Testing and Validation

### Compare with Standard Library:

```cpp
double my_sin = sine_series(x, 10);
double std_sin = sin(x);
double error = fabs(my_sin - std_sin);
cout << "Error: " << error << endl;
````

**Validation Process:**

- Calculate value using your implementation
- Calculate same value using standard library function
- Find absolute difference between the two
- Output the error to verify accuracy
- Smaller error means better approximationegative values
- Multiple ranges

## Related Concepts

- Numerical methods
- Approximation algorithms
- Mathematical libraries
- Complex numbers
- Matrix operations
