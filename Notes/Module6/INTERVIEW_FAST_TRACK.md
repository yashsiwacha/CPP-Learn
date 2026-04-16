# Module 6 - Fast Learning + Interview Notes (RAII + PIMPL)

This is the highest-yield modern C++ section for your upcoming interview.

Companion Q&A bank: [ALL_MODULES_INTERVIEW_QA.md](../ALL_MODULES_INTERVIEW_QA.md)

## 1. RAII in One Line

RAII binds resource lifetime to object lifetime so cleanup is automatic and exception-safe.

Typical resources:

- Memory
- File handles
- Mutex locks
- Network/socket handles
- Timers/transactions

Interview examples:

- `std::lock_guard<std::mutex>` for automatic unlock
- `std::unique_ptr<T>` for automatic deletion

## 2. PIMPL in One Line

PIMPL hides implementation details behind a pointer to private `Impl` to reduce dependencies and stabilize interfaces.

Header contains:

- Public API declarations
- `struct Impl;`
- `std::unique_ptr<Impl> impl;`

Source contains:

- Full `Impl` definition
- Heavy includes (`vector`, `map`, third-party headers)

## 3. Why Interviewers Like RAII + PIMPL

- Strong ownership model
- Cleaner architecture
- Better compile-time scalability
- Exception-safe cleanup by default

## 4. Rule-of-5 for PIMPL Classes

Because `unique_ptr` is move-only:

- Move ctor/assign are natural
- Copy operations require explicit deep-copy behavior

Pattern:

- Copy ctor: `impl = make_unique<Impl>(*other.impl)`
- Copy assign: deep copy underlying Impl
- Move ctor/assign: `std::move(other.impl)`

## 5. Typical Pitfalls

- Forgetting deep copy for PIMPL copies
- Accessing moved-from object without null checks
- Putting heavy headers in public API header
- Manual lock/unlock instead of lock guards

## 6. What to Say in Interview (ready lines)

- "RAII gives deterministic cleanup, so resources are released on all control paths, including exceptions."
- "PIMPL keeps ABI and compile dependencies stable by hiding private data layout in source files."
- "With PIMPL and unique_ptr, move is cheap but copy requires explicit deep-copy semantics."

## 7. Your Module 6 Task Map

- Task 4: RAII mutex locking
- Task 5: RAII timer lifetime
- Task 6: basic PIMPL separation
- Task 7: PIMPL + RAII dynamic resource
- Task 8: PIMPL deep copy + move
- Task 9: PIMPL for heavy dependencies
- Task 10: RAII + PIMPL network connection lifecycle

## Quick Practice Set (Module 6)

- Implement RAII logger class (open file in ctor, close in dtor)
- Implement PIMPL class with hidden vector/map state
- Add deep copy + move to a PIMPL class and test moved-from safety
- Explain ABI stability in 3 crisp bullet points
