// Student Grade Analyzer - calculates average grade from multiple assignments
#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char continueProcessing;

    do
    {
        int studentID;
        int numAssignments;
        float totalGrades = 0;         // Sum of all valid grades
        int validAssignmentsCount = 0; // Count of valid entries

        // Get and validate student ID (must be 101-999)
        cout << "Enter Student ID (e.g., 101-999): ";
        cin >> studentID;

        while (studentID < 101 || studentID > 999)
        {
            cout << "Invalid Student ID. Must be between 101 and 999. Please re-enter." << endl;
            cout << "Enter Student ID (e.g., 101-999): ";
            cin >> studentID;
        }

        // Get number of assignments
        cout << "How many assignments does Student " << studentID << " have? ";
        cin >> numAssignments;

        // Loop through each assignment to get grade
        for (int i = 1; i <= numAssignments; i++)
        {
            float grade;

            cout << "Enter grade for Assignment #" << i << " (0-100): ";
            cin >> grade;

            // Validate grade is within valid range
            if (grade < 0 || grade > 100)
            {
                cout << "Invalid grade. Must be between 0 and 100. Skipping this assignment." << endl;
                continue; // Skip this iteration and move to next assignment
            }

            // Add valid grade to total
            totalGrades += grade;
            validAssignmentsCount++;
        }

        // Check if any valid grades were entered
        if (validAssignmentsCount == 0)
        {
            cout << "No valid grades entered for Student " << studentID << "." << endl;
        }
        else
        {
            float averageGrade = totalGrades / validAssignmentsCount;
            cout << "Student " << studentID << " - Average Grade: " << averageGrade << "%" << endl;

            if (averageGrade >= 90)
            {
                cout << "Excellent!" << endl;
            }
            else if (averageGrade >= 70)
            {
                cout << "Good job!" << endl;
            }
            else if (averageGrade >= 50)
            {
                cout << "Needs improvement." << endl;
            }
            else
            {
                cout << "At risk." << endl;
            }
        }

        cout << "\nProcess another student? (Y/N): ";
        cin >> continueProcessing;

        continueProcessing = toupper(continueProcessing);

        if (continueProcessing == 'N')
        {
            break;
        }

        cout << endl;

    } while (true);

    cout << "Exiting Grade Analyzer. Goodbye!" << endl;

    return 0;
}