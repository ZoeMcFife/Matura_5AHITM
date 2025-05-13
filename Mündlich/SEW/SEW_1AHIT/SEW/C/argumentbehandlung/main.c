#include <stdio.h>
#include <stdlib.h>

void Usage(char progName[]);

int main(int argc, char *argv[])
{
    int i;

    if(argc != 1)
    {
        Usage(argv[0]);
    }

    printf("ARGC:\t%d\n", argc);
    printf("Program Name: %s\n", argv[0]);

    for(i = 0; i < argc; i++)
    {
        printf("argv[%d] %s \n", i, argv[i]);
    }

    return EXIT_SUCCESS;
}

//je nach aufgaben stellung
void Usage(char progName[])
{
    printf("USAGE %s ARGUMENT0 [ARGUMENT1] [ARGUMENT2] . . . \n", progName);
    exit(EXIT_FAILURE);
}
