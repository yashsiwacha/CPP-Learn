/*
 * Student Record Management System
 * This program allows users to:
 * 1. Add student records to a binary file
 * 2. Display all stored student records
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Student structure
struct Student
{
    int rollNo;    // Student's roll number
    char name[50]; // Student's name (max 50 characters)
    float marks;   // Student's marks
};

/*
 * Function: addStudentRecord
 * Purpose: Adds a new student record to the binary file
 * File Mode: "ab" (append binary) - adds records without overwriting
 */
void addStudentRecord()
{
    struct Student student;
    FILE *file;

    // Prompt user for student details
    printf("\n=== Add Student Record ===\n");

    // Input and validate roll number
    printf("Enter Roll Number: ");
    if (scanf("%d", &student.rollNo) != 1)
    {
        printf("Error: Invalid input for roll number!\n");
        while (getchar() != '\n')
            ; // Clear input buffer
        return;
    }

    // Validate roll number (must be positive)
    if (student.rollNo <= 0)
    {
        printf("Error: Roll number must be positive!\n");
        while (getchar() != '\n')
            ; // Clear input buffer
        return;
    }

    // Clear input buffer before reading string
    while (getchar() != '\n')
        ;

    // Input student name
    printf("Enter Name: ");
    if (fgets(student.name, sizeof(student.name), stdin) == NULL)
    {
        printf("Error: Failed to read name!\n");
        return;
    }

    // Remove newline character from name if present
    size_t len = strlen(student.name);
    if (len > 0 && student.name[len - 1] == '\n')
    {
        student.name[len - 1] = '\0';
    }

    // Validate name (must not be empty)
    if (strlen(student.name) == 0)
    {
        printf("Error: Name cannot be empty!\n");
        return;
    }

    // Input and validate marks
    printf("Enter Marks: ");
    if (scanf("%f", &student.marks) != 1)
    {
        printf("Error: Invalid input for marks!\n");
        while (getchar() != '\n')
            ; // Clear input buffer
        return;
    }

    // Validate marks (must be between 0 and 100)
    if (student.marks < 0.0 || student.marks > 100.0)
    {
        printf("Error: Marks must be between 0 and 100!\n");
        while (getchar() != '\n')
            ; // Clear input buffer
        return;
    }

    // Open file in binary append mode
    file = fopen("students.dat", "ab");
    if (file == NULL)
    {
        printf("Error: Could not open file for writing!\n");
        return;
    }

    // Write the student record to file
    if (fwrite(&student, sizeof(struct Student), 1, file) != 1)
    {
        printf("Error: Failed to write record to file!\n");
        fclose(file);
        return;
    }

    // Close the file
    fclose(file);

    printf("\n>>> Student record added successfully! <<<\n");
}

/*
 * Function: displayAllRecords
 * Purpose: Displays all student records from the binary file
 * File Mode: "rb" (read binary) - reads existing records
 */
void displayAllRecords()
{
    struct Student student;
    FILE *file;
    int count = 0;

    printf("\n=== All Student Records ===\n");

    // Open file in binary read mode
    file = fopen("students.dat", "rb");
    if (file == NULL)
    {
        printf("Error: Could not open file! No records found or file doesn't exist.\n");
        return;
    }

    // Print table header
    printf("\n%-10s %-30s %-10s\n", "Roll No", "Name", "Marks");
    printf("--------------------------------------------------------\n");

    // Read and display each record
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