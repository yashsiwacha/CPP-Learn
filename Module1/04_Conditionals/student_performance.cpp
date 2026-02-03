// Student performance evaluation system
#include <iostream>
#include <limits>
using namespace std;

void enterMarks(int marks[], int numSubjects)
{
    int a = 0;
    while (a < numSubjects)
    {
        cout << "Marks for Subject " << a + 1 << ": ";
        cin >> marks[a];

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!\n";
            continue;
        }

        if (marks[a] >= 0 && marks[a] <= 100)
            a++;
        else
            cout << "Marks must be 0-100\n";
    }
}

float calculateAverage(int marks[], int numSubjects)
{
    float sum = 0;
    for (int i = 0; i < numSubjects; i++)
        sum += marks[i];
    return sum / numSubjects;
}

char determineGrade(float average)
{
    if (average >= 90)
        return 'A';
    if (average >= 80)
        return 'B';
    if (average >= 70)
        return 'C';
    return 'F';
}

int main()
{
    int numSubjects;

    cout << "Enter number of subjects: ";
    cin >> numSubjects;

    if (cin.fail() || numSubjects <= 0)
    {
        cout << "Invalid input!\n";
        return 1;
    }

    int *marks = new int[numSubjects];

    enterMarks(marks, numSubjects);
    float average = calculateAverage(marks, numSubjects);
    char grade = determineGrade(average);

    cout << "\nSubject-wise marks:\n";
    for (int i = 0; i < numSubjects; i++)
        cout << "  Subject " << i + 1 << ": " << marks[i] << "/100\n";

    cout << "\nAverage: " << average << "/100\n";
    cout << "Grade: " << grade << "\n";

    delete[] marks;
    return 0;
}