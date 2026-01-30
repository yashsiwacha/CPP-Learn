//Student Grade Analyzer
#include <stdio.h>
#include <ctype.h>

int main() {
    char continueProcessing;
    
    // Main Program Loop (do-while)
    do {
        int studentID;
        int numAssignments;
        float totalGrades = 0;
        int validAssignmentsCount = 0;
        
        // Student ID Input and Validation (while loop)
        printf("Enter Student ID (e.g., 101-999): ");
        scanf("%d", &studentID);
        
        while (studentID < 101 || studentID > 999) {
            printf("Invalid Student ID. Must be between 101 and 999. Please re-enter.\n");
            printf("Enter Student ID (e.g., 101-999): ");
            scanf("%d", &studentID);
        }
        
        // Ask for number of assignments
        printf("How many assignments does Student %d have? ", studentID);
        scanf("%d", &numAssignments);
        
        // Assignment Grade Input Loop (for loop)
        for (int i = 1; i <= numAssignments; i++) {
            float grade;
            
            // Prompt for assignment grade
            printf("Enter grade for Assignment #%d (0-100): ", i);
            scanf("%f", &grade);
            
            // Validation and continue
            if (grade < 0 || grade > 100) {
                printf("Invalid grade. Must be between 0 and 100. Skipping this assignment.\n");
                continue;  // Skip to next assignment
            }
            
            // Add valid grade to total
            totalGrades += grade;
            validAssignmentsCount++;
        }
        
        // Output and Performance Feedback
        if (validAssignmentsCount == 0) {
            printf("No valid grades entered for Student %d.\n", studentID);
        } else {
            float averageGrade = totalGrades / validAssignmentsCount;
            printf("Student %d - Average Grade: %.2f%%\n", studentID, averageGrade);
            
            // Performance message based on average
            if (averageGrade >= 90) {
                printf("Excellent!\n");
            } else if (averageGrade >= 70) {
                printf("Good job!\n");
            } else if (averageGrade >= 50) {
                printf("Needs improvement.\n");
            } else {
                printf("At risk.\n");
            }
        }
        
        // Ask if user wants to process another student
        printf("\nProcess another student? (Y/N): ");
        scanf(" %c", &continueProcessing);  // Space before %c to skip whitespace
        
        // Convert to uppercase for easier comparison
        continueProcessing = toupper(continueProcessing);
        
        // Break if user enters 'N'
        if (continueProcessing == 'N') {
            break;
        }
        
        printf("\n");  // Empty line for readability
        
    } while (1);  // Infinite loop, exit controlled by break statement
    
    // Program Exit Message
    printf("Exiting Grade Analyzer. Goodbye!\n");
    
    return 0;
}