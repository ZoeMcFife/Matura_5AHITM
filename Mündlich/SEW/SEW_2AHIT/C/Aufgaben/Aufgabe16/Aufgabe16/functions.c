#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "library.h"

void Usage()
{
    printf("wc.exe file1 [file2] ...");
    return EXIT_FAILURE;
}

int countCharacters(char *filename)
{
    FILE *fp;
    int characterCount = 0;
    char temp;

    fp = fopen(filename, "rt");

    if (fp == NULL) return -1;

    while (temp != EOF)
    {
        temp = fgetc(fp);
        characterCount++;
    }

    fclose(fp);

    return characterCount;
}

int countLines(char *filename)
{
    FILE *fp;
    int lineCount = 1;
    char temp;

    fp = fopen(filename, "rt");

    if (fp == NULL) return -1;

    while (!feof(fp))
    {
        temp = fgetc(fp);

        if (temp == '\n')
        {
            lineCount++;
        }
    }

    fclose(fp);

    return lineCount;
}

int countWords(char *filename)
{
    FILE *fp;
    int wordCount = 0;
    char currentChar = ' ';
    char previousChar = ' ';

    fp = fopen(filename, "rt");

    if (fp == NULL) return -1;

    while (currentChar != EOF)
    {
        currentChar = fgetc(fp);

        if ( (isalnum(previousChar) ) && (!isalnum(currentChar) && currentChar != '-') )
        {
            wordCount++;
        }

        previousChar = currentChar;
    }

    fclose(fp);

    return wordCount;
}
