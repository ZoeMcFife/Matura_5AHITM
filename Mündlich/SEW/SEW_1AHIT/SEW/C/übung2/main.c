#include <stdio.h>
#include <stdlib.h>

float inputValues(float f[]);
float getAVG(float f[]);


int main()
{
    float array[10] = {0.0};

    inputValues(array);
    printf("%f", getAVG(array));


    return EXIT_SUCCESS;
}

float inputValues(float f[])
{
    int i;

    printf("Enter 10 floats: \n");

    for(i = 0; i < 10; i++)
    {
        printf("%i: ", i);
        scanf("%f", &f[i]);
    }
}

float getAVG(float f[])
{
    int i = 0;
    float average;

    for(i = 0; i < 10; i++)
    {
        average += f[i];
    }

    average = average / 10;

    return average;
}
