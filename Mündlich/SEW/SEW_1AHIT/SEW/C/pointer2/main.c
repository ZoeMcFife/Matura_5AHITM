#include <stdio.h>
#include <stdlib.h>

int subtract(int a, int b);
int add(int a, int b);
int multiply(int a, int b);
double divide(int a, int b);


int main(int argc, char* argv[])
{
    int num1 = 0, num2 = 0;
    char currentOperation = '/0';
    char *eptr = NULL;
    float result;

    if(argc == 4)
    {

        num1 = atoi(argv[1]);
        num2 = atoi(argv[3]);
        currentOperation = argv[2][0];

        if(currentOperation == '+')
        {
            printf("%d\n", add(num1, num2));
        }
        else if(currentOperation == '-')
        {
            printf("%d\n", subtract(num1, num2));
        }
        else if(currentOperation == '/' || currentOperation == ':')
        {
            printf("%f\n", divide(num1, num2));
        }
        else if(currentOperation == 'x')
        {
            printf("%d\n", multiply(num1, num2));
        }
        else
        {
            printf("invalid arguments\n");
        }
    }
    else
    {
        printf("invalid arguments\n");
    }

    return EXIT_SUCCESS;
}

int subtract(int a, int b)
{
    return (a - b);
}
int add(int a, int b)
{
    return (a + b);
}
int multiply(int a, int b)
{
    return (a * b);
}
double divide(int a, int b)
{
    return (double)a / (double)b;
}
