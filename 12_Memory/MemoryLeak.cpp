// Program to Detect Memory Leaks Using Overloaded new and delete Operators
#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

class Tracker
{
private:
    static int allocation_count;            // Total allocations made
    static int deallocation_count;          // Total deallocations made
    static int active_allocations;          // Current active allocations
    static int object_id_counter;           // Counter for assigning unique IDs
    static map<void *, int> allocation_map; // Maps memory addresses to object IDs

    int object_id; // Unique identifier for each object

public:
    // Constructor to assign unique ID
    Tracker() : object_id(++object_id_counter)
    {
        cout << "  [Constructor] Tracker object ID #" << object_id << " initialized" << endl;
    }

    // Destructor
    ~Tracker()
    {
        cout << "  [Destructor] Tracker object ID #" << object_id << " destroyed" << endl;
    }

    // Overloaded operator new
    void *operator new(size_t size)
    {
        void *ptr = ::operator new(size);
        ++allocation_count;
        ++active_allocations;

        cout << "\n[ALLOCATION #" << allocation_count << "]" << endl;
        cout << "  Memory allocated: " << size << " bytes" << endl;
        cout << "  Memory address: " << ptr << endl;
        cout << "  Active allocations: " << active_allocations << endl;

        // Store the allocation
        allocation_map[ptr] = allocation_count;

        return ptr;
    }

    // Overloaded operator delete
    void operator delete(void *ptr)
    {
        if (ptr == nullptr)
            return;

        ++deallocation_count;
        --active_allocations;

        cout << "\n[DEALLOCATION #" << deallocation_count << "]" << endl;
        cout << "  Memory freed at address: " << ptr << endl;

        // Remove from allocation map
        auto it = allocation_map.find(ptr);
        if (it != allocation_map.end())
        {
            cout << "  This was allocation #" << it->second << endl;
            allocation_map.erase(it);
        }

        cout << "  Active allocations remaining: " << active_allocations << endl;

        ::operator delete(ptr);
    }

    // Static method to display leak report
    static void display_leak_report()
    {
        cout << "\n"
             << string(60, '=') << endl;
        cout << "          MEMORY LEAK DETECTION REPORT" << endl;
        cout << string(60, '=') << endl;

        cout << "\nSummary Statistics:" << endl;
        cout << "  Total allocations made:     " << allocation_count << endl;
        cout << "  Total deallocations made:   " << deallocation_count << endl;
        cout << "  Current active allocations: " << active_allocations << endl;

        if (active_allocations > 0)
        {
            cout << "\n[WARNING] MEMORY LEAK DETECTED!" << endl;
            cout << "  Number of leaked objects: " << active_allocations << endl;
            cout << "\n  Leaked allocations details:" << endl;

            for (const auto &pair : allocation_map)
            {
                cout << "    - Allocation #" << pair.second
                     << " at address " << pair.first
                     << " was never freed" << endl;
            }

            cout << "\n  Impact: " << active_allocations
                 << " object(s) remain in memory without proper cleanup." << endl;
        }
        else
        {
            cout << "\n[SUCCESS] No memory leaks detected!" << endl;
            cout << "  All allocated memory has been properly freed." << endl;
        }

        cout << "\n"
             << string(60, '=') << endl;
    }

    // Getter for object ID
    int get_id() const { return object_id; }
};

// Initialize static members
int Tracker::allocation_count = 0;
int Tracker::deallocation_count = 0;
int Tracker::active_allocations = 0;
int Tracker::object_id_counter = 0;
map<void *, int> Tracker::allocation_map;

int main()
{
    cout << "=== Memory Leak Detection Demo ===" << endl;
    cout << "Creating multiple Tracker objects...\n"
         << endl;

    // Allocate multiple Tracker objects
    Tracker *t1 = new Tracker();
    Tracker *t2 = new Tracker();
    Tracker *t3 = new Tracker();
    Tracker *t4 = new Tracker();
    Tracker *t5 = new Tracker();

    cout << "\n--- Deleting some objects (t1, t2, t4) ---" << endl;

    // Free only some objects - simulating memory leaks
    delete t1;
    delete t2;
    delete t4;

    cout << "\n--- Intentionally NOT deleting t3 and t5 (LEAK SIMULATION) ---" << endl;
    cout << "  t3 and t5 are still allocated but will not be freed" << endl;

    // Display comprehensive leak report
    Tracker::display_leak_report();

    cout << "\n\nNote: In a real scenario, these leaks would persist until program termination." << endl;
    cout << "The operating system will reclaim the memory, but this is poor practice!" << endl;

    return 0;
}