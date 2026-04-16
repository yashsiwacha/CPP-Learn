# Module 2 - Fast Learning + Interview Notes

High-yield revision for OOP and memory-heavy interview topics.

Companion Q&A bank: [ALL_MODULES_INTERVIEW_QA.md](../ALL_MODULES_INTERVIEW_QA.md)

## 1. OOP Fundamentals

- Class = data + behavior.
- Constructor initializes object; destructor releases owned resources.
- Encapsulation: hide internal state, expose controlled API.

Interview points:

- Why constructors should establish valid object state.
- Why destructors should be noexcept-friendly.

## 2. Four Pillars Summary

- Encapsulation: hide data with private/protected.
- Abstraction: expose essential interface, hide details.
- Inheritance: derive new behavior from existing types.
- Polymorphism: one interface, many implementations.

## 3. Inheritance and Polymorphism

- Use `virtual` for runtime polymorphism.
- Use `override` always for derived overrides.
- Add virtual destructor in polymorphic base classes.

Interview points:

- Object slicing and how to avoid it.
- Composition vs inheritance: prefer composition unless true is-a.

## 4. Memory Management and RAII

- RAII: acquire in constructor, release in destructor.
- Prefer `std::unique_ptr` for exclusive ownership.
- Use `std::shared_ptr` only when shared ownership is required.
- `std::weak_ptr` breaks shared_ptr cycles.

Interview points:

- Rule of 3/5/0 and when each applies.
- Shallow copy vs deep copy.

## 5. Common Bugs Interviewers Ask

- Memory leak
- Double delete
- Dangling pointer / use-after-free
- Null dereference
- Missing virtual destructor in base class

## 6. Design Quality Signals

- Small coherent classes
- Clear ownership semantics
- Const-correctness (`const` member funcs, `const&` params)
- Minimal public surface area

## Quick Practice Set (Module 2)

- Design base `Shape` with derived `Circle/Rectangle` and virtual `area()`
- Implement class with deep copy semantics
- Implement class with unique_ptr member and move support
- Show bad vs good ownership design in two versions
