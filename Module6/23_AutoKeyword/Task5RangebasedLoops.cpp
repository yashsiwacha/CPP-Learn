#include <iostream>
#include <string>
#include <vector>

struct Student
{
    std::string name;
    int marks;
};

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5};
    std::vector<std::string> words{"auto", "range", "loop"};
    std::vector<Student> students{{"Aman", 76}, {"Neha", 82}, {"Ravi", 68}};

    // auto x creates a copy of each element (safe for read-only iteration).
    std::cout << "Integers (range-based, copy): ";
    for (auto x : v)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Traditional iterator loop for comparison with range-based style.
    std::cout << "Integers (iterator-based): ";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // auto& gives a reference, so updates happen in-place inside the vector.
    for (auto &x : v)
    {
        x *= 10;
    }
    std::cout << "Integers after in-place update (auto&): ";
    for (const auto &x : v)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Works with other data types too; const auto& avoids unnecessary string copies.
    std::cout << "Strings (const auto&): ";
    for (const auto &word : words)
    {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    // Range-based loops also work well with custom structs.
    // Using auto& lets us modify each student's marks directly.
    for (auto &student : students)
    {
        student.marks += 5;
    }
    std::cout << "Students after grace marks (+5): ";
    for (const auto &student : students)
    {
        std::cout << "[" << student.name << ": " << student.marks << "] ";
    }
    std::cout << std::endl;

    return 0;
}
