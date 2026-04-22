#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <utility>
#include <vector>

struct Student
{
    int id;
    std::string name;
    bool active;
    double grade;

    Student(int i, std::string n, bool a, double g)
        : id(i), name(std::move(n)), active(a), grade(g)
    {
    }
};

class StudentRoster
{
private:
    std::vector<Student> studentsVector;
    std::list<Student> studentsList;
    std::map<int, Student> studentsMap;

public:
    // Safe vector removal: erase-remove idiom avoids iterator invalidation issues.
    void removeFailedStudentsVector()
    {
        studentsVector.erase(
            std::remove_if(studentsVector.begin(), studentsVector.end(),
                           [](const Student &student)
                           { return student.grade < 60.0; }),
            studentsVector.end());
    }

    // Safe list removal: erase returns the next valid iterator, so we only increment when no erase occurs.
    void removeInactiveStudentsList()
    {
        for (auto it = studentsList.begin(); it != studentsList.end();)
        {
            if (!it->active)
            {
                it = studentsList.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

    // Safe map removal: post-increment the iterator before erasing the current element.
    void removeLowGradesMap(double threshold)
    {
        for (auto it = studentsMap.begin(); it != studentsMap.end();)
        {
            if (it->second.grade < threshold)
            {
                studentsMap.erase(it++);
            }
            else
            {
                ++it;
            }
        }
    }

    // Safe vector cleanup: iterator-based loop prevents skipping elements after erase.
    void cleanupVector()
    {
        for (auto it = studentsVector.begin(); it != studentsVector.end();)
        {
            if (it->grade < 60.0 || !it->active)
            {
                it = studentsVector.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

    void addStudent(int id, std::string name, bool active, double grade)
    {
        Student student(id, std::move(name), active, grade);
        studentsVector.push_back(student);
        studentsList.push_back(student);
        studentsMap.emplace(id, student);
    }

    void printRoster() const
    {
        std::cout << "Vector (" << studentsVector.size() << "): ";
        for (const auto &student : studentsVector)
        {
            std::cout << student.name << "(" << student.grade << ") ";
        }

        std::cout << "\nList (" << studentsList.size() << "): ";
        for (const auto &student : studentsList)
        {
            std::cout << student.name << "(" << student.grade << ") ";
        }

        std::cout << "\nMap (" << studentsMap.size() << "): ";
        for (const auto &[id, student] : studentsMap)
        {
            (void)id;
            std::cout << student.name << "(" << student.grade << ") ";
        }

        std::cout << "\n---\n";
    }
};

void testEdgeCases()
{
    std::cout << "\nEdge case checks:\n";

    // Test 1: Empty container
    {
        StudentRoster roster;
        roster.removeFailedStudentsVector();
        roster.removeInactiveStudentsList();
        roster.removeLowGradesMap(50.0);
        roster.cleanupVector();
        std::cout << "Empty roster handled safely.\n";
    }

    // Test 2: All elements removed
    {
        StudentRoster roster;
        roster.addStudent(1, "Fail1", true, 30.0);
        roster.addStudent(2, "Fail2", true, 40.0);
        roster.removeFailedStudentsVector();
        roster.removeInactiveStudentsList();
        roster.removeLowGradesMap(50.0);
        roster.cleanupVector();
        std::cout << "All-failing roster handled safely.\n";
    }

    // Test 3: No elements removed
    {
        StudentRoster roster;
        roster.addStudent(3, "Pass", true, 90.0);
        roster.removeFailedStudentsVector();
        roster.removeInactiveStudentsList();
        roster.removeLowGradesMap(50.0);
        roster.cleanupVector();
        std::cout << "Passing roster handled safely.\n";
    }

    // Test 4: Mixed scenario
    {
        StudentRoster roster;
        roster.addStudent(4, "Mixed", false, 55.0);
        roster.cleanupVector();
        std::cout << "Mixed roster cleanup handled safely.\n";
    }
}

int main()
{
    StudentRoster roster;

    // Test data
    roster.addStudent(1, "Alice", true, 95.5);
    roster.addStudent(2, "Bob", false, 45.0);    // Inactive, failing
    roster.addStudent(3, "Charlie", true, 58.5); // Failing
    roster.addStudent(4, "Diana", true, 88.0);
    roster.addStudent(5, "Eve", false, 30.0); // Inactive, failing

    std::cout << "Initial roster:\n";
    roster.printRoster();

    roster.removeFailedStudentsVector();
    roster.removeInactiveStudentsList();
    roster.removeLowGradesMap(50.0);
    roster.cleanupVector();

    std::cout << "\nAfter removals (should be bug-free):\n";
    roster.printRoster();

    testEdgeCases();

    return 0;
}
