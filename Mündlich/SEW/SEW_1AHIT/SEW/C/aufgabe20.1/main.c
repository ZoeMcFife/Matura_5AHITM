#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Title:        argument counter
//Description:  checks if an argument is a long
//Last Change:  2021/06/08
//Author:       Leonard Bunea

void Usage(char progName[]);


int main(int argc, char *argv[])
{
    int i;
    long sum = 0, temp = 0;
    int count = 0;
    char *eptr = NULL;

    if(argc == 1)
    {
        Usage(argv[0]);
    }
    else
    {
        for (i = 1; i < argc; i++)
        {
            temp = strtol(argv[i], &eptr, 10);

            if(*eptr != '\0')
            {
                continue;
            }
            else if(isdigit(temp) == 0)
            {
                sum += temp;
                count++;
            }
        }

        printf("SUM:\t%ld\nCOUNT:\t%d out of %d\n", sum, count, argc);
    }

    return EXIT_SUCCESS;
}

void Usage(char progName[])
{
    printf("USAGE %s ARGUMENT1 [ARGUMENT2 [ARGUMENT3] . . .] \n", progName);
    exit(EXIT_FAILURE);
}
