#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//beispiel 3

void Usage()
{
    printf("Usage: sortNumbers number1 number2 [number3] . . .\n");
    exit(EXIT_FAILURE);
}

void sortArray(int array[], int arrayLenght);
int getNumberFromString(char string[]);
void createArrayFromArguments(int argc, char *argv[], int outputArray[]);
void printArray(int array[], int arrayLength);

int main (int argc, char *argv[])
{
    if (argc == 1)
    {
        Usage();
    }

    int array[argc - 1];

    createArrayFromArguments(argc, argv, array);
    sortArray(array, argc - 1);
    printArray(array, argc - 1);

    return EXIT_SUCCESS;
}

//creates an integer array from given arguments
void createArrayFromArguments(int argc, char *argv[], int outputArray[])
{
    int i;

    for (i = 0; i < argc - 1; i++)
    {
        outputArray[i] = getNumberFromString(argv[i + 1]);
    }
}

int getNumberFromString(char string[20])
{
    char *eptr = NULL;
    int number;

    number = strtol(string, &eptr, 10);

    if (*eptr != '\0')
    {
        Usage();
    }

    return number;
}

//sorts an int array using bubble ort
void sortArray(int array[], int arrayLenght)
{
    int i, j, k = 0;

    for (i = 0; i < arrayLenght - 1; i++)
    {
        for (j = 0; j < arrayLenght - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                k = array[j];
                array[j] = array[j + 1];
                array[j + 1] = k;
            }
        }
    }
}

void printArray(int array[], int arrayLength)
{
    int i;

    for (i = 0; i < arrayLength; i++)
    {
        printf("%d ", array[i]);
    }
}
