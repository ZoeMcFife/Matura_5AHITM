
//Header Datei stdio.h inkludieren
//Input Output
//alle befehle, die mit # beginnen, sind Präprozzesoranweisungen

#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592
//io --> Standard Input Output
//main.c -> Präprozzesor -> Compiler (*.o) --> Linker -> *.exe


//Hauptprogramm
int main()
{
    //unsigned --> Keine negativen Werte
    char zeichen = 0;       //1 Byte -128 +128
    short kleineZahl = 2500050;   //2 Byte
    int zahl = 255;           //4 Byte
    long grossezahl;        //4 Byte

    float glZahl = (float)2545.5568;
    double glZahlDouble = 1004.678;
    //float, double, long double --> Gleitkommazahlen


    //%d int ; %ld long ; %c Zeichen (Char) ; %f float ; %lf double ; %hd short ; %e expoential Schreibweise

    printf("Hello world!\n");
    printf("Hello sunbun\n");
    printf("This is pi: %lf\n", PI);

    zeichen = 'Z';
    printf("Zeichen: %c\n", zeichen);
    printf("Zeichenwert: %d\n", zeichen);
    printf("Kleine Zahl: %hd\n", kleineZahl);
    printf("grose Zahl: %ld", grossezahl);
    printf("%c\t%i\t%f\n", zeichen, zahl, glZahl);

    printf("%20c\n", zeichen);
    printf("%20hd\n", kleineZahl);
    printf("%+20hd\n", kleineZahl);
    printf("%-20hd%20.1lf\n", kleineZahl, glZahlDouble);
    printf("%e\n", glZahl);
    printf("Zahl: %X\n", zahl);
    printf("Zahl: %o\n", zahl);
    printf("%%\t \\\a \a \r test \n");

    return EXIT_SUCCESS;
}
