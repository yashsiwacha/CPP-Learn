# CLion C++ Setup Guide for CPPLearn

## ✅ Step 1: Install Required Tools

### Install MinGW-w64 (C++ Compiler for Windows)
1. Download MinGW-w64 from: https://winlibs.com/ or https://www.mingw-w64.org/
2. Extract to `C:\mingw64`
3. Add to PATH:
   - Open System Properties → Environment Variables
   - Edit "Path" variable
   - Add: `C:\mingw64\bin`
4. Verify in CMD: `g++ --version`

### Install CMake (if not included with CLion)
- CLion usually bundles CMake, but you can verify:
- Go to `Settings > Build, Execution, Deployment > Toolchains`
- Check that CMake is detected

---

## ✅ Step 2: Configure CLion

### A. Set Up Toolchain
1. Open CLion
2. Go to: **File → Settings → Build, Execution, Deployment → Toolchains**
3. Click **"+"** to add a new toolchain
4. Select **"MinGW"**
5. Set Environment path: `C:\mingw64` (or where you installed MinGW)
6. CLion should auto-detect:
   - CMake
   - Make
   - C Compiler (gcc.exe)
   - C++ Compiler (g++.exe)
   - Debugger (gdb.exe)
7. Click **"OK"**

### B. Load CMake Project
1. CLion should automatically detect `CMakeLists.txt` in the project root
2. If you see a banner at the top: **"CMake project is not loaded"**
   - Click **"Load CMake Project"**
3. Or manually: **Tools → CMake → Reload CMake Project**
4. Wait for CMake to configure (check bottom-right status bar)

### C. Set Build Directory
- Go to: **File → Settings → Build, Execution, Deployment → CMake**
- You should see profiles like:
  - **Debug** (builds to `cmake-build-debug/`)
  - **Release** (builds to `cmake-build-release/`)
- These are automatically configured ✅

---

## ✅ Step 3: Run Your First Program

### Option 1: Use the Dropdown Menu
1. Look at the **top-right** of CLion
2. You'll see a dropdown with all your programs (e.g., `calculator`, `banking_system`)
3. Select any program
4. Click the **Green Play Button ▶️** to run
5. Or press **Shift+F10**

### Option 2: Right-Click in Editor
1. Open any `.cpp` file
2. Right-click anywhere in the code
3. Select **"Run [filename]"** or **"Debug [filename]"**

### Option 3: Use Keyboard Shortcuts
- **Shift+F10** → Run current configuration
- **Shift+F9** → Debug current configuration
- **Ctrl+F9** → Build project (compile only)
- **Ctrl+F2** → Stop running program

---

## ✅ Step 4: Debugging in CLion

### Set Breakpoints
1. Click in the **left margin** (gutter) next to any line number
2. A red dot appears = breakpoint set

### Start Debugging
1. Press **Shift+F9** or click the **Debug Button** (bug icon)
2. Program pauses at breakpoints
3. Use the debug panel to:
   - **Step Over** (F8) - Execute current line
   - **Step Into** (F7) - Go inside function calls
   - **Step Out** (Shift+F8) - Exit current function
   - **Resume** (F9) - Continue to next breakpoint

### View Variables
- When paused, hover over any variable to see its value
- Or check the **Variables** panel at the bottom

---

## ✅ Step 5: Project Organization

Your project has **over 100+ programs** organized by modules:

### Module 1 (Basics)
- `array_basics`, `array_sorting`, etc. → Arrays
- `calculator`, `grade_calculator` → Conditionals
- `banking_system`, `temperature_converter` → Functions
- `Ptr_*` → Pointer programs
- `FileH_*` → File handling
- `Prep_*` → Preprocessor examples

### Module 2 (Advanced)
- `OOPS_*` → Object-Oriented Programming
- `Mem_*` → Memory management
- `Enc_*` → Encapsulation
- `Abs_*` → Abstraction
- `Inh_*` → Inheritance
- `Poly_*` → Polymorphism

**Prefixes help you quickly find programs in the dropdown!**

---

## ✅ Step 6: Add New Programs

When you create a new C++ file:

1. Create the file: `Module1/01_Arrays/my_new_program.cpp`
2. Open `CMakeLists.txt`
3. Add this line:
   ```cmake
   add_executable(my_new_program Module1/01_Arrays/my_new_program.cpp)
   ```
4. CLion will prompt to **Reload CMake** → Click **"Reload"**
5. Your new program appears in the dropdown!

---

## 🚀 Quick Reference

| Action | Shortcut |
|--------|----------|
| Run program | **Shift+F10** |
| Debug program | **Shift+F9** |
| Stop program | **Ctrl+F2** |
| Build project | **Ctrl+F9** |
| Edit configurations | **Alt+Shift+F10** then **0** |
| Find anything | **Double Shift** |
| Go to file | **Ctrl+Shift+N** |
| Search everywhere | **Shift+Shift** |
| Reload CMake | **Tools → CMake → Reload** |
| Format code | **Ctrl+Alt+L** |
| Comment/Uncomment | **Ctrl+/** |

---

## 🔧 Troubleshooting

### "CMake Error: Could not find CMAKE_C_COMPILER"
- Install MinGW-w64 and set up toolchain (see Step 2A)

### "Cannot load CMake project"
- Check `CMakeLists.txt` exists in project root
- Click "Reload CMake Project" from Tools menu

### "Program not showing in dropdown"
- Make sure you added it to `CMakeLists.txt`
- Reload CMake project

### Build fails with errors
- Check the **Build** panel at the bottom
- Read error messages carefully
- Make sure all `#include` files exist

### Can't input data (scanf/cin)
- The Run window at the bottom has an input field
- Type your input there and press Enter

---

## 📚 Additional Resources

- **CLion Documentation**: https://www.jetbrains.com/help/clion/
- **CMake Tutorial**: https://cmake.org/cmake/help/latest/guide/tutorial/
- **C++ Reference**: https://en.cppreference.com/

---

## ✨ You're All Set!

Your project is configured with:
- ✅ Complete CMakeLists.txt with 100+ programs
- ✅ Organized module structure
- ✅ C and C++ support
- ✅ Ready to run and debug

**Select a program from the dropdown and start coding! 🚀**
