#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mySTRCAT(char dest[], char add[]);

int main()
{
    char string1[20] = "fucking gheafas";
    char string2[20] = " etet at";

    mySTRCAT(string1, string2);
    //strcat(string1, string2);

    puts(string1);

    return EXIT_SUCCESS;
}

void mySTRCAT(char dest[], char add[])
{
    int len = strlen(dest);
    int i;

    for(i = len; i < 40; i++)
    {
        dest[i] = add[i-len];
    }

}
