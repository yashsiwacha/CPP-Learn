# 16 - Polymorphism

## Study Plan

**Time Needed:** 2-3 hours  
**Difficulty:** ⭐⭐⭐⭐ (Important interview topic)  
**Prerequisites:** classes, inheritance, function overloading

---

## Definition (Memorize This)

```
┌──────────────────────────────────────────────────────────┐
│ POLYMORPHISM = Same interface, different behavior       │
│                                                          │
│ Types:                                                   │
│  • Compile-time: overloading, templates                 │
│  • Runtime: virtual functions + inheritance             │
└──────────────────────────────────────────────────────────┘
```

---

## Key Concepts

### 1. Compile-Time Polymorphism

- Function overloading
- Operator overloading
- Templates

Resolved by compiler before runtime.

### 2. Runtime Polymorphism

- Base pointer/reference to derived object
- Virtual function call resolves at runtime
- Needs inheritance + `virtual`

### 3. Critical Keywords

- `virtual`: enables dynamic dispatch
- `override`: compile-time safety for overrides
- `final`: blocks further override/inheritance

### 4. Virtual Destructor Rule

If class is used polymorphically, base destructor should be virtual.

Reason: deleting derived object via base pointer must run both destructors.

---

## Common Pitfalls

```
┌──────────────────────────────────────────────────────────┐
│ ❌ Missing virtual destructor in polymorphic base         │
│ ❌ Signature mismatch when overriding                     │
│ ❌ Object slicing with base-by-value                      │
│ ❌ Expecting runtime behavior without virtual keyword     │
└──────────────────────────────────────────────────────────┘
```

---

## Best Practices

- Always use `override` in derived overrides.
- Prefer references/pointers to base to avoid slicing.
- Keep interfaces small and behavior-focused.
- Use composition if polymorphism is not required.

---

## Interview Drill (5 Questions)

1. Compile-time vs runtime polymorphism?
2. Why `override`?
3. Why virtual destructor in base classes?
4. What is object slicing?
5. When to prefer composition over inheritance?

---

## Key Takeaways

1. Runtime polymorphism needs `virtual` dispatch.
2. `override` prevents silent bugs.
3. Virtual destructors are mandatory for safe polymorphic deletion.
4. Avoid slicing by using base references/pointers.
