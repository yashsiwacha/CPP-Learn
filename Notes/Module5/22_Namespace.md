# 22 - Namespace

## Study Plan

**Time Needed:** 1-1.5 hours  
**Difficulty:** ⭐⭐ (Easy but important for clean codebases)  
**Prerequisites:** scopes, headers/source organization

---

## Definition (Memorize This)

```
┌──────────────────────────────────────────────────────────┐
│ NAMESPACE = Named scope used to group symbols and avoid │
│ collisions in large codebases                           │
└──────────────────────────────────────────────────────────┘
```

---

## Key Concepts

### 1. Basic Namespace Usage

- Define: `namespace app { ... }`
- Access: `app::functionName()`

### 2. Namespace Alias

- Simplifies long names
- Example style: `namespace fs = std::filesystem;`

### 3. Anonymous Namespace

- `namespace { ... }` in source file
- Gives internal linkage to symbols in that translation unit

### 4. Header Hygiene Rule

Avoid `using namespace ...` in headers.

Reason: pollutes global namespace for all including files.

---

## Common Pitfalls

```
┌──────────────────────────────────────────────────────────┐
│ ❌ using namespace in header files                        │
│ ❌ Inconsistent namespace naming across modules           │
│ ❌ Global-symbol clutter in large projects                │
└──────────────────────────────────────────────────────────┘
```

---

## Best Practices

- Keep namespace names meaningful and stable.
- Use nested namespaces for large systems.
- Keep helper/internal symbols in anonymous namespace (.cpp).

---

## Interview Drill

1. Why namespaces are needed in C++?
2. Why avoid `using namespace` in headers?
3. Namespace alias and anonymous namespace use-cases?

---

## Key Takeaways

1. Namespaces prevent symbol collisions cleanly.
2. Header hygiene with namespaces is critical.
3. Anonymous namespace is a simple internal-linkage tool.
