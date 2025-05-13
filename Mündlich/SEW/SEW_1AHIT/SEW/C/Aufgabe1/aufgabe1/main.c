//Title: Formated Output
//Author: Leonard Bunea
//Description: Formatierte Ausgabe von Zahlen und Wörtern
//Last change: 2020/11/24

#include <stdio.h>
#include <stdlib.h>


//Hauptprogramm
int main()
{
    //Variablendeklarationen

    char wort[]="Elektrotechnik";
    float a=(float)20.0/6.0;
    double b=-200.0/6.0;

    //Formatierte Ausdrucken
    printf("<123456789012345678901234567890>\n");
    printf("<%22s>\n", wort);
    printf("<%-19.7s>\n");
    printf("<%c%-14s%-8c>\n", '"', wort, '"');
    printf("<\\%-22s>\n", wort);
    printf("<%9c%12s%c>\n",'%', wort, '%');
    printf("<%010.3f>\n", a);
    printf("<%+011.1e>\n", a);
    printf("<%011.1E>\n", b);
    printf("<%+15.6f>\n", a);
    printf("<%17.10f>\n", b);

    return EXIT_SUCCESS;
}
