#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**********************************************************************************************************
*  Sortieralgorithmus: Bubblesort
*  Parameter: a .... zu sortierendes int-Feld
*             gr ... Groesse des Feldes (Anzahl der Elemente)
**********************************************************************************************************/
void bubbleSortInt(int a[], int gr)
{
    int sortiert,i,tmp;
    do
    {
        sortiert = 1;
        for (i=1; i<gr; i++)
        {
            if (a[i-1]>a[i])
            {
                tmp=a[i-1];
                a[i-1]=a[i];
                a[i]=tmp;
                sortiert=0;
            }
        }
    }
    while (!sortiert);
}

/**********************************************************************************************************
*  Feld mit Zufallswerten initialisieren
*  Parameter: a .... zu initialisierendes  int-Feld
*             gr ... Groesse des Feldes (Anzahl der Elemente)
**********************************************************************************************************/
void initRandomInt(int a[], int gr)
{
    int i;
    for(i=0; i<gr; i++)
    {
        a[i]=rand()%100;
    }
}


/**********************************************************************************************************
*  Feld mit Zufallswerten ausgeben
*  Parameter: a .... auszugebendes  int-Feld
*             gr ... Groesse des Feldes (Anzahl der Elemente)
**********************************************************************************************************/
void outputInt(int a[], int gr)
{
    int i;
    printf("%d Elemente:\n",gr);
    for(i=0; i<gr; i++)
    {
        printf("%3d\n",a[i]);
    }
    printf("==================\n");
}

/**********************************************************************************************************
*  Main:
*  Feld mit verschiedenen Groessen anlegen, initialisieren, sortieren
**********************************************************************************************************/
int main(void)
{
    int *feld;
    int anzahl;

    srand(time(NULL));

    /********Größe des Feldes bestimmen*******/
    anzahl = rand()%8+3; //Zufallszahl im Bereich von 3 bis 10

    /**************Feld anlegen***************/
    feld=(int *)malloc(sizeof(int)*anzahl);

    if (feld==NULL)
    {
        printf("Feld mit %d int-Elementen konnte nicht angelegt werden\n",anzahl);
        return EXIT_FAILURE;
    }


    /**************Werte initialisieren*******/
    initRandomInt(feld,anzahl);

    /**************Werte ausgeben*************/
    outputInt(feld,anzahl);

    /**************Werte sortieren************/
    bubbleSortInt(feld,anzahl);

    /**************Werte ausgeben*************/
    outputInt(feld,anzahl);

    return EXIT_SUCCESS;
}
