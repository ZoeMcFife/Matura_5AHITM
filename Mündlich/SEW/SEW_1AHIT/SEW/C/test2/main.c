#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main()
{
    int n;
    time_t timeStart, timeEnd;
    char again = 'y';
    int check;
    int i;

    do
    {
        printf("Anzahl: \n");
        check = scanf("%d", &n);

        if (check == 1)
        {
            for (i = 0; i < n; i++)
            {
                printf("Press any key\n");
                getch();
            }
                        printf("benötighte zeit; ");

            time(&timeStart);

            do
            {
                time(&timeEnd);
            }
            while ((timeEnd-timeStart) != n);
            printf("%d", timeEnd - timeStart);
        }
        else
        {
            printf("fuck you\n");
        }
    again = getchar();

    }
    while (again == 'y');
    return EXIT_SUCCESS;
}
