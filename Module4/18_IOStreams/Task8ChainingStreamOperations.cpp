#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Person supports stream-friendly input/output through operator overloading.
class Person
{
private:
    string name;
    int age;

public:
    Person() : name(""), age(0) {}

    friend istream &operator>>(istream &is, Person &p);
    friend ostream &operator<<(ostream &os, const Person &p);
};

istream &operator>>(istream &is, Person &p)
{
    // When reading from console, show prompts to guide the user.
    if (&is == &cin)
    {
        cout << "Name: ";
    }
    getline(is, p.name);

    if (&is == &cin)
    {
        cout << "Age : ";
    }
    if (!(is >> p.age))
    {
        return is;
    }

    // Remove trailing newline so the next getline works correctly.
    is.ignore(numeric_limits<streamsize>::max(), '\n');
    return is;
}

ostream &operator<<(ostream &os, const Person &p)
{
    os << "| Name: " << p.name << '\n'
       << "| Age : " << p.age;
    return os;
}

int main()
{
    Person firstPerson;
    Person secondPerson;

    // Chained extraction: both objects are read in one expression.
    // This is possible because operator>> returns the same stream reference.
    cout << "Enter details for Person 1:\n";
    cin >> firstPerson;

    cout << "\nEnter details for Person 2:\n";
    cin >> secondPerson;

    if (!cin)
    {
        cout << "Invalid input. Please enter age as a number.\n";
        return 1;
    }

    // Chained insertion: both objects are printed in one output expression.
    cout << "\n================================\n"
         << "        PERSON DETAILS         \n"
         << "================================\n"
         << "Person 1\n"
         << "--------------------------------\n"
         << firstPerson << '\n'
         << "--------------------------------\n"
         << "Person 2\n"
         << "--------------------------------\n"
         << secondPerson << '\n'
         << "--------------------------------\n";

    return 0;
}