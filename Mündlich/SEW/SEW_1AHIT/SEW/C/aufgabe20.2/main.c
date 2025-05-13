#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

//Title:        Lotto tips
//Description:  generates lotto tips
//Last Change:  2021/06/09
//Author:       Leonard Bunea

void Usage(char progName[]);
void sort(int array[]);
void outputArray(int array[]);
bool isInArray(int integer, int array[]);

int main(int argc, char *argv[])
{
    int lottoNumber[6] = {0};
    int i, j, max = 45, min = 1;
    int count = 1;
    int temp = 0;

    srand(time(NULL));

    //if more than 2 arguments are given
    if (argc > 2)
    {
        Usage(argv[0]);
    }

    //converts the 1st argument into an integer
    if(argc == 2)
    {
        count = atoi(argv[1]);
    }

    //generates 6 random numbers for any given amount of arrays
    for (i = 0; i < count; i++)
    {
        for (j = 0; j < 6; j++)
        {
            do
            {
                temp = rand() % (max - min + 1) + min;
            }
            while(isInArray(temp, lottoNumber) == true);

            lottoNumber[j] = temp;
        }

        //outputs and sorts each array
        sort(lottoNumber);
        outputArray(lottoNumber);
    }

    return EXIT_SUCCESS;
}

//sorts an array using the bubble sort algorithm
void sort(int array[])
{
    int i = 0, j = 0, k = 0, len = 6;

    for (i = 0; i < len - 1; i++)
    {
        for(j = 0; j < len - 1; j++)
        {
            if(array[j] > array[j + 1])
            {
                k = array[j];
                array[j] = array[j + 1];
                array[j + 1] = k;
            }
        }
    }
}

//outputs an array of length 6
void outputArray(int array[])
{
    int i, len = 6;

    printf("Your Tips:\t");
    for(i = 0; i < len; i++)
    {
        printf("%d\t", array[i]);
    }
    puts("");
}

//checks if an integer is in an array
bool isInArray(int integer, int array[])
{
    int i;
    int len = 6;

    for(i = 0; i < len; i++)
    {
        if(array[i] == integer)
        {
            return true;
        }
    }

    return false;
}

//usage of program
void Usage(char progName[])
{
    printf("USAGE %s [COUNT] \n", progName);
    exit(EXIT_FAILURE);
}
