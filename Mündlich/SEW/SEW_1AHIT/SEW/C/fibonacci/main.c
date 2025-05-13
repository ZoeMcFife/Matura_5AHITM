#include <stdio.h>
#include <stdlib.h>

//Title:        fibonacci
//Author:       Leonard Bunea
//Description:  prints fibonacci numbers
//Last Change:  2020/01/19

int main()
{
    long userLimit;
    long fib1 = 1, fib2 = 1, fib3 = 0;
    char keepRunning = 'y';
    short correctInput;

    system("COLOR 05"); //changes console text color to violet

    do
    {
        printf("Enter maximum fibonacci number.\n");
        correctInput = scanf("%ld", &userLimit);


        //userinput
        //throws errors, if user inputs a negative number or a letter
        if (correctInput != 1)
        {
            printf("There seems to be an error. \n");
        }
        else if (userLimit < 1)
        {
            printf("Error: Range must be a positive number. \n");
        }
        else
        {
            //main
            printf("Printing fibonacci numbers up to %ld. \n", userLimit);
            printf("\n");
            printf("%ld %ld", fib1, fib2);

            //prints fibonacci numbers
            while (fib3 < userLimit)
            {
                fib3 = fib1 + fib2;

                if (fib3 < userLimit)
                {
                    printf(" %ld", fib3);
                }

                fib1 = fib2;
                fib2 = fib3;
            }
        }
        //asks user if they want to continue
        printf("\n");
        printf("Do you want to continue? (y / n) \n");
        fflush(stdin);
        keepRunning = getchar();
        printf("\n");
    }
    while (keepRunning == 'y' || keepRunning == 'Y');

    return EXIT_SUCCESS;
}
