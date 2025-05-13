#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define FUNCTION_ERROR -1

void getFile(char filename[]);
void createFile();
int transfer_S_(char filename[]);
bool stringIncludes_S_(char string[]);


int main()
{
    char filename[100];

    getFile(filename);
    createFile();
    transfer_S_(filename);

    return EXIT_SUCCESS;
}

int transfer_S_(char filename[])
{
    FILE *fp;
    FILE *outputFile;

    fp = fopen(filename, "rt");

    if (fp == NULL)
    {
        printf("Error opening file:'%s'\n", filename);
        return FUNCTION_ERROR;
    }

    outputFile = fopen("output.txt", "wt");

    if (outputFile == NULL)
    {
        printf("Error opening file:'output.txt'\n");
        return FUNCTION_ERROR;
    }

    /** ------------------------------- */

    char sLine[10000];
    char temp;

    while (fgets(sLine, sizeof(sLine), fp) != NULL)
    {
        if (stringIncludes_S_(sLine))
        {
            fputs(sLine, outputFile);
        }
    }

    return EXIT_SUCCESS;
}

bool stringIncludes_S_(char string[])
{
    int i;
    for (i = 0; i < strlen(string); i++)
    {
        if (tolower(string[i]) == 's')
        {
            return true;
        }
    }

    return false;
}

void getFile(char filename[])
{
    printf("Which file do you want to use?\n");

    fgets(filename, sizeof(filename) + 1, stdin);
    filename[strcspn(filename, "\n")] = 0;

    printf("File: '%s'\n", filename);
}

void createFile()
{
    FILE *fp;

    fp = fopen("output.txt", "wt");
}

