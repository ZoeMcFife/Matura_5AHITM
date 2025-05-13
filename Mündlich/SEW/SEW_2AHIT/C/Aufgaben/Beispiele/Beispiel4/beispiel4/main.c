#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void getFile(char filename[100]);
void changeCase(char filename[100]);
int getCharCount(char filename[]);

int main()
{
    char filename[100];

    getFile(filename);
    changeCase(filename);

    return EXIT_SUCCESS;
}

void changeCase(char filename[100])
{
    FILE *fp;

    fp = fopen(filename, "rt");

    if (fp == NULL)
    {
        printf("Error opening file:'%s'\n", filename);
        return;
    }

    char file[getCharCount(filename)];

    char temp;
    int i = 0;

    while (!feof(fp))
    {
        temp = fgetc(fp);

        if (islower(temp))
        {
            temp = toupper(temp);
        }
        else if (isupper(temp))
        {
            temp = tolower(temp);
        }

        if (!feof(fp))
            file[i] = temp;

        i++;
    }

    fclose(fp);

    fp = fopen(filename, "wt");

    if (fp == NULL)
    {
        printf("Error opening file:'%s'\n", filename);
        return;
    }

    fputs(file, fp);

    fclose(fp);
}

void getFile(char filename[])
{
    printf("Which file do you want to use?\n");

    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = 0;

    printf("File: '%s'\n", filename);
}

int getCharCount(char filename[])
{
    int count = 0;

    FILE *fp;

    fp = fopen(filename, "rt");

    if (fp == NULL)
    {
        printf("Error opening file:'%s'\n", filename);
        return;
    }

    while (!feof(fp))
    {
        fgetc(fp);
        count++;
    }

    fclose(fp);

    return count;
}
