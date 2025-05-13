#include <stdio.h>
#include <stdlib.h>

//Title: temperature converter
//Author: Leonard Bunea
//Description: Converts Celsius to Reaumur and Fahrenheit
//Last change: 2020/12/01

//function declaration
float temperatureConverter(float temperature, char scale);

int main()
{
    float tempCelsius;

    //User inputs temperature
    printf("Enter a temperature in Celsius: ");
    scanf("%f", &tempCelsius);

    //prints out temperature
    printf("Fahrenheit: %.3f\n", temperatureConverter(tempCelsius, 'F'));
    printf("Reaumur:    %.3f\n", temperatureConverter(tempCelsius, 'R'));

    return EXIT_SUCCESS;
}

//Converts Celsius to Reaumur or Fahrenheit
float temperatureConverter(float temperature, char scale)
{
    float tempOutput;

    if (scale == 'F')
    {
        tempOutput = (temperature * 9.0 / 5) + 32;
    }

    else if (scale == 'R')
    {
        tempOutput = (temperature * 4.0 / 5) ;
    }

    return tempOutput;
}
