#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 3

int main()
{
    short magSquare[ROWS][COLS] = {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};
    short temp[ROWS*COLS] = {0};
    short flag = 1;
    int sum;
    int i = 0, j = 0;
    short proofSum;

    printf("proof %d\n", proofSum);

    //a lot of shit to do:

    //sind alle zahlen von 1 .. ROWSxCOLS enthalten

    for (i = 0; i < ROWS*COLS; i++)
    {
        temp[i] = i + 1;
    }

    //alle zeilen summen bilden
    for (j = 0; j < COLS; j++)
    {
        proofSum+=magSquare[0][j];
    }

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            sum+= magSquare[i][j];
        }
        if(sum != proofSum)
        {
            flag = 0;
            break;
        }
        sum = 0;
    }
    for (j = 0; j < COLS; j++)
    {
        for (i = 0; i < ROWS; i++)
        {
            sum+= magSquare[i][j];
        }
        if(sum != proofSum)
        {
            flag = 0;
            break;
        }
        sum = 0;
    }

    //diagonalen

    //summe = magSquare[0][0] + ... + magSquare[2][2]

    printf("IS MAGIC    %d", flag);
    return EXIT_SUCCESS;
}
