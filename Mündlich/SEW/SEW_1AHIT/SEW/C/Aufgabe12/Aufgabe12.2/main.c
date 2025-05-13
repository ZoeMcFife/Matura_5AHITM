#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Title:        Convert to Fraction
//Author:       Leonard Bunea
//Description:  converts a float into a fraction
//Last Change:  2020/03/02

void convertToFraction(float userFloat, int *numerator, int *denominator);

int main()
{
    float userInput;
    int denominator;
    int numerator;

    printf("Enter a fractional number: \t");
    scanf("%f", &userInput);

    convertToFraction(userInput, &numerator, &denominator);

    printf("Fraction:   %d/%d", numerator, denominator);

    return EXIT_SUCCESS;
}

void convertToFraction(float userFloat, int *numerator, int *denominator)
{
    float floatValue = userFloat;
    int fractionalValue, fractionalValue2;
    int i;
    int GCD = 0;

    userFloat = userFloat * 100;

    //GCD calculation
    for (i = 1; i <= (int)userFloat; i++)
    {
        if ((int)userFloat % i == 0 && 100 % i == 0)
        {
            GCD = i;
        }
    }

    fractionalValue = (int)userFloat / GCD;
    fractionalValue2 = 100 / GCD;

    *numerator = fractionalValue;
    *denominator = fractionalValue2;
}
