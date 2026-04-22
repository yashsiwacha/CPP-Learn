#include <iostream>
#include <set>
#include <string>
#include <vector>

bool scheduleEvent(std::set<int> &scheduledEvents, int startTime)
{
    auto insertResult = scheduledEvents.insert(startTime);

    if (insertResult.second)
    {
        std::cout << "Scheduled event at " << startTime << " minutes.\n";
        return true;
    }

    std::cout << "Conflict: time slot " << startTime << " minutes is already taken.\n";
    return false;
}

void displayScheduledEvents(const std::set<int> &events)
{
    std::cout << "--------------------------------\n";
    std::cout << "Scheduled Events\n";
    std::cout << "--------------------------------\n";

    if (events.empty())
    {
        std::cout << "No events scheduled.\n";
        std::cout << "--------------------------------\n";
        return;
    }

    for (int time : events)
    {
        std::cout << " - " << time << " minutes\n";
    }

    std::cout << "--------------------------------\n";
}

int main()
{
    std::set<int> myCalendar;

    std::cout << "Attempting to schedule events for the first time:\n";
    scheduleEvent(myCalendar, 900);
    scheduleEvent(myCalendar, 1030);
    scheduleEvent(myCalendar, 1300);
    scheduleEvent(myCalendar, 1400);
    displayScheduledEvents(myCalendar);

    std::cout << "\nAttempting to schedule a conflicting event:\n";
    scheduleEvent(myCalendar, 1030);
    displayScheduledEvents(myCalendar);

    std::cout << "\nAttempting to schedule another unique event:\n";
    scheduleEvent(myCalendar, 1200);
    displayScheduledEvents(myCalendar);

    std::cout << "\nAttempting to schedule a batch of events (some new, some duplicates):\n";
    std::vector<int> newEventTimes = {800, 1400, 1600, 900, 1800};
    for (int time : newEventTimes)
    {
        scheduleEvent(myCalendar, time);
    }
    displayScheduledEvents(myCalendar);

    return 0;
}
