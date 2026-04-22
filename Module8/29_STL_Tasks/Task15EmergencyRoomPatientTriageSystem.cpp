#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Patient
{
    std::string name;
    int severity;
    int arrivalTime;

    Patient(std::string patientName, int patientSeverity, int patientArrivalTime)
        : name(std::move(patientName)), severity(patientSeverity), arrivalTime(patientArrivalTime)
    {
    }
};

struct ComparePatients
{
    // Return true when p1 has LOWER priority than p2.
    bool operator()(const Patient &p1, const Patient &p2) const
    {
        // Lower severity number means higher urgency.
        if (p1.severity != p2.severity)
        {
            return p1.severity > p2.severity;
        }

        // If severity ties, earlier arrival gets higher priority.
        if (p1.arrivalTime != p2.arrivalTime)
        {
            return p1.arrivalTime > p2.arrivalTime;
        }

        // If both are identical for triage purposes, neither is lower priority.
        return false;
    }
};

int main()
{
    std::priority_queue<Patient, std::vector<Patient>, ComparePatients> erQueue;

    erQueue.push(Patient("Alice Smith", 3, 10));
    erQueue.push(Patient("Bob Jones", 1, 5));
    erQueue.push(Patient("Charlie Brown", 3, 8));
    erQueue.push(Patient("David Lee", 2, 12));
    erQueue.push(Patient("Eve White", 1, 7));
    erQueue.push(Patient("Frank Green", 5, 2));
    erQueue.push(Patient("Grace Hall", 2, 4));

    std::cout << "--- Emergency Room Patient Triage System ---\n";
    std::cout << "Patients are processed by severity first, then by arrival time.\n\n";

    while (!erQueue.empty())
    {
        const Patient &current = erQueue.top();
        std::cout << "Processing patient " << current.name
                  << ": Severity " << current.severity
                  << ", Arrived at " << current.arrivalTime << "\n";
        erQueue.pop();
    }

    return 0;
}
