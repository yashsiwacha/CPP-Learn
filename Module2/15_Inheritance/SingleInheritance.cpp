// Program to demonstrate Single Inheritance in C++
#include <iostream>
using namespace std;

/**
 * SINGLE INHERITANCE EXPLAINED:
 * Single inheritance is when a derived class inherits from only ONE base class.
 * This allows the derived class to REUSE all the features (data and methods) of
 * the base class without rewriting the code, promoting code reusability.
 *
 * In this example:
 * - Person is the BASE CLASS (parent) with common attributes like name and age
 * - Student and Teacher are DERIVED CLASSES (children) that inherit from Person
 * - Both Student and Teacher can use Person's methods WITHOUT redefining them
 */

// BASE CLASS: Person - Contains common attributes shared by all persons
class Person
{
    /**
     * ACCESS SPECIFIER: protected
     * WHY PROTECTED?
     * - 'private' would prevent derived classes from accessing these members directly
     * - 'public' would allow anyone to access them, breaking encapsulation
     * - 'protected' is the MIDDLE GROUND: accessible in derived classes but not outside
     *
     * This demonstrates the importance of access specifiers in inheritance:
     * Protected members enable derived classes to work with base class data
     * while maintaining encapsulation from external code.
     */
protected:
    string name;
    int age;

    /**
     * PUBLIC INTERFACE of Base Class:
     * These methods will be INHERITED by derived classes.
     * This is a KEY BENEFIT of inheritance: derived classes get all these
     * methods "for free" without writing any code!
     */
public:
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    int getAge()
    {
        return age;
    }
};

/**
 * DERIVED CLASS: Student
 *
 * INHERITANCE SYNTAX: class Student : public Person
 * - 'public' inheritance means public members of Person remain public in Student
 * - 'protected' members of Person remain protected in Student
 *
 * HOW SINGLE INHERITANCE ENABLES REUSE:
 * - Student automatically gets all Person's methods (setName, getName, setAge, getAge)
 * - No need to rewrite these methods - they're inherited!
 * - Student can focus on its UNIQUE features (rollNo, grade)
 *
 * HOW DERIVED CLASSES EXTEND BASE FUNCTIONALITY:
 * - Student adds NEW members: rollNo and grade
 * - Student adds NEW methods: setRollNo, getRollNo, setGrade, getGrade
 * - Student adds SPECIALIZED behavior: showStudent() that uses both inherited
 *   and new data members
 *
 * This demonstrates EXTENDING base functionality rather than replacing it.
 */
class Student : public Person
{
    // PRIVATE members specific to Student (not in base class)
    int rollNo;
    char grade;

public:
    void setRollNo(int rollNo)
    {
        this->rollNo = rollNo;
    }
    int getRollNo()
    {
        return rollNo;
    }
    void setGrade(char grade)
    {
        this->grade = grade;
    }
    char getGrade()
    {
        return grade;
    }

    /**
     * showStudent() - Demonstrates EXTENDING base functionality
     *
     * This method uses BOTH:
     * 1. Inherited protected members from Person (name, age)
     * 2. Student's own private members (rollNo, grade)
     *
     * KEY POINT: Because 'name' and 'age' are PROTECTED in Person,
     * Student can access them directly. If they were PRIVATE, Student
     * would need to use getName() and getAge() methods instead.
     *
     * This shows how access specifiers affect inheritance!
     */
    void showStudent()
    {
        cout << "THE STUDENT DETAILS:" << endl;
        cout << "Name   : " << name << endl;   // Direct access to protected member
        cout << "Age    : " << age << endl;    // Direct access to protected member
        cout << "RollNo : " << rollNo << endl; // Student's own member
        cout << "Grade  : " << grade << endl;  // Student's own member
    }
};

/**
 * DERIVED CLASS: Teacher
 *
 * ANOTHER EXAMPLE of Single Inheritance:
 * - Teacher ALSO inherits from Person (a separate inheritance)
 * - Like Student, Teacher REUSES Person's name/age functionality
 * - Teacher EXTENDS with its own unique features (subject, salary)
 *
 * BENEFIT OF CODE REUSE:
 * - Without inheritance, we'd duplicate name/age code in both Student and Teacher
 * - With inheritance, we write it ONCE in Person and reuse it everywhere
 * - Changes to Person automatically reflect in all derived classes
 */
class Teacher : public Person
{
    // PRIVATE members specific to Teacher
    string subject;
    double salary;

public:
    void setSubject(string subject)
    {
        this->subject = subject;
    }
    string getSubject()
    {
        return subject;
    }
    void setSalary(double salary)
    {
        this->salary = salary;
    }
    double getSalary()
    {
        return salary;
    }

    /**
     * showTeacher() - Another example of EXTENDING base functionality
     *
     * Same pattern as showStudent():
     * - Uses inherited protected members (name, age) from Person
     * - Combines them with Teacher-specific data (subject, salary)
     * - Creates specialized behavior for Teacher objects
     */
    void showTeacher()
    {
        cout << "THE TEACHER DETAILS:" << endl;
        cout << "Name    : " << name << endl;    // Inherited protected member
        cout << "Age     : " << age << endl;     // Inherited protected member
        cout << "Subject : " << subject << endl; // Teacher's own member
        cout << "Salary  : " << salary << endl;  // Teacher's own member
    }
};

int main()
{
    /**
     * DEMONSTRATION OF INHERITANCE IN ACTION:
     *
     * Watch how Student and Teacher objects can use:
     * 1. INHERITED methods from Person (setName, setAge, getName, getAge)
     * 2. Their OWN methods (setRollNo, setGrade, setSubject, setSalary)
     *
     * This is the power of single inheritance: combining base class features
     * with derived class extensions seamlessly!
     */

    // Creating a Student object
    Student s1;

    // Using INHERITED methods from Person class (code reuse!)
    s1.setName("Yash"); // Inherited from Person
    s1.setAge(20);      // Inherited from Person

    // Using Student's OWN methods (extending base functionality)
    s1.setRollNo(01); // Student-specific method
    s1.setGrade('A'); // Student-specific method

    // Creating a Teacher object
    Teacher t1;

    // Using INHERITED methods from Person class (same reuse!)
    t1.setName("Aryan"); // Inherited from Person
    t1.setAge(20);       // Inherited from Person

    // Using Teacher's OWN methods (extending base functionality)
    t1.setSubject("DSA"); // Teacher-specific method
    t1.setSalary(27500);  // Teacher-specific method

    /**
     * DISPLAYING RESULTS:
     * Both showStudent() and showTeacher() demonstrate how derived classes
     * combine inherited features with their own extensions to create
     * specialized, complete functionality.
     */
    cout << "\n";
    s1.showStudent();
    cout << "\n";
    t1.showTeacher();

    return 0;
}