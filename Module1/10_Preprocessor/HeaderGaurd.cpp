/*
 * HEADER GUARDS DEMONSTRATION
 * ===========================
 * This program demonstrates the use of header guards to prevent multiple inclusions.
 *
 * Problem: Without header guards, including the same header multiple times causes
 *          "redefinition" errors during compilation.
 *
 * Solution: Use #ifndef, #define, and #endif preprocessor directives to create
 *           an "include guard" that ensures the header content is included only once.
 */

#include <iostream>
#include <iomanip>
using namespace std;

// ============================================================================
// SECTION 1: DEMONSTRATION WITHOUT HEADER GUARDS (Commented Out)
// ============================================================================
// If we uncomment the following code and include it twice, we get errors:

/*
// First inclusion
#define CIRCLE_AREA_CONST 3.14159
int add(int a, int b) { return a + b; }

// Second inclusion (simulating multiple includes)
#define CIRCLE_AREA_CONST 3.14159  // ERROR: Redefinition of CIRCLE_AREA_CONST
int add(int a, int b) { return a + b; }  // ERROR: Redefinition of add()
*/

// ============================================================================
// SECTION 2: PROPER HEADER STRUCTURE WITH HEADER GUARDS
// ============================================================================

// Simulating myheader.h content with header guard
#ifndef MYHEADER_H // Step 1: Check if MYHEADER_H is NOT defined
#define MYHEADER_H // Step 2: Define MYHEADER_H (mark as included)

// Header file contents - safe to include multiple times now
#define PI 3.14159
#define MAX_SIZE 100
#define VERSION "1.0.0"

// Function prototypes
void printMessage();
void useConstant();
double calculateCircleArea(double radius);
int add(int a, int b);

#endif // MYHEADER_H      // Step 3: End the conditional block

// ============================================================================
// SECTION 3: SIMULATING MULTIPLE INCLUDES
// ============================================================================

// First file (file1.c) includes myheader.h
#ifndef MYHEADER_H // Not defined yet, so contents will be included
#define MYHEADER_H
#define PI 3.14159
// ... all header content ...
#endif

// Second file (file2.c) also includes myheader.h
#ifndef MYHEADER_H // Already defined! So contents are SKIPPED
#define MYHEADER_H
#define PI 3.14159 // This line is never processed
// ... all header content is skipped ...
#endif

// Result: No redefinition errors!

// ============================================================================
// SECTION 4: FUNCTION IMPLEMENTATIONS
// ============================================================================

void printMessage()
{
    cout << "===========================================" << endl;
    cout << "  HEADER GUARDS DEMONSTRATION" << endl;
    cout << "===========================================" << endl;
    cout << "This message is printed from printMessage()" << endl;
    cout << "Header Version: " << VERSION << endl;
}

void useConstant()
{
    cout << "\nUsing constants from header:" << endl;
    cout << "  PI = " << fixed << setprecision(5) << PI << endl;
    cout << "  MAX_SIZE = " << MAX_SIZE << endl;
}

double calculateCircleArea(double radius)
{
    return PI * radius * radius;
}

int add(int a, int b)
{
    return a + b;
}

// ============================================================================
// SECTION 5: EXPLANATION AND TESTING
// ============================================================================

void explainHeaderGuards()
{
    cout << "\n===========================================" << endl;
    cout << "  HOW HEADER GUARDS WORK" << endl;
    cout << "===========================================" << endl;

    cout << "\n1. FIRST INCLUSION:" << endl;
    cout << "   - Preprocessor encounters: #ifndef MYHEADER_H" << endl;
    cout << "   - MYHEADER_H is not defined yet" << endl;
    cout << "   - Condition is TRUE, so it processes the content" << endl;
    cout << "   - Defines MYHEADER_H with: #define MYHEADER_H" << endl;
    cout << "   - Includes all declarations (PI, functions, etc.)" << endl;

    cout << "\n2. SECOND INCLUSION (same file):" << endl;
    cout << "   - Preprocessor encounters: #ifndef MYHEADER_H" << endl;
    cout << "   - MYHEADER_H is ALREADY defined" << endl;
    cout << "   - Condition is FALSE, so it SKIPS the content" << endl;
    cout << "   - Jumps directly to #endif" << endl;
    cout << "   - No redefinition errors!" << endl;

    cout << "\n3. BENEFITS:" << endl;
    cout << "   ✓ Prevents multiple definition errors" << endl;
    cout << "   ✓ Allows safe inclusion in multiple files" << endl;
    cout << "   ✓ Improves compilation speed" << endl;
    cout << "   ✓ Essential for modular programming" << endl;
}

void demonstrateWithoutGuards()
{
    cout << "\n===========================================" << endl;
    cout << "  WITHOUT HEADER GUARDS (Errors)" << endl;
    cout << "===========================================" << endl;

    cout << "\nIf myheader.h did NOT have header guards:\n"
         << endl;
    cout << "  // myheader.h (BAD - No guards)" << endl;
    cout << "  #define PI 3.14159" << endl;
    cout << "  void printMessage();\n"
         << endl;

    cout << "  // file1.c" << endl;
    cout << "  #include \"myheader.h\"  // First inclusion - OK" << endl;
    cout << "  #include \"myheader.h\"  // Second inclusion - ERROR!\n"
         << endl;

    cout << "  Compiler Error:" << endl;
    cout << "  ❌ error: redefinition of 'PI'" << endl;
    cout << "  ❌ error: redefinition of 'printMessage'" << endl;
}

void demonstrateWithGuards()
{
    cout << "\n===========================================" << endl;
    cout << "  WITH HEADER GUARDS (Success)" << endl;
    cout << "===========================================" << endl;

    cout << "\nWith proper header guards in myheader.h:\n"
         << endl;
    cout << "  // myheader.h (GOOD - Has guards)" << endl;
    cout << "  #ifndef MYHEADER_H" << endl;
    cout << "  #define MYHEADER_H" << endl;
    cout << "  #define PI 3.14159" << endl;
    cout << "  void printMessage();" << endl;
    cout << "  #endif\n"
         << endl;

    cout << "  // file1.c" << endl;
    cout << "  #include \"myheader.h\"  // First inclusion - included" << endl;
    cout << "  #include \"myheader.h\"  // Second inclusion - skipped\n"
         << endl;

    cout << "  Compilation Result:" << endl;
    cout << "  ✓ No errors" << endl;
    cout << "  ✓ Content included only once" << endl;
    cout << "  ✓ Program compiles successfully" << endl;
}

void practicalExample()
{
    cout << "\n===========================================" << endl;
    cout << "  PRACTICAL EXAMPLE" << endl;
    cout << "===========================================" << endl;

    cout << "\nUsing functions from the header:" << endl;

    int sum = add(10, 20);
    cout << "  add(10, 20) = " << sum << endl;

    double radius = 5.0;
    double area = calculateCircleArea(radius);
    cout << "  Circle area (radius=" << fixed << setprecision(1) << radius
         << ") = " << setprecision(2) << area << endl;

    cout << "\nAll functions work because header guards prevented" << endl;
    cout << "multiple definitions during compilation!" << endl;
}

// ============================================================================
// MAIN PROGRAM
// ============================================================================

int main()
{
    cout << "\n";
    cout << "╔═══════════════════════════════════════════╗" << endl;
    cout << "║   HEADER GUARDS COMPLETE TUTORIAL        ║" << endl;
    cout << "╚═══════════════════════════════════════════╝" << endl;

    // Section 1: Introduction
    printMessage();
    useConstant();

    // Section 2: Explanation
    explainHeaderGuards();

    // Section 3: Demonstration without guards
    demonstrateWithoutGuards();

    // Section 4: Demonstration with guards
    demonstrateWithGuards();

    // Section 5: Practical usage
    practicalExample();

    // Summary
    cout << "\n===========================================" << endl;
    cout << "  KEY TAKEAWAYS" << endl;
    cout << "===========================================" << endl;
    cout << "1. Always use header guards in .h files" << endl;
    cout << "2. Format: #ifndef <NAME>_H ... #endif" << endl;
    cout << "3. Makes headers safe to include multiple times" << endl;
    cout << "4. Essential for modular C/C++ programming" << endl;
    cout << "5. Prevents compilation errors and saves time" << endl;

    cout << "\n===========================================" << endl;
    cout << "  HEADER GUARD TEMPLATE" << endl;
    cout << "===========================================" << endl;
    cout << "#ifndef FILENAME_H" << endl;
    cout << "#define FILENAME_H" << endl;
    cout << "" << endl;
    cout << "// Your declarations here" << endl;
    cout << "" << endl;
    cout << "#endif // FILENAME_H" << endl;

    cout << "\n✓ Program completed successfully!\n"
         << endl;

    return 0;
}
