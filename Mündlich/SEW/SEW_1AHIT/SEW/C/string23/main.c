#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long mystrlen(char string[]);

int main()
{
    char string[] = "Zoe uwu";
    char string2[101] = "";
    long number = 0;
    char vorname[20] = "test";
            char reverse[20] = "test";


    gets(string);

    //strcpy(string2, string);

    //string[strlen(string) - 1];

    printf("%s is %ld", string, mystrlen(string));
    int i;
    for(i = 0; i<strlen(vorname); i++)
    {
        reverse[i] = vorname[strlen(vorname)- i -1];
    }
    reverse[i] = 0;
    printf("%s", reverse);

    return EXIT_SUCCESS;
}

long mystrlen(char string[])
{
    long len = 0;
    int i = 0;

    while(string[i] != '\0')
    {
        if(string[i] != '\0')
        {
            len++;
        }
        i++;
    }

    return len;

}
