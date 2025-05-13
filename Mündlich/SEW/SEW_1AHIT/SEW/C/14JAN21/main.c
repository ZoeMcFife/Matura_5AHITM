#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define MAX 1000000
#define MIN 1

//anzahl einlesen im bereich 100000 und 300000
//Anzahl 2 stelliger zufallszahlen erzeugen und bestimmen bei wie vielen die ziefernsumme 10 ist
int main()
{
    long anzahl = 0;
    char nochmal = 'j';
    int i, counter = 0;
    int zufallsZahl, ziffernsumme;

    srand(time(NULL));

    do
    {
        printf("Anzahl:  ");
        scanf("%ld", &anzahl);

        if (anzahl < 100000 || anzahl > 300000)
        {
            printf("Error; Zahl auﬂerhalb des Werte bereiches; \n");
        }
        else
        {
            counter = 0;
            for (i = 0; i < anzahl; i++)
            {
                zufallsZahl = rand() % (MAX - MIN + 1) + MIN;

                while (zufallsZahl > 1)
                {

                }

                if ((einerStelle + zehnerStelle) == 10)
                {
                    counter++;
                }
            }

            printf("So viele Zahlen hatten die Ziffernsumme 10: %d \n", counter);
        }
        printf("Nochmals durfuehren? j|n \n   ");
        nochmal = getch();
    }
    while (nochmal == 'j' || nochmal == 'J');

    return EXIT_SUCCESS;
}
