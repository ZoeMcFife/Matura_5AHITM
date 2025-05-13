#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Title:        random numbers
//Author:       Leonard Bunea
//Description:  generates random numbers and counts how many times a certain numbers shows up
//Last Change:  2020/12/28

int main()
{
    int userInput;
    int randomNumber;
    int count = 0;
    int i;
    long startTime, endTime;

    do              //User should Input number between 5 and 150
    {
        printf("Enter a number between 5 and 150:   ");
        scanf("%d", &userInput);
    }
    while ((userInput < 5) || (userInput > 150));

    //generates random numbers
    srand(time(NULL));
    startTime = clock();
    for (i = 0; i < 1e6; i++)
    {
        randomNumber = rand() % (150 - 5 + 1) + 5;
        if (randomNumber == userInput)
        {
            count++;
        }
    }
    endTime = clock();

    printf("Your number appeared %d times. Process took %ld milliseconds to execute.", count, (endTime - startTime));


    return EXIT_SUCCESS;
}
