#include <iostream>
#include <limits>
#include <list>
#include <string>

void printList(const std::list<int> &values, const std::string &heading)
{
    std::cout << "\n"
              << heading << "\n";
    std::cout << "List: ";

    if (values.empty())
    {
        std::cout << "(empty)\n";
        return;
    }

    for (int value : values)
    {
        std::cout << value << " ";
    }
    std::cout << "\n";
}

// Removes all occurrences of target using std::list::remove().
void removeUsingMemberFunction(std::list<int> &values, int target)
{
    printList(values, "Before list::remove():");

    // list::remove(value) deletes every node equal to value in one call.
    values.remove(target);

    printList(values, "After list::remove():");
}

// Removes all occurrences manually using iterator traversal and erase().
void removeUsingManualTraversal(std::list<int> &values, int target)
{
    printList(values, "Before manual erase traversal:");

    // While erasing in a loop, never do ++it after erase(it).
    // erase(it) invalidates only the erased iterator and returns the next valid iterator.
    for (auto it = values.begin(); it != values.end();)
    {
        if (*it == target)
        {
            it = values.erase(it);
        }
        else
        {
            ++it;
        }
    }

    printList(values, "After manual erase traversal:");
}

int main()
{
    std::list<int> numbers = {3, 7, 5, 3, 9, 3, 1, 7, 4, 3, 8, 5};

    std::cout << "--- Removing All Occurrences from std::list ---\n";
    printList(numbers, "Original list:");

    std::cout << "\nEnter an integer value to remove: ";
    int valueToRemove{};
    if (!(std::cin >> valueToRemove))
    {
        std::cerr << "Error: Invalid input. Please enter an integer.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1;
    }

    // Keep the same starting data for a fair side-by-side comparison.
    std::list<int> numbersForMemberRemove = numbers;
    std::list<int> numbersForManualErase = numbers;

    removeUsingMemberFunction(numbersForMemberRemove, valueToRemove);
    removeUsingManualTraversal(numbersForManualErase, valueToRemove);

    return 0;
}
