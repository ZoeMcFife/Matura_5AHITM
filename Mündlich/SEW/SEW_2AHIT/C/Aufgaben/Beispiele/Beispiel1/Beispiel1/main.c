#include <stdio.h>
#include <stdlib.h>

#define FUNCTION_ERROR -1

void getFile(char filename[]);
int getCharCount(char filename[]);
int getLineCount(char filename[]);

int main()
{
    char filename[100];

    getFile(filename);
    printf("Char Count: %d\n", getCharCount(filename));
    printf("Line Count: %d\n", getLineCount(filename));



    return EXIT_SUCCESS;
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
        return FUNCTION_ERROR;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        count++;
    }

    fclose(fp);

    return count;
}

int getCharCount(char filename[])
{
    int count = 0;

    FILE *fp;

    fp = fopen(filename, "rt");

    if (fp == NULL)
    {
        printf("Error opening file:'%s'\n", filename);
        return FUNCTION_ERROR;
    }

    while (!feof(fp))
    {
        fgetc(fp);
        count++;
    }

    fclose(fp);

    return count;
}


void getFile(char filename[])
{
    printf("Which file do you want to use?\n");

    fgets(filename, sizeof(filename) + 1, stdin);
    filename[strcspn(filename, "\n")] = 0;

    printf("File: '%s'\n", filename);
}
