// Employee record editor using dynamic memory
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
    printf("Name: %s\n", emp->name);
    printf("ID: %d\n", emp->employee_id);
    printf("Salary: %.2f\n", emp->salary);
}

int main()
{
    struct employee *empPtr = (struct employee *)malloc(sizeof(struct employee));
    if (empPtr == NULL)
    {
        printf("Error: Memory allocation failed\n");
        return 1;
    }

    printf("Enter name: ");
    scanf("%49s", empPtr->name);

    printf("Enter ID: ");
    if (scanf("%d", &empPtr->employee_id) != 1 || empPtr->employee_id <= 0)
    {
        printf("Error: Invalid ID\n");
        free(empPtr);
        return 1;
    }

    printf("Enter salary: ");
    if (scanf("%f", &empPtr->salary) != 1 || empPtr->salary < 0)
    {
        printf("Error: Invalid salary\n");
        free(empPtr);
        return 1;
    }

    printf("\n");
    printEmp(empPtr);

    printf("\nEnter new salary: ");
    if (scanf("%f", &empPtr->salary) != 1 || empPtr->salary < 0)
    {
        printf("Error: Invalid salary\n");
        free(empPtr);
        return 1;
    }

    printf("\nUpdated:\n");
    printEmp(empPtr);

    free(empPtr);
    empPtr = NULL;
    return 0;
}
