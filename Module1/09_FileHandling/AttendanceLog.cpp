// Attendance Logging System
#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;

bool validateTimestamp(const char *timeStamp)
{
    int year, month, day, hour, minute;
    char dash1, dash2, colon, space;

    int result = sscanf(timeStamp, "%d%c%d%c%d%c%d%c%d",
                        &year, &dash1, &month, &dash2, &day, &space, &hour, &colon, &minute);

    if (result != 9 || dash1 != '-' || dash2 != '-' || space != ' ' || colon != ':')
    {
        return false;
    }

    if (year < 2000 || year > 2100 || month < 1 || month > 12 ||
        day < 1 || day > 31 || hour < 0 || hour > 23 || minute < 0 || minute > 59)
    {
        return false;
    }

    return true;
}

bool isDuplicateEntry(int empID, const char *timeStamp)
{
    FILE *f1 = fopen("Attendance.txt", "r");
    if (f1 == NULL)
    {
        return false;
    }

    char line[256];
    char date[15];
    sscanf(timeStamp, "%10s", date);

    while (fgets(line, sizeof(line), f1) != NULL)
    {
        int existingEmpID;
        char existingTimestamp[50];

        if (sscanf(line, "%d , %49[^\n]", &existingEmpID, existingTimestamp) == 2)
        {
            char existingDate[15];
            sscanf(existingTimestamp, "%10s", existingDate);

            if (existingEmpID == empID && strcmp(date, existingDate) == 0)
            {
                fclose(f1);
                return true;
            }
        }
    }

    fclose(f1);
    return false;
}

void appendAttendance(int empID, const char *timeStamp)
{
    if (!validateTimestamp(timeStamp))
    {
        cout << "Error: Invalid timestamp format (use YYYY-MM-DD HH:MM)\n";
        return;
    }

    if (isDuplicateEntry(empID, timeStamp))
    {
        cout << "Warning: Employee " << empID << " already logged today. Continue? (y/n): ";
        char confirm;
        cin >> confirm;
        if (confirm != 'y' && confirm != 'Y')
        {
            cout << "Attendance not logged\n";
            return;
        }
    }

    FILE *f1 = fopen("Attendance.txt", "a");
    if (f1 == NULL)
    {
        cout << "Error: Could not open file\n";
        return;
    }

    fprintf(f1, "%-8d , %s\n", empID, timeStamp);
    fclose(f1);
    cout << "Attendance logged for Employee " << empID << "\n";
}

void readFile()
{
    FILE *f1 = fopen("Attendance.txt", "r");
    if (f1 == NULL)
    {
        cout << "Error: No attendance records found\n";
        return;
    }

    cout << "\nAttendance Log\n";
    cout << "Emp ID   | Date       | Time\n";

    char line[256];
    int count = 0;

    while (fgets(line, sizeof(line), f1) != NULL)
    {
        int empID;
        char timestamp[50];

        if (sscanf(line, "%d , %49[^\n]", &empID, timestamp) == 2)
        {
            char date[15], time[10];
            sscanf(timestamp, "%10s %5s", date, time);
            printf("%-8d | %-10s | %s\n", empID, date, time);
            count++;
        }
    }

    fclose(f1);
    cout << "Total records: " << count << "\n";
}

int main()
{
    int choice;

    cout << "Employee Attendance System\n";

    while (true)
    {
        cout << "\n1. Log Attendance\n2. View Attendance\n3. Exit\nChoice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int empID;
            char timeStamp[50];

            cout << "\nEmployee ID: ";
            if (!(cin >> empID) || empID <= 0)
            {
                cout << "Error: Invalid ID\n";
                cin.clear();
                cin.ignore(10000, '\n');
                break;
            }

            cin.ignore();
            cout << "Timestamp (YYYY-MM-DD HH:MM): ";
            cin.getline(timeStamp, 50);

            if (strlen(timeStamp) == 0)
            {
                cout << "Error: Timestamp cannot be empty\n";
                break;
            }

            appendAttendance(empID, timeStamp);
            break;
        }
        case 2:
            readFile();
            break;
        case 3:
            return 0;
        default:
            cout << "Invalid choice\n";
        }
    }

    return 0;
}