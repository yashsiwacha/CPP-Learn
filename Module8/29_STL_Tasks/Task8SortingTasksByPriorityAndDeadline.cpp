#include <iostream>
#include <list>
#include <string>

struct Task
{
    std::string name;
    int priority;
    int deadline;

    void print() const
    {
        std::cout << "Task: " << name
                  << ", Priority: " << priority
                  << ", Deadline: " << deadline << "\n";
    }
};

bool taskCompare(const Task &a, const Task &b)
{
    // Primary key: higher numeric priority comes first.
    if (a.priority != b.priority)
    {
        return a.priority > b.priority;
    }

    // Secondary key: for equal priority, earlier deadline comes first.
    return a.deadline < b.deadline;
}

void printTaskList(const std::list<Task> &tasks, const std::string &heading)
{
    std::cout << "\n"
              << heading << "\n";
    for (const Task &task : tasks)
    {
        task.print();
    }
}

int main()
{
    std::list<Task> tasks = {
        {"Sending the Mail", 2, 5},
        {"Fix Critical bug", 1, 1},
        {"Team meeting", 2, 1},
        {"Code review", 2, 3},
        {"Update docs", 3, 4},
        {"Prepare demo", 3, 2}};

    printTaskList(tasks, "Tasks before sorting:");

    // Sort using the custom predicate:
    // 1) Priority descending, 2) Deadline ascending.
    tasks.sort(taskCompare);

    printTaskList(tasks, "Tasks after sorting:");

    return 0;
}
