#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;

    ///Datei öffnen
    fp = fopen("Datei.txt", "wb"); /// c://..... "//" /// "w" erstellt / überschreibt ... "a" append /// "wb" für Binary "wt" für text

    /// wt  at  rt      r+t w+t a+t

    if (fp == NULL)
    {
        printf(stderr, "fopen Error \n");
        return EXIT_FAILURE;
    };

    /// Schreiben
    fprintf(fp, "Hallo\n");
    fprintf(fp, "rawr\n");

    ///Datei schließen
    fclose(fp);


    ///----------------------------------------------------------


    fp = fopen("Datei.txt", "rt");

    /// Lesen zeichenweise
    /*char c;

    while ((c = fgetc(fp)) != EOF)
    {
           printf("gelsesen wurde: %c\n", c);
    }*/

    ///Lesen Zeileweise

    char zeile[10];

    while (fgets(zeile, sizeof(zeile), fp) != NULL)
        printf("EEEP %s\n", zeile);


    fclose(fp);

    return 0;
}
