#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Hello world!\n");

    int lamps = (int)(pow(2, 6) + pow(2, 3));
    //0100 1000
    int i;

   // lamps = lamps | (int)(pow(2, 2)+pow(2, 7)) ;

    for (i = 7; i >= 0; i--)
    {
        if ((lamps & (1 << i)) != 0)
            printf("1");
        else
            printf("0");
    }

    return 0;
}
