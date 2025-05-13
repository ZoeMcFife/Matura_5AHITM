#include <stdio.h>
#include <stdlib.h>

int main()
{
    //arrays - Felder - Vektoren/Matrizen

    long laufZeiten[30] = {0};
    int i;

    srand(time(NULL));

    for (i = 0; i < 30; i++)
    {
        laufZeiten[i] = rand() % (3600 - 3300 + 1) + 3300;
        printf("%ld \n", laufZeiten[i]);
    }

    return EXIT_SUCCESS;
}
