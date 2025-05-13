#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Title:        second largest number
//Author:       Leonard Bunea
//Description:  Gets the second largest number of an array
//Last Change:  2020/01/12

int main()
{
    int numberArray[100]; //limits input to only 100 inputs from user, which isn't ideal but I don't expect anyone to put more than 100 numbers here
    int currentNumber;
    int maxArrayElement;
    int secondLargestArrayElement;

    int i = 0;

    do
    {
        printf("Enter Numbers below. Type 0 to stop.\n");

        do
        {
            printf("Enter a positive number:    \n");
            scanf("%d", &currentNumber);
            if (currentNumber != 0)
            {
                numberArray[i] = currentNumber;
                i++;
            }
        }
        while (currentNumber);

        maxArrayElement = i;

        //sorting algorithm --> Bubble sort
        int temp, temp3, temp4;

        for (temp = 0; temp < maxArrayElement; temp++)  //loops through each array element
        {
            for (temp3 = temp + 1; temp3 < maxArrayElement; temp3++) //gets next array element
            {
                if (numberArray[temp3] < numberArray[temp])    //swaps if next element is bigger
                {
                    temp4 = numberArray[temp];
                    numberArray[temp] = numberArray[temp3];
                    numberArray[temp3] = temp4;
                }
            }
        }

        secondLargestArrayElement = numberArray[(maxArrayElement - 2)];

        printf("The second largest number is %d.", secondLargestArrayElement);

        printf("\n");
        printf("Do you want to continue? (y / n) \n");
        fflush(stdin);
        keepProgramRunning = getche();
        printf("\n");
    }
    while (keepProgramRunning == 'y' ||keepProgramRunning == 'Y');

    return EXIT_SUCCESS;
}
