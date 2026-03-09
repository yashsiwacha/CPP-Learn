#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class InvalidPriceException : public runtime_error
{
public:
    explicit InvalidPriceException(const char *message) : runtime_error(message) {}

    explicit InvalidPriceException(const string &message) : runtime_error(message) {}
};

class Product
{
private:
    string name;
    double price;
    int stock;

public:
    Product(string productName, double productPrice, int productStock)
        : name(move(productName)), price(productPrice), stock(productStock) {}

    const string &getName() const
    {
        return name;
    }

    double getPrice() const
    {
        return price;
    }

    int getStock() const
    {
        return stock;
    }

    void setPrice(double newPrice)
    {
        price = newPrice;
    }

    void display() const
    {
        cout << left << setw(16) << name
             << " Price: Rs. " << fixed << setprecision(2) << setw(10) << price
             << " Stock: " << stock << '\n';
    }
};

double getNewPrice()
{
    cout << "Enter new price (Rs.): ";

    double newPrice = 0.0;
    cin >> newPrice;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidPriceException("Error: Invalid input. Please enter a numeric value for price.");
    }

    if (newPrice <= 0.0)
    {
        throw InvalidPriceException("Error: Price must be a positive value.");
    }

    if (newPrice > 10000.0)
    {
        throw InvalidPriceException("Error: Price cannot exceed Rs. 10,000.");
    }

    // Check if price has more than 2 decimal places by scaling to cents.
    const double scaled = newPrice * 100.0;
    if (fabs(scaled - round(scaled)) > 1e-9)
    {
        throw InvalidPriceException("Error: Price can have at most 2 decimal places.");
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return newPrice;
}

void updateProductPrice(Product &product)
{
    cout << "\nCurrent product details:\n";
    product.display();

    while (true)
    {
        try
        {
            const double currentPrice = product.getPrice();
            const double newPrice = getNewPrice();

            if (currentPrice == 0.0)
            {
                throw InvalidPriceException("Error: Current price is zero; percentage change cannot be computed.");
            }

            const double percentageChange = fabs((newPrice - currentPrice) / currentPrice) * 100.0;

            if (percentageChange > 50.0)
            {
                throw InvalidPriceException("Error: Price change cannot exceed 50% in a single update.");
            }

            product.setPrice(newPrice);
            cout << "Price updated successfully for " << product.getName() << ".\n";
            product.display();
            break;
        }
        catch (const InvalidPriceException &e)
        {
            cout << e.what() << "\nPlease try again.\n\n";
        }
    }
}

template <size_t N>
void displayInventory(const array<Product, N> &inventory)
{
    cout << "\n========== Inventory ==========" << '\n';
    for (size_t index = 0; index < inventory.size(); ++index)
    {
        cout << index + 1 << ". ";
        inventory[index].display();
    }
    cout << "===============================\n";
}

int main()
{
    array<Product, 3> inventory = {
        Product("Laptop", 65000.00, 5),
        Product("Mouse", 499.99, 40),
        Product("Keyboard", 1499.50, 25)};

    cout << "===============================================\n";
    cout << " Product Price Validation System (Custom Exception)\n";
    cout << "===============================================\n";

    char continueUpdate = 'y';

    do
    {
        try
        {
            displayInventory(inventory);

            cout << "Select product number to update price: ";
            int selectedProduct = 0;
            cin >> selectedProduct;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidPriceException("Error: Invalid product selection.");
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (selectedProduct < 1 || selectedProduct > static_cast<int>(inventory.size()))
            {
                throw InvalidPriceException("Error: Invalid product selection. Please enter a number between 1 and " +
                                            to_string(inventory.size()) + ".");
            }

            updateProductPrice(inventory[selectedProduct - 1]);
        }
        catch (const InvalidPriceException &e)
        {
            cout << e.what() << '\n';
        }

        cout << "\nDo you want to update another product? (y/n): ";
        cin >> continueUpdate;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (continueUpdate == 'y' || continueUpdate == 'Y');

    cout << "\nFinal inventory status:\n";
    displayInventory(inventory);
    cout << "Exiting program.\n";

    return 0;
}
