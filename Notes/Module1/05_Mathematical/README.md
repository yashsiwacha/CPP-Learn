# Mathematical Programming

## Overview

Mathematical programming involves implementing mathematical formulas, series, and algorithms in code.

## Topics Covered

### 1. Exponential Series

**File Reference**: [exponential_series.cpp](../../Module1/05_Mathematical/exponential_series.cpp)

#### Mathematical Formula:

$$e^x = 1 + x + \frac{x^2}{2!} + \frac{x^3}{3!} + \frac{x^4}{4!} + ...$$

#### Key Concepts:

- Series expansion
- Factorial calculation
- Power calculation
- Convergence and precision
- Loop-based accumulation

#### Implementation Approach:

```cpp
double exponential(double x, int terms) {
    double result = 1.0;  // First term
    double term = 1.0;

    for(int i = 1; i < terms; i++) {
        term *= x / i;  // x^i / i!
        result += term;
    }
    return result;
}
```

#### Concepts Demonstrated:

- Iterative calculation
- Accumulator pattern
- Mathematical precision
- Term-by-term computation

### 2. Sine Series

**File Reference**: [sine_series.cpp](../../Module1/05_Mathematical/sine_series.cpp)

#### Mathematical Formula:

$$\sin(x) = x - \frac{x^3}{3!} + \frac{x^5}{5!} - \frac{x^7}{7!} + ...$$

#### Key Concepts:

- Alternating series
- Odd power terms
- Sign alternation
- Radian conversion
- Taylor series

#### Implementation Approach:

```cpp
double sine(double x, int terms) {
    double result = 0;
    double term = x;

    for(int i = 0; i < terms; i++) {
        result += term;
        term *= -x * x / ((2*i+2) * (2*i+3));
    }
    return result;
}
```

#### Important Points:

- Input should be in radians
- Sign alternates: +, -, +, -, ...
- Only odd powers: x, x³, x⁵, x⁷, ...
- Converges for all x

## Mathematical Concepts

### 1. Series Expansion

- Infinite sum representation
- Approximation using finite terms
- More terms = better accuracy
- Used for function computation

### 2. Factorial

```cpp
int factorial(int n) {
    int result = 1;
    for(int i = 2; i <= n; i++)
        result *= i;
    return result;
}
```

- n! = n × (n-1) × (n-2) × ... × 2 × 1
- 0! = 1 (by definition)
- Grows very rapidly

### 3. Power Calculation

```cpp
double power(double base, int exp) {
    double result = 1.0;
    for(int i = 0; i < exp; i++)
        result *= base;
    return result;
}
```

- Repeated multiplication
- Can use `pow()` from `<cmath>`
- Watch for overflow

### 4. Convergence

- Series approaches actual value
- More terms = closer to actual
- Some series converge faster
- Stop when desired accuracy reached

## Taylor Series

### General Form:

$$f(x) = f(a) + f'(a)(x-a) + \frac{f''(a)}{2!}(x-a)^2 + \frac{f'''(a)}{3!}(x-a)^3 + ...$$

### Common Series:

#### e^x (Exponential):

- $e^x = \sum_{n=0}^{\infty} \frac{x^n}{n!}$
- Converges for all x

#### sin(x) (Sine):

- $\sin(x) = \sum_{n=0}^{\infty} \frac{(-1)^n x^{2n+1}}{(2n+1)!}$
- Converges for all x

#### cos(x) (Cosine):

- $\cos(x) = \sum_{n=0}^{\infty} \frac{(-1)^n x^{2n}}{(2n)!}$
- Converges for all x

#### ln(1+x) (Natural Log):

- $\ln(1+x) = \sum_{n=1}^{\infty} \frac{(-1)^{n+1} x^n}{n}$
- Converges for -1 < x ≤ 1

## Optimization Techniques

### 1. Avoid Repeated Calculations:

```cpp
// Instead of calculating power and factorial separately
term = term * x / i;  // Incremental calculation
```

### 2. Early Termination:

```cpp
if(fabs(term) < threshold) break;
```

- Stop when term becomes negligible
- Saves computation
- Maintains accuracy

### 3. Precomputation:

```cpp
// Precompute factorials if needed multiple times
int fact[20];
fact[0] = 1;
for(int i = 1; i < 20; i++)
    fact[i] = fact[i-1] * i;
```

### 4. Use Built-in Functions:

```cpp
#include <cmath>
exp(x);   // Exponential
sin(x);   // Sine
cos(x);   // Cosine
pow(x,y); // Power
```

## Numerical Precision

### 1. Floating Point Issues:

- Limited precision (typically 6-7 digits for float)
- Use `double` for better precision
- Be aware of rounding errors

### 2. Large Numbers:

- Factorials grow very fast
- May cause overflow
- Use `long long` or libraries for big numbers

### 3. Small Numbers:

- Terms may become too small
- May lose significance
- Use threshold for termination

## Best Practices

1. **Precision**: Use `double` instead of `float`
2. **Validation**: Check input ranges
3. **Convergence**: Set appropriate number of terms
4. **Efficiency**: Optimize calculations
5. **Testing**: Compare with standard library functions
6. **Documentation**: Explain mathematical formulas
7. **Constants**: Use `const` for mathematical constants

## Common Pitfalls

1. **Integer Division**: `1/2` = 0, use `1.0/2.0`
2. **Overflow**: Large factorials or powers
3. **Precision Loss**: Too many operations
4. **Wrong Units**: Degrees vs radians
5. **Insufficient Terms**: Poor approximation

## Testing and Validation

### Compare with Standard Library:

```cpp
double my_sin = sine_series(x, 10);
double std_sin = sin(x);
double error = fabs(my_sin - std_sin);
cout << "Error: " << error << endl;
```

### Test Cases:

- Known values (sin(π/6) = 0.5)
- Edge cases (0, very large, very small)
- Negative values
- Multiple ranges

## Related Concepts

- Numerical methods
- Approximation algorithms
- Mathematical libraries
- Complex numbers
- Matrix operations
