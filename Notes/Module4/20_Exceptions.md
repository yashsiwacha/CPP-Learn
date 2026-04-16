# 20 - Exceptions

## Study Plan

**Time Needed:** 2-3 hours  
**Difficulty:** ⭐⭐⭐⭐ (Design + correctness critical)  
**Prerequisites:** functions, classes, RAII basics

---

## Definition (Memorize This)

```
┌──────────────────────────────────────────────────────────┐
│ EXCEPTIONS = Structured runtime error handling in C++   │
│ using try / throw / catch                               │
└──────────────────────────────────────────────────────────┘
```

---

## Key Concepts

### 1. Core Flow

- `throw` creates exceptional control transfer
- `try` marks protected region
- `catch` handles specific exception types

### 2. Best Handling Rules

- Throw by value
- Catch by (const) reference
- Catch specific exception types before generic handlers

### 3. Stack Unwinding and RAII

When exception propagates:

- Local destructors run automatically
- RAII cleanup remains reliable

### 4. Safety Guarantees (Interview Favorite)

- Basic guarantee: no leaks, valid state
- Strong guarantee: operation succeeds fully or has no effect
- Nothrow guarantee: operation never throws

---

## Common Pitfalls

```
┌──────────────────────────────────────────────────────────┐
│ ❌ Throwing raw pointers/strings as ad-hoc exceptions     │
│ ❌ Catching exceptions by value (extra copy/slicing)      │
│ ❌ Throwing from destructors during unwinding             │
│ ❌ Using exceptions for normal control flow               │
└──────────────────────────────────────────────────────────┘
```

---

## Best Practices

- Derive custom exceptions from `std::exception`.
- Keep exception messages meaningful.
- Design APIs with clear exception behavior.
- Pair with RAII for cleanup guarantees.

---

## Interview Drill

1. Throw-by-value/catch-by-reference: why?
2. What is stack unwinding?
3. Why should destructors avoid throwing?
4. Difference between error codes and exceptions?

---

## Key Takeaways

1. Exceptions improve error separation from normal logic.
2. RAII + exceptions is the safe C++ combination.
3. Exception safety guarantees are core design tools.
