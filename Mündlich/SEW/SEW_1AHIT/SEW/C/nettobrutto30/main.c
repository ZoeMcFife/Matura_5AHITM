#include <stdio.h>
#include <stdlib.h>

void calculatePrice(double *Netto, double Brutto, double *PriceFinal);

int main()
{
    double Netto, Brutto, PriceFinal;

    printf("Enter Brutto: \n");
    scanf("%lf", &Brutto);

    calculatePrice(Brutto, &Netto, &PriceFinal);
    printf("Final Price:    %lf \n", PriceFinal);
    printf("Netto:         %lf", Netto);

    return EXIT_SUCCESS;
}

void calculatePrice(double Netto, double *Brutto, double *PriceFinal)
{
    *Netto = Brutto / 1.2;
    *PriceFinal = Brutto * 1.3;
}
