#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;

// Function to validate timestamp format (YYYY-MM-DD HH:MM)
bool validateTimestamp(const char *timeStamp)
{
    int year, month, day, hour, minute;
    char dash1, dash2, colon, space;

    // Parse the timestamp
    int result = sscanf(timeStamp, "%d%c%d%c%d%c%d%c%d",
                        &year, &dash1, &month, &dash2, &day, &space, &hour, &colon, &minute);

    // Check if parsing was successful and format is correct
    if (result != 9 || dash1 != '-' || dash2 != '-' || space != ' ' || colon != ':')
    {
        return false;
    }

    // Validate ranges
    if (year < 2000 || year > 2100 || month < 1 || month > 12 ||
        day < 1 || day > 31 || hour < 0 || hour > 23 || minute < 0 || minute > 59)
    {
        return false;
    }

    return true;
}

// Function to check if attendance already logged for this employee today
bool isDuplicateEntry(int empID, const char *timeStamp)
{
    FILE *f1 = fopen("Attendance.txt", "r");
    if (f1 == NULL)
    {
        return false; // File doesn't exist yet, no duplicates
    }

    char line[256];
    char date[15];
    sscanf(timeStamp, "%10s", date); // Extract date portion (YYYY-MM-DD)

    while (fgets(line, sizeof(line), f1) != NULL)
    {
        int existingEmpID;
        char existingTimestamp[50];

        if (sscanf(line, "%d , %49[^\n]", &existingEmpID, existingTimestamp) == 2)
        {
            char existingDate[15];
            sscanf(existingTimestamp, "%10s", existingDate);

            // Check if same employee and same date
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

// Function to log attendance
void appendAttendance(int empID, const char *timeStamp)
{
    // Validate timestamp format
    if (!validateTimestamp(timeStamp))
    {
        cout << "Error: Invalid timestamp format!" << endl;
        cout << "Please use format: YYYY-MM-DD HH:MM (e.g., 2026-01-21 09:30)" << endl;
        return;
    }

    // Check for duplicate entry
    if (isDuplicateEntry(empID, timeStamp))
    {
        cout << "Warning: Employee " << empID << " has already logged attendance today!" << endl;
        cout << "Do you want to log again anyway? (y/n): ";
        char confirm;
        cin >> confirm;
        if (confirm != 'y' && confirm != 'Y')
        {
            cout << "Attendance not logged." << endl;
            return;
        }
    }

    FILE *f1 = fopen("Attendance.txt", "a");
    if (f1 == NULL)
    {
        cout << "Error: Could not open 'Attendance.txt' file for writing!" << endl;
        cout << "Please ensure you have write permissions in this directory." << endl;
        return;
    }

    fprintf(f1, "%-8d , %s\n", empID, timeStamp);
    fclose(f1);
    cout << "\n✓ Attendance logged successfully for Employee ID: " << empID << endl;
}

// Function to read and display attendance log
void readFile()
{
    FILE *f1 = fopen("Attendance.txt", "r");
    if (f1 == NULL)
    {
        cout << "Error: Could not open 'Attendance.txt' file for reading!" << endl;
        cout << "No attendance records found. Please log some attendance first." << endl;
        return;
    }

    cout << "\n=================================================" << endl;
    cout << "              ATTENDANCE LOG" << endl;
    cout << "=================================================" << endl;
    cout << "Emp ID   | Date       | Time" << endl;
    cout << "---------+------------+-------" << endl;

    char line[256];
    int count = 0;

    while (fgets(line, sizeof(line), f1) != NULL)
    {
        int empID;
        char timestamp[50];

        if (sscanf(line, "%d , %49[^\n]", &empID, timestamp) == 2)
        {
            // Parse date and time
            char date[15], time[10];
            sscanf(timestamp, "%10s %5s", date, time);

            printf("%-8d | %-10s | %s\n", empID, date, time);
            count++;
        }
        else
        {
            // If parsing fails, just print the line as is
            cout << line;
            count++;
        }
    }

    fclose(f1);

    if (count == 0)
    {
        cout << "No records found." << endl;
    }
    else
    {
        cout << "=================================================" << endl;
        cout << "Total records: " << count << endl;
    }
}

int main()
{
    int choice;

    cout << "========================================" << endl;
    cout << "   EMPLOYEE ATTENDANCE SYSTEM" << endl;
    cout << "========================================" << endl;

    while (true)
    {
        cout << "\nMenu:" << endl;
        cout << "1. Log Attendance" << endl;
        cout << "2. View Attendance Log" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int empID;
            char timeStamp[50];

            cout << "\n--- Log Attendance ---" << endl;
            cout << "Enter Employee ID (positive number): ";

            if (!(cin >> empID) || empID <= 0)
            {
                cout << "Error: Invalid Employee ID! Please enter a positive number." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                break;
            }

            cin.ignore(); // Clear the newline from buffer
            cout << "Enter Timestamp (Format: YYYY-MM-DD HH:MM): ";
            cin.getline(timeStamp, 50);

            // Trim leading/trailing whitespace
            int len = strlen(timeStamp);
            if (len == 0)
            {
                cout << "Error: Timestamp cannot be empty!" << endl;
                break;
            }

            appendAttendance(empID, timeStamp);
            break;
        }
        case 2:
            readFile();
            break;
        case 3:
            cout << "\nThank you for using the Attendance System!" << endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}