#include <stdio.h>
#include <stdlib.h>

void Test(int a);
long factorial(long n);
long ziffernSumme(long n);

int main()
{
    printf("%ld\n", factorial(3));
    printf("%ld\n ", ziffernSumme(28));


    return EXIT_SUCCESS;
}

long ziffernSumme(long n)
{
    if(n == 0)
    {
        return 0;
    }

    return n % 10 + ziffernSumme(n/10);
}

void Test(int a)
{
    if(a > 10)
    {
        return;
    }

    Test(a + 1);
    printf("%d \t", a);

    return;
}

long factorial(long n)
{
    if (n == 1)
    {
        return;
    }

    return n*factorial(n-1);
}

