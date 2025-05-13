#include <stdio.h>
#include <stdlib.h>

#define A 10
#define MAX(A,B) ((A) > (B) ? A : B)
#define MULT(X,Y) ((X)*(Y))
#define SQAURE(X) ((X)*(X))

int max(int a, int b)
{
    return ((a) > (b) ? a : b);
}

int main()
{
    int feld[A];
    feld[0] = 1;

    int a = 3, b = 4;

    #define a 4
    printf("%d\n", __LINE__);
    #undef a
    printf("%s\n", __FILE__);
    return 0;
}

