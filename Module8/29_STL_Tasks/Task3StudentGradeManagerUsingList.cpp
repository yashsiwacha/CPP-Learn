#include <exception>
#include <iostream>
#include <iterator>
#include <list>
#include <stdexcept>

void printGrades(const std::list<int> &grades, const std::string &title)
{
    std::cout << "\n"
              << title << "\n";
    std::cout << "Grades: ";

    if (grades.empty())
    {
        std::cout << "(empty)\n";
        return;
    }

    for (int grade : grades)
    {
        std::cout << grade << " ";
    }
    std::cout << "\n";
}

int main()
{
    // 1) Initialization
    std::list<int> grades;
    std::cout << "--- Student Grade Manager using std::list ---\n";
    std::cout << "Initially empty? " << (grades.empty() ? "Yes" : "No") << "\n";

    // 2) Adding Grades
    grades.push_back(80);
    grades.push_back(90);
    grades.push_back(75);
    grades.push_back(98);
    grades.push_back(89);
    grades.push_back(84);

    printGrades(grades, "After adding grades:");
    std::cout << "Current size: " << grades.size() << "\n";

    // 3) Accessing & Modifying Grades
    if (!grades.empty())
    {
        std::cout << "\nFirst grade: " << grades.front() << "\n";
        std::cout << "Last grade: " << grades.back() << "\n";
    }

    if (grades.size() >= 3)
    {
        auto it = grades.begin();
        std::advance(it, 2);
        std::cout << "Grade at third position (index 2): " << *it << "\n";

        *it = 99;
        std::cout << "Updated grade at third position: " << *it << "\n";
    }

    // Demonstrate iterator boundary handling: std::advance itself does not throw.
    try
    {
        std::size_t badIndex = grades.size();
        auto badIt = grades.begin();

        std::advance(badIt, static_cast<long long>(badIndex));
        if (badIt == grades.end())
        {
            throw std::out_of_range("Iterator reached end(); dereferencing beyond valid range is not allowed.");
        }

        std::cout << "Out-of-bounds value: " << *badIt << "\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << "\n";
    }

    // 4) Inserting Grades
    grades.push_front(100);

    auto beforeLast = grades.end();
    --beforeLast;
    grades.insert(beforeLast, 77);

    printGrades(grades, "After insertions:");
    std::cout << "Updated size: " << grades.size() << "\n";

    // 5) Removing Grades
    if (!grades.empty())
    {
        grades.pop_back();
    }

    if (grades.size() >= 2)
    {
        auto secondPos = grades.begin();
        std::advance(secondPos, 1);
        grades.erase(secondPos);
    }

    printGrades(grades, "After removals:");
    std::cout << "Updated size: " << grades.size() << "\n";

    // 6) Clearing
    grades.clear();
    std::cout << "\nAfter clear() -> size: " << grades.size()
              << ", empty? " << (grades.empty() ? "Yes" : "No") << "\n";

    return 0;
}
