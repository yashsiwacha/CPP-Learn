#include <iostream>
#include <set>
#include <string>

void printSetContents(const std::set<int> &studentIDs, const std::string &title)
{
    std::cout << "\n"
              << title << "\n";

    if (studentIDs.empty())
    {
        std::cout << "(empty)\n";
        return;
    }

    for (int studentId : studentIDs)
    {
        std::cout << studentId << "\n";
    }
}

void populateAndDemonstrateUniqueness(std::set<int> &studentIDs)
{
    std::cout << "--- Step 2: Populating roster and demonstrating uniqueness ---\n";
    std::cout << "Size before initial insertions: " << studentIDs.size() << "\n";

    studentIDs.insert(101);
    studentIDs.insert(105);
    studentIDs.insert(103);
    studentIDs.insert(102);

    std::cout << "Size after initial insertions: " << studentIDs.size() << "\n";

    std::cout << "Attempting to insert duplicate student ID 105 again...\n";
    auto insertResult = studentIDs.insert(105);
    if (insertResult.second)
    {
        std::cout << "105 was added. This should not happen for a duplicate in std::set.\n";
    }
    else
    {
        std::cout << "105 was not added because std::set only stores unique values.\n";
    }
    std::cout << "Final size after duplicate attempt: " << studentIDs.size() << "\n";
}

void checkStudentExistence(const std::set<int> &studentIDs, int studentId)
{
    auto it = studentIDs.find(studentId);
    if (it != studentIDs.end())
    {
        std::cout << "Student ID " << studentId << " was found in the roster.\n";
    }
    else
    {
        std::cout << "Student ID " << studentId << " was not found in the roster.\n";
    }
}

void removeElements(std::set<int> &studentIDs)
{
    std::cout << "--- Step 5: Removing student IDs ---\n";

    std::cout << "Removing existing student ID 102...\n";
    std::size_t removedCount = studentIDs.erase(102);
    std::cout << "Elements removed: " << removedCount << "\n";
    std::cout << "Size after removing 102: " << studentIDs.size() << "\n";

    std::cout << "Attempting to remove non-existent student ID 108...\n";
    removedCount = studentIDs.erase(108);
    std::cout << "Elements removed: " << removedCount << "\n";
    std::cout << "Size after attempting to remove 108: " << studentIDs.size() << "\n";
}

int main()
{
    std::set<int> studentIDs;
    std::cout << "Student ID set declared successfully.\n";

    populateAndDemonstrateUniqueness(studentIDs);

    printSetContents(studentIDs, "Student IDs in the set (initial roster):");

    std::cout << "\n--- Step 4: Checking for Student Existence ---\n";
    checkStudentExistence(studentIDs, 103);
    checkStudentExistence(studentIDs, 999);
    std::cout << "\n";

    removeElements(studentIDs);

    printSetContents(studentIDs, "Final Student IDs in the set:");
    std::cout << "Final size of the set: " << studentIDs.size() << "\n";
    std::cout << "Expected remaining IDs: 101, 103, 105\n";

    return 0;
}
