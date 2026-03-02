#include <iostream>
#include <string>
using namespace std;

class Result;

class Student
{
private:
    string name;
    int marks;

public:
    Student(const string &name, int marks) : name(name), marks(marks) {}

    // Result can access private members for evaluation/reporting.
    friend class Result;
};

class Result
{
public:
    void display(const Student &student) const
    {
        cout << "Student Name : " << student.name << '\n';
        cout << "Marks        : " << student.marks << '\n';

        if (student.marks >= 50)
        {
            cout << "Result       : Pass\n";
        }
        else
        {
            cout << "Result       : Fail\n";
        }
    }
};

int main()
{
    Student student("Alice", 72);
    Result result;

    result.display(student);

    return 0;
}
