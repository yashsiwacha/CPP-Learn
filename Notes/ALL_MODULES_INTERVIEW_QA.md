# All Modules - Interview Rapid-Fire Sheet

Use this as a final revision file before interview rounds.

## Module Mapping

- Single source of truth for interview Q&A across all modules.
- Use this file as your only interview question bank.

## Top 30 Must-Know Questions

1. Stack vs heap?
   Answer: Stack memory is automatic and tied to scope, so it is fast and simple. Heap memory is dynamic and flexible, but you must manage ownership properly, ideally through RAII and smart pointers.

2. Pass by value vs reference vs const reference?
   Answer: Pass by value when you need an independent copy, by reference when the function should modify the original, and by const reference for read-only access without copying large objects.

3. Rule of 3/5/0?
   Answer: If a class manually manages resources, define special member functions carefully: Rule of 3 in classic C++, Rule of 5 with move semantics, and Rule of 0 when RAII members like smart pointers handle ownership for you.

4. Shallow vs deep copy?
   Answer: Shallow copy copies handles only, so two objects may share the same resource unintentionally. Deep copy duplicates the resource so each object owns its own state.

5. unique_ptr/shared_ptr/weak_ptr?
   Answer: `unique_ptr` is for exclusive ownership, `shared_ptr` is for shared ownership with reference counting, and `weak_ptr` is a non-owning reference mainly used to break `shared_ptr` cycles.

6. Why virtual destructor?
   Answer: In polymorphic hierarchies, a virtual destructor ensures correct destructor chaining when deleting via a base pointer, preventing partial destruction and leaks.

7. What is object slicing?
   Answer: Object slicing happens when a derived object is copied into a base object by value, which removes the derived part. Use base references or pointers to avoid it.

8. Encapsulation vs abstraction?
   Answer: Encapsulation is about protecting internal state through controlled access. Abstraction is about exposing what the object does while hiding how it does it.

9. Inheritance vs composition?
   Answer: Use inheritance only for true is-a relationships with polymorphic behavior. Prefer composition for has-a relationships because it gives better flexibility and lower coupling.

10. Compile-time vs runtime polymorphism?
    Answer: Compile-time polymorphism is resolved by the compiler, like overloading and templates. Runtime polymorphism is resolved at execution using virtual functions via base references or pointers.

11. What is override?
    Answer: `override` tells the compiler this method must override a virtual base method, so it catches signature mistakes early.

12. What is RAII?
    Answer: RAII means acquire a resource during object creation and release it in the destructor, giving deterministic and exception-safe cleanup.

13. Why lock_guard?
    Answer: `std::lock_guard` guarantees the mutex is unlocked at scope exit, including early returns and exceptions, so it prevents deadlock-prone manual unlock mistakes.

14. What is PIMPL?
    Answer: PIMPL hides implementation details behind a forward-declared `Impl` pointer, keeping headers clean and reducing coupling.

15. Why PIMPL improves build times?
    Answer: PIMPL moves heavy includes to `.cpp` files, reducing transitive dependencies in headers and therefore reducing recompilation impact.

16. map vs unordered_map?
    Answer: `map` keeps sorted order with O(log n) operations; `unordered_map` gives average O(1) lookups using hashing but has no ordering guarantees.

17. vector internals and growth behavior?
    Answer: `vector` stores elements contiguously and grows by reallocating to larger capacity, typically geometric growth, which can invalidate pointers and iterators.

18. Iterator invalidation basics?
    Answer: Iterator validity depends on container and operation. For example, `vector` reallocation invalidates all iterators, while some node-based containers keep most iterators valid.

19. Header guards vs pragma once?
    Answer: Both prevent multiple inclusion. Include guards are standard and portable; `#pragma once` is cleaner and widely supported in modern compilers.

20. Common memory bugs and fixes?
    Answer: Common bugs are leaks, dangling pointers, double delete, and use-after-free. The practical fix is clear ownership design with RAII and smart pointers.

21. Why const correctness matters?
    Answer: Const correctness communicates intent, prevents accidental mutation, and makes APIs safer and easier to reason about.

22. What is exception safety guarantee?
    Answer: Basic guarantee preserves valid state, strong guarantee gives commit-or-rollback behavior, and nothrow guarantee promises no exceptions.

23. What is move semantics?
    Answer: Move semantics transfers resource ownership from temporary or expiring objects, avoiding expensive deep copies.

24. lvalue vs rvalue?
    Answer: An lvalue has stable identity and addressable storage; an rvalue is typically a temporary value meant to be moved from.

25. Why std::move does not move by itself?
    Answer: `std::move` only casts to an rvalue reference. Actual movement happens only if a move constructor or move assignment is available and selected.

26. Can constructors be virtual?
    Answer: No, constructors cannot be virtual because object type must already be known before construction.

27. Why avoid macros when possible?
    Answer: Macros are not type-safe, ignore scope rules, and are harder to debug. Prefer `constexpr`, inline functions, and templates.

28. What is ABI stability?
    Answer: ABI stability means you can update implementation without breaking binary compatibility for already-compiled client programs.

29. Why use interfaces/abstract classes?
    Answer: Interfaces decouple usage from implementation, improve testability, and enable substitutable implementations through polymorphism.

30. Explain your strongest C++ project design choice.
    Answer: "My strongest design choice was combining RAII and PIMPL: RAII gave deterministic cleanup and exception safety, while PIMPL improved encapsulation and reduced compile-time coupling."

## 1-Minute Pitch Template (for self-introduction in technical round)

"I am strongest in core C++ fundamentals, OOP design, and modern idioms like RAII and PIMPL. I focus on writing safe, maintainable code with clear ownership using smart pointers and exception-safe patterns. Recently I implemented copy/move-safe PIMPL classes and RAII-based resource wrappers for mutex and connection lifecycles."
