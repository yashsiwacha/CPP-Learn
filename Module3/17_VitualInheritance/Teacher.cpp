// Program to demonstrate:
// 1) Abstract base class (interface contract via pure virtual function),
// 2) Virtual inheritance (single shared base subobject), and
// 3) Diamond problem resolution in multiple inheritance.
#include <iostream>
#include <string>

// Person is an abstract interface-like base class.
// It enforces a common contract: every concrete role must implement displayInfo().
class Person
{
protected:
    std::string name;
    int id;

public:
    Person(const std::string &personName, int personId)
        : name(personName), id(personId)
    {
    }

    virtual void displayInfo() const = 0;
    virtual ~Person() = default;
};

// Student and Employee both derive from Person *virtually*.
// Without virtual inheritance, TeachingAssistant would contain two Person subobjects
// (one via Student, one via Employee), creating duplication and ambiguity.
class Student : virtual public Person
{
protected:
    int rollNo;

public:
    Student(const std::string &personName, int personId, int studentRollNo)
        : Person(personName, personId), rollNo(studentRollNo)
    {
    }
};

// Another branch of the diamond hierarchy.
// `virtual public Person` ensures this branch shares the same Person base instance.
class Employee : virtual public Person
{
protected:
    double salary;

public:
    Employee(const std::string &personName, int personId, double employeeSalary)
        : Person(personName, personId), salary(employeeSalary)
    {
    }
};

// TeachingAssistant combines both roles.
// In a virtual inheritance hierarchy, the most-derived class (TeachingAssistant)
// is responsible for constructing the virtual base (Person).
class TeachingAssistant : public Student, public Employee
{
public:
    TeachingAssistant(const std::string &personName, int personId, int studentRollNo, double employeeSalary)
        : Person(personName, personId), Student(personName, personId, studentRollNo), Employee(personName, personId, employeeSalary)
    {
    }

    void displayInfo() const override
    {
        std::cout << "TeachingAssistant Information" << std::endl;
        std::cout << "Name   : " << name << std::endl;
        std::cout << "ID     : " << id << std::endl;
        std::cout << "RollNo : " << rollNo << std::endl;
        std::cout << "Salary : " << salary << std::endl;
    }
};

int main()
{
    // One object with two roles (Student + Employee) and one shared Person identity.
    TeachingAssistant ta("Yash", 101, 22017, 45000.0);

    // Concrete implementation of the abstract Person contract.
    ta.displayInfo();

    // Access Person through both inheritance paths.
    // If virtual inheritance works correctly, both pointers must be identical.
    Person *viaStudent = static_cast<Person *>(static_cast<Student *>(&ta));
    Person *viaEmployee = static_cast<Person *>(static_cast<Employee *>(&ta));

    std::cout << "Person subobject via Student path : " << viaStudent << std::endl;
    std::cout << "Person subobject via Employee path: " << viaEmployee << std::endl;

    if (viaStudent == viaEmployee)
    {
        // Proof of diamond resolution: only one Person base subobject exists.
        std::cout << "Confirmed: TeachingAssistant has only one Person subobject." << std::endl;
    }

    return 0;
}