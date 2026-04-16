#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

void printTodoList(const std::vector<std::string> &tasks)
{
    std::cout << "\nCurrent To-Do List (" << tasks.size() << " tasks):\n";

    if (tasks.empty())
    {
        std::cout << "(empty)\n";
        return;
    }

    for (std::size_t i = 0; i < tasks.size(); ++i)
    {
        std::cout << (i + 1) << ". " << tasks[i] << "\n";
    }
}

void clearInputBuffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string toUpperString(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c)
                   { return static_cast<char>(std::toupper(c)); });
    return s;
}

std::string toLowerString(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c)
                   { return static_cast<char>(std::tolower(c)); });
    return s;
}

int readMenuChoice()
{
    int choice = -1;
    std::cout << "Enter choice: ";
    std::cin >> choice;

    if (std::cin.fail())
    {
        std::cin.clear();
        clearInputBuffer();
        return -1;
    }

    clearInputBuffer();
    return choice;
}

class TodoList
{
private:
    std::vector<std::string> tasks;

public:
    void initializeTodoList()
    {
        tasks.clear();
        tasks = {
            "SendingStatusUpdateMail",
            "PrepareForMeeting",
            "CompletingTrainings",
            "UrgerntCriticalBugFix",
            "KnowledgeTransferNotes"};
        std::cout << "\nTo-Do list initialized with default tasks.\n";
    }

    void displayInitialList() const
    {
        printTodoList(tasks);
    }

    void addNewTask()
    {
        std::cout << "\n--- Add New Task ---\n";
        std::cout << "Enter task name: ";

        std::string newTask;
        std::getline(std::cin >> std::ws, newTask);

        if (newTask.empty())
        {
            std::cout << "Task cannot be empty.\n";
            return;
        }

        tasks.push_back(newTask);
        std::cout << "Task added.\n";
        printTodoList(tasks);
    }

    void insertHighPriorityTask()
    {
        std::cout << "\n--- Insert High-Priority Task ---\n";
        std::cout << "Enter high-priority task: ";

        std::string highPriorityTask;
        std::getline(std::cin >> std::ws, highPriorityTask);

        if (highPriorityTask.empty())
        {
            std::cout << "Task cannot be empty.\n";
            return;
        }

        std::size_t position = 0;
        std::cout << "Enter position to insert (1 to " << (tasks.size() + 1) << "): ";
        std::cin >> position;

        if (std::cin.fail())
        {
            std::cin.clear();
            clearInputBuffer();
            std::cout << "Invalid index input.\n";
            return;
        }
        clearInputBuffer();

        if (position == 0 || position > (tasks.size() + 1))
        {
            std::cout << "Index out of valid range.\n";
            return;
        }

        auto it = tasks.begin() + static_cast<std::ptrdiff_t>(position - 1);
        tasks.insert(it, highPriorityTask);
        std::cout << "High-priority task inserted.\n";
        printTodoList(tasks);
    }

    void viewFirstAndLastTasks() const
    {
        std::cout << "\n--- View First and Last Tasks ---\n";

        if (tasks.empty())
        {
            std::cout << "The list is empty.\n";
            return;
        }

        std::cout << "First task: " << tasks.front() << "\n";
        std::cout << "Last task: " << tasks.back() << "\n";
    }

    void removeLastTask()
    {
        std::cout << "\n--- Remove Last Task ---\n";

        if (tasks.empty())
        {
            std::cout << "The list is empty. Nothing to remove.\n";
            return;
        }

        std::cout << "Removing: " << tasks.back() << "\n";
        tasks.pop_back();
        printTodoList(tasks);
    }

    void markTaskComplete()
    {
        std::cout << "\n--- Mark Task as Complete (Remove by Index) ---\n";

        if (tasks.empty())
        {
            std::cout << "The list is empty. Nothing to complete.\n";
            return;
        }

        printTodoList(tasks);
        std::size_t index = 0;
        std::cout << "Enter index of completed task (1 to " << tasks.size() << "): ";
        std::cin >> index;

        if (std::cin.fail())
        {
            std::cin.clear();
            clearInputBuffer();
            std::cout << "Invalid index input.\n";
            return;
        }
        clearInputBuffer();

        if (index == 0 || index > tasks.size())
        {
            std::cout << "Index out of range.\n";
            return;
        }

        const std::size_t actualIndex = index - 1;
        std::cout << "Completed: " << tasks[actualIndex] << "\n";
        tasks.erase(tasks.begin() + static_cast<std::ptrdiff_t>(actualIndex));
        printTodoList(tasks);
    }

    void sortTasksAlphabetically()
    {
        std::cout << "\n--- Sort Tasks Alphabetically ---\n";

        if (tasks.empty())
        {
            std::cout << "The list is empty.\n";
            return;
        }

        std::sort(tasks.begin(), tasks.end());
        printTodoList(tasks);
    }

    void reverseTaskOrder()
    {
        std::cout << "\n--- Reverse Task Order ---\n";

        if (tasks.empty())
        {
            std::cout << "The list is empty. No tasks to reverse.\n";
            return;
        }

        std::reverse(tasks.begin(), tasks.end());
        printTodoList(tasks);
    }

    void searchAndCountTasks() const
    {
        std::cout << "\n--- Search and Count Tasks ---\n";

        if (tasks.empty())
        {
            std::cout << "The list is empty.\n";
            return;
        }

        std::cout << "Enter task text to search: ";
        std::string query;
        std::getline(std::cin >> std::ws, query);

        if (query.empty())
        {
            std::cout << "Search query cannot be empty.\n";
            return;
        }

        const std::string normalizedQuery = toLowerString(query);
        std::vector<std::string> normalizedTasks = tasks;
        std::transform(normalizedTasks.begin(), normalizedTasks.end(), normalizedTasks.begin(),
                       [](std::string s)
                       { return toLowerString(std::move(s)); });

        auto firstIt = std::find(normalizedTasks.begin(), normalizedTasks.end(), normalizedQuery);
        if (firstIt == normalizedTasks.end())
        {
            std::cout << "Task not found.\n";
        }
        else
        {
            std::size_t index = static_cast<std::size_t>(std::distance(normalizedTasks.begin(), firstIt));
            std::cout << "First occurrence found at position: " << (index + 1) << "\n";
        }

        int occurrences = static_cast<int>(std::count(normalizedTasks.begin(), normalizedTasks.end(), normalizedQuery));
        std::cout << "Total occurrences: " << occurrences << "\n";
    }

    void transformToUppercase()
    {
        std::cout << "\n--- Transform Tasks to UPPERCASE ---\n";

        if (tasks.empty())
        {
            std::cout << "The list is empty.\n";
            return;
        }

        std::transform(tasks.begin(), tasks.end(), tasks.begin(),
                       [](std::string s)
                       { return toUpperString(std::move(s)); });
        printTodoList(tasks);
    }

    void checkKeywordContainingTasks() const
    {
        std::cout << "\n--- Check for URGENT/DEADLINE Tasks ---\n";

        if (tasks.empty())
        {
            std::cout << "The list is empty.\n";
            return;
        }

        std::cout << "Enter additional keyword to search: ";
        std::string userKeyword;
        std::getline(std::cin >> std::ws, userKeyword);
        const std::string lowerKeyword = toLowerString(userKeyword);

        const bool hasKeywordTask = std::any_of(tasks.begin(), tasks.end(),
                                                [&](const std::string &task)
                                                {
                                                    const std::string lowerTask = toLowerString(task);
                                                    const bool hasDefaultKeyword =
                                                        lowerTask.find("urgent") != std::string::npos ||
                                                        lowerTask.find("deadline") != std::string::npos;
                                                    const bool hasUserKeyword =
                                                        !lowerKeyword.empty() &&
                                                        lowerTask.find(lowerKeyword) != std::string::npos;
                                                    return hasDefaultKeyword || hasUserKeyword;
                                                });

        if (hasKeywordTask)
        {
            if (lowerKeyword.empty())
            {
                std::cout << "At least one task contains URGENT or DEADLINE.\n";
            }
            else
            {
                std::cout << "At least one task contains URGENT, DEADLINE, or '" << userKeyword << "'.\n";
            }
        }
        else
        {
            if (lowerKeyword.empty())
            {
                std::cout << "No task contains URGENT or DEADLINE.\n";
            }
            else
            {
                std::cout << "No task contains URGENT, DEADLINE, or '" << userKeyword << "'.\n";
            }
        }
    }

    void findLexicographicallyFirstLast() const
    {
        std::cout << "\n--- Lexicographically First and Last Tasks ---\n";

        if (tasks.empty())
        {
            std::cout << "The list is empty.\n";
            return;
        }

        auto minIt = std::min_element(tasks.begin(), tasks.end());
        auto maxIt = std::max_element(tasks.begin(), tasks.end());

        std::cout << "First (lexicographically): " << *minIt << "\n";
        std::cout << "Last  (lexicographically): " << *maxIt << "\n";
    }

    void finalCleanup()
    {
        std::cout << "\n--- Final Cleanup ---\n";

        if (tasks.empty())
        {
            std::cout << "List already empty.\n";
            return;
        }

        tasks.clear();
        std::cout << "All tasks cleared. Empty now? " << (tasks.empty() ? "Yes" : "No") << "\n";
    }
};

void printMenu()
{
    std::cout << "\n========== To-Do List Manager =========="
              << "\n1.  Initialize/Reset To-Do List"
              << "\n2.  Display Current To-Do List"
              << "\n3.  Add New Task"
              << "\n4.  Insert High-Priority Task"
              << "\n5.  View First and Last Tasks"
              << "\n6.  Remove Last Task"
              << "\n7.  Mark Task as Complete (Remove by Index)"
              << "\n8.  Sort Tasks Alphabetically"
              << "\n9.  Reverse Task Order"
              << "\n10. Search for a Task & Count Occurrences"
              << "\n11. Transform All Tasks to UPPERCASE"
              << "\n12. Check for Keyword-Containing Tasks"
              << "\n13. Find Lexicographically First and Last Tasks"
              << "\n14. Clear All Tasks (Final Cleanup)"
              << "\n16. Exit"
              << "\n========================================\n";
}

int main()
{
    TodoList myTodoList;
    myTodoList.initializeTodoList();
    myTodoList.displayInitialList();

    int choice = -1;
    do
    {
        printMenu();
        choice = readMenuChoice();

        switch (choice)
        {
        case 1:
            myTodoList.initializeTodoList();
            myTodoList.displayInitialList();
            break;
        case 2:
            myTodoList.displayInitialList();
            break;
        case 3:
            myTodoList.addNewTask();
            break;
        case 4:
            myTodoList.insertHighPriorityTask();
            break;
        case 5:
            myTodoList.viewFirstAndLastTasks();
            break;
        case 6:
            myTodoList.removeLastTask();
            break;
        case 7:
            myTodoList.markTaskComplete();
            break;
        case 8:
            myTodoList.sortTasksAlphabetically();
            break;
        case 9:
            myTodoList.reverseTaskOrder();
            break;
        case 10:
            myTodoList.searchAndCountTasks();
            break;
        case 11:
            myTodoList.transformToUppercase();
            break;
        case 12:
            myTodoList.checkKeywordContainingTasks();
            break;
        case 13:
            myTodoList.findLexicographicallyFirstLast();
            break;
        case 14:
            myTodoList.finalCleanup();
            break;
        case 16:
            std::cout << "Exiting To-Do List Manager.\n";
            break;
        default:
            std::cout << "Invalid choice. Please enter a valid menu option.\n";
            break;
        }
    } while (choice != 16);

    return 0;
}
