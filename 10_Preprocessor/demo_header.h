/*
 * DEMO_HEADER.H - Header file with proper header guards
 * ======================================================
 * This header file demonstrates the use of include guards to prevent
 * multiple inclusions and redefinition errors.
 */

#ifndef DEMO_HEADER_H // Step 1: Check if DEMO_HEADER_H is not defined
#define DEMO_HEADER_H // Step 2: Define DEMO_HEADER_H (marks file as included)

// Constants
#define PI 3.14159265359
#define MAX_STUDENTS 100
#define VERSION "2.0"

// Global variables (declared but not defined)
extern int globalCounter;

// Function declarations
void printWelcomeMessage();
void displayVersion();
double calculateCircleArea(double radius);
double calculateCirclePerimeter(double radius);
int add(int a, int b);
int multiply(int a, int b);

// Inline function (defined in header)
inline double square(double x)
{
    return x * x;
}

#endif // DEMO_HEADER_H   // Step 3: End the conditional block
