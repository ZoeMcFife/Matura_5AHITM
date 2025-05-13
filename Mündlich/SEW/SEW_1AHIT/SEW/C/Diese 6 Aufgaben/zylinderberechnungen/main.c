#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159265358979323846

//Title: Cylinder calculations
//Author: Leonard Bunea
//Description: calculates volume and lateral surface area of a cylinder
//Last change: 2020/12/01

int main()
{
    //Variable declarations
    float radius;
    float height;

    float volume;
    float lateralSurfaceArea;

    //user input of radius and height
    printf("Enter radius: ");
    scanf("%f", &radius);
    printf("Enter height: ");
    scanf("%f", &height);

    //calculates volume and lateralSurfaceArea
    volume = PI * radius * radius * height;
    lateralSurfaceArea = 2 * PI * radius * height;

    printf("\n")

    //outputs volume and lateralSurfaceArea
    printf("Volume: %.5f \n", volume);
    printf("Lateral Surface Area: %.5f \n", lateralSurfaceArea);

    return EXIT_SUCCESS;
}
