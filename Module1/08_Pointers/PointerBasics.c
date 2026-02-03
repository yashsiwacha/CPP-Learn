// Program to demonstrate dynamic memory allocation and basic pointer operations in C
// This program allocates memory for a color code, validates user input, and manages memory properly

#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

// Define valid color code range
#define MIN_COLOR_CODE 0
#define MAX_COLOR_CODE 255

int main()
{
    // Dynamically allocate memory for an integer to store theme color code
    int *ptr = (int *)malloc(sizeof(int));

    // Check if memory allocation was successful
    if (ptr == NULL)
    {
        printf("Error: Memory allocation failed\n");
        return 1;
    }

    // Initialize the allocated memory to 0
    *ptr = 0;

    // Prompt user for input
    printf("Enter a theme color code (0-255): ");

    // Read user input and validate
    if (scanf("%d", ptr) != 1)
    {
        printf("Error: Invalid input. Please enter a valid integer.\n");
        free(ptr);
        ptr = NULL;
        return 1;
    }

    // Validate the color code range
    if (*ptr < MIN_COLOR_CODE || *ptr > MAX_COLOR_CODE)
    {
        printf("Error: Color code must be between %d and %d.\n", MIN_COLOR_CODE, MAX_COLOR_CODE);
        free(ptr);
        ptr = NULL;
        return 1;
    }

    // Print the theme color code with descriptive message
    printf("Successfully set theme color code: %d\n", *ptr);

    // Free the allocated memory
    free(ptr);

    // Set pointer to NULL after freeing to avoid dangling pointer
    ptr = NULL;

    printf("Memory successfully deallocated.\n");

    return 0;
}