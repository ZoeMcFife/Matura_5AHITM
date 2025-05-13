#include <stdio.h>
#include <stdlib.h>

double berechneUmfang(double radius);

int main()
{

    double radius = 0.0, umfang = 0.0;
    printf("Radius!!!! \n", radius);
    scanf("%lf", &radius);
    umfang = berechneUmfang(radius);
    printf("%lf", umfang);

    return EXIT_SUCCESS;
}

double berechneUmfang(double radius)
{
    double u = 0.0;

    u = 2*radius*3.141;

    return u;
}


/*    int i = 0, j = 0, summe = 0;
    double avg = 0.0;

*/

/*
    i = i + 1;
    i++;//Postfix-Notation
    i+=1;
    i+=5;

    ++i; //Prefix-Notation
    */
/*
    for (i = 0; i < 10; i++)
    {
        printf("%d \n", i);
        summe+=i;
    }

    avg = (double)summe / i;

    printf("AVG %lf", avg);
*/
    /*if (i == 10)
    {
        printf("zehn \n");
    }
    else
    {
        printf("nicth zehn \n");
    }

    (i == 10) ? printf("zehn\n") : printf("nicht zehn\n");

    printf("Size of i: %ld Bytes\n", sizeof(i));
    printf("Size of long: %ld Bytes\n", sizeof(long));
    printf("Size of char: %ld Bytes\n", sizeof(char));
    printf("Size of float: %ld Bytes\n", sizeof(float));
    printf("Size of double: %ld Bytes\n", sizeof(double));

    printf("inhalt von i: %d\n", i);
    printf("Speicheradresse von i: %p\n", &i); //& --> speicheradresse
*/
