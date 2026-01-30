#include <stdio.h>
#include <string.h>

/**
 * Structure to store employee information
 * Contains name, employee ID, and salary
 */
struct employee
{
    char name[50];
    int employee_id;
    float salary;
};

/**
 * Function to take input of employee details
 * @param emp: Pointer to employee structure to store input
 * Validates that salary is non-negative
 */
void inputDetails(struct employee *emp)
{
    printf("Enter employee name: ");
    scanf("%s", emp->name);

    printf("Enter employee ID: ");
    scanf("%d", &emp->employee_id);

    printf("Enter salary: ");
    scanf("%f", &emp->salary);

    // Input validation - ensure salary is non-negative
    if (emp->salary < 0)
    {
        printf("Warning: Salary cannot be negative. Setting to 0.\n");
        emp->salary = 0;
    }
}

/**
 * Function to print employee details
 * @param emp: Employee structure to print (passed by value)
 * Displays name, employee ID, and salary with 2 decimal places
 */
void printEmployeeDetails(const struct employee emp)
{
    printf("Name of Employee : %s\n", emp.name);
    printf("Employee ID : %d\n", emp.employee_id);
    printf("Salary of Employee : %.2f\n", emp.salary);
    printf("\n");
}

int main()
{
    // Step B: Managing a single employee
    struct employee emp1;
    char name[50] = "Yash";
    strcpy(emp1.name, name);
    emp1.employee_id = 50;
    emp1.salary = 50000.75;

    printf("=== Single Employee Details ===\n");
    printEmployeeDetails(emp1);

    // Step D: Managing multiple employees with direct initialization
    struct employee emp[3];

    // Initialize first employee
    strcpy(emp[0].name, "Alice");
    emp[0].employee_id = 101;
    emp[0].salary = 45000.50;

    // Initialize second employee
    strcpy(emp[1].name, "Bob");
    emp[1].employee_id = 102;
    emp[1].salary = 52000.75;

    // Initialize third employee
    strcpy(emp[2].name, "Charlie");
    emp[2].employee_id = 103;
    emp[2].salary = 48500.00;

    // Print all employees
    printf("=== Array of Employees ===\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Employee %d:\n", i + 1);
        printEmployeeDetails(emp[i]);
    }

    return 0;
}