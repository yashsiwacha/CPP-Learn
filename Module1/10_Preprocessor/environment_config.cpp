// Program demonstrating environment-specific configuration using macros
#include <iostream>
#include <cstdio>

using namespace std;

#if defined(DEV)
#define API_URL "http://localhost"
#define ENVIRONMENT "Development"
#define DEBUG_MODE 1
#define LOG_LEVEL "VERBOSE"
#elif defined(TEST)
#define API_URL "http://test-server"
#define ENVIRONMENT "Testing"
#define DEBUG_MODE 1
#define LOG_LEVEL "INFO"
#else
#define API_URL "http://prod-server"
#define ENVIRONMENT "Production"
#define DEBUG_MODE 0
#define LOG_LEVEL "ERROR"
#endif

void displayConfiguration()
{
    printf("Environment Configuration\n\n");
    printf("Current Environment: %s\n", ENVIRONMENT);
    printf("API URL: %s\n", API_URL);
    printf("Debug Mode: %s\n", DEBUG_MODE ? "Enabled" : "Disabled");
    printf("Log Level: %s\n\n", LOG_LEVEL);
}

void simulateEnvironmentBehavior()
{
    cout << "Environment-specific behavior:\n";

#if defined(DEV)
    cout << "  Running in DEVELOPMENT mode\n";
    cout << "  Hot-reloading enabled\n";
    cout << "  Local database: localhost:5432\n";
#elif defined(TEST)
    cout << "  Running in TESTING mode\n";
    cout << "  Test data populated\n";
    cout << "  Test database: test-db.company.com\n";
#else
    cout << "  Running in PRODUCTION mode\n";
    cout << "  Performance optimization enabled\n";
    cout << "  Production database: prod-db.company.com\n";
#endif

    cout << "\n";
}

void demonstrateFeatures()
{
    cout << "Feature Availability:\n";

#if DEBUG_MODE
    cout << "  [DEBUG] Debug console available\n";
    cout << "  [DEBUG] Stack traces enabled\n";
#else
    cout << "  [PROD] Debug features disabled\n";
#endif

#if defined(DEV)
    cout << "  [DEV] Auto-reload on file changes\n";
    cout << "  [DEV] Unminified code for debugging\n";
#endif

#if defined(TEST)
    cout << "  [TEST] Integration test suite enabled\n";
    cout << "  [TEST] Automated testing active\n";
#endif

    cout << "\n";
}

int main()
{
    cout << "\n";

    // Display current configuration
    displayConfiguration();

    // Show environment-specific behavior
    simulateEnvironmentBehavior();

    // Demonstrate conditional features
    demonstrateFeatures();

    // Display compilation instructions
    cout << "═══════════════════════════════════════════════════════\n";
    cout << "How to Compile for Different Environments:\n";
    cout << "═══════════════════════════════════════════════════════\n";
    cout << "Development Environment:\n";
    cout << "  C:\\mingw64\\bin\\g++.exe -DDEV environment_config.cpp \\\n";
    cout << "    -o ..\\build\\env_dev.exe\n\n";
    cout << "Testing Environment:\n";
    cout << "  C:\\mingw64\\bin\\g++.exe -DTEST environment_config.cpp \\\n";
    cout << "    -o ..\\build\\env_test.exe\n\n";
    cout << "Production Environment:\n";
    cout << "  C:\\mingw64\\bin\\g++.exe environment_config.cpp \\\n";
    cout << "    -o ..\\build\\env_prod.exe\n";
    cout << "═══════════════════════════════════════════════════════\n";
    cout << "\n";

    return 0;
}
