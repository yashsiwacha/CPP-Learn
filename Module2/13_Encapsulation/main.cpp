// main.cpp - Usage and Verification of Student class
// This file demonstrates the practical use of the encapsulated Student class.
// It shows how encapsulation provides data safety through validation.

#include "Student.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "===== Student Encapsulation Demo =====" << endl
         << endl;

    // Create a Student object
    // Note: We can only interact with it through public methods, not direct data access
    Student s1;

    // Set valid student information using setter methods
    // The setters ensure data integrity through validation
    cout << "Setting valid data..." << endl;
    s1.setName("John Doe");
    s1.setRollNo(101);
    s1.setMarks(85);

    // Display student information using getter methods
    // Getters provide controlled, read-only access to private data
    cout << "\nStudent Information:" << endl;
    cout << "Name: " << s1.getName() << endl;
    cout << "Roll No: " << s1.getRollNo() << endl;
    cout << "Marks: " << s1.getMarks() << endl;

    // ===== VALIDATION TESTING =====
    // The following tests demonstrate how encapsulation protects data integrity
    // by rejecting or correcting invalid inputs automatically
    cout << "\n===== Testing Validation =====" << endl;

    // Test 1: Negative marks (invalid)
    cout << "\nAttempting to set marks to -10:" << endl;
    s1.setMarks(-10); // Setter will validate and correct to 0
    cout << "Actual marks after setting: " << s1.getMarks() << endl;

    // Test 2: Marks exceeding maximum (invalid)
    cout << "\nAttempting to set marks to 120:" << endl;
    s1.setMarks(120); // Setter will validate and correct to 100
    cout << "Actual marks after setting: " << s1.getMarks() << endl;

    // Test 3: Negative roll number (invalid)
    cout << "\nAttempting to set roll number to -5:" << endl;
    s1.setRollNo(-5); // Setter will validate and correct to 1
    cout << "Actual roll number after setting: " << s1.getRollNo() << endl;

    // Test 4: Empty name (invalid)
    cout << "\nAttempting to set name to empty string:" << endl;
    s1.setName(""); // Setter will validate and set to 'Unknown'
    cout << "Actual name after setting: " << s1.getName() << endl;

    // Restore valid values for s1
    s1.setName("John Doe");
    s1.setRollNo(101);
    s1.setMarks(95);
    cout << "\nRestored valid values for Student 1" << endl;

    // ===== ENCAPSULATION DEMONSTRATION =====
    // Encapsulation prevents direct access to private members from outside the class
    // This is crucial for maintaining data integrity and preventing invalid states
    cout << "\n===== Encapsulation Demonstration =====" << endl;
    cout << "Note: Direct access to private members (name, rollNo, marks) is not allowed." << endl;
    cout << "This protects data and ensures all modifications go through validation." << endl;
    cout << "Try uncommenting the following line in main.cpp to see compilation error:" << endl;
    cout << "// s1.name = \"Jane Doe\";  // This would cause a compilation error!" << endl;

    // Uncommenting ANY of these lines will cause a compilation error
    // because all these members are private and inaccessible from outside the class
    // s1.name = "Jane Doe";     // ERROR: 'string Student::name' is private
    // s1.rollNo = 200;          // ERROR: 'int Student::rollNo' is private
    // s1.marks = 150;           // ERROR: 'int Student::marks' is private
    //

    // ===== MULTIPLE OBJECTS TEST =====
    // Each Student object maintains its own encapsulated data
    // Changes to one object don't affect another - data independence
    cout << "\n===== Testing Multiple Students =====" << endl;
    Student s2;
    s2.setName("Alice Smith");
    s2.setRollNo(102);
    s2.setMarks(92);

    // Display both students - showing data independence
    cout << "\nStudent 1: " << s1.getName() << " (Roll: " << s1.getRollNo()
         << ", Marks: " << s1.getMarks() << ")" << endl;
    cout << "Student 2: " << s2.getName() << " (Roll: " << s2.getRollNo()
         << ", Marks: " << s2.getMarks() << ")" << endl;

    cout << "\n===== Program End =====" << endl;
    cout << "Key Takeaways:" << endl;
    cout << "1. Encapsulation protects data integrity through controlled access" << endl;
    cout << "2. Validation in setters prevents invalid states" << endl;
    cout << "3. Interface-implementation separation improves maintainability" << endl;
    cout << "4. Each object maintains independent, validated state" << endl;

    return 0;
}
