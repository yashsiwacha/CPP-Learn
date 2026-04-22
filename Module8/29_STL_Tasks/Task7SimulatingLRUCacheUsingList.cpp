#include <iostream>
#include <limits>
#include <list>

const int CACHE_CAPACITY = 6;

void printCache(const std::list<int> &cache)
{
    std::cout << "Cache (MRU -> LRU): ";

    if (cache.empty())
    {
        std::cout << "(empty)\n";
        return;
    }

    for (int value : cache)
    {
        std::cout << value << " ";
    }
    std::cout << "\n";
}

/**
 * Access a value in the LRU cache.
 * If found, move it to front (MRU). If not found, insert at front.
 * When capacity is exceeded, remove the back element (LRU).
 */
void accessCache(std::list<int> &cache, int value)
{
    // Manually traverse the list to find the requested value.
    auto it = cache.begin();
    bool found = false;

    while (it != cache.end())
    {
        if (*it == value)
        {
            // erase(it) returns the next valid iterator.
            it = cache.erase(it);
            found = true;
            break;
        }
        ++it;
    }

    if (found)
    {
        // Cache hit: move accessed item to the front (most recently used).
        cache.push_front(value);
    }
    else
    {
        // Cache miss: insert new item at the front.
        cache.push_front(value);

        // If capacity is exceeded, remove the least recently used item from the back.
        if (static_cast<int>(cache.size()) > CACHE_CAPACITY)
        {
            cache.pop_back();
        }
    }
}

int main()
{
    std::list<int> cache;

    std::cout << "--- LRU Cache Simulation Using std::list ---\n";
    std::cout << "Cache capacity: " << CACHE_CAPACITY << "\n";
    std::cout << "Enter -1 to stop.\n\n";

    while (true)
    {
        std::cout << "Access value: ";

        int value{};
        if (!(std::cin >> value))
        {
            std::cerr << "Invalid input. Please enter an integer.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (value == -1)
        {
            break;
        }

        accessCache(cache, value);
        printCache(cache);
    }

    std::cout << "\nFinal cache state:\n";
    printCache(cache);

    return 0;
}
