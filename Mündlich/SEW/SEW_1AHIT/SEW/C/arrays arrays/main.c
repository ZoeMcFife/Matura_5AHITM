#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define MAX 45
#define MIN 1

int main()
{
    /*long feld[MAXSIZE] = {10, 8, 1, 3, 0};  //Feld von 100 Elementen (alle vom Tyo long)

    printf("1. Element:  %d\n", feld[0]); //[0] index ... für feld gilt:    index 0 .. 99
    */

    //int lottoNums[6];
    int randomNum;
    int i;
    //int j;

    srand(time(NULL));

    /*
    for (i = 0; i < 6; i++)
    {
        randomNum = rand() % (MAX - MIN + 1) + MIN;

        for (j = 0; j < i - 1; j++)
        {
            if (randomNum == lottoNums[j])
            {
                randomNum = rand() % (1 + 45) - 1;
            }
        }

        lottoNums[i] = randomNum;
    }

    for (i = 0; i < 6; i++)
    {
        printf("%d \n", lottoNums[i]);
    }
*/
    // erzeuge 1000 zufällige zahlen im bereich 1 bis 45 und bestimme wie viele davon größer als der mittelwert

    double randomNumbers[1000];
    double average;
    double sum = 0;
    double numbersAboveAVG = 0;

    for (i = 0; i < 1000; i++)
    {
        randomNum == rand() % (MAX - MIN + 1) + MIN;
        sum += (double)randomNum;


        randomNumbers[i] = randomNum;
    }

    printf("%lf \n", sum);

    average = sum / 1000.0;

    for (i = 0; i < 1000; i++)
    {
        if (randomNumbers[i] > average)
        {
            numbersAboveAVG++;
        }
    }

    printf("%lf", numbersAboveAVG);

    return EXIT_SUCCESS;
}
