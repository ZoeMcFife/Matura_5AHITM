#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Title:        bit operators
//Author:       Leonard Bunea
//Description:  shows off what bit operators do
//Last Change:  2020/01/26

void binaryConverter(signed int numDec);
void bitOperator(int num1, int num2);

int main()
{
    int num1, num2;
    char keepProgramRunning = 'y';

    do
    {
        //user inputs 2 numbers
        printf("Enter 2 numbers: \n");
        printf("1st Number:\t");
        scanf("%d", &num1);
        printf("2nd Number:\t");
        scanf("%d", &num2);

        printf("\n");
        printf("-----------------------------------------\n");
        printf("\n");

        bitOperator(num1, num2);

        printf("\n");
        printf("-----------------------------------------\n");
        printf("\n");

        printf("\n");
        printf("Do you want to continue? (y / n) \n");
        fflush(stdin);
        keepProgramRunning = getche();
        printf("\n");
    }
    while (keepProgramRunning == 'y' ||keepProgramRunning == 'Y');

    return EXIT_SUCCESS;
}

void binaryConverter(signed int numDec)
{
    int i;
    int temp;
    bool moreBitsFlag = false; //if set to true disables 8 bit limit (breaks formatting)

    if (floor(log2(numDec)) > 7 && moreBitsFlag)
    {
        i = floor(log2(numDec));
    }
    else
    {
        i = 7;
    }

    for (i; i >= 0; i--)
    {
        temp = numDec&(1<<i);
        if (temp != 0)
        {
            printf("1");
        }
        else if (temp == 0)
        {
            printf("0");
        }
    }
}

void bitOperator(int num1, int num2)
{
    int temp;

    printf("%d \t", num1);
    binaryConverter(num1);
    printf("\n");

    printf("~%d \t", num1);
    temp = (~num1);
    binaryConverter(temp);
    printf("\n");

    printf("%d>>1 \t", num1);
    temp = num1 >> 1;
    binaryConverter(temp);
    printf("\n");

    printf("%d>>2 \t", num1);
    temp = num1 >> 2;
    binaryConverter(temp);
    printf("\n");

    printf("%d<<1 \t", num1);
    temp = num1 << 1;
    binaryConverter(temp);
    printf("\n");

    printf("%d<<2 \t", num1);
    temp = num1 << 2;
    binaryConverter(temp);
    printf("\n");

    printf("\n");
    printf("\n");

    printf("%d \t", num1);
    binaryConverter(num1);
    printf("\n");

    printf("%d \t", num2);
    binaryConverter(num2);
    printf("\n");

    printf("%d&%d \t", num1, num2);
    temp = num1 & num2;
    binaryConverter(temp);
    printf("\n");

    printf("%d|%d \t", num1, num2);
    temp = num1 | num2;
    binaryConverter(temp);
    printf("\n");

    printf("%d^%d \t", num1, num2);
    temp = num1 ^ num2;
    binaryConverter(temp);
    printf("\n");
}
