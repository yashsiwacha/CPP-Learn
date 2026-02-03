// Student.cpp - Implementation of Student class
// This file contains the IMPLEMENTATION details of the Student class.
// By separating implementation from declaration, we achieve:
// - Better code organization and maintainability
// - Ability to change implementation without affecting users of the class
// - Reduced compilation dependencies

#include "Student.h"
#include <iostream>
using namespace std;

// Setter for name with validation
// Ensures the name is not empty, maintaining data integrity
void Student::setName(string name)
{
    // Validate that name is not empty
    if (name.empty())
    {
        cout << "Error: Name cannot be empty. Setting to 'Unknown'." << endl;
        this->name = "Unknown";
    }
    else
    {
        this->name = name;
    }
}

// Getter for name
// Provides read-only access to the private name member
string Student::getName()
{
    return name;
}

// Setter for roll number with validation
// Ensures roll number is positive (valid student ID)
void Student::setRollNo(int rollNo)
{
    // Validate that roll number is positive
    if (rollNo <= 0)
    {
        cout << "Error: Roll number must be positive. Setting to 1." << endl;
        this->rollNo = 1;
    }
    else
    {
        this->rollNo = rollNo;
    }
}

// Getter for roll number
// Provides read-only access to the private rollNo member
int Student::getRollNo()
{
    return rollNo;
}

// Setter for marks with validation (0-100 range)
// This is a key example of encapsulation - preventing invalid data states
// Without this validation, marks could be set to any value (negative, >100, etc.)
void Student::setMarks(int marks)
{
    if (marks < 0)
    {
        cout << "Error: Marks cannot be negative. Setting to 0." << endl;
        this->marks = 0;
    }
    else if (marks > 100)
    {
        cout << "Error: Marks cannot exceed 100. Setting to 100." << endl;
        this->marks = 100;
    }
    else
    {
        this->marks = marks;
    }
}

// Getter for marks
// Provides read-only access to the private marks member
int Student::getMarks()
{
    return marks;
}