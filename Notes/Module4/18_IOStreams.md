# 18 - IO Streams

## Study Plan

**Time Needed:** 2 hours  
**Difficulty:** ⭐⭐⭐ (Practical)  
**Prerequisites:** strings, file basics, control flow

---

## Definition (Memorize This)

```
┌──────────────────────────────────────────────────────────┐
│ IO STREAMS = Type-safe input/output abstraction in C++  │
│ for console, files, and string buffers                  │
└──────────────────────────────────────────────────────────┘
```

---

## Key Concepts

### 1. Standard Streams

- `cin` : standard input
- `cout` : standard output
- `cerr` : error output (unbuffered)

### 2. File Streams

- `ifstream` : read from file
- `ofstream` : write to file
- `fstream` : read + write

### 3. Stream State Flags

- `good()` : no errors
- `fail()` : logical format/read failure
- `bad()` : serious I/O error
- `eof()` : end-of-file reached

### 4. Safe Input Patterns

- Use `getline` for full-line string input
- Validate stream state after operations
- Reset/clear stream state when needed

---

## Common Pitfalls

```
┌──────────────────────────────────────────────────────────┐
│ ❌ Mixing `cin >>` and `getline` without cleanup          │
│ ❌ Ignoring stream fail state                            │
│ ❌ Using `endl` excessively (forces flush each time)      │
└──────────────────────────────────────────────────────────┘
```

---

## Best Practices

- Prefer `\n` over `std::endl` unless immediate flush is needed.
- Check stream success before processing input.
- Encapsulate file read/write into helper functions.

---

## Interview Drill

1. `endl` vs `\n`?
2. Why does `getline` sometimes read empty string after `cin >>`?
3. How do you detect and recover from stream fail state?

---

## Key Takeaways

1. Streams provide safer, unified I/O handling.
2. Always validate stream state.
3. Use line-based input carefully with token-based extraction.
