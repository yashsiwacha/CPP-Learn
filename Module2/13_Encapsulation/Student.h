// Student.h - Class Declaration and Encapsulation
// Program to demonstrate encapsulation across multiple files.
//
// ENCAPSULATION CONCEPT:
// Encapsulation is one of the fundamental principles of Object-Oriented Programming.
// It means bundling data (attributes) and methods (functions) that operate on the data
// into a single unit (class), while restricting direct access to some components.
//
// INTERFACE-IMPLEMENTATION SEPARATION:
// The header file (.h) serves as the INTERFACE - it declares what the class can do
// without revealing how it does it. This allows users to understand the class's
// capabilities without needing to know the implementation details.
//
// BENEFITS OF THIS APPROACH:
// 1. Data Hiding: Private members cannot be accessed directly from outside
// 2. Controlled Access: Public methods provide validated, safe access to data
// 3. Maintainability: Implementation can change without affecting code that uses the class
// 4. Code Organization: Clear separation between interface and implementation

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student
{
private:
    // Private data members - cannot be accessed directly from outside the class
    // This protects data integrity and prevents invalid states
    string name; // Student's name
    int rollNo;  // Student's roll number (must be positive)
    int marks;   // Student's marks (must be between 0-100)

public:
    // Public setter functions - provide controlled, validated access to modify data
    void setName(string name);  // Sets name with validation
    void setRollNo(int rollNo); // Sets roll number with validation
    void setMarks(int marks);   // Sets marks with validation (0-100)

    // Public getter functions - provide read-only access to private data
    string getName(); // Returns student's name
    int getRollNo();  // Returns student's roll number
    int getMarks();   // Returns student's marks
};

#endif // STUDENT_H
