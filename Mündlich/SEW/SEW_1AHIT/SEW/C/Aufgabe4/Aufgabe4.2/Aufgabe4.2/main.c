#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Title:        Number sorter
//Author:       Leonard Bunea
//Description:  sorts three numbers in ascending order
//Last Change:  2020/12/12


int main()
{
    float num1, num2, num3;
    float temp; //holds a temporary value

    //Input
    printf("Enter three numbers:    \n");
    scanf("%f", &num1);
    scanf("%f", &num2);
    scanf("%f", &num3);

    //sort numbers
    while (!(num1 <= num2 && num2 <= num3))
    {
        if (num2 < num1)
        {
            temp = num1;
            num1 = num2;
            num2 = temp;
        }
        if (num2 > num3)
        {
            temp = num2;
            num2 = num3;
            num3 = temp;
        }
    }

    //outpus numbers
    printf("%f | %f | %f", num1, num2, num3);

    return EXIT_SUCCESS;
}
