/*
 * Student Performance Evaluation System
 * This program calculates the average marks of a student across multiple subjects
 * and assigns a grade based on the following scale:
 * A: 90-100, B: 80-89, C: 70-79, F: Below 70
 */
#include <iostream>
#include <limits>
using namespace std;

//Function to input marks for all subjects with validation
//Parameters: marks[] - array to store marks, numSubjects - number of subjects
void enterMarks(int marks[], int numSubjects){
    int a = 0;
    while(a < numSubjects){
        cout << "Enter marks for Subject " << a+1 << " : ";
        cin >> marks[a];
        
        // Handle non-numeric input
        if(cin.fail()){
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input! Please enter a numeric value." << endl;
            continue;
        }
        
        // Validate marks are within range [0, 100]
        if(marks[a] <= 100 && marks[a] >= 0){
            a++; // Move to next subject
        }
        else {
            cout << "Invalid marks! Please enter a value between 0 and 100." << endl;
        }
    }
}
//Function to calculate average marks across all subjects
//Parameters: marks[] - array of marks, numSubjects - number of subjects
//Returns: float - average of all marks
float calculateAverage(int marks[], int numSubjects){
    float sum = 0;
    // Sum all marks
    for(int i = 0; i < numSubjects; i++){
        sum += marks[i];
    }
    // Return average
    return sum / numSubjects;
}

//Function to determine grade based on average marks
//Grading Scale: A: 90-100, B: 80-89, C: 70-79, F: Below 70
//Parameter: average - calculated average marks
//Returns: char - assigned grade
char determineGrade(float average){
    if(average >= 90) return 'A';       // A: 90-100
    else if(average >= 80) return 'B';  // B: 80-89
    else if(average >= 70) return 'C';  // C: 70-79
    else return 'F';                     // F: Below 70
}
//Function to display formatted performance report
//Parameters: marks[] - array of marks, numSubjects - number of subjects,
//            grade - assigned grade, average - calculated average
void displayResult(int marks[], int numSubjects, char grade, float average){
    cout << "\n========================================" << endl;
    cout << "    STUDENT PERFORMANCE REPORT" << endl;
    cout << "========================================" << endl;
    
    cout << "\nTotal Subjects: " << numSubjects << endl;
    cout << "\nSubject-wise Marks:" << endl;
    for(int i = 0; i < numSubjects; i++){
        cout << "  Subject " << i + 1 << ": " << marks[i] << "/100" << endl;
    }
    
    cout << "\n----------------------------------------" << endl;
    cout << "Average Marks: " << average << "/100" << endl;
    cout << "Grade Assigned: " << grade << endl;
    cout << "========================================" << endl;
}
//Main function - Entry point of the program
int main(){
    int numSubjects;
    int* marks;
    
    // Display program header
    cout << "========================================" << endl;
    cout << "  Student Performance Evaluation System" << endl;
    cout << "========================================" << endl;
    
    // Get number of subjects from user
    cout << "\nEnter the number of subjects: ";
    cin >> numSubjects;
    
    // Validate numeric input for number of subjects
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a numeric value." << endl;
        return 1;
    }
    
    // Validate that number of subjects is positive
    if(numSubjects <= 0){
        cout << "Invalid number of subjects! Must be greater than 0." << endl;
        return 1;
    }
    
    // Dynamically allocate memory for marks array
    marks = new int[numSubjects];
    
    // Input marks for all subjects with validation
    enterMarks(marks, numSubjects);
    
    // Calculate the average of all marks
    float average = calculateAverage(marks, numSubjects);
    
    // Determine grade based on average
    char grade = determineGrade(average);
    
    // Display formatted performance report
    displayResult(marks, numSubjects, grade, average);
    
    // Free dynamically allocated memory
    delete[] marks;
    
    return 0;
}