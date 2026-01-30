#include "myheader.h"
#include <stdio.h>

extern void printMessage();

void useConstant()
{
    printf("Value of PI: %f\n", PI);
}

int main()
{
    printMessage();
    useConstant();
    return 0;
}
