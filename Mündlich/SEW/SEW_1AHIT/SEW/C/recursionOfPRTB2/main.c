#include <stdio.h>
#include <stdlib.h>

void prtb2(int i);
long sumlong n);

int main()
{
    printf("%ld \n", sum(10));

    prtb2(8);

    return EXIT_SUCCESS;
}

void prtb2(int i)
{
  if ( i >= 2 )
    prtb2 ( i / 2 );
  printf ( "%d", i % 2 );
}

long sum(long n)
{
    if (n == 1)
        return 1;
    else
        return n + sumn - 1);
}
