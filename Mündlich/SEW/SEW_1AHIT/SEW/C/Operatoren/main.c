#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");

    int x = 6, y = 2, a = 3, b = 4;

    printf("%d \n", (x + 1));
    printf("%d \n", ((x/y)*(a+b)));
    printf("%d\n", x < y);
    printf("%d\n", x = x + 1);
    printf("%d\n", x);
    printf("%d\n", 3);

    long zahl1 = 1, zahl2 = 3;
    double dzahl1 = 1.0, dzahl2 = 3.0, ergebnis = 0.0;

    ergebnis = (double)zahl1 / dzahl2 + 1.0; //(cast)
    printf("Ergebnis: %lf \n", ergebnis);

    return EXIT_SUCCESS;
}
