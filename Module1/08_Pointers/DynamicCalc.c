// Dynamic calculator using function pointers
#include <iostream>
#include <limits>
using namespace std;

const int DIV_BY_ZERO_ERROR = INT_MIN;

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

int divide(int a, int b)
{
    if (b == 0)
    {
        cout << "Error: Division by zero\n";
        return DIV_BY_ZERO_ERROR;
    }
    return a / b;
}

int calculate(int a, int b, int (*operation)(int, int))
{
    return operation(a, b);
}

void printResult(const char *op, int a, int b, int result)
{
    if (result == DIV_BY_ZERO_ERROR)
        cout << op << ": " << a << " and " << b << " -> ERROR\n";
    else
        cout << op << ": " << a << " and " << b << " = " << result << "\n";
}

int main()
{
    int num1 = 20, num2 = 5;

    cout << "Individual Operations:\n";
    printResult("Addition", num1, num2, calculate(num1, num2, add));
    printResult("Subtraction", num1, num2, calculate(num1, num2, subtract));
    printResult("Multiplication", num1, num2, calculate(num1, num2, multiply));
    printResult("Division", num1, num2, calculate(num1, num2, divide));

    cout << "\nError Handling:\n";
    printResult("Division", num1, 0, calculate(num1, 0, divide));

    cout << "\nDispatch Table:\n";
    int (*operations[])(int, int) = {add, subtract, multiply, divide};
    const char *names[] = {"Add", "Sub", "Mul", "Div"};

    for (int i = 0; i < 4; i++)
        printResult(names[i], 100, 25, calculate(100, 25, operations[i]));

    return 0;
}
