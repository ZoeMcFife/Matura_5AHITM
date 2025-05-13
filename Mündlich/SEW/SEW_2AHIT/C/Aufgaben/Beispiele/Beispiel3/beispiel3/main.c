#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void getFile(char filename[100]);
int getLongs(char string[], long output[]);
int readAllNumbersInFile(char filename[], long outputArray[]);
int getLineCount(char filename[]);
void outputNumbers(long numberArray[], int length);

int main()
{
    char filename[100];
    long numberArray[20000];
    int length;

    getFile(filename);

    length = readAllNumbersInFile(filename, numberArray);

    outputNumbers(numberArray, length);

    return EXIT_SUCCESS;
}

int readAllNumbersInFile(char filename[], long outputArray[])
{
    FILE *fp;

    fp = fopen(filename, "rt");

    if (fp == NULL)
    {
        printf("Error opening file:'%s'\n", filename);
        return;
    }

    char currentLine[1000] = "";
    char fileFlat[60000] = "";

    while (fgets(currentLine, sizeof(currentLine), fp) != NULL)
    {
        strcat(fileFlat, currentLine);
    }

    int count = getLongs(fileFlat, outputArray);

    fclose(fp);

    return count;
}

void getFile(char filename[100])
{
    printf("Which file do you want to use?\n");

    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = 0;

    printf("File: '%s'\n", filename);
}


void outputNumbers(long numberArray[], int length)
{
    int i;
    int count = 0;
    int positiveCount = 0;

    for (i = 0; i < length; i++)
    {
        count++;

        if (numberArray[i] >= 0)
        {
            positiveCount++;
        }
    }

    printf("There are %d numbers; %d are positive\n", count, positiveCount);
}

int getLongs(char string[], long output[])
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

    return i;
}

int getLineCount(char filename[])
{
    int count = 0;
    char line[10000];

    FILE *fp;

    fp = fopen(filename, "rt");

    if (fp == NULL)
    {
        printf("Error opening file:'%s'\n", filename);
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        count++;
    }

    fclose(fp);

    return count;

}
