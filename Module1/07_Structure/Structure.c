// Program demonstrating structures and pointers to structures
#include <stdio.h>
#include <string.h>

struct employee
{
    char name[50];
    int employee_id;
    float salary;
};

void inputDetails(struct employee *emp)
{
    printf("Enter name: ");
    scanf("%s", emp->name);

    printf("Enter ID: ");
    scanf("%d", &emp->employee_id);

    printf("Enter salary: ");
    scanf("%f", &emp->salary);

    if (emp->salary < 0)
    {
        printf("Warning: Negative salary set to 0\n");
        emp->salary = 0;
    }
}

void printEmployeeDetails(const struct employee emp)
{
    printf("Name: %s\n", emp.name);
    printf("ID: %d\n", emp.employee_id);
    printf("Salary: %.2f\n\n", emp.salary);
}

int main()
{
    struct employee emp1;
    strcpy(emp1.name, "Yash");
    emp1.employee_id = 50;
    emp1.salary = 50000.75;

    printf("Single Employee:\n");
    printEmployeeDetails(emp1);

    struct employee emp[3];

    strcpy(emp[0].name, "Alice");
    emp[0].employee_id = 101;
    emp[0].salary = 45000.50;

    strcpy(emp[1].name, "Bob");
    emp[1].employee_id = 102;
    emp[1].salary = 52000.75;

    strcpy(emp[2].name, "Charlie");
    emp[2].employee_id = 103;
    emp[2].salary = 48500.00;

    printf("Array of Employees:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Employee %d:\n", i + 1);
        printEmployeeDetails(emp[i]);
    }

    return 0;
}