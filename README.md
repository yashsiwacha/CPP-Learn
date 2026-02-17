# CPPLearn - C++ Learning Project

Complete C++ learning repository with 100+ example programs covering basics to advanced concepts.

## 📁 Project Structure

### Module 1 - Fundamentals
- **01_Arrays** - Array operations, searching, sorting, matrices
- **02_Functions** - Function examples, banking system, converters
- **03_Data** - Data structures, classes, book management
- **04_Conditionals** - If/else, switch, calculators
- **05_Mathematical** - Series calculations, exponentials
- **06_Recursion** - Recursive algorithms, directory traversal
- **07_Structure** - C structures
- **08_Pointers** - Pointer basics, dynamic memory (C)
- **09_FileHandling** - File I/O operations
- **10_Preprocessor** - Macros, conditional compilation, headers

### Module 2 - Advanced OOP
- **11_OOPS** - Classes, constructors, destructors, static members
- **12_Memory** - Dynamic memory, new/delete, memory leaks
- **13_Encapsulation** - Access specifiers, getters/setters
- **14_Abstraction** - Abstract classes, interfaces
- **15_Inheritance** - Single, multiple, multilevel, hierarchical
- **16_Polymorphism** - Virtual functions, operator overloading

## 🚀 Quick Start

### Prerequisites
- **CLion IDE** (recommended) or any C++ IDE
- **MinGW-w64** (C++ compiler for Windows)
- **CMake 3.20+** (bundled with CLion)

### Setup Instructions

1. **Clone or open this project in CLion**

2. **Verify your setup:**
   ```cmd
   verify_setup.bat
   ```

3. **Load CMake Project:**
   - CLion will detect `CMakeLists.txt` automatically
   - Click "Load CMake Project" when prompted
   - Wait for indexing to complete

4. **Run a program:**
   - Select any program from the dropdown (top-right)
   - Click the green Run button (▶️) or press `Shift+F10`

5. **Debug a program:**
   - Set breakpoints by clicking the left margin
   - Press `Shift+F9` to start debugging

📖 **See [CLION_SETUP_GUIDE.md](CLION_SETUP_GUIDE.md) for detailed instructions**

## 📝 Program Naming Convention

Programs are prefixed by category for easy identification:

- `array_*` - Array programs
- `Ptr_*` - Pointer programs
- `FileH_*` - File handling programs
- `Prep_*` - Preprocessor examples
- `OOPS_*` - Object-oriented programming
- `Mem_*` - Memory management
- `Enc_*` - Encapsulation
- `Abs_*` - Abstraction
- `Inh_*` - Inheritance
- `Poly_*` - Polymorphism

## 🔧 Adding New Programs

1. Create your `.cpp` or `.c` file in the appropriate module folder
2. Open `CMakeLists.txt`
3. Add: `add_executable(program_name path/to/file.cpp)`
4. Reload CMake (CLion will prompt automatically)

Example:
```cmake
add_executable(my_calculator Module1/04_Conditionals/my_calculator.cpp)
```

## ⌨️ Keyboard Shortcuts (CLion)

| Action | Shortcut |
|--------|----------|
| Run | `Shift+F10` |
| Debug | `Shift+F9` |
| Stop | `Ctrl+F2` |
| Build | `Ctrl+F9` |
| Format Code | `Ctrl+Alt+L` |
| Find File | `Ctrl+Shift+N` |
| Search Everywhere | `Shift+Shift` |

## 📚 Learning Path

### Beginner (Module 1)
1. Start with **Arrays** and **Functions**
2. Move to **Conditionals** and **Mathematical** programs
3. Learn **Pointers** and **File Handling**
4. Understand **Preprocessor** directives

### Intermediate (Module 2)
1. Master **OOPS** concepts (classes, objects)
2. Learn **Memory Management** (new/delete)
3. Understand **Encapsulation** principles
4. Study **Abstraction** patterns

### Advanced (Module 2)
1. Deep dive into **Inheritance** hierarchies
2. Master **Polymorphism** and virtual functions
3. Practice operator overloading
4. Build complex systems

## 🐛 Troubleshooting

### CMake not loading?
- Check that `CMakeLists.txt` exists in project root
- Go to `Tools > CMake > Reload CMake Project`

### Compiler not found?
- Install MinGW-w64: https://winlibs.com/
- Add `C:\mingw64\bin` to your PATH
- Configure toolchain in CLion settings

### Program not in dropdown?
- Make sure you added it to `CMakeLists.txt`
- Reload CMake project

### Input not working (scanf/cin)?
- Use the input field in the Run panel at the bottom
- Type your input and press Enter

## 📖 Resources

- [CPP Reference](https://en.cppreference.com/)
- [CLion Documentation](https://www.jetbrains.com/help/clion/)
- [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/)
- [LearnCPP](https://www.learncpp.com/)

## 📄 License

Educational project for learning C++ programming.

---

**Happy Coding! 🚀**
