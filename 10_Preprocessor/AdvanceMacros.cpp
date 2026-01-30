#include <iostream>
#include <cstdio>

#define ERROR 1
#define WARN 2
#define INFO 3
#define DEBUG 4

#ifndef LOG_LEVEL
#define LOG_LEVEL 1
#endif

// Conditional LOG macro based on LOG_LEVEL
#if LOG_LEVEL >= 4
#define LOG(level, msg)              \
    if (level <= LOG_LEVEL)          \
    {                                \
        printf("[DEBUG] %s\n", msg); \
    }

#elif LOG_LEVEL >= 3
#define LOG(level, msg)             \
    if (level <= LOG_LEVEL)         \
    {                               \
        printf("[INFO] %s\n", msg); \
    }

#elif LOG_LEVEL >= 2
#define LOG(level, msg)             \
    if (level <= LOG_LEVEL)         \
    {                               \
        printf("[WARN] %s\n", msg); \
    }

#else
#define LOG(level, msg)              \
    if (level <= LOG_LEVEL)          \
    {                                \
        printf("[ERROR] %s\n", msg); \
    }

#endif

int main()
{
    printf("Testing Logging System\n");
    printf("Compiled with LOG_LEVEL = %d\n\n", LOG_LEVEL);

    LOG(ERROR, "Critical error occurred!");
    LOG(WARN, "This is a warning.");
    LOG(INFO, "Application started successfully.");
    LOG(DEBUG, "Debugging variable x = 42.");

    return 0;
}