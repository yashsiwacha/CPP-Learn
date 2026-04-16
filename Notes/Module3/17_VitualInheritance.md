# 17 - Virtual Inheritance

## Study Plan

**Time Needed:** 1.5-2 hours  
**Difficulty:** ⭐⭐⭐⭐ (Concept-heavy)  
**Prerequisites:** inheritance, polymorphism

---

## Definition (Memorize This)

```
┌──────────────────────────────────────────────────────────┐
│ VIRTUAL INHERITANCE = Share one common base subobject   │
│ in multiple-inheritance diamond hierarchies             │
└──────────────────────────────────────────────────────────┘
```

---

## Diamond Problem (Why It Exists)

If class `D` inherits from `B` and `C`, and both inherit from `A`, then `D` may contain two `A` parts.

Issues:

- Ambiguous member access
- Duplicate base state

Virtual inheritance makes `A` shared (single instance).

---

## Key Concepts

### 1. Syntax

Use `virtual` in base inheritance declaration:

- `class B : virtual public A`
- `class C : virtual public A`

### 2. Constructor Order Impact

- Virtual base is constructed by the most-derived class.
- Constructor initialization behavior differs from normal inheritance.

### 3. Practical Guidance

- Use only when solving a real diamond design need.
- Prefer composition when inheritance graph becomes complex.

---

## Common Pitfalls

```
┌──────────────────────────────────────────────────────────┐
│ ❌ Using multiple inheritance without clear design need   │
│ ❌ Forgetting virtual base constructor responsibility     │
│ ❌ Ambiguous member access in diamond hierarchy           │
└──────────────────────────────────────────────────────────┘
```

---

## Interview Drill (Quick)

1. Explain diamond problem with class diagram.
2. How virtual inheritance fixes duplicate base.
3. Why composition is often better than complex inheritance.

---

## Key Takeaways

1. Virtual inheritance solves duplicate-base ambiguity.
2. It changes construction responsibilities.
3. Use carefully; keep class hierarchies simple.
