#include <stdio.h>
#include <stdlib.h>

//Title:        binary converter
//Author:       Leonard Bunea
//Description:  Converts Decimal Numbers to Binary
//Last Change:  2020/01/26


int main()
{
    int numDec;
    int i;
    int temp;
    char keepProgramRunning = 'y';

    do
    {
            //user input
        printf("Number to convert in binary: ");
        scanf("%d", &numDec);

        printf("\n");
        printf("-----------------------------------------\n");
        printf("%d is ", numDec);

        //conversion
        for (i = floor(log2(numDec)); i >= 0; i--)  //i = floor(log2(numDec)) calculates how many bits a number takes up in binary
        {
            //prints 1 if current binary digit is a '1' and prints a 0 if it's a '0'
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

        printf(" in binary.\n");
        printf("-----------------------------------------\n");
        printf("\n");

        printf("\n");
        printf("Do you want to convert another number? (y / n) \n");
        fflush(stdin);
        keepProgramRunning = getche();
        printf("\n");
    }
    while (keepProgramRunning == 'y' ||keepProgramRunning == 'Y');

    return EXIT_SUCCESS;
}
