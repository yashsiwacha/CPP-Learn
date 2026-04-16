#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void printStudents(const std::vector<std::string> &students, const std::string &title)
{
    std::cout << "\n"
              << title << "\n";

    if (students.empty())
    {
        std::cout << "Student list is empty.\n";
        return;
    }

    std::cout << "Students: ";
    for (const std::string &name : students)
    {
        std::cout << name << " ";
    }
    std::cout << "\n";
}

int main()
{
    // 1) Create vector of student names.
    std::vector<std::string> students;

    // 2) Insert required names.
    students.push_back("Alice");
    students.push_back("Bob");
    students.push_back("Charlie");
    students.push_back("Diana");
    students.push_back("Eve");

    // 3) Display list.
    printStudents(students, "Initial student list:");

    // 4) Remove "Charlie" by name.
    auto newEnd = std::remove(students.begin(), students.end(), "Charlie");
    if (newEnd != students.end())
    {
        students.erase(newEnd, students.end());
        std::cout << "\nRemoved student: Charlie\n";
    }
    else
    {
        std::cout << "\nStudent Charlie not found. No removal performed.\n";
    }
    printStudents(students, "After removal:");

    // 5) Find if "Eve" is present.
    auto it = std::find(students.begin(), students.end(), "Eve");
    if (it != students.end())
    {
        std::cout << "\nSearch result: Eve is enrolled in the workshop.\n";
    }
    else
    {
        std::cout << "\nSearch result: Eve is not enrolled in the workshop.\n";
    }

    // 6) Sort alphabetically and display.
    std::sort(students.begin(), students.end());
    printStudents(students, "After alphabetical sort (A-Z):");

    // 7) Clear list and confirm empty state.
    students.clear();
    std::cout << "\nAfter clear() -> size: " << students.size()
              << ", empty? " << (students.empty() ? "Yes" : "No") << "\n";

    return 0;
}
