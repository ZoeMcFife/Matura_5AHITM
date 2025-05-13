#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define MAX 6
#define MIN 1

int main()
{
    //Variables
    int userInputThrows;
    int dieNumber1;
    int dieNumber2;
    int dieNumberCommon = 0;

    //for loop variable
    int i = 0;

    srand(time(NULL));  //rng initializing

    //gets user input between 1000000 and 500000
    while (userInputThrows > 1e6 || userInputThrows < 500000)
    {
        printf("Enter how many throws should be made! (between 1 000 000 and 500 000)   \n");
        scanf("%d", &userInputThrows);
        printf("\n"); //padding
        if (userInputThrows > 1e6 || userInputThrows < 500000)
        {
            printf("Error: Please enter between 1 000 000 and 500 000! %d is not valid! \n", userInputThrows);
        }
    }

    //simulates die throws
    for (i; i < userInputThrows; i++)
    {
        dieNumber1 = rand() % (MAX - MIN + 1) + MIN;
        dieNumber2 = rand() % (MAX - MIN + 1) + MIN;

        if (dieNumber1 == dieNumber2)
        {
            dieNumberCommon++;
        }
    }

    //outputs results
    printf("\n"); //padding
    printf("Two dice have been thrown %d times; they had the same number %d times.", userInputThrows, dieNumberCommon);
    printf("\n"); //padding

    return EXIT_SUCCESS;
}
