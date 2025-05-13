#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//title: Strings und Stringfunktionen

int main()
{
    char vorname[20] = "Zoe";
    char nachname[20] = "Bunea";
    char vorname2[20] = "Zoe";
    char name[40] = "";

    printf("%s\n", vorname);
    printf("%s\n", nachname);
    strcpy(name, vorname); //    strcpy(Dest, Source);



    //strings anhängen
    strcat(name, " ");
    strcat(name, nachname);

    printf("%s\n", name);

    //länge von strings
    printf("len: %ld\n", strlen(name));

    //vergleiche zwei strings:  strcmp(s1, s2) 0 wenn gleich 1 wenn s1 > s2, -1 wenn s1<s2
    printf("COMPARE %d \n", strcmp(vorname, vorname2));

    if(strcmp(vorname, vorname2) == 0)
    {
        printf("Gleiche Vornamen \n");
    }
    else
    {
        printf("nein \n");
    }

    printf("Ihr vorname:");
    gets(vorname2);
    fgets(vorname, sizeof(vorname), stdin);
    if(vorname[strlen(vorname)-1] == '\n')
    {
        vorname[strlen(vorname)-1] = 0;
    }

    if (stricmp(vorname, "test") == 0)
    {
        printf("SADNESS\n");
    }
    puts(vorname);
    printf("%s\n", vorname2);
    puts(vorname2);


    return EXIT_SUCCESS;
}
