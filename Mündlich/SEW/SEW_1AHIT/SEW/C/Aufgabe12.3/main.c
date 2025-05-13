#include <stdio.h>
#include <stdlib.h>

void prtb2(int i);

int main()
{
    prtb2(5);
    printf("\n");
    prtb2(10);
    printf("\n");
    prtb2(255);

    //Die Funktion prtb2() tut einen Integer in Binär umwandeln

    return EXIT_SUCCESS;
}

void prtb2(int i)
{
  if ( i >= 2 )
    prtb2 ( i / 2 );
  printf ( "%d", i % 2 );
}
