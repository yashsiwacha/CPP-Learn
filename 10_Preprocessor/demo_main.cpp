/*
 * DEMO_MAIN.CPP
 * =============
 * Main program that demonstrates header guards across multiple files
 * This file also includes demo_header.h (third inclusion!)
 */

#include "demo_header.h"
#include <iostream>
#include <iomanip>
using namespace std;

// External function declaration (implemented in demo_file2.cpp)
void demonstrateHeaderGuards();

void explainHeaderGuards()
{
    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║    HOW HEADER GUARDS WORK              ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;

    cout << "\nWithout Header Guards:" << endl;
    cout << "  demo_file1.cpp includes demo_header.h" << endl;
    cout << "  demo_file2.cpp includes demo_header.h" << endl;
    cout << "  demo_main.cpp includes demo_header.h" << endl;
    cout << "  ❌ RESULT: Multiple definition errors!" << endl;

    cout << "\nWith Header Guards:" << endl;
    cout << "  #ifndef DEMO_HEADER_H  // Is it defined?" << endl;
    cout << "  #define DEMO_HEADER_H  // Define it!" << endl;
    cout << "  // ... header content ..." << endl;
    cout << "  #endif" << endl;
    cout << "  ✓ RESULT: Content included only once!" << endl;
}

void testAllFunctions()
{
    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║    TESTING ALL FUNCTIONS               ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;

    // Test functions from demo_file1.cpp
    cout << "\n--- Functions from demo_file1.cpp ---" << endl;
    int sum = add(15, 25);
    cout << "add(15, 25) = " << sum << endl;

    double area = calculateCircleArea(10.0);
    cout << fixed << setprecision(2);
    cout << "Circle area (r=10.0) = " << area << endl;

    // Test functions from demo_file2.cpp
    cout << "\n--- Functions from demo_file2.cpp ---" << endl;
    int product = multiply(6, 7);
    cout << "multiply(6, 7) = " << product << endl;

    double perimeter = calculateCirclePerimeter(10.0);
    cout << "Circle perimeter (r=10.0) = " << perimeter << endl;

    // Test inline function from header
    cout << "\n--- Inline function from header ---" << endl;
    cout << "square(5.0) = " << square(5.0) << endl;

    // Show global counter
    extern int globalCounter;
    cout << "\n--- Global Variable Access ---" << endl;
    cout << "Total function calls tracked: " << globalCounter << endl;
}

void demonstrateFileStructure()
{
    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║    FILE STRUCTURE                      ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;

    cout << "\n📁 demo_header.h" << endl;
    cout << "   └─ Contains: Header guards, constants," << endl;
    cout << "      function declarations, inline functions" << endl;

    cout << "\n📄 demo_file1.cpp" << endl;
    cout << "   ├─ Includes: demo_header.h" << endl;
    cout << "   └─ Implements: printWelcomeMessage()," << endl;
    cout << "      displayVersion(), calculateCircleArea(), add()" << endl;

    cout << "\n📄 demo_file2.cpp" << endl;
    cout << "   ├─ Includes: demo_header.h" << endl;
    cout << "   └─ Implements: calculateCirclePerimeter()," << endl;
    cout << "      multiply(), demonstrateHeaderGuards()" << endl;

    cout << "\n📄 demo_main.cpp (this file)" << endl;
    cout << "   ├─ Includes: demo_header.h" << endl;
    cout << "   └─ Contains: main(), coordination functions" << endl;

    cout << "\n✓ All three files include demo_header.h" << endl;
    cout << "✓ Header guards prevent multiple definitions" << endl;
    cout << "✓ Compiles successfully!" << endl;
}

void showHeaderGuardTemplate()
{
    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║    HEADER GUARD TEMPLATE               ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;

    cout << "\n// filename.h" << endl;
    cout << "#ifndef FILENAME_H" << endl;
    cout << "#define FILENAME_H" << endl;
    cout << "" << endl;
    cout << "// Your declarations here:" << endl;
    cout << "// - Constants (#define)" << endl;
    cout << "// - Function prototypes" << endl;
    cout << "// - Class declarations" << endl;
    cout << "// - Inline functions" << endl;
    cout << "" << endl;
    cout << "#endif // FILENAME_H" << endl;

    cout << "\n⚠️  Important Rules:" << endl;
    cout << "1. Guard macro name should be UPPERCASE" << endl;
    cout << "2. Use filename with _H suffix" << endl;
    cout << "3. Must be unique across project" << endl;
    cout << "4. Always use #ifndef, not #ifdef" << endl;
}

int main()
{
    cout << "\n";
    cout << "╔═════════════════════════════════════════════╗" << endl;
    cout << "║  HEADER GUARDS - MULTI-FILE DEMONSTRATION  ║" << endl;
    cout << "╚═════════════════════════════════════════════╝" << endl;

    // Section 1: Welcome and version
    printWelcomeMessage();
    displayVersion();

    // Section 2: Explain how header guards work
    explainHeaderGuards();

    // Section 3: Demonstrate file structure
    demonstrateFileStructure();

    // Section 4: Show that header guards are working
    demonstrateHeaderGuards();

    // Section 5: Test all functions from different files
    testAllFunctions();

    // Section 6: Show template
    showHeaderGuardTemplate();

    // Final summary
    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║    KEY LEARNING POINTS                 ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    cout << "\n✓ Header guards prevent multiple inclusions" << endl;
    cout << "✓ Use #ifndef, #define, #endif pattern" << endl;
    cout << "✓ Essential for modular programming" << endl;
    cout << "✓ Allows safe inclusion in multiple .cpp files" << endl;
    cout << "✓ Prevents compilation errors" << endl;

    cout << "\n✅ Program completed successfully!\n"
         << endl;

    return 0;
}
