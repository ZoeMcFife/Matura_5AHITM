#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char taco[20] = "Taco";

    char name[20] = "";
    char lastName[20] = "";

    printf("ERNTETR ur NAME \n");
    gets(name);
    printf("enteret ur ozherte NAME \n");
    gets(lastName);

    strcat(name, " ");
    strcat(name, lastName);
    strcat(name, " ");
    strcat(name, taco);

    printf("ur naem gege: %s \n", name);

    return 0;
}
