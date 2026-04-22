#include <iostream>
#include <limits>
#include <map>
#include <string>

void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool getProductStock(int productId, int &currentStock, const std::map<int, int> &inventoryMap)
{
    auto it = inventoryMap.find(productId);
    if (it != inventoryMap.end())
    {
        currentStock = it->second;
        return true;
    }

    currentStock = 0;
    return false;
}

void displayInventory(const std::map<int, int> &inventoryMap, const std::string &title)
{
    std::cout << "\n"
              << title << "\n";

    if (inventoryMap.empty())
    {
        std::cout << "Inventory is empty.\n";
        return;
    }

    std::cout << "ProductID -> Stock\n";
    for (const auto &entry : inventoryMap)
    {
        std::cout << entry.first << " -> " << entry.second << "\n";
    }
}

void addNewProduct(std::map<int, int> &inventory)
{
    int productId{};
    int initialStock{};

    std::cout << "Enter new Product ID: ";
    if (!(std::cin >> productId))
    {
        std::cerr << "Invalid Product ID.\n";
        clearInputBuffer();
        return;
    }

    if (productId <= 0)
    {
        std::cerr << "Product ID must be positive.\n";
        clearInputBuffer();
        return;
    }

    if (inventory.count(productId) > 0)
    {
        std::cout << "Product already exists. Use Restock for Product ID " << productId << ".\n";
        clearInputBuffer();
        return;
    }

    std::cout << "Enter initial stock quantity: ";
    if (!(std::cin >> initialStock))
    {
        std::cerr << "Invalid stock quantity.\n";
        clearInputBuffer();
        return;
    }

    if (initialStock < 0)
    {
        std::cerr << "Initial stock cannot be negative.\n";
        clearInputBuffer();
        return;
    }

    inventory[productId] = initialStock;
    std::cout << "Product added: " << productId << " with stock " << initialStock << ".\n";
}

void performSale(std::map<int, int> &inventory)
{
    int productId{};
    int quantityToSell{};

    std::cout << "Enter Product ID for sale: ";
    if (!(std::cin >> productId))
    {
        std::cerr << "Invalid Product ID.\n";
        clearInputBuffer();
        return;
    }

    std::cout << "Enter quantity to sell: ";
    if (!(std::cin >> quantityToSell))
    {
        std::cerr << "Invalid quantity.\n";
        clearInputBuffer();
        return;
    }

    if (quantityToSell <= 0)
    {
        std::cerr << "Quantity to sell must be positive.\n";
        clearInputBuffer();
        return;
    }

    int currentStock{};
    if (!getProductStock(productId, currentStock, inventory))
    {
        std::cout << "Product ID " << productId << " not found.\n";
        return;
    }

    if (currentStock < quantityToSell)
    {
        std::cout << "Insufficient stock. Current stock: " << currentStock << ".\n";
        return;
    }

    inventory[productId] = currentStock - quantityToSell;
    std::cout << "Sale recorded. Updated stock for Product ID " << productId
              << " is " << inventory[productId] << ".\n";
}

void performRestock(std::map<int, int> &inventory)
{
    int productId{};
    int quantityToRestock{};

    std::cout << "Enter Product ID to restock: ";
    if (!(std::cin >> productId))
    {
        std::cerr << "Invalid Product ID.\n";
        clearInputBuffer();
        return;
    }

    std::cout << "Enter quantity to restock: ";
    if (!(std::cin >> quantityToRestock))
    {
        std::cerr << "Invalid quantity.\n";
        clearInputBuffer();
        return;
    }

    if (quantityToRestock <= 0)
    {
        std::cerr << "Quantity to restock must be positive.\n";
        clearInputBuffer();
        return;
    }

    if (inventory.count(productId) > 0)
    {
        inventory[productId] += quantityToRestock;
        std::cout << "Restock complete. Updated stock for Product ID " << productId
                  << " is " << inventory[productId] << ".\n";
    }
    else
    {
        inventory[productId] = quantityToRestock;
        std::cout << "Product ID " << productId
                  << " did not exist. Added as a new product with stock "
                  << quantityToRestock << ".\n";
    }
}

void checkProductStatus(const std::map<int, int> &inventory)
{
    int productId{};

    std::cout << "Enter Product ID to check: ";
    if (!(std::cin >> productId))
    {
        std::cerr << "Invalid Product ID.\n";
        clearInputBuffer();
        return;
    }

    int currentStock{};
    if (getProductStock(productId, currentStock, inventory))
    {
        std::cout << "Product ID " << productId << " has stock: " << currentStock << ".\n";
    }
    else
    {
        std::cout << "Product ID " << productId << " not found.\n";
    }
}

void discontinueProduct(std::map<int, int> &inventory)
{
    int productId{};

    std::cout << "Enter Product ID to discontinue: ";
    if (!(std::cin >> productId))
    {
        std::cerr << "Invalid Product ID.\n";
        clearInputBuffer();
        return;
    }

    std::size_t removedCount = inventory.erase(productId);
    if (removedCount > 0)
    {
        std::cout << "Product ID " << productId << " removed from inventory.\n";
    }
    else
    {
        std::cout << "Product ID " << productId << " was not found.\n";
    }
}

void ActionToPerform(std::map<int, int> &inventory)
{
    int choice{};

    do
    {
        std::cout << "\n===== Inventory Menu =====\n";
        std::cout << "1. Add New Product\n";
        std::cout << "2. Perform Sale\n";
        std::cout << "3. Perform Restock\n";
        std::cout << "4. Check Product Status\n";
        std::cout << "5. Discontinue Product\n";
        std::cout << "6. Display All Products\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";

        if (!(std::cin >> choice))
        {
            std::cerr << "Invalid menu choice. Please enter a number from 0 to 6.\n";
            clearInputBuffer();
            continue;
        }

        // Remove trailing buffered characters after reading menu choice.
        clearInputBuffer();

        switch (choice)
        {
        case 1:
            addNewProduct(inventory);
            break;
        case 2:
            performSale(inventory);
            break;
        case 3:
            performRestock(inventory);
            break;
        case 4:
            checkProductStatus(inventory);
            break;
        case 5:
            discontinueProduct(inventory);
            break;
        case 6:
            displayInventory(inventory, "Current Inventory Overview");
            break;
        case 0:
            std::cout << "Exiting inventory manager...\n";
            break;
        default:
            std::cout << "Invalid choice. Please select a valid option.\n";
            break;
        }
    } while (choice != 0);
}

int main()
{
    std::map<int, int> productInventory;
    productInventory[101] = 50;
    productInventory[102] = 25;
    productInventory[103] = 100;
    productInventory[104] = 10;
    productInventory[105] = 75;

    displayInventory(productInventory, "Initial Inventory");

    ActionToPerform(productInventory);

    std::cout << "Program completion.\n";
    return 0;
}
