#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//Title:        Is it a triangle?
//Author:       Leonard Bunea
//Description:  Determines if something is a triangle
//Last Change:  2020/12/12

bool isTriangle( double side1, double side2, double side3);
const char* defineTriangle(double side1, double side2, double side3);

int main()
{
    double side1, side2, side3;

    printf("Enter Sides in ascending order: \n");
    printf("Enter 1st side: ");
    scanf("%lf", &side1);
    printf("Enter 2nd side: ");
    scanf("%lf", &side2);
    printf("Enter 3rd side: ");
    scanf("%lf", &side3);

    if (isTriangle(side1, side2, side3))
    {
        printf("It is a %s triangle.", defineTriangle(side1, side2, side3));
    }
    else
    {
        printf("It's not a triangle.");
    }

    return EXIT_SUCCESS;
}

bool isTriangle(double side1, double side2, double side3)
{
    if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1)
    {
       return true;
    }
    else
    {
        return false;
    }
}

const char* defineTriangle(double side1, double side2, double side3)
{
    char *triangle;

    bool equilateral = (side1 == side2 && side1 == side3 && side2 == side3);
    bool isosceles = (side1 == side2 || side1 == side3 || side3 == side2);
    bool right = (sqrt(pow(side1, 2) + pow(side2, 2)) == side3);

    if (equilateral)
    {
        triangle = "equilateral";
    }
    else if (isosceles && !equilateral)
    {
        triangle = "isosceles";
    }
    else if (right && isosceles)
    {
        triangle = "right and isosceles";
    }
    else if (right)
    {
        triangle = "right";
    }
    else
    {
        triangle = "standard";
    }
    return triangle;
}
