#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Title: Area Calculation
//Author: Leonard Bunea
//Description: Calculates Area for a slanted room
//Last change: 2020/12/01

int main()
{
  //Variables
    float length;
    float height1;
    float height2;

    float cost = 0;
    float area = 0;
    float totalArea = 0;
    int costm2 = 96;

    bool keepRunning = true;
    char temp;

    while (keepRunning)
    {
         //User Input in cm
        printf("Length of segment (cm): ");
        scanf("%f", &length);
        fflush(stdin);
        printf("Height (cm): ");
        scanf("%f", &height1);
        fflush(stdin);
        printf("Second height (cm): ");
        scanf("%f", &height2);
        fflush(stdin);

        //converts to meters
        length = length / 100.0;
        height1 = height1 / 100.0;
        height2 = height2 / 100.0;

        //calculates area and cost
        area = ((height1 * length) - (length * (height1 - height2)/2.0)); //to calculate price of 1 segment to add to cost
        cost =  cost + area * costm2;
        totalArea += area; //total area

        //add another section
        printf("Add Section?: y/n  ");
        scanf("%c", &temp);

        if (temp == 'y')
        {
            keepRunning = true;
            length = 0;
            height1 = 0;
            height2 = 0;
        }
        else
        {
            keepRunning = false;
        }
    }

    printf("\n");

    //prints out results
    printf("Area: %.2f m2\n", totalArea);
    printf("Total Cost: %.2f Euro \n", cost);

    return EXIT_SUCCESS;
}
