# Module 7 Task Notes

## Task 1: Numeric Casting - C-style vs static_cast

File: Module7/27_Various C++ Castings and RTTI/Task1NumericCasting–C-stylevsstatic_cast.cpp
Date: 2026-04-06

### What this task demonstrates

- Numeric conversion between `int` and `double` using C-style casts.
- Equivalent conversion using `static_cast` in modern C++.
- Narrowing conversion behavior when converting `double` to `int`.

### Key output takeaways

- `int -> double` keeps numeric value (`10` becomes `10.0` in floating-point context).
- `double -> int` truncates fractional part (`3.7` becomes `3`).
- Both C-style and `static_cast` produce the same numeric result in this simple case.

### Safety notes

- C-style casts are terse but less explicit and harder to audit in large codebases.
- `static_cast` clearly expresses conversion intent and is easier to search in reviews.
- Prefer `static_cast` in modern C++ for readability and safer coding practice.

## Task 2: Inheritance Casting - static_cast vs dynamic_cast

File: Module7/27_Various C++ Castings and RTTI/Task2InheritanceCasting–static_castvsdynamic_cast.cpp
Date: 2026-04-06

### What this task demonstrates

- Polymorphic base class `Shape` with virtual destructor (required for RTTI in `dynamic_cast`).
- Downcasting with `static_cast` (unchecked at runtime).
- Safe downcasting with `dynamic_cast` pointers (returns `nullptr` on failure).
- Safe downcasting with `dynamic_cast` references (throws `std::bad_cast` on failure).

### Key output takeaways

- `dynamic_cast<Circle*>(s)` succeeds when `s` actually points to `Circle`.
- `dynamic_cast<Rectangle*>(s)` fails and returns `nullptr` when types do not match.
- `dynamic_cast<Circle&>(*s2)` throws `std::bad_cast` when `*s2` is `Rectangle`.

### Safety notes

- `static_cast` downcasting is only valid when the dynamic type is known and correct.
- Wrong `static_cast` downcasts can cause undefined behavior when used.
- Always check pointer results from `dynamic_cast` before dereferencing.

## Task 3: const_cast - safe vs unsafe const removal

File: Module7/27_Various C++ Castings and RTTI/Task3ConstCasting–const_castsafevsunsafe.cpp
Date: 2026-04-06

### What this task demonstrates

- Removing constness with `const_cast` in two scenarios.
- Unsafe case: writing to a truly `const` object (`const int x`).
- Safe case: modifying an originally non-const variable through a `const int*` view.

### Key output takeaways

- Attempting to modify `x` is undefined behavior (may appear unchanged, changed, or crash).
- Modifying `y` is valid because `y` was originally non-const.

### Safety notes

- `const_cast` should not be used to break actual constness.
- Writing to truly const objects after cast is undefined behavior.
- Safe usage is rare and usually for legacy APIs where original data is non-const.

## Task 4: reinterpret_cast and low-level memory dangers

File: Module7/27_Various C++ Castings and RTTI/Task4ReinterpretCasting-lowlevelmemorydangers.cpp
Date: 2026-04-06

### What this task demonstrates

- Viewing an `int` as raw bytes via `reinterpret_cast<unsigned char*>`.
- Observing byte order in memory (endianness insight).
- Unsafe cast between unrelated pointer types (`int*` to `double*`) and UB write.

### Key output takeaways

- Byte print order depends on architecture (often little-endian on modern PCs).
- Reading and writing through unrelated pointer types produces undefined behavior.
- UB results are unreliable: nonsense values, inconsistent output, or crashes.

### Safety notes

- `reinterpret_cast` gives raw power with no type safety checks.
- Code relying on low-level layout assumptions is typically non-portable.
- Prefer higher-level, type-safe alternatives unless low-level control is truly required.

## Task 5: RTTI with typeid and dynamic_cast

File: Module7/27_Various C++ Castings and RTTI/Task5RTTI-typeidanddynamic_cast.cpp
Date: 2026-04-06

### What this task demonstrates

- Polymorphic hierarchy with `Animal` base and `Dog`/`Cat` derived classes.
- Using `typeid(*ptr).name()` to inspect dynamic type at runtime.
- Using `dynamic_cast` to safely downcast from base pointer and call derived-specific methods.

### Key output takeaways

- `speak()` dispatch is virtual and resolves to the correct derived override.
- `typeid` displays runtime type names (compiler-dependent formatting).
- `dynamic_cast` safely selects `Dog` or `Cat`; failed pointer casts return `nullptr`.

### Safety notes

- RTTI features require polymorphic base classes (for example, virtual destructor).
- `typeid` is for identification; `dynamic_cast` is for safe conversion.
- If RTTI is disabled by compiler options, `typeid`/`dynamic_cast` usage may fail for polymorphic downcasting scenarios.

## Task 6: Avoiding dangling pointers in a library system

File: Module7/28_Memory Management Tasks/Task6DanglingPointers-librarysmartpointers.cpp
Date: 2026-04-06

### What this task demonstrates

- Replacing `std::vector<Book*>` with `std::vector<std::unique_ptr<Book>>` for ownership safety.
- Automatic cleanup when a book is erased (no manual `delete`).
- How observer raw pointers can become invalid after removal and should be invalidated.

### Key output takeaways

- Book is found and printed before removal.
- Removing a book frees memory automatically through `unique_ptr`.
- Resetting the observer pointer to `nullptr` avoids use-after-free.

### Safety notes

- `unique_ptr` prevents leaks and double-delete bugs by enforcing single ownership.
- Raw pointers returned by `.get()` are non-owning observers only.
- Never dereference an observer pointer after the pointed object may have been erased.

## Task 7: Smart pointer lifecycle with Logger and unique_ptr

File: Module7/28_Memory Management Tasks/Task7SmartPointerLifecycle-loggerunique_ptr.cpp
Date: 2026-04-06

### What this task demonstrates

- `Logger` lifecycle events (create, log, close, destroy) with deterministic cleanup.
- `std::unique_ptr` ownership changes across assignment, reset, nullptr assignment, and move.
- How old owned objects are destroyed automatically when ownership is replaced.

### Key output takeaways

- Reassigning/resetting destroys the previous logger immediately.
- `logger2` becomes `nullptr` after `logger = std::move(logger2)`.
- End-of-scope destroys the last owned logger automatically via RAII.

### Safety notes

- `std::unique_ptr` cannot be copied; ownership must be moved.
- Prefer `std::make_unique` for exception-safe construction.
- Self-move should be avoided in real code; behavior should not be relied upon.

## Task 8: Critical system monitor with SensorReport ownership

File: Module7/28_Memory Management Tasks/Task8CriticalSystemMonitor-uniqueownershipsensorreport.cpp
Date: 2026-04-06

### What this task demonstrates

- Managing a custom class object (`SensorReport`) with `std::unique_ptr`.
- Constructor/destructor lifecycle tracing for creation and automatic cleanup.
- Accessing class methods through smart-pointer arrow operator (`->`).

### Key output takeaways

- `SensorReport` is created once with raw sensor input data.
- Details are processed via `criticalReportPtr->displayDetails()`.
- Destructor message appears automatically when `criticalReportPtr` goes out of scope.

### Safety notes

- `std::unique_ptr` enforces exclusive ownership (copy attempt is compile-time error).
- Automatic destruction prevents leaks in long-running systems.
- Prefer `std::make_unique` for safe and clear object construction.

## Task 9: Resource handover with unique_ptr::release

File: Module7/28_Memory Management Tasks/Task9ResourceHandover-unique_ptrrelease.cpp
Date: 2026-04-06

### What this task demonstrates

- Managing a `LogMessage` object with `std::unique_ptr`.
- Releasing ownership explicitly with `myLog.release()`.
- Handing raw ownership to a legacy-style function that deletes the object.

### Key output takeaways

- Constructor prints creation and heap address under `unique_ptr` management.
- After `release()`, `myLog` becomes `nullptr` and no longer owns the object.
- Destructor runs from `handleLegacyLog` after `delete rawMessage`.

### Safety notes

- `release()` transfers responsibility; forgetting to delete the raw pointer leaks memory.
- `release()` prevents double deletion because `unique_ptr` no longer owns the object.
- Prefer staying in smart-pointer ownership unless legacy interop requires raw pointers.

## Task 10: Ownership transfer with unique_ptr and std::move

File: Module7/28_Memory Management Tasks/Task10OwnershipTransfer-filehandlerunique_ptrmove.cpp
Date: 2026-04-06

### What this task demonstrates

- A `FileHandler` class managed with `std::unique_ptr`.
- Returning unique ownership from `createFileHandler()`.
- Transferring ownership to `processFileHandler()` via `std::move`.

### Key output takeaways

- Constructor prints "File opened." when resource is acquired.
- `processFileHandler()` writes a message and then triggers automatic cleanup at scope end.
- After move, the original pointer becomes `nullptr` and must not be dereferenced.

### Safety notes

- `std::move` transfers ownership; source pointer enters moved-from state.
- Always check moved-from pointers before use.
- RAII ensures deterministic cleanup (`File closed.`) without manual `delete`.

## Task 11: Game asset smart pointer selection

File: Module7/28_Memory Management Tasks/Task11GameAssetManagement-smartpointerselection.cpp
Date: 2026-04-06

### What this task demonstrates

- `Texture` managed with `std::unique_ptr` for exclusive per-object ownership.
- `Shader` managed with `std::shared_ptr` for reusable shared ownership.
- `GameObject` drawing, texture replacement, and scope-based cleanup behavior.

### Key output takeaways

- Texture load/unload messages show strict object-local ownership.
- Shared shaders stay alive across multiple GameObjects and delete when last user is gone.
- Replacing player texture triggers immediate unload of previous texture and load of new one.

### Safety notes

- Choose `unique_ptr` when one owner controls lifetime.
- Choose `shared_ptr` when multiple objects need coordinated lifetime.
- Using `make_unique` and `make_shared` improves safety and clarity over raw `new`.

## Task 12: File resource with unique_ptr custom deleter

File: Module7/28_Memory Management Tasks/Task12FileResources-unique_ptrcustomdeleter.cpp
Date: 2026-04-06

### What this task demonstrates

- Managing `FILE*` with `std::unique_ptr` using a lambda custom deleter.
- Writing to a file with `fprintf` through `filePtr.get()`.
- Proper error handling for failed `fopen`.

### Key output takeaways

- On success, program writes `Log started` to `log.txt`.
- Scope exit triggers custom deleter and prints file-closed message.
- On open failure, program exits with a clear error message.

### Safety notes

- Default `unique_ptr` deleter is for `delete`; `FILE*` needs `fclose`.
- Custom deleters extend RAII to non-memory resources.
- This pattern prevents resource leaks even with early returns.

### Habit for next tasks

- For every new `TaskN...cpp` file in Module 7, add a new section here with:
  - task title and file name
  - concept summary
  - key outputs
  - common pitfalls and best practices



