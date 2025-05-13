#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char temp[27] = "";
    char *eptr = NULL;
    long num = 0;

    gets(temp);

    num = strtol(temp, &eptr, 10);

    printf("NUM: %ld\teptr: %s\n\n", num, eptr);


    num = strtol(&temp[10], &eptr, 10);

    printf("NUM: %ld\teptr: %s", num, eptr);

    return 0;
}
