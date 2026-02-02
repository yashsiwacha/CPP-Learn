// Program for editing employee records using pointers.
#include <stdio.h>
#include <stdlib.h>

struct employee
{
    char name[50];
    int employee_id;
    float salary;
};

void printEmp(struct employee *emp)
{
    printf("Employee name : %s\n", emp->name);
    printf("Employee ID : %d\n", emp->employee_id);
    printf("Employee Salary : %.2f\n", emp->salary);
}

int main()
{
    struct employee *empPtr = (struct employee *)malloc(sizeof(struct employee));
    if (empPtr == NULL)
    {
        printf("Error: Memory allocation failed. Cannot create employee record.\n");
        return 1;
    }
    printf("Enter employee name (no spaces): ");
    scanf("%49s", empPtr->name);

    if (empPtr->name[0] == '\0')
    {
        printf("Error: Name cannot be empty.\n");
        free(empPtr);
        return 1;
    }
    printf("Enter employee ID (positive integer): ");
    if (scanf("%d", &empPtr->employee_id) != 1)
    {
        printf("Error: Invalid employee ID format. Please enter a positive integer.\n");
        free(empPtr);
        return 1;
    }
    if (empPtr->employee_id <= 0)
    {
        printf("Error: Employee ID must be a positive number.\n");
        free(empPtr);
        return 1;
    }
    printf("Enter employee salary (positive number): ");
    if (scanf("%f", &empPtr->salary) != 1)
    {
        printf("Error: Invalid salary format. Please enter a positive number (e.g., 50000.00).\n");
        free(empPtr);
        return 1;
    }
    if (empPtr->salary < 0)
    {
        printf("Error: Salary cannot be negative. Please enter a positive value.\n");
        free(empPtr);
        return 1;
    }
    printEmp(empPtr);
    printf("\nEnter new salary amount (positive number): ");
    if (scanf("%f", &empPtr->salary) != 1)
    {
        printf("Error: Invalid salary format. Please enter a positive number (e.g., 55000.00).\n");
        free(empPtr);
        return 1;
    }
    if (empPtr->salary < 0)
    {
        printf("Error: Salary cannot be negative. Please enter a positive value.\n");
        free(empPtr);
        return 1;
    }

    printf("\nUpdated Employee Record:\n");
    printEmp(empPtr);
    free(empPtr);
    empPtr = NULL;
    return 0;
}
