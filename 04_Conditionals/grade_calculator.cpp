//Student Grade Analyzer
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char continueProcessing;
    
    // Main Program Loop (do-while)
    do {
        int studentID;
        int numAssignments;
        float totalGrades = 0;
        int validAssignmentsCount = 0;
        
        // Student ID Input and Validation (while loop)
        cout << "Enter Student ID (e.g., 101-999): ";
        cin >> studentID;
        
        while (studentID < 101 || studentID > 999) {
            cout << "Invalid Student ID. Must be between 101 and 999. Please re-enter." << endl;
            cout << "Enter Student ID (e.g., 101-999): ";
            cin >> studentID;
        }
        
        // Ask for number of assignments
        cout << "How many assignments does Student " << studentID << " have? ";
        cin >> numAssignments;
        
        // Assignment Grade Input Loop (for loop)
        for (int i = 1; i <= numAssignments; i++) {
            float grade;
            
            // Prompt for assignment grade
            cout << "Enter grade for Assignment #" << i << " (0-100): ";
            cin >> grade;
            
            // Validation and continue
            if (grade < 0 || grade > 100) {
                cout << "Invalid grade. Must be between 0 and 100. Skipping this assignment." << endl;
                continue;  // Skip to next assignment
            }
            
            // Add valid grade to total
            totalGrades += grade;
            validAssignmentsCount++;
        }
        
        // Output and Performance Feedback
        if (validAssignmentsCount == 0) {
            cout << "No valid grades entered for Student " << studentID << "." << endl;
        } else {
            float averageGrade = totalGrades / validAssignmentsCount;
            cout << "Student " << studentID << " - Average Grade: " << averageGrade << "%" << endl;
            
            // Performance message based on average
            if (averageGrade >= 90) {
                cout << "Excellent!" << endl;
            } else if (averageGrade >= 70) {
                cout << "Good job!" << endl;
            } else if (averageGrade >= 50) {
                cout << "Needs improvement." << endl;
            } else {
                cout << "At risk." << endl;
            }
        }
        
        // Ask if user wants to process another student
        cout << "\nProcess another student? (Y/N): ";
        cin >> continueProcessing;
        
        // Convert to uppercase for easier comparison
        continueProcessing = toupper(continueProcessing);
        
        // Break if user enters 'N'
        if (continueProcessing == 'N') {
            break;
        }
        
        cout << endl;  // Empty line for readability
        
    } while (true);  // Infinite loop, exit controlled by break statement
    
    // Program Exit Message
    cout << "Exiting Grade Analyzer. Goodbye!" << endl;
    
    return 0;
}