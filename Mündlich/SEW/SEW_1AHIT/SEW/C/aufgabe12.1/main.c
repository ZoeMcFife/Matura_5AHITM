#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Title:        number reverser
//Author:       Leonard Bunea
//Description:  reverses a number and compares it to the original
//Last Change:  2020/03/02

long reverseLong(long reversedLong);
long compareLong(long standardLong, long reversedLong);
int digitsOf(long number);
int main()
{
    unsigned long userInput;
    char keepProgramRunning = 'y';

    do
    {
        printf("Enter a number: \t");
        scanf("%ld", &userInput);

        if (digitsOf(userInput) <= 8)
        {
            printf("The Reverse of your number is: %ld \n", reverseLong(userInput));

            switch (compareLong(userInput, reverseLong(userInput)))
            {
            case 1:
                printf("The original number is larger than the reversed one. \n");

                break;
            case 2:
                printf("The original number is smaller than the reversed one. \n");

                break;
            case 3:
                printf("The original number is equal to the reversed one. \n");

                break;
            }
        }
        printf("-----------------------------------------\n");
        printf("\n");

        printf("\n");
        printf("Do you want to do this again? (y / n) \n");
        fflush(stdin);
        keepProgramRunning = getche();
        printf("\n");
    }
    while (keepProgramRunning == 'y' ||keepProgramRunning == 'Y');


    return EXIT_SUCCESS;
}

long reverseLong(long reverse)
{

    long reversedLong = 0;

    while (reverse != 0)
    {
        reversedLong = reversedLong * 10;
        reversedLong += reverse % 10;
        reverse = reverse / 10;
    }

    return reversedLong;
}

long compareLong(long standardLong, long reversedLong)
{
    if (standardLong > reversedLong)
    {
        return 1;
    }
    else if (standardLong < reversedLong)
    {
        return 2;
    }
    else if (standardLong == reversedLong)
    {
        return 3;
    }
}

int digitsOf(long number)
{
    int digits = 0;

    while(number > 1)
    {
        number = number / 10;
        digits++;
    }

    return digits;
}
