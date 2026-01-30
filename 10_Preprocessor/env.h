#ifndef ENV_H
#define ENV_H

// Environment-Specific Constants Using Macros
// This header file defines API_URL based on the environment macro

#if defined(DEV)
#define API_URL "http://localhost"
#define ENVIRONMENT "Development"
#elif defined(TEST)
#define API_URL "http://test-server"
#define ENVIRONMENT "Testing"
#else
#define API_URL "http://prod-server"
#define ENVIRONMENT "Production"
#endif

#endif // ENV_H
