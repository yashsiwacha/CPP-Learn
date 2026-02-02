// Program to modify marks of students in an existing record.
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Student
{
    int rollNo;
    char name[50];
    float marks;
};

void createStudentRecords()
{
    FILE *file = fopen("students.dat", "wb");
    if (file == NULL)
    {
        cout << "Error: Could not create students.dat file!" << endl;
        return;
    }

    int numStudents;
    cout << "\nEnter number of students to add: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; i++)
    {
        Student student;
        cout << "\n--- Student " << (i + 1) << " ---" << endl;
        cout << "Enter Roll Number: ";
        cin >> student.rollNo;
        cin.ignore();
        cout << "Enter Name: ";
        cin.getline(student.name, 50);
        cout << "Enter Marks (0-100): ";
        cin >> student.marks;

        if (student.marks < 0 || student.marks > 100)
        {
            cout << "Error: Marks must be between 0 and 100. Skipping this student." << endl;
            continue;
        }

        fwrite(&student, sizeof(Student), 1, file);
        cout << "Student record added successfully!" << endl;
    }

    fclose(file);
    cout << "\nStudent records file created successfully!" << endl;
}

void displayAllRecords()
{
    FILE *file = fopen("students.dat", "rb");
    if (file == NULL)
    {
        cout << "Error: Could not open 'students.dat' file!" << endl;
        cout << "Please create student records first." << endl;
        return;
    }

    Student student;
    int count = 0;

    cout << "\n==========================================================" << endl;
    cout << "                   STUDENT RECORDS" << endl;
    cout << "==========================================================" << endl;
    cout << "Roll No  | Name                      | Marks" << endl;
    cout << "---------+---------------------------+-------" << endl;

    while (fread(&student, sizeof(Student), 1, file) == 1)
    {
        printf("%-8d | %-25s | %.2f\n", student.rollNo, student.name, student.marks);
        count++;
    }

    fclose(file);

    if (count == 0)
    {
        cout << "No student records found." << endl;
    }
    else
    {
        cout << "==========================================================" << endl;
        cout << "Total students: " << count << endl;
    }
}

void searchAndUpdateMarks()
{
    FILE *file = fopen("students.dat", "r+b");
    if (file == NULL)
    {
        cout << "Error: Could not open 'students.dat' file!" << endl;
        cout << "The file may not exist. Please create student records first." << endl;
        return;
    }

    int searchRollNo;
    cout << "\nEnter Roll Number to search: ";

    if (!(cin >> searchRollNo) || searchRollNo <= 0)
    {
        cout << "Error: Invalid Roll Number! Please enter a positive integer." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        fclose(file);
        return;
    }

    Student student;
    int recordIndex = 0;
    bool found = false;
    long position = 0;

    // Search for the student record
    while (fread(&student, sizeof(Student), 1, file) == 1)
    {
        if (student.rollNo == searchRollNo)
        {
            found = true;
            position = recordIndex * sizeof(Student);
            break;
        }
        recordIndex++;
    }

    if (!found)
    {
        cout << "\nRecord not found!" << endl;
        cout << "No student with Roll Number " << searchRollNo << " exists in the file." << endl;
        fclose(file);
        return;
    }

    // Display current record
    cout << "\n--- Record Found ---" << endl;
    cout << "Roll Number : " << student.rollNo << endl;
    cout << "Name        : " << student.name << endl;
    cout << "Current Marks: " << student.marks << endl;

    // Get new marks
    float newMarks;
    cout << "\nEnter new marks (0-100): ";

    if (!(cin >> newMarks))
    {
        cout << "Error: Invalid marks input!" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        fclose(file);
        return;
    }

    // Validate new marks
    if (newMarks < 0 || newMarks > 100)
    {
        cout << "Error: Marks must be between 0 and 100!" << endl;
        fclose(file);
        return;
    }

    // Compute position and seek to the record
    if (fseek(file, position, SEEK_SET) != 0)
    {
        cout << "Error: Could not navigate to the record position!" << endl;
        fclose(file);
        return;
    }

    // Verify position
    long currentPos = ftell(file);
    if (currentPos != position)
    {
        cout << "Error: File pointer position mismatch!" << endl;
        fclose(file);
        return;
    }

    // Update the marks in memory
    student.marks = newMarks;

    // Write the updated record back to the file
    if (fwrite(&student, sizeof(Student), 1, file) != 1)
    {
        cout << "Error: Could not write updated record to file!" << endl;
        fclose(file);
        return;
    }

    // Verify the write operation by reading it back
    fseek(file, position, SEEK_SET);
    Student verifyStudent;
    fread(&verifyStudent, sizeof(Student), 1, file);

    if (verifyStudent.marks != newMarks)
    {
        cout << "Warning: Verification failed! The marks may not have been updated correctly." << endl;
    }
    else
    {
        cout << "\n✓ Marks updated successfully!" << endl;
        cout << "Roll Number : " << verifyStudent.rollNo << endl;
        cout << "Name        : " << verifyStudent.name << endl;
        cout << "Updated Marks: " << verifyStudent.marks << endl;
    }

    fclose(file);
}

int main()
{
    int choice;

    cout << "==========================================================" << endl;
    cout << "         STUDENT MARKS MANAGEMENT SYSTEM" << endl;
    cout << "==========================================================" << endl;

    while (true)
    {
        cout << "\nMenu:" << endl;
        cout << "1. Create Student Records File" << endl;
        cout << "2. Display All Student Records" << endl;
        cout << "3. Search and Update Student Marks" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createStudentRecords();
            break;
        case 2:
            displayAllRecords();
            break;
        case 3:
            searchAndUpdateMarks();
            break;
        case 4:
            cout << "\nThank you for using the Student Marks Management System!" << endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
