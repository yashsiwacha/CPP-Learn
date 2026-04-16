#include <iomanip>
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <vector>

void printGrades(const std::vector<int> &grades, const std::string &label)
{
    std::cout << "\n"
              << label << "\n";
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

void printSimpleStats(const std::vector<int> &grades)
{
    if (grades.empty())
    {
        std::cout << "Statistics: No data available.\n";
        return;
    }

    int sum = std::accumulate(grades.begin(), grades.end(), 0);
    double average = static_cast<double>(sum) / grades.size();

    std::cout << "Statistics -> Sum: " << sum
              << ", Average: " << std::fixed << std::setprecision(2) << average
              << "\n";
}

int main()
{
    std::vector<int> grades;

    // 1) Initialization
    std::cout << "--- Student Grade Manager ---\n";
    std::cout << "Initially empty? " << (grades.empty() ? "Yes" : "No") << "\n";

    // 2) Adding Grades
    grades.push_back(80);
    grades.push_back(90);
    grades.push_back(75);
    grades.push_back(98);
    grades.push_back(89);
    grades.push_back(84);

    printGrades(grades, "After adding initial grades:");
    std::cout << "Current size: " << grades.size() << "\n";

    // 3) Accessing & Modifying Grades
    std::cout << "\nFirst grade (front): " << grades.front() << "\n";
    std::cout << "Last grade (back): " << grades.back() << "\n";

    std::cout << "Grade at index 2 using operator[]: " << grades[2] << "\n";
    std::cout << "Grade at index 2 using at(): " << grades.at(2) << "\n";

    grades[2] = 80;
    std::cout << "Modified grade at index 2: " << grades.at(2) << "\n";

    try
    {
        std::cout << "Trying out-of-range access with at(100): ";
        std::cout << grades.at(100) << "\n";
    }
    catch (const std::out_of_range &ex)
    {
        std::cout << "Caught exception -> " << ex.what() << "\n";
    }

    // 4) Inserting Grades
    grades.insert(grades.begin(), 100);
    grades.insert(grades.end() - 1, 75);

    printGrades(grades, "After insertions:");
    std::cout << "New size: " << grades.size() << "\n";

    // 5) Removing Grades
    grades.pop_back();
    grades.erase(grades.begin() + 1);

    printGrades(grades, "After removals:");
    std::cout << "New size: " << grades.size() << "\n";

    // Simple statistics from current data.
    printSimpleStats(grades);

    // 6) Clearing
    grades.clear();
    std::cout << "\nAfter clear() -> size: " << grades.size()
              << ", empty? " << (grades.empty() ? "Yes" : "No") << "\n";

    return 0;
}
