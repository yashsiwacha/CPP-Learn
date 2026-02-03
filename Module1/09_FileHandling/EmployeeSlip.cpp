// Employee Salary Slip Generator
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

void createEmployeeData()
{
    FILE *file = fopen("employee.dat", "wb");
    if (file == NULL)
    {
        cout << "Error: Could not create employee.dat file!" << endl;
        return;
    }

    int numEmployees;
    cout << "Enter number of employees to add: ";
    cin >> numEmployees;

    for (int i = 0; i < numEmployees; i++)
    {
        Employee emp;
        cout << "\nEmployee " << (i + 1) << ":" << endl;
        cout << "Enter Employee ID: ";
        cin >> emp.empId;
        cin.ignore();
        cout << "Enter Employee Name: ";
        cin.getline(emp.name, 100);
        cout << "Enter Basic Salary: ";
        cin >> emp.basicSalary;

        if (emp.basicSalary <= 0)
        {
            cout << "Error: Basic salary must be positive. Skipping this employee." << endl;
            continue;
        }

        fwrite(&emp, sizeof(Employee), 1, file);
        cout << "Employee record added successfully!" << endl;
    }

    fclose(file);
    cout << "\nEmployee data file created successfully!" << endl;
}

void processEmployeeRecords()
{
    FILE *file = fopen("employee.dat", "rb");
    if (file == NULL)
    {
        cout << "Error: Could not open employee.dat file!" << endl;
        cout << "Please create the file first using option 1." << endl;
        return;
    }

    Employee emp;
    int count = 0;

    cout << "\nProcessing employee records..." << endl;
    cout << "======================================" << endl;

    while (fread(&emp, sizeof(Employee), 1, file) == 1)
    {
        float DA = emp.basicSalary * 0.2f;
        float HRA = emp.basicSalary * 0.1f;
        float netSalary = emp.basicSalary + DA + HRA;

        char fileName[50];
        sprintf(fileName, "emp%d_slip.txt", emp.empId);

        FILE *slipFile = fopen(fileName, "w");
        if (slipFile == NULL)
        {
            cout << "Error: Could not create salary slip for Employee ID " << emp.empId << endl;
            continue;
        }

        fprintf(slipFile, "=========================================\n");
        fprintf(slipFile, "       EMPLOYEE SALARY SLIP\n");
        fprintf(slipFile, "=========================================\n\n");
        fprintf(slipFile, "Employee ID   : %d\n", emp.empId);
        fprintf(slipFile, "Employee Name : %s\n", emp.name);
        fprintf(slipFile, "-----------------------------------------\n");
        fprintf(slipFile, "Basic Salary            : Rs. %.2f\n", emp.basicSalary);
        fprintf(slipFile, "Dearness Allowance (DA) : Rs. %.2f\n", DA);
        fprintf(slipFile, "House Rent Allowance (HRA): Rs. %.2f\n", HRA);
        fprintf(slipFile, "-----------------------------------------\n");
        fprintf(slipFile, "Net Salary              : Rs. %.2f\n", netSalary);
        fprintf(slipFile, "=========================================\n");

        fclose(slipFile);

        cout << "Salary slip generated for " << emp.name
             << " (ID: " << emp.empId << ") -> " << fileName << endl;
        count++;
    }

    fclose(file);

    cout << "======================================" << endl;
    cout << "Total salary slips generated: " << count << endl;

    if (count == 0)
    {
        cout << "No employee records found in the file." << endl;
    }
}

void displayEmployeeRecords()
{
    FILE *file = fopen("employee.dat", "rb");
    if (file == NULL)
    {
        cout << "Error: Could not open employee.dat file!" << endl;
        return;
    }

    Employee emp;
    int count = 0;

    cout << "\n========================================" << endl;
    cout << "        EMPLOYEE RECORDS" << endl;
    cout << "========================================" << endl;

    while (fread(&emp, sizeof(Employee), 1, file) == 1)
    {
        count++;
        float DA = emp.basicSalary * 0.2f;
        float HRA = emp.basicSalary * 0.1f;
        float netSalary = emp.basicSalary + DA + HRA;

        cout << "\nEmployee " << count << ":" << endl;
        cout << "  ID            : " << emp.empId << endl;
        cout << "  Name          : " << emp.name << endl;
        printf("  Basic Salary  : Rs. %.2f\n", emp.basicSalary);
        printf("  DA (20%%)      : Rs. %.2f\n", DA);
        printf("  HRA (10%%)     : Rs. %.2f\n", HRA);
        printf("  Net Salary    : Rs. %.2f\n", netSalary);
        cout << "----------------------------------------" << endl;
    }

    fclose(file);

    if (count == 0)
    {
        cout << "No employee records found." << endl;
    }
    else
    {
        cout << "\nTotal employees: " << count << endl;
    }
    cout << "========================================" << endl;
}

int main()
{
    int choice;

    cout << "Employee Salary Slip Generator\n";

    while (true)
    {
        cout << "\n1. Create Employee Data\n2. Generate Slips\n3. Display Records\n4. Exit\nChoice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createEmployeeData();
            break;
        case 2:
            processEmployeeRecords();
            break;
        case 3:
            displayEmployeeRecords();
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
