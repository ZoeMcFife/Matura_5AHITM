#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define MIN 'A'
#define MAX 'Z'

//anzahl einlesen im bereich 5 < anzahl < 100
//anzahl groﬂbuchstaben erzeugen, dem benutzer anzeiger, und warten, bis er diese richtig eingegeben hat. dann n‰chster buchstabe. dann zeit ausgeben

int main()
{
    int anzahl = 0;
    char nochmal = 'j';
    int i;
    char zufallsBuchstabe;
    char currentChar = 'a';
    long start, end;

    srand(time(NULL));
    do
    {
        printf("Anzahl:  ");
        scanf("%d", &anzahl);

        if (anzahl <= 5 || anzahl > 100)
        {
            printf("Error; Zahl auﬂerhalb des Werte bereiches; \n");
        }
        else
        {
            start = clock();
            for (i = 0; i < anzahl; i++)
            {
                zufallsBuchstabe = rand() % (MAX - MIN + 1) + MIN;

                do
                {
                    printf("%c \n", zufallsBuchstabe);
                    currentChar = getch();
                }
                while (currentChar != zufallsBuchstabe);
            }
            end = clock();
            printf("ZEIT: %d\n", end - start);
        }

        printf("Nochmals durfuehren? j|n \n   ");
        nochmal = getch();
    }
    while (nochmal == 'j' || nochmal == 'J');

    return EXIT_SUCCESS;
}
