#include <algorithm>
#include <iostream>
#include <list>
#include <string>

void printInventory(const std::list<std::string> &inventory, const std::string &label)
{
    std::cout << label << ": ";

    if (inventory.empty())
    {
        std::cout << "(empty)\n";
        return;
    }

    for (const std::string &product : inventory)
    {
        std::cout << product << " ";
    }
    std::cout << "\n";
}

int main()
{
    std::list<std::string> warehouse1 = {"A100", "A200", "A300"};
    std::list<std::string> warehouse2 = {"A150", "A250", "A350"};

    std::cout << "--- Merging Online Store Inventory Lists ---\n\n";

    // Display original inventories.
    printInventory(warehouse1, "Warehouse 1 (before merge)");
    printInventory(warehouse2, "Warehouse 2 (before merge)");

    // Ensure both lists are sorted before merge.
    if (!std::is_sorted(warehouse1.begin(), warehouse1.end()))
    {
        warehouse1.sort();
    }
    if (!std::is_sorted(warehouse2.begin(), warehouse2.end()))
    {
        warehouse2.sort();
    }

    // Merge Warehouse 2 into Warehouse 1.
    warehouse1.merge(warehouse2);

    std::cout << "\nAfter merge:\n";
    printInventory(warehouse1, "Unified inventory (Warehouse 1)");
    printInventory(warehouse2, "Warehouse 2 (after merge)");

    std::cout << "Warehouse 2 empty after merge? "
              << (warehouse2.empty() ? "Yes" : "No") << "\n";

    return 0;
}
