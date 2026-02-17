cmake_minimum_required(VERSION 3.20)
project(CPPLearn)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)

# ===== SETUP TEST =====
# Run this first to verify your setup is working correctly
add_executable(test_setup test_setup.cpp)

# ===== MODULE 1 =====

# Module 1 - Arrays
add_executable(array_basics Module1/01_Arrays/array_basics.cpp)
add_executable(array_searching Module1/01_Arrays/array_searching.cpp)
add_executable(array_sorting Module1/01_Arrays/array_sorting.cpp)
add_executable(collection_sorting Module1/01_Arrays/collection_sorting.cpp)
add_executable(matrix_operations Module1/01_Arrays/matrix_operations.cpp)
add_executable(DoubleDelete_Arrays Module1/01_Arrays/DoubleDelete.cpp)

# Module 1 - Functions
add_executable(banking_system Module1/02_Functions/banking_system.cpp)
add_executable(temperature_converter Module1/02_Functions/temperature_converter.cpp)
add_executable(temperature_converter_v2 Module1/02_Functions/temperature_converter_v2.cpp)

# Module 1 - Data
add_executable(book_management Module1/03_Data/book_management.cpp)
add_executable(student_class Module1/03_Data/student_class.cpp)

# Module 1 - Conditionals
add_executable(calculator Module1/04_Conditionals/calculator.cpp)
add_executable(grade_calculator Module1/04_Conditionals/grade_calculator.cpp)
add_executable(shipping_cost Module1/04_Conditionals/shipping_cost.cpp)
add_executable(student_performance Module1/04_Conditionals/student_performance.cpp)

# Module 1 - Mathematical
add_executable(exponential_series Module1/05_Mathematical/exponential_series.cpp)
add_executable(sine_series Module1/05_Mathematical/sine_series.cpp)

# Module 1 - Recursion
add_executable(directory_traversal Module1/06_Recursion/directory_traversal.cpp)
add_executable(staircase_problem Module1/06_Recursion/staircase_problem.cpp)

# Module 1 - Structure
add_executable(Structure Module1/07_Structure/Structure.c)

# Module 1 - Pointers
add_executable(Ptr_2DArray Module1/08_Pointers/2DArray.cpp)
add_executable(Ptr_DanglingPointer Module1/08_Pointers/DanglingPointer.cpp)
add_executable(Ptr_PointerBasics Module1/08_Pointers/PointerBasics.c)
add_executable(Ptr_DynamicCalc Module1/08_Pointers/DynamicCalc.c)
add_executable(Ptr_DynamicScorecard Module1/08_Pointers/DynamicScorecard.c)
add_executable(Ptr_DynamicString Module1/08_Pointers/DynamicString.c)
add_executable(Ptr_EmployeeRecordEditor Module1/08_Pointers/EmployeeRecordEditor.c)
add_executable(Ptr_PhoneDirectory Module1/08_Pointers/PhoneDirectory.c)
add_executable(Ptr_SimpleConfigCalc Module1/08_Pointers/SimpleConfigCalc.c)

# Module 1 - File Handling
add_executable(FileH_AttendanceLog Module1/09_FileHandling/AttendanceLog.cpp)
add_executable(FileH_DeleteEmployee Module1/09_FileHandling/DeleteEmployee.cpp)
add_executable(FileH_EmployeeSlip Module1/09_FileHandling/EmployeeSlip.cpp)
add_executable(FileH_Studentmarks Module1/09_FileHandling/Studentmarks.cpp)
add_executable(FileH_StudentRecord Module1/09_FileHandling/StudentRecord.cpp)

# Module 1 - Preprocessor
add_executable(Prep_AdvanceMacros Module1/10_Preprocessor/AdvanceMacros.cpp)
add_executable(Prep_debug_toggle Module1/10_Preprocessor/debug_toggle.cpp)
add_executable(Prep_debugifdef Module1/10_Preprocessor/debugifdef.cpp)
add_executable(Prep_debugpractice Module1/10_Preprocessor/debugpractice.cpp)
add_executable(Prep_demo_file1 Module1/10_Preprocessor/demo_file1.cpp)
add_executable(Prep_demo_file2 Module1/10_Preprocessor/demo_file2.cpp)
add_executable(Prep_demo_main Module1/10_Preprocessor/demo_main.cpp)
add_executable(Prep_environment_config Module1/10_Preprocessor/environment_config.cpp)
add_executable(Prep_env_example Module1/10_Preprocessor/env_example.cpp)
add_executable(Prep_HeaderGaurd Module1/10_Preprocessor/HeaderGaurd.cpp)
add_executable(Prep_OS Module1/10_Preprocessor/OS.cpp)
add_executable(Prep_pragma Module1/10_Preprocessor/pragma.cpp)
add_executable(Prep_test_version Module1/10_Preprocessor/test_version.cpp)
add_executable(Prep_version_control Module1/10_Preprocessor/version_control.cpp)
add_executable(Prep_vesionconfig Module1/10_Preprocessor/vesionconfig.cpp)
add_executable(Prep_file1 Module1/10_Preprocessor/file1.c)
add_executable(Prep_file2 Module1/10_Preprocessor/file2.c)

# ===== MODULE 2 =====

# Module 2 - OOPS
add_executable(OOPS_AccessSpecifier Module2/11_OOPS/AccessSpecifier.cpp)
add_executable(OOPS_CopyConstructor Module2/11_OOPS/CopyConstructor.cpp)
add_executable(OOPS_Destructors Module2/11_OOPS/Destructors.cpp)
add_executable(OOPS_InlinevsMacros Module2/11_OOPS/InlinevsMacros.cpp)
add_executable(OOPS_mutablekeyword Module2/11_OOPS/mutablekeyword.cpp)
add_executable(OOPS_StaticDemo Module2/11_OOPS/StaticDemo.cpp)
add_executable(OOPS_StuctANDclass Module2/11_OOPS/StuctANDclass.cpp)
add_executable(OOPS_Task3Constructor Module2/11_OOPS/Task3Constructor.cpp)
add_executable(OOPS_ThisPointer Module2/11_OOPS/ThisPointer.cpp)

# Module 2 - Memory
add_executable(Mem_ArrayPointer Module2/12_Memory/ArrayPointer.cpp)
add_executable(Mem_Delete Module2/12_Memory/Delete[].cpp)
add_executable(Mem_MemoryLeak Module2/12_Memory/MemoryLeak.cpp)
add_executable(Mem_MemoryLeakinLoop Module2/12_Memory/MemoryLeakinLoop.cpp)
add_executable(Mem_MemoryLeakTest Module2/12_Memory/MemoryLeakTest.cpp)
add_executable(Mem_NewAndDelete Module2/12_Memory/New[]anddelete[].cpp)

# Module 2 - Encapsulation
add_executable(Enc_BankAccount Module2/13_Encapsulation/BankAccount.cpp)
add_executable(Enc_main Module2/13_Encapsulation/main.cpp)
add_executable(Enc_Temperature Module2/13_Encapsulation/Temerature.cpp)

# Module 2 - Abstraction
add_executable(Abs_Car Module2/14_Abstraction/Car.cpp)
add_executable(Abs_Payment Module2/14_Abstraction/Payment.cpp)
add_executable(Abs_Shape Module2/14_Abstraction/Shape.cpp)

# Module 2 - Inheritance
add_executable(Inh_Character Module2/15_Inheritance/Character.cpp)
add_executable(Inh_DiamondInheritance Module2/15_Inheritance/DiamondInheritance.cpp)
add_executable(Inh_DocumentMultilevel Module2/15_Inheritance/DocumentMultilevel.cpp)
add_executable(Inh_EmployeePayroll Module2/15_Inheritance/EmployeePayroll.cpp)
add_executable(Inh_HierachicalInhertance Module2/15_Inheritance/HierachicalInhertance.cpp)
add_executable(Inh_LibraryManagement Module2/15_Inheritance/LibraryManagement.cpp)
add_executable(Inh_MultiLevelInheritance Module2/15_Inheritance/MultiLevelInheritance.cpp)
add_executable(Inh_SingleInheritance Module2/15_Inheritance/SingleInheritance.cpp)
add_executable(Inh_DiamondProblem Module2/15_Inheritance/DiamondProblem.cpp)
add_executable(Inh_VirtualInheritanceTask2 Module2/15_Inheritance/VirtualInheritanceTask2.cpp)

# Module 2 - Polymorphism
add_executable(Poly_BaseLogger Module2/16_Polymorphism/BaseLogger.cpp)
add_executable(Poly_EmployeePayroll Module2/16_Polymorphism/EmployeePayroll.cpp)
add_executable(Poly_FractionOverload Module2/16_Polymorphism/FractionOverload.cpp)
add_executable(Poly_Matrix Module2/16_Polymorphism/Matrix.cpp)
add_executable(Poly_Messenger Module2/16_Polymorphism/Messenger.cpp)
add_executable(Poly_OperatorOverload Module2/16_Polymorphism/OperatorOverload.cpp)
add_executable(Poly_ShapeHierarchy Module2/16_Polymorphism/ShapeHierarchy.cpp)
add_executable(Poly_SimpleClalc Module2/16_Polymorphism/SimpleClalc.cpp)
add_executable(Poly_VirtualFuncDefaultParam Module2/16_Polymorphism/VirtualFuncDefaultParam.cpp)
