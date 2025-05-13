#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//beispiel 1

void Usage()
{
    printf("Usage: power number\n");
    exit(EXIT_FAILURE);
}

int getNumberFromString(char string[]);

int main (int argc, char *argv[])
{
    int number = 0;

    if (argc != 2 )
    {
        Usage();
    }

    number = getNumberFromString(argv[1]);
    double power = pow((double)number, (double)number);
    printf("%d hoch %d = %.0f", number, number, power);

    return EXIT_SUCCESS;
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
