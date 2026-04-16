# 21 - Variadic Templates

## Study Plan

**Time Needed:** 2-3 hours  
**Difficulty:** ⭐⭐⭐⭐ (Template-heavy)  
**Prerequisites:** templates, function overloading, type deduction basics

---

## Definition (Memorize This)

```
┌──────────────────────────────────────────────────────────┐
│ VARIADIC TEMPLATE = Template that accepts variable       │
│ number of type/value parameters                          │
└──────────────────────────────────────────────────────────┘
```

---

## Key Concepts

### 1. Parameter Packs

- Type pack: `typename... Args`
- Value pack: `Args... args`

### 2. Pack Expansion

- Recursive expansion (older pattern)
- Fold expressions (C++17 preferred)

Example fold:

- `(args + ...)` for left fold sum

### 3. Perfect Forwarding Context

- Common with variadic templates
- Uses forwarding references + `std::forward`
- Preserves value category (lvalue/rvalue)

### 4. Practical Uses

- Generic logging
- Forwarding wrappers/factories
- Tuple utilities and formatting utilities

---

## Common Pitfalls

```
┌──────────────────────────────────────────────────────────┐
│ ❌ Confusing variadic templates with C variadic args      │
│ ❌ Forgetting expansion context for parameter packs        │
│ ❌ Losing value categories without std::forward            │
└──────────────────────────────────────────────────────────┘
```

---

## Best Practices

- Prefer fold expressions where possible.
- Use `std::forward<Args>(args)...` in forwarding wrappers.
- Keep template error surface small with clear helper layers.

---

## Interview Drill

1. Variadic templates vs C-style variadic functions?
2. What does `typename... Args` represent?
3. What is fold expression with one example?
4. Why `std::forward` in variadic wrappers?

---

## Key Takeaways

1. Variadic templates provide type-safe flexible APIs.
2. Fold expressions simplify parameter-pack logic.
3. Perfect forwarding is essential in generic wrappers.
