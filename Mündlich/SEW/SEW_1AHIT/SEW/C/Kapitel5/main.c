#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define MAX 20
#define MIN 5

int main()
{
    //!=0 true
    //==0 false
    // == != < > >= <= !

    //x==3 && / || y==4

    long start = 0, ende = 0;
    getch();
    start = clock();
    getch();
    ende = clock();
    printf("ZEIT; %ld", ende - start);

    //noten app1111111

/*
    short grade;

    printf("Grade: ");
    scanf("%hd", &grade);

    switch (grade)
    {
    case 1:
        printf("sehr gut \n");
        break;
    case 2:
            printf(" gut\n");
            break;
    case 3:
            printf("befridigent \n");
            break;
    case 4:
            printf("genuegend \n");
            break;
    case 5:
            printf("nicht genügend \n");
            break;
    default:
        printf("no");
        break;
    }
*/
    int i = 0;
/*
    for (i = 0; i < 10; i++)
    {
        printf("%d\t", i);
    }
    printf("%d\t", i);
*/

    do
    {
         printf("%d\t", i);
         i++;
    }
    while (i < 10);


  //gerade oder ungerade
    /*long zufall = 0;

    //zufalllzahlen generator initialiesieren (nicht immer die gleichen zahlen)
    srand(time(NULL)); //srand((unsigned int)time(NULL));

    zufall = rand() % (MAX - MIN + 1) + MIN; //rand liefert eine zahl von 0 bis 32767 // 5 bis 20: abstand + 1 + min

    printf("%ld \n", zufall);

    if (zufall % 2 != 0)

        printf("ungerade");

    else
    {
        printf("gerade");
    }
*/



    return EXIT_SUCCESS;
}
