/*
 * version_control.cpp - Main program to demonstrate header guards and version control
 *
 * This program demonstrates:
 * 1. Using header guards to prevent multiple inclusions
 * 2. Version control using preprocessor macros
 * 3. Conditional compilation based on version numbers
 * 4. Modular programming with header files
 *
 * To test different versions:
 * - Edit config.h and change VERSION to different values (e.g., 2, 3, 4, 5)
 * - VERSION >= 3 will show "Stable version"
 * - VERSION < 3 will show "Beta version"
 */

#include <iostream>
#include <cstdio>
#include "config.h"
#include "config.h" // Include again to test header guard protection
#include "config.h" // Include a third time - no errors due to header guards!

using namespace std;

// Function to display version information
void displayVersionInfo()
{
    printf("=================================\n");
    printf("Software Version Control System\n");
    printf("=================================\n");
    printf("Current VERSION: %d\n", VERSION);
    printf("Status: %s\n", VERSION_STATUS);
    printf("%s\n", VERSION_DESC);
    printf("=================================\n\n");
}

// Function to display feature flags
void displayFeatures()
{
    printf("Feature Flags:\n");
    printf("  - Advanced Logging: %s\n", FEATURE_ADVANCED_LOGGING ? "Enabled" : "Disabled");
    printf("  - Beta Testing Mode: %s\n", FEATURE_BETA_TESTING ? "Enabled" : "Disabled");
    printf("\n");
}

// Function to demonstrate version-specific behavior
void executeVersionSpecificCode()
{
    cout << "Executing version-specific code...\n";

#if VERSION >= 3
    cout << "  [STABLE] Running production code path\n";
    cout << "  [STABLE] All features are enabled and tested\n";
    cout << "  [STABLE] Full error handling is active\n";
#else
    cout << "  [BETA] Running testing code path\n";
    cout << "  [BETA] Some features may be experimental\n";
    cout << "  [BETA] Verbose logging enabled for debugging\n";
#endif

    cout << endl;
}

// Demonstrate feature-based compilation
void demonstrateFeatures()
{
    cout << "Demonstrating feature-based compilation:\n";

#if FEATURE_ADVANCED_LOGGING
    cout << "  [LOG] Advanced logging is available\n";
    cout << "  [LOG] Writing detailed logs to file...\n";
#endif

#if FEATURE_BETA_TESTING
    cout << "  [TEST] Beta testing mode is active\n";
    cout << "  [TEST] Collecting diagnostic information...\n";
#endif

    cout << endl;
}

int main()
{
    cout << "\n";
    cout << "╔═══════════════════════════════════════════════╗\n";
    cout << "║  Header Guards & Version Control Demo        ║\n";
    cout << "╚═══════════════════════════════════════════════╝\n";
    cout << endl;

    // Display version information from config.h
    displayVersionInfo();

    // Display feature availability
    displayFeatures();

    // Execute version-specific code
    executeVersionSpecificCode();

    // Demonstrate feature-based compilation
    demonstrateFeatures();

    // Show that header was included multiple times without errors
    cout << "Note: config.h was included 3 times in this file,\n";
    cout << "but header guards prevented any compilation errors!\n";
    cout << endl;

    // Additional information about changing versions
    cout << "═══════════════════════════════════════════════\n";
    cout << "To test different versions:\n";
    cout << "═══════════════════════════════════════════════\n";
    cout << "1. Open config.h\n";
    cout << "2. Change the line: #define VERSION 2\n";
    cout << "3. Try VERSION 3, 4, or 5 for stable version\n";
    cout << "4. Try VERSION 0, 1, or 2 for beta version\n";
    cout << "5. Recompile and run this program\n";
    cout << "═══════════════════════════════════════════════\n";
    cout << endl;

    return 0;
}
