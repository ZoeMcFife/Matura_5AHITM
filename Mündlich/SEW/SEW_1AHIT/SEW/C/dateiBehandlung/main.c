#include <stdio.h>
#include <stdlib.h>

int main()
{
    //File * anlegen (stream)
    //datei öffnen (fopen)
    //daten lesen/schreiben (fgetc, fgets, fread, fputc, fputs, fwrite, fprintf)
    //datei schließen (fclose)

    FILE *fp = NULL;
    char character = 0;
    char zeile[1024] = "";
    fp = fopen("c:\\users\\redcr\\downloads\\tagebuch.txt", "r"); //Mode: r, w, a, r+, w+, a+, t, b
    if (fp == NULL)
    {
        printf("Error\n");
    }
    else
    {
        /*while ((character=fgetc(fp)) != EOF) //zeichenweises Lesen einer Datei
        {
            printf("%c", character);
        }*/

        fprintf(fp, "hot hot hot hot hoth htohtohtohtohtohothotoh\n cuuuuuummmmmmmerrrrr\n");
        while(fgets(zeile, sizeof(zeile), fp) != NULL)
        {
            printf("%s", zeile);
        }
    }
    if (fp != NULL)
        fclose(fp);

    fp = fopen("c:\\users\\redcr\\downloads\\tagebuch.txt", "a");
    if (fp = NULL)
    {
        printf("Ewoor");
    }
    else
    {
       fputc('*', fp); //zeichenweises Schreiben in eine Datei

    }
    if (fp != NULL)
        fclose(fp);

    return EXIT_SUCCESS;
}
