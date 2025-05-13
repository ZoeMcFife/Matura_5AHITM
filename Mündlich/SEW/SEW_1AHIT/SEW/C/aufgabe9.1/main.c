#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <conio.h>
#include "conioex.h"


//Title:        Postfix Calculator
//Author:       Leonard Bunea
//Description:  a simple postfix calculator
//Last Change:  2021/02/09

int main()
{
    char keepRunning = 'y';
    char currentOperation;
    double num1, num2;
    double result = 0;
    bool calculate = true;
    int i;

    do
    {
        textcolor(YELLOW);
        printf("Postfix Calculator\n");
        printf("------------------\n");
        textcolor(WHITE);

        printf("Enter numbers below: \n");
        scanf("%lf", &num1);
        scanf("%lf", &num2);

        calculate = true;

        while (calculate)
        {
            if (num2 == 0)
            {
                calculate = false;
                break;
            }
            fflush(stdin);
            printf("op: ");
            currentOperation = getchar();

            switch (currentOperation)
            {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '/':
                result = num1 / num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            }
            num1 = result;
            printf("num: ");
            scanf("%lf", &num2);
        }

        textcolor(YELLOW);
        printf("\n");
        printf("------------------");
        printf("Result: %lf", result);
        printf("------------------");
        printf("\n");
        textcolor(WHITE);

        printf("\n");
        printf("Do another calculation? y / n \n");
        keepRunning = getch();
        printf("\n");
        fflush(stdin);
    }
    while (keepRunning == 'y' || keepRunning == 'Y');

    return EXIT_SUCCESS;
}

