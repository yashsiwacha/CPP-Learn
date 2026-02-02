// Student Record Management System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int rollNo;
    char name[50];
    float marks;
};

void addStudentRecord()
{
    struct Student student;
    FILE *file;

    printf("\n=== Add Student Record ===\n");

    printf("Enter Roll Number: ");
    if (scanf("%d", &student.rollNo) != 1)
    {
        printf("Error: Invalid input for roll number!\n");
        while (getchar() != '\n')
            ;
        return;
    }

    if (student.rollNo <= 0)
    {
        printf("Error: Roll number must be positive!\n");
        while (getchar() != '\n')
            ;
        return;
    }

    while (getchar() != '\n')
        ;

    printf("Enter Name: ");
    if (fgets(student.name, sizeof(student.name), stdin) == NULL)
    {
        printf("Error: Failed to read name!\n");
        return;
    }

    size_t len = strlen(student.name);
    if (len > 0 && student.name[len - 1] == '\n')
    {
        student.name[len - 1] = '\0';
    }

    if (strlen(student.name) == 0)
    {
        printf("Error: Name cannot be empty!\n");
        return;
    }

    printf("Enter Marks: ");
    if (scanf("%f", &student.marks) != 1)
    {
        printf("Error: Invalid input for marks!\n");
        while (getchar() != '\n')
            ;
        return;
    }

    if (student.marks < 0.0 || student.marks > 100.0)
    {
        printf("Error: Marks must be between 0 and 100!\n");
        while (getchar() != '\n')
            ;
        return;
    }

    file = fopen("students.dat", "ab");
    if (file == NULL)
    {
        printf("Error: Could not open file for writing!\n");
        return;
    }

    if (fwrite(&student, sizeof(struct Student), 1, file) != 1)
    {
        printf("Error: Failed to write record to file!\n");
        fclose(file);
        return;
    }

    fclose(file);

    printf("\n>>> Student record added successfully! <<<\n");
}

void displayAllRecords()
{
    struct Student student;
    FILE *file;
    int count = 0;

    printf("\n=== All Student Records ===\n");

    file = fopen("students.dat", "rb");
    if (file == NULL)
    {
        printf("Error: Could not open file! No records found or file doesn't exist.\n");
        return;
    }

    printf("\n%-10s %-30s %-10s\n", "Roll No", "Name", "Marks");
    printf("--------------------------------------------------------\n");

    while (fread(&student, sizeof(struct Student), 1, file) == 1)
    {
        printf("%-10d %-30s %-10.2f\n", student.rollNo, student.name, student.marks);
        count++;
    }

    // Check if file was empty
    if (count == 0)
    {
        printf("No records found in the file.\n");
    }
    else
    {
        printf("--------------------------------------------------------\n");
        printf("Total records: %d\n", count);
    }

    // Close the file
    fclose(file);
}

/*
 * Function: displayMenu
 * Purpose: Displays the main menu options
 */
void displayMenu()
{
    printf("\n");
    printf("========================================\n");
    printf("  Student Record Management System\n");
    printf("========================================\n");
    printf("1. Add Student Record\n");
    printf("2. Display All Records\n");
    printf("3. Exit\n");
    printf("========================================\n");
    printf("Enter your choice: ");
}

/*
 * Main Function
 * Purpose: Implements menu-driven interface for the program
 */
int main()
{
    int choice;

    printf("\n*** Welcome to Student Record Management System ***\n");

    // Main program loop
    while (1)
    {
        displayMenu();

        // Read user choice
        if (scanf("%d", &choice) != 1)
        {
            printf("\nError: Invalid input! Please enter a number.\n");
            while (getchar() != '\n')
                ; // Clear input buffer
            continue;
        }

        // Clear input buffer
        while (getchar() != '\n')
            ;

        // Handle user choice using switch-case
        switch (choice)
        {
        case 1:
            addStudentRecord();
            break;

        case 2:
            displayAllRecords();
            break;

        case 3:
            printf("\n*** Thank you for using Student Record Management System! ***\n");
            printf("Exiting program...\n\n");
            exit(0);

        default:
            printf("\nError: Invalid choice! Please select 1, 2, or 3.\n");
        }
    }

    return 0;
}