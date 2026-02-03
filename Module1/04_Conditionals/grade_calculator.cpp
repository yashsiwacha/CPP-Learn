// Program to calculate average grade from multiple assignments
#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char continueProcessing;

    do
    {
        int studentID, numAssignments;
        float totalGrades = 0;
        int validCount = 0;

        cout << "Enter Student ID (101-999): ";
        cin >> studentID;

        while (studentID < 101 || studentID > 999)
        {
            cout << "Invalid ID. Enter again: ";
            cin >> studentID;
        }

        cout << "Number of assignments: ";
        cin >> numAssignments;

        for (int i = 1; i <= numAssignments; i++)
        {
            float grade;
            cout << "Grade for Assignment #" << i << " (0-100): ";
            cin >> grade;

            if (grade < 0 || grade > 100)
            {
                cout << "Invalid grade. Skipping.\n";
                continue;
            }

            totalGrades += grade;
            validCount++;
        }

        if (validCount == 0)
        {
            cout << "No valid grades for Student " << studentID << "\n";
        }
        else
        {
            float average = totalGrades / validCount;
            cout << "Student " << studentID << " - Average: " << average << "%\n";

            if (average >= 90)
                cout << "Excellent!\n";
            else if (average >= 70)
                cout << "Good job!\n";
            else if (average >= 50)
                cout << "Needs improvement\n";
            else
                cout << "At risk\n";
        }

        cout << "\nProcess another? (Y/N): ";
        cin >> continueProcessing;
        continueProcessing = toupper(continueProcessing);

    } while (continueProcessing != 'N');

    return 0;
}