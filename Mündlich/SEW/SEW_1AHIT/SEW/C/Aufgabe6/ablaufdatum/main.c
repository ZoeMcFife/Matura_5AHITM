#include <stdio.h>
#include <stdlib.h>

//Title:        Ablaufdatum
//Author:       Leonard Bunea
//Description:  calculates when a medicine expires
//Last Change:  2020/01/15

int main()
{
    float milligramConcentration;
    float critialMilligramConcentration;
    int maxMonthsForMedicine = 0;
    float monthlyMilligramReductionProcent;

    char keepProgramRunning = 'y';

    do
    {
        printf("Enter current concentration of the medicine in mg:\n");
        scanf("%f", &milligramConcentration);
        printf("Enter minimum amount of medicine in mg:\n");
        scanf("%f", &critialMilligramConcentration);
        printf("Enter monthly reduction in medicine in %:\n");
        scanf("%f", &monthlyMilligramReductionProcent);

        //calculates months, by reducing milligrams with given procentage
        while (milligramConcentration > critialMilligramConcentration)
        {
            milligramConcentration -= (monthlyMilligramReductionProcent * milligramConcentration / 100);
            maxMonthsForMedicine++;
        }

        printf("You can use this medicine for %d months. \n", maxMonthsForMedicine);

        printf("\n");
        printf("Do you want to continue? (y / n) \n");
        fflush(stdin);
        keepProgramRunning = getche();
        printf("\n");
    }
    while (keepProgramRunning == 'y' ||keepProgramRunning == 'Y');


    return EXIT_SUCCESS;
}
