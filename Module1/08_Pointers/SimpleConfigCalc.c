// Function pointer calculator
#include <stdio.h>

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

int divide(int a, int b)
{
    if (b == 0)
    {
        printf("Error: Division by zero\n");
        return 0;
    }
    return a / b;
}

int main()
{
    int num1 = 15, num2 = 5;
    int (*operation)(int, int);

    operation = add;
    printf("%d + %d = %d\n", num1, num2, operation(num1, num2));

    operation = subtract;
    printf("%d - %d = %d\n", num1, num2, operation(num1, num2));

    operation = multiply;
    printf("%d * %d = %d\n", num1, num2, operation(num1, num2));

    operation = divide;
    printf("%d / %d = %d\n", num1, num2, operation(num1, num2));

    printf("\n1. Add\n2. Sub\n3. Mul\n4. Div\nChoice: ");
    int choice;
    scanf("%d", &choice);

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    switch (choice)
    {
    case 1:
        operation = add;
        break;
    case 2:
        operation = subtract;
        break;
    case 3:
        operation = multiply;
        break;
    case 4:
        operation = divide;
        break;
    default:
        printf("Invalid, using add\n");
        operation = add;
    }

    printf("Result: %d\n", operation(num1, num2));

    printf("\nDispatch table:\n");
    int (*ops[4])(int, int) = {add, subtract, multiply, divide};
    const char *names[] = {"Add", "Sub", "Mul", "Div"};

    for (int i = 0; i < 4; i++)
        printf("%s: %d\n", names[i], ops[i](20, 4));

    return 0;
}
}
