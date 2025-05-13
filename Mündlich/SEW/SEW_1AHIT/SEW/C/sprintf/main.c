#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    /*char ascii[11] = "";

    sprintf(ascii, "%2d", 'A'); //formatierter output zu string

    puts(ascii);

    sprintf(ascii, "%s%2d", ascii, 'B');

    puts(ascii);

    char htmlTags[100][21];

    strcpy(htmlTags[0], "<html>");
    strcpy(htmlTags[1], "<head>");*/

    char test[10] = "44:45";

    char *eptr = NULL;
    char *ptr = NULL, *p = test;
    char teest[10] = "";
    long test2 = 0;
    long test3 = 0;

    test2 = strtol(test, &eptr, 10);
    while (*p)
    {
            if ( isdigit(*p) || ( (*p=='-'||*p=='+') && isdigit(*(p+1)) )) {
        // Found a number
        long val = strtol(p, &p, 10); // Read number
        printf("%ld\n", val); // and print it.
    } else {
        // Otherwise, move on to the next character.
        p++;
        puts("tesfft");
    }
    }
    printf("re %s\n", teest);

    printf("test2 %ld eptr %s test3 %ld", test2, eptr, test3);


    return EXIT_SUCCESS;
}
