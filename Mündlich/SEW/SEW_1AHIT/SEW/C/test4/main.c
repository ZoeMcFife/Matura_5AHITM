#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trim(char str[]);
void trim2(char str[]);


int main()
{
    char test[20] = "owouwu44    ";
    char test2[20] = "ow";

    trim2(test);

    printf("%s%s\n", test, test2);



    return 0;
}

void trim(char str[])
{
    int i;
    int len = strlen(str);

    while(str[len - 1]== 32)
    {
        len--;
    }

    str[len] = '\0';

}

void trim2(char str[])
{
    int i;
    int len = strlen(str) - 1;

    for(i = len; i > 0; i--)
    {
        if(str[i] == 32)
        {
            str[i] = '\0';
        }
        else
        {
            break;
        }
    }

}
