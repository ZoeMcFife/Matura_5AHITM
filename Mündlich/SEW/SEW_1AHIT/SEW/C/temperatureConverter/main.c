#include <stdio.h>
#include <stdlib.h>

float temperatureConverter(float temperature, char scale);

int main()
{
    float tempCelsius;

    printf("Enter a temperature in Celsius: ");
    scanf("%e", &tempCelsius);

    printf("Fahrenheit: %f\n", temperatureConverter(tempCelsius, 'F'));
    printf("Kelvin:     %f \n", temperatureConverter(tempCelsius, 'K'));
    printf("Rankine:    %f\n", temperatureConverter(tempCelsius, 'R'));

    return EXIT_SUCCESS;
}


float temperatureConverter(float temperature, char scale)
{
    float tempOutput;

    if (scale == 'F')
    {
        tempOutput = (temperature * 9 / 5) + 32;
    }
    else if (scale == 'K')
    {
        tempOutput = (temperature + 273.15);
    }
    else if (scale == 'R')
    {
        tempOutput = (temperature * 9 / 5) + 491.67;
    }

    return tempOutput;
}
