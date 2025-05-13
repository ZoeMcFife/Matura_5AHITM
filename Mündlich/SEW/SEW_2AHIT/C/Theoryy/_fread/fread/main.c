#include <stdio.h>
#include <stdlib.h>

#define DATEINAME "datei01.txt"
#define DATEINAMEBIN "datei02.zozopie"

struct daten
{
    int nr;
    char name[20];
};

void datenschreiben(struct daten daten[])
{
    FILE *fp;

    int i;

    fp = fopen(DATEINAME, "wt");
    for (i = 0; i < 10; i++)
    {
        fprintf(fp, "%d,", daten[i].nr);
        fprintf(fp, "%s\n", daten[i].name);

    }

    fclose(fp);
}

void datenlesen(struct daten daten[])
{
    FILE *fp;

    int i;
    char zeile[100];
    char *eptr;

    fp = fopen(DATEINAME, "rt");
    for (i = 0; i < 10; i++)
    {
        fgets(zeile, sizeof(zeile), fp);

        daten[i].nr = strtol(zeile, &eptr, 10);

        fgets(zeile, sizeof(zeile), fp);
        //zeile[strlen(zeile) - 1] =
    }

    fclose(fp);
}

void datenausgeben(struct daten daten[])
{
    int i;

    for (i = 0; i < 10; i++)
    {
        printf("%d %s; \n", daten[i].nr, daten[i].name);
    }
}

void datenschreibenBIN(struct daten daten[])
{
    FILE *fp;

    fp = fopen(DATEINAMEBIN, "wb");

    fwrite(daten, sizeof(struct daten), 10, fp);

    fclose(fp);
}

void datenlesenBIN(struct daten daten[])
{
    FILE *fp;

    fp = fopen(DATEINAMEBIN, "rb");

    fread(daten, sizeof(struct daten), 10, fp);

    fclose(fp);
}




int main()
{
    struct daten daten[10]; //= {{5, "etst"}, {6, "OwO"},{7, "Imprea"},{53, "OwO"},{1, "TOwOm"},{2, "Ara"},{2, "UWU"},{2, "OwO"},{4, "OwO"},{5, "Zozopie"},};

    //datenschreibenBIN(daten);

    datenlesenBIN(daten);

    datenausgeben(daten);

    struct daten person3;

    FILE *fp;

    fp = fopen(DATEINAMEBIN, "rb");
    fseek(fp, sizeof(struct daten)*2, SEEK_SET);
    fread(&person3, sizeof(struct daten), 1, fp);

    printf("%s, %d\n", person3.name, person3.nr);

    fclose(fp);

    /*
    datenschreiben(daten);
    datenlesen(daten);
    daten[0].nr++;
    datenausgeben(daten);
    */

    return 0;
}
