#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//beispiel 2

void Usage()
{
    printf("Usage: isPrime number\n");
    exit(EXIT_FAILURE);
}

int getNumberFromString(char string[]);
bool isPrime(int number);

int main (int argc, char *argv[])
{
    if (argc != 2 )
    {
        Usage();
    }

    if (isPrime(getNumberFromString(argv[1])))
    {
        printf("%s is prime.\n", argv[1]);
    }
    else
    {
        printf("%s isn't prime.\n", argv[1]);
    }



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

bool isPrime(int number)
{
    int i;

    for (i = number - 1; i > 1; i--)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;
}
