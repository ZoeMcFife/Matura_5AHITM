#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*** Strukturdefinition f�r die gespeicherten Daten ******************************************************/
typedef struct
{
    char name[100];
    int dauer;
    int fehler;
    int punkte;
} spieler;


/**********************************************************************************************************
*  Sortieralgorithmus: Bubblesort - Feld wird nach "punkte"-Wert absteigend sortiert
*  Parameter: a .... zu sortierendes spieler-Feld
*             gr ... Groesse des Feldes (Anzahl der Elemente)
**********************************************************************************************************/
void bubbleSortSpieler(spieler a[], int gr)
{
    int sorted, i;

    spieler tmp;

    do
    {
        sorted = 1;
        for (i = 1; i < gr; i++)
        {
            if (a[i-1].punkte < a[i].punkte)
            {
                tmp = a[i-1];
                a [i-1] = a[i];
                a[i] = tmp;
                sorted = 0;
            }
        }
    }
    while (!sorted);
}

/**********************************************************************************************************
*  Feld mit Zufallswerten initialisieren
*  Parameter: a .... zu initialisierendes  int-Feld
*             gr ... Groesse des Feldes (Anzahl der Elemente)
**********************************************************************************************************/
void initRandomSpieler(spieler a[], int gr)
{
    int i;
    for(i=0; i<gr; i++)
    {
        a[i].dauer=rand()%90+10;
        a[i].fehler=rand()%10;
        switch(rand()%5)
        {
        case 4:
            strcpy(a[i].name,"Jakob");
            break;
        case 3:
            strcpy(a[i].name,"Sabine");
            break;
        case 2:
            strcpy(a[i].name,"Sandra");
            break;
        case 1:
            strcpy(a[i].name,"David");
            break;
        case 0:
            strcpy(a[i].name,"Lukas");
            break;
        }

        /**** Formel zur Berechnung der Punkte anpassen ****/
        a[i].punkte = (int)((1.0 / (a[i].fehler + a[i].dauer / 10)) * 100);

    }
}


/**********************************************************************************************************
*  Feld mit Zufallswerten ausgeben
*  Parameter: a .... auszugebendes  spieler-Feld
*             gr ... Groesse des Feldes (Anzahl der Elemente)
**********************************************************************************************************/
void outputSpieler(spieler a[], int gr)
{
    int i;
    printf("%d Elemente:\n",gr);
    printf("Name       Fehler Dauer Punkte\n");
    for(i=0; i<gr; i++)
    {
        printf("%-10.10s %5d %5d %5d \n",a[i].name,a[i].fehler,a[i].dauer,a[i].punkte);
    }
    printf("==============================\n");
}

/**********************************************************************************************************
*  Main:
*  Feld mit verschiedenen Groessen anlegen, initialisieren, sortieren
**********************************************************************************************************/
int main(void)
{
    spieler *feld;
    int anzahl;

    srand(time(NULL));

    /********Gr��e des Feldes bestimmen*******/
    anzahl = rand()%8+3; //Zufallszahl im Bereich von 3 bis 10

    /**************Feld anlegen***************/
    feld=(spieler *)malloc(sizeof(spieler)*anzahl);

    if (feld==NULL)
    {
        printf("Feld mit %d Elementen konnte nicht angelegt werden\n",anzahl);
        return EXIT_FAILURE;
    }


    /**************Werte initialisieren*******/
    initRandomSpieler(feld,anzahl);

    /**************Werte ausgeben*************/
    outputSpieler(feld,anzahl);

    /**************Werte sortieren************/
    bubbleSortSpieler(feld,anzahl);

    /**************Werte ausgeben*************/
    outputSpieler(feld,anzahl);

    return EXIT_SUCCESS;
}
