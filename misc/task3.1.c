//Creating and Displaying an Aligned Student Table
#include <stdio.h>

char name1[20], name2[20], name3[20]; //Name of three students
int age1, age2, age3; //Age of three students
float gpa1, gpa2, gpa3; //GPA of three students

void dataInput(){
    //Input data for student 1
    printf("Enter name for student 1: ");
    scanf("%s", name1);
    printf("Enter age for student 1: ");
    scanf("%d", &age1);
    printf("Enter GPA for student 1: ");
    scanf("%f", &gpa1);
    
    //Input data for student 2
    printf("Enter name for student 2: ");
    scanf("%s", name2);
    printf("Enter age for student 2: ");
    scanf("%d", &age2);
    printf("Enter GPA for student 2: ");
    scanf("%f", &gpa2);
    
    //Input data for student 3
    printf("Enter name for student 3: ");
    scanf("%s", name3);
    printf("Enter age for student 3: ");
    scanf("%d", &age3);
    printf("Enter GPA for student 3: ");
    scanf("%f", &gpa3);
}

void displayTable(){
    //Display table with aligned columns
    printf("\n    |---------------|-----|-------|\n");
    printf("    |%15s|%5s|%7s|\n", "Name", "Age", "GPA");
    printf("    |---------------|-----|-------|\n");
    printf("    | %-13s |%4d |%6.2f |\n", name1, age1, gpa1);
    printf("    | %-13s |%4d |%6.2f |\n", name2, age2, gpa2);
    printf("    | %-13s |%4d |%6.2f |\n", name3, age3, gpa3);
}

int main(){
    dataInput();
    displayTable();
    return 0;
}