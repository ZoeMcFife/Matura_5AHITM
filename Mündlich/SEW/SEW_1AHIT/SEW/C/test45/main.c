#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toUpper(char string[]);
void toLower(char string[]);


int main()
{
    char string[30];
//char* eptr = NULL;
    long array[10] = {0};
    int i = 0;

    gets(string);
    char *eptr = string;

    //sprintf()

    while (*eptr)
    {
        if(isdigit(*eptr) || ( (*eptr=='-'||*eptr=='+') && isdigit(*(eptr+1))))
        {
           array[i] = strtol(eptr, &eptr, 10);
            i++;
        }
        else
        {
            eptr++;
        }
    }

    for (i = 0; i < 10; i++)
    {
        printf("%ld\n", array[i]);
    }



    return 0;
}

void toUpper(char string[])
{
    int i;

    for (i = 0; i < strlen(string); i++)
    {
        if (islower(string[i]))
        {
            string[i] -= 32;
        }
    }
}

void toLower(char string[])
{
    int i;

    for (i = 0; i < strlen(string); i++)
    {
        if (isupper(string[i]))
        {
            string[i] += 32;
        }
    }
}
