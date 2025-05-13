#include <stdio.h>
#include <stdlib.h>

//Title:        partygäste
//Author:       Leonard Bunea
//Description:  counts how often a number people toast at a party.
//Last Change:  2020/01/14

int main()
{
    int people = 1, toasts = 0, maxAmountOfPeople;
    int i;

    char keepProgramRunning = 'y';

    do
    {
            //user input of how many people should come.
        printf("How many people should come to the party? \n");
        scanf("%d", &maxAmountOfPeople);

        for (i = 0; i < maxAmountOfPeople; i++)
        {
            //uses gausses formula for anytime a new guest arrives and adds it up
            people++;
            toasts += (people * (people - 1) / 2);
        }
        //prints results
        printf("%d People toast %d times.", maxAmountOfPeople, toasts);

        printf("\n");
        printf("Do you want to continue? (y / n) \n");
        fflush(stdin);
        keepProgramRunning = getche();
        printf("\n");
    }
    while (keepProgramRunning == 'y' ||keepProgramRunning == 'Y');

    return EXIT_SUCCESS;
}
