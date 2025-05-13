#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;  // Für den Zugriff auf eine Datei wird ein Filepointer (=File-Stream) deklariert.
    int i;

    // Datei "ausgabe.txt" wird zum Schreiben ("w") im Textmodus ("t") geöffnet.
    // falls sie bereits existiert wird sie überschrieben
    // falls sie noch nicht existiert wird sie neu angelegt
    fp = fopen ("ausgabe.txt","wt");

    // Wenn die Datei nicht geändert werden kann bzw. wenn keine Schreibberechtigung besteht,
    // liefert hier fopen() NULL zurück
    if (fp == NULL)
    {
        printf("Fehler beim Oeffnen der Datei\n");
        return EXIT_FAILURE;
    }

    // In die geöffnete Datei wird nun hineingeschrieben
    fprintf(fp,"Inhalt:\n");
    for (i=1; i<10; i++)
    {
        fprintf(fp,"Test %d\n",i);
    }

    // File-Stream wird wieder geschlossen. Erst danach ist sichergestellt, dass alles in den
    // File-Stream geschriebene auch wirklich in die Datei geschrieben wurde.
    fclose(fp);


    printf("Datei \"ausgabe.txt\" wurde geschrieben.\n");
    return EXIT_SUCCESS;
}
