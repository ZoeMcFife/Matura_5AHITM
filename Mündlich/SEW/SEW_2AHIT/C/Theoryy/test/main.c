#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[100];
    int dauer;
    int fehler;
    int punkte;
} spieler;

int main()
{
    char zeile[100] = "Hammer;100;10";
    char *eptr1;
    char *eptr2;
    spieler sp;
    int i;


    /*Name wird in die Struktur gespeichert*/
    i=0;
    while (zeile[i]!=';')
    {
        sp.name[i]=zeile[i];
        i++;
    }
    sp.name[i]='\0';

    /*Dauer wird in die Struktur gespeichert*/
    sp.dauer = strtol(zeile+i, &eptr1, 10);

    /*Fehler wird in die Struktur gespeichert*/
    sp.fehler = strtol(eptr1+1,  &eptr2, 10);


    printf("Name:   %s\n",sp.name  );
    printf("Dauer:  %d\n",sp.dauer );
    printf("Fehler: %d\n",sp.fehler);

    return 0;
}
