// Student Performance Evaluation System
#include <iostream>
#include <limits>
using namespace std;

void enterMarks(int marks[], int numSubjects)
{
    int a = 0;
    while (a < numSubjects)
    {
        cout << "Enter marks for Subject " << a + 1 << " : ";
        cin >> marks[a];

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a numeric value." << endl;
            continue;
        }

        if (marks[a] <= 100 && marks[a] >= 0)
        {
            a++;
        }
        else
        {
            cout << "Invalid marks! Please enter a value between 0 and 100." << endl;
        }
    }
}

float calculateAverage(int marks[], int numSubjects)
{
    float sum = 0;
    for (int i = 0; i < numSubjects; i++)
    {
        sum += marks[i];
    }
    return sum / numSubjects;
}

// Grading Scale: A: 90-100, B: 80-89, C: 70-79, F: Below 70
char determineGrade(float average)
{
    if (average >= 90)
        return 'A';
    else if (average >= 80)
        return 'B';
    else if (average >= 70)
        return 'C';
    else
        return 'F';
}

void displayResult(int marks[], int numSubjects, char grade, float average)
{
    cout << "\n========================================" << endl;
    cout << "    STUDENT PERFORMANCE REPORT" << endl;
    cout << "========================================" << endl;

    cout << "\nTotal Subjects: " << numSubjects << endl;
    cout << "\nSubject-wise Marks:" << endl;
    for (int i = 0; i < numSubjects; i++)
    {
        cout << "  Subject " << i + 1 << ": " << marks[i] << "/100" << endl;
    }

    cout << "\n----------------------------------------" << endl;
    cout << "Average Marks: " << average << "/100" << endl;
    cout << "Grade Assigned: " << grade << endl;
    cout << "========================================" << endl;
}

int main()
{
    int numSubjects;
    int *marks;

    cout << "========================================" << endl;
    cout << "  Student Performance Evaluation System" << endl;
    cout << "========================================" << endl;

    cout << "\nEnter the number of subjects: ";
    cin >> numSubjects;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a numeric value." << endl;
        return 1;
    }

    if (numSubjects <= 0)
    {
        cout << "Invalid number of subjects! Must be greater than 0." << endl;
        return 1;
    }

    marks = new int[numSubjects];

    enterMarks(marks, numSubjects);

    float average = calculateAverage(marks, numSubjects);

    char grade = determineGrade(average);

    displayResult(marks, numSubjects, grade, average);

    delete[] marks;

    return 0;
}