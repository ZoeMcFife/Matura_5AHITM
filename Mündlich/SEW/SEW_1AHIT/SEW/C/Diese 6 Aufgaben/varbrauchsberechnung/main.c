#include <stdio.h>
#include <stdlib.h>

//Title: Fuel Usage
//Author: Leonard Bunea
//Description: calculates average fuel usage
//Last change: 2020/12/01

int main()
{
    //Variable declarations
    float startkm;
    float endkm;
    float fuel;

    float fuelPer100km;

    //User input
    printf("Enter kilometers at start: ");
    scanf("%f", &startkm);
    printf("Enter kilometers at end: ");
    scanf("%f", &endkm);
    printf("Enter consumed fuel: ");
    scanf("%f", &fuel);

    //calculates fuel consumptions
    fuelPer100km = 100 / ((endkm - startkm)/ fuel);

    printf("\n");

    //outputs fuel consumption
    printf("Fuel Consumption: %.3f L / 100km", fuelPer100km);

    return EXIT_SUCCESS;
}
