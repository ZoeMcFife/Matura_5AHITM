#include <stdio.h>
#include <stdlib.h>

void output(long n);

int main()
{
    long num = 10;
    output(num);

    return 0;
}

void output(long n)
{
    if (n > 1024)
    {
        return;
    }

    output(n*2);

    printf("%ld \n", n);
}
