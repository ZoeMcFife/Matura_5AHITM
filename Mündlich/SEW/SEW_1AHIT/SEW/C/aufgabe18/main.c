#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getLongs(char string[], long output[]);
long arraySum(long array[], int length);
long getLargestInArray(long array[], long size);

int main()
{
    long inputArray1[2];
    int parkingSpots;
    int cars;
    char string[10000];
    int i;
    long activeCars = 0, inactiveCars = 0;
    long carArray[1000];
    long result;
    long inputArray2[9999] = {0};


    do
    {
        printf("Input 1:\t");
        gets(string);
        getLongs(string, inputArray1);

        if (inputArray1[0] > 200 || inputArray1[0] <= 0)
        {
            printf("Less than 200\n");
        }
    }
    while(inputArray1[0] > 200 || inputArray1[0] <= 0);

    parkingSpots = inputArray1[0];
    cars = inputArray1[1];

    do
    {
        printf("Input 2:\t");
        gets(string);
        getLongs(string, inputArray2);
    }
    while(arraySum(inputArray2, cars * 2) != 0);

    for (i = 0; i < cars*2; i++)
    {
        if (inputArray2[i] > 0)
        {
            activeCars++;
        }
        else if (inputArray2[i] < 0)
        {
            inactiveCars++;
            activeCars--;
        }

        carArray[i] = activeCars;
    }

    result = getLargestInArray(carArray, cars * 2);

    printf("RESULT %ld\n", result);

    return EXIT_SUCCESS;
}

void getLongs(char string[], long output[])
{
    char *eptr = string;
    int i = 0;

    while (*eptr)
    {
        if(isdigit(*eptr) || ((*eptr == '-') && isdigit(*(eptr+1))))
        {
           output[i] = strtol(eptr, &eptr, 10);
           i++;
        }
        else
        {
            eptr++;
        }
    }
}

long arraySum(long array[], int length)
{
    int i;
    long sum = 0;

    for(i = 0; i < length; i++)
    {
        sum += array[i];
    }

    return sum;
}

long getLargestInArray(long array[], long size)
{
    int i = 0, j = 0, k = 0;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                k = array[j];
                array[j] = array[j + 1];
                array[j + 1] = k;
            }
        }
    }

    return array[size - 1];
}


