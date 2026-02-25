// Program to demonstrate formatted output with stream manipulators.
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

struct Item
{
    std::string name;
    double price;
};

int main()
{
    Item items[] = {
        {"Apple", 1.50},
        {"Banana", 0.99},
        {"Orange", 2.25}};

    const int itemCount = sizeof(items) / sizeof(items[0]);
    const int padding = 3;
    int itemWidth = static_cast<int>(std::string("Item").length()) + padding;
    int priceWidth = static_cast<int>(std::string("Price").length()) + padding;

    for (int index = 0; index < itemCount; ++index)
    {
        if (static_cast<int>(items[index].name.length()) + padding > itemWidth)
        {
            itemWidth = static_cast<int>(items[index].name.length()) + padding;
        }

        std::ostringstream priceStream;
        priceStream << std::fixed << std::setprecision(2) << items[index].price;
        const int formattedPriceLength = static_cast<int>(priceStream.str().length()) + padding;
        if (formattedPriceLength > priceWidth)
        {
            priceWidth = formattedPriceLength;
        }
    }

    // std::setw controls column width; std::left/std::right control alignment.
    std::cout << std::left << std::setw(itemWidth) << "Item"
              << std::right << std::setw(priceWidth) << "Price" << '\n';
    std::cout << std::string(itemWidth + priceWidth, '-') << '\n';

    for (const Item &item : items)
    {
        // std::fixed + std::setprecision(2) prints money with 2 decimals.
        std::cout << std::left << std::setw(itemWidth) << item.name
                  << std::right << std::setw(priceWidth) << std::fixed << std::setprecision(2)
                  << item.price << '\n';
    }

    return 0;
}
