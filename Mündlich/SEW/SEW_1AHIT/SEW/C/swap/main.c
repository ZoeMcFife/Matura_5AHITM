#include <stdio.h>
#include <stdlib.h>

void swapDouble(double *num1, double *num2);

int main()
{
    double num1 = 45, num2 = 42;

    swapDouble(&num1, &num2);

    if (num1 == 42 && num2 == 45)
    {
        printf("I want to be my fursona but can't ;w; owo");
    }

    return EXIT_SUCCESS;
}

void swapDouble(double *num1, double *num2)
{
    double temp;

    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

