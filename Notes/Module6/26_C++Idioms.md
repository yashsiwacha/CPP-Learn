# C++ Idioms (RAII + PIMPL)

## Study Plan

**Time Needed:** 5-7 hours  
**Difficulty:** ⭐⭐⭐⭐ (Hard)  
**Prerequisites:** OOP fundamentals, pointers, dynamic memory, constructors/destructors

**Goal:** Learn production-grade C++ design patterns for safe ownership, exception safety, and compile-time scalability.

---

## Definition (Memorize This)

```
┌──────────────────────────────────────────────────────────┐
│ RAII = Resource lifetime tied to object lifetime        │
│        (acquire in constructor, release in destructor)  │
│                                                          │
│ PIMPL = Pointer to implementation                         │
│         (hide private details behind stable interface)    │
│                                                          │
│ Together: safe cleanup + cleaner APIs + faster builds    │
└──────────────────────────────────────────────────────────┘
```

---

## Architecture View (Draw This)

```
User Code (main.cpp)
	|
	v
Public Header (small, stable)
class Widget {
  struct Impl;
  unique_ptr<Impl> impl;
}
	|
	v
Implementation (.cpp)
 - Full Impl definition
 - Heavy includes
 - Resource management (RAII)
```

---

## Key Concepts

### 1. RAII Basics

RAII means resources are acquired and released automatically via object lifetime.

| Resource Type | Acquire                     | Release                        |
| ------------- | --------------------------- | ------------------------------ |
| Heap memory   | `new` / `make_unique`       | destructor / smart pointer     |
| Mutex lock    | `lock_guard` constructor    | `lock_guard` destructor        |
| File/Socket   | open/connect in constructor | close/disconnect in destructor |

Benefits:

- No forgotten cleanup on error paths
- Exception-safe by default
- Smaller and clearer code

### 2. PIMPL Basics

PIMPL separates interface and implementation:

- Header: declarations only
- Source: `Impl` data + logic + heavy includes

Benefits:

- Reduced recompilation of dependent files
- Better encapsulation of internal data layout
- ABI stability for library distribution

### 3. Rule of 5 with PIMPL

When class owns `std::unique_ptr<Impl>`:

- Move operations are natural and cheap
- Copy operations require explicit deep copy

Typical plan:

- Copy ctor: allocate new Impl copied from source
- Copy assign: deep copy Impl content
- Move ctor/assign: transfer ownership via `std::move`

### 4. Exception Safety with RAII

RAII guarantees cleanup during stack unwinding.

Examples from this module:

- lock released even if exception occurs in critical section
- timer reports scope end even on early return
- network connection closes at scope exit

---

## Module 6 Task Map (1 to 10)

### Task 1: RAII File Wrapper

File: `../../../../Module6/26_C++Idioms/Task1RAIIBasics_FileWrapper.cpp`

- Resource: file handle
- Key takeaway: automatic close in destructor

### Task 2: RAII Dynamic Memory

File: `../../../../Module6/26_C++Idioms/Task2RAIIDynamicMemory.cpp`

- Resource: heap memory
- Key takeaway: cleanup tied to scope, not manual calls

### Task 3: RAII Smart Pointers

File: `../../../../Module6/26_C++Idioms/Task3RAIISmartPointers.cpp`

- Resource: owned object via `unique_ptr`
- Key takeaway: safer than raw `new/delete`

### Task 4: RAII Mutex Locking

File: `../../../../Module6/26_C++Idioms/Task4RAIIMutexLocking.cpp`

- Resource: mutex lock
- Key takeaway: `lock_guard` prevents unlock bugs and deadlocks

### Task 5: RAII Timer Lifetime

File: `../../../../Module6/26_C++Idioms/Task5RAIIResourceLifetimeTimer.cpp`

- Resource: timing scope state
- Key takeaway: RAII works beyond memory/file resources

### Task 6: PIMPL Basics

File: `../../../../Module6/26_C++Idioms/Task6PIMPLBasicsSingleFile.cpp`

- `Impl` hidden from header users
- Key takeaway: stable interface, hidden implementation

### Task 7: PIMPL + RAII Dynamic Resource

File: `../../../../Module6/26_C++Idioms/Task7PIMPLWithDynamicResource.cpp`

- Impl owns dynamic buffer and releases in destructor
- Key takeaway: hidden resource management with deterministic cleanup

### Task 8: PIMPL Copy and Move Semantics

File: `../../../../Module6/26_C++Idioms/Task8PIMPLCopyMoveSemantics.cpp`

- Deep copy for copy operations, ownership transfer for moves
- Key takeaway: proper value semantics with `unique_ptr<Impl>`

### Task 9: PIMPL for Heavy Dependencies

File: `../../../../Module6/26_C++Idioms/Task9PIMPLLargeDependencies.cpp`

- Heavy includes kept out of header
- Key takeaway: lower compile overhead for users

### Task 10: Combine RAII + PIMPL (NetworkConnection)

File: `../../../../Module6/26_C++Idioms/Task10RAIIPIMPLNetworkConnection.cpp`

- Connection opens in Impl constructor and closes in Impl destructor
- Key takeaway: robust abstraction with clear ownership and hidden internals

---

## Common Mistakes

```
┌──────────────────────────────────────────────────────────┐
│ ❌ Manual lock()/unlock() across multiple return paths    │
│ ❌ Using raw new/delete where unique_ptr is enough        │
│ ❌ Defining heavy containers directly in public header    │
│ ❌ Copying PIMPL class without deep-copy logic            │
│ ❌ Accessing moved-from objects without null checks       │
│ ❌ Forgetting virtual destructor in polymorphic bases     │
└──────────────────────────────────────────────────────────┘
```

---

## Best Practices

| Practice                             | Why It Helps                                  |
| ------------------------------------ | --------------------------------------------- |
| Prefer `std::unique_ptr<Impl>`       | Clear ownership, automatic cleanup            |
| Keep heavy includes in `.cpp`        | Faster incremental builds                     |
| Use `std::lock_guard` for mutexes    | Exception-safe lock release                   |
| Implement deep copy only if required | Correct semantics for copyable PIMPL types    |
| Treat moved-from as valid-but-empty  | Prevents undefined behavior and crashes       |
| Keep API small and stable            | Easier maintenance and ABI-friendly evolution |

---

## Interview Cheat Sheet

1. RAII guarantees deterministic cleanup on every control path.
2. PIMPL hides data layout and heavy dependencies from header consumers.
3. `unique_ptr<Impl>` makes move easy and copy explicit.
4. Deep copy is required when copy semantics are needed for PIMPL classes.
5. RAII + PIMPL is a production-friendly pattern for robust C++ libraries.

---

## Quick Revision Drill (20 Minutes)

- 5 min: RAII definition + 3 practical examples
- 5 min: PIMPL structure (what goes in header vs source)
- 5 min: Rule-of-5 copy/move behavior in Task 8
- 5 min: explain one benefit each for safety, performance, and maintainability

If you can explain all four sections without looking, you are interview-ready for this module.
