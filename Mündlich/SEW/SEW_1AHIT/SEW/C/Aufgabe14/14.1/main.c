#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 60

//Name:         Leonard Bunea
//Title:        String Permutation
//Description:  Checks if a string of characters is permutation of another string
//Last Change:  2021/04/08

bool isPermutation(char string1[60], char string2[60]);
void sortString(char string[60], char *outputString[60]);

int main()
{
    char string1[60];
    char string2[60];
    char again = 'y';
    int i;

    do
    {
        //----------INPUT----------

        printf("Enter 1st string: \n");

        for(i = 0; i < MAXSIZE; i++)
        {
            char temp = getchar();
            fflush(stdin);

            if(temp == '\n')
            {
                break;
            }
            else
            {
                string1[i] = temp;
            }
        }

        printf("\nEnter 2nd string: \n");

        for(i = 0; i < MAXSIZE; i++)
        {
            char temp = getchar();
            fflush(stdin);

            if(temp == '\n')
            {
                break;
            }
            else
            {
                string2[i] = temp;
            }
        }

        //----------CLEANING----------

        for(i = 0; i < MAXSIZE; i++)
        {
            if(string1[i] > 'Z' || string1[i] < 'A')
            {
                string1[i] = NULL;
            }
        }

        for(i = 0; i < MAXSIZE; i++)
        {
            if(string2[i] > 'Z' || string2[i] < 'A')
            {
                string2[i] = NULL;
            }
        }

        //----------PERMUTATION CHECK----------

        if(isPermutation(string1, string2))
        {
            printf("String 2 is permutation of string 1. \n");
        }
        else
        {
            printf("Not a permutation. \n");
        }

        //----------CONTINUE PROGRAMM----------

        printf("\nCheck again? y/n \n");
        again = getche();
        system("cls");
    }
    while(again == 'y' || again == 'Y');

    return EXIT_SUCCESS;
}

bool isPermutation(char string1[60], char string2[60])
{
    sortString(string1, &string1);
    sortString(string2, &string2);

    int i;

    for (i = 0; i < MAXSIZE; i++)
    {
        if (string1[i] == string2[i])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void sortString(char string[60], char *outputString[60])
{
    int i = 0, j = 0, k = 0;


    for (i = 0; i < MAXSIZE - 1; i++)
    {
        for (j = 0; j < MAXSIZE - 1 - i; j++)
        {
            if (string[j] > string[j + 1])
            {
                k = string[j];
                string[j] = string[j + 1];
                string[j + 1] = k;
            }
        }
    }
    *outputString = string;
}

