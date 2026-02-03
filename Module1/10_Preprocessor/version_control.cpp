// Program demonstrating header guards and version control

#include <iostream>
#include <cstdio>
#include "config.h"
#include "config.h"
#include "config.h"

using namespace std;

void displayVersionInfo()
{
    printf("Software Version Control\n");
    printf("VERSION: %d\n", VERSION);
    printf("Status: %s\n", VERSION_STATUS);
    printf("%s\n\n", VERSION_DESC);
}

void displayFeatures()
{
    printf("Feature Flags:\n");
    printf("  - Advanced Logging: %s\n", FEATURE_ADVANCED_LOGGING ? "Enabled" : "Disabled");
    printf("  - Beta Testing Mode: %s\n", FEATURE_BETA_TESTING ? "Enabled" : "Disabled");
    printf("\n");
}

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
    cout << "\nHeader Guards & Version Control Demo\n\n";

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
