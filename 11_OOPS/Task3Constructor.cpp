//Program to demonstrate Constructors in C++ OOPS.
#include <iostream>
using namespace std;


//Declaring a Student class
class Student{
    public:
        int rollNo;
        string name;
        char grade;
        const int studentID;  // const member - must be initialized via initializer list
        
        // Default Constructor: Initializes object with default values
        // Called automatically when an object is created without arguments
        Student(): studentID(0) {
            this->rollNo = 0;
            this->name = "Unknown";
            this->grade = 'U';
            cout << "This is called from default constructor." << endl;
        }
        
        // Parameterized Constructor: Initializes object with provided values
        // Uses Member Initializer List for efficiency
        // Advantages of initializer lists:
        // 1. Direct initialization (more efficient than assignment)
        // 2. Required for const members, references, and members without default constructors
        // 3. Avoids creating temporary objects
        // 4. Members are initialized in declaration order, not list order
        Student(int rollNo, string name, char grade, int id = 1001): 
            rollNo(rollNo), name(name), grade(grade), studentID(id) {
            cout << "This is called from parameterized constructor." << endl;
        }

};

int main(){
    // Creating object using default constructor
    Student s1;
    cout << "\nDetails of default student:\n";
    cout << "Roll No: " << s1.rollNo << endl;
    cout << "Name: " << s1.name << endl;
    cout << "Grade: " << s1.grade << endl;
    cout << "Student ID: " << s1.studentID << endl;

    // Creating object using parameterized constructor
    Student s2(1, "Yash", 'A', 2024);
    cout << "\nDetails of parameterized student:\n";
    cout << "Roll No: " << s2.rollNo << endl;
    cout << "Name: " << s2.name << endl;
    cout << "Grade: " << s2.grade << endl;
    cout << "Student ID: " << s2.studentID << endl;

    return 0;
}

