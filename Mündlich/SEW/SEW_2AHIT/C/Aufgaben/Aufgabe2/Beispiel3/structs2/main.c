#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int tag;
    int monat;
    int jahr;
} Datum;


typedef struct
{
    char titel[100];
    int seiten;
    Datum datum;

} Buch;

void ausgabeBuch(Buch b)
{
    printf("Titel: %s\nSeiten: %d\nDAtum: %d.%d.%d", b.titel, b.seiten, b.datum.tag, b.datum.monat, b.datum.jahr);
}

void Buchseitenveraendern(Buch *b)
{
    srand(time(NULL));

    b->seiten += rand() % 2000; //(*b).seiten
}

int main()
{
    Buch b1;

    b1.seiten = 123;
    strcpy(b1.titel, "OWO");
    b1.datum.jahr = 3307;
    b1.datum.monat = 3;
    b1.datum.tag = 1;
    Buchseitenveraendern(&b1);
    ausgabeBuch(b1);



    return 0;
}
