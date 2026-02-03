// Program to delete employee records
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Employee
{
    int empId;
    char name[100];
    float basicSalary;
};

void createEmployeeRecords()
{
    FILE *file = fopen("employee.dat", "wb");
    if (file == NULL)
    {
        cout << "Error: Could not create employee.dat file!" << endl;
        return;
    }

    int numEmployees;
    cout << "\nEnter number of employees to add: ";
    cin >> numEmployees;

    for (int i = 0; i < numEmployees; i++)
    {
        Employee emp;
        cout << "\n--- Employee " << (i + 1) << " ---" << endl;
        cout << "Enter Employee ID: ";
        cin >> emp.empId;
        cin.ignore();
        cout << "Enter Name: ";
        cin.getline(emp.name, 100);
        cout << "Enter Basic Salary: ";
        cin >> emp.basicSalary;

        if (emp.basicSalary <= 0)
        {
            cout << "Error: Salary must be positive. Skipping this employee." << endl;
            continue;
        }

        fwrite(&emp, sizeof(Employee), 1, file);
        cout << "Employee record added successfully!" << endl;
    }

    fclose(file);
    cout << "\nEmployee records file created successfully!" << endl;
}

void displayAllEmployees()
{
    FILE *file = fopen("employee.dat", "rb");
    if (file == NULL)
    {
        cout << "Error: Could not open 'employee.dat' file!" << endl;
        cout << "Please create employee records first." << endl;
        return;
    }

    Employee emp;
    int count = 0;

    cout << "\nEmployee Records\n";
    cout << "Emp ID  | Name                          | Basic Salary\n";

    while (fread(&emp, sizeof(Employee), 1, file) == 1)
    {
        printf("%-7d | %-29s | Rs. %.2f\n", emp.empId, emp.name, emp.basicSalary);
        count++;
    }

    fclose(file);

    if (count == 0)
        cout << "No employee records found\n";
    else
        cout << "Total employees: " << count << "\n";
}

void deleteEmployeeRecord()
{
    FILE *originalFile = fopen("employee.dat", "rb");
    if (originalFile == NULL)
    {
        cout << "Error: Could not open file\n";
        return;
    }

    int deleteEmpId;
    cout << "\nEmployee ID to delete: ";

    if (!(cin >> deleteEmpId) || deleteEmpId <= 0)
    {
        cout << "Error: Invalid Employee ID\n";
        cin.clear();
        cin.ignore(10000, '\n');
        fclose(originalFile);
        return;
    }

    FILE *tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL)
    {
        cout << "Error: Could not create temp file\n";
        fclose(originalFile);
        return;
    }

    Employee emp;
    bool found = false;
    int totalRecords = 0;
    int recordsCopied = 0;

    // Step 3: Read each record from original file
    while (fread(&emp, sizeof(Employee), 1, originalFile) == 1)
    {
        totalRecords++;

        // Step 4: Conditional Writing
        // If the empId matches the one to delete, skip writing to temp file
        if (emp.empId == deleteEmpId)
        {
            found = true;
            cout << "\n--- Record Found and Marked for Deletion ---" << endl;
            cout << "Employee ID  : " << emp.empId << endl;
            cout << "Name         : " << emp.name << endl;
            cout << "Basic Salary : Rs. " << emp.basicSalary << endl;
            // Skip writing this record (effectively deleting it)
            continue;
        }

        // Write all other records to the temporary file
        if (fwrite(&emp, sizeof(Employee), 1, tempFile) != 1)
        {
            cout << "Error: Failed to write record to temporary file!" << endl;
            fclose(originalFile);
            fclose(tempFile);
            remove("temp.dat"); // Clean up temp file
            return;
        }
        recordsCopied++;
    }

    // Close both files before rename operation
    fclose(originalFile);
    fclose(tempFile);

    // Step 5: Replace the original file with temporary file
    if (found)
    {
        // Delete the original file
        if (remove("employee.dat") != 0)
        {
            cout << "Error: Could not delete original file!" << endl;
            cout << "The record may not have been deleted." << endl;
            remove("temp.dat"); // Clean up temp file
            return;
        }

        // Rename temp file to original file name
        if (rename("temp.dat", "employee.dat") != 0)
        {
            cout << "Error: Could not rename temporary file!" << endl;
            cout << "Original file has been deleted. Please check 'temp.dat' for your data." << endl;
            return;
        }

        // Step 6: Provide user feedback
        cout << "\n✓ Employee record deleted successfully!" << endl;
        cout << "Total records processed: " << totalRecords << endl;
        cout << "Records remaining: " << recordsCopied << endl;
    }
    else
    {
        // Employee ID not found - remove temp file and keep original
        remove("temp.dat");
        cout << "\nRecord not found!" << endl;
        cout << "No employee with ID " << deleteEmpId << " exists in the file." << endl;
        cout << "Total records searched: " << totalRecords << endl;
    }
}

int main()
{
    int choice;

    cout << "===============================================================" << endl;
    cout << "           EMPLOYEE RECORD DELETION SYSTEM" << endl;
    cout << "===============================================================" << endl;

    while (true)
    {
        cout << "\nMenu:" << endl;
        cout << "1. Create Employee Records File" << endl;
        cout << "2. Display All Employee Records" << endl;
        cout << "3. Delete Employee Record" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createEmployeeRecords();
            break;
        case 2:
            displayAllEmployees();
            break;
        case 3:
            deleteEmployeeRecord();
            break;
        case 4:
            cout << "\nThank you for using the Employee Record Deletion System!" << endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}