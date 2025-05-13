#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

#define arraylength(x) (int)(sizeof(x) / sizeof(x[0])) //turns out I didn't even need this

//Name:         Leonard Bunea
//Title:        Integer Permutation
//Description:  Checks if an array of integers is a permutation of [1, 2, 3, ..., n]
//Last Change:  2021/04/08

void sort(int arrayInput[9999], int arrayLength, int *inversionsOutput);
void createSortedArrayFromOneToN(int length, int arrayOutput[length]);
bool isPermutation(int array1[9999], int array2[], int length);

int main()
{
    int array1[9999]; //
    int array2[9999] = {};
    int i, inversions;
    bool permutationIsEven;
    int temp;
    char again = 'y';
    int length;


    do
    {
       //input
        printf("How many numbers do you want to enter? \n");
        scanf("%d", &temp);

        printf("Enter numbers: \n");
        for(i = 0; i < temp; i++)
        {
            scanf("%d", &array1[i]);
        }

        length = temp;
        createSortedArrayFromOneToN(length, array2);

        printf("You Array:\n");
        for (i = 0; i < length; i++)
        {
            printf("%d ", array1[i]);
        }
        printf("\n");

        //sorting
        sort(array1, length, &inversions);

        //prints out the sorted array
        printf("\n");
        printf("Your Array, but sorted:\n");
        for (i = 0; i < length; i++)
        {
            printf("%d ", array1[i]);
        }
        printf("\n");

        //calculates if there are an even amount of permutations or not
        switch (inversions % 2 == 0)
        {
            case 1:
                permutationIsEven = true;
                break;
            case 0:
                permutationIsEven = false;
                break;
        }

        //outputs permutation type
        switch (isPermutation(array1, array2, length))
        {
            case true:
                if (permutationIsEven)
                {
                    printf("Even Permutation \n");
                }
                else
                {
                    printf("Odd Permutation \n");
                }
                break;
            case false:
                printf("Not a Permutation \n");
                break;
        }

        printf("\nCheck again? y/n \n");
        again = getche();
        system("cls");
    }
    while(again == 'y' || again == 'Y');

    return EXIT_SUCCESS;
}

void sort(int arrayInput[9999], int arrayLength, int *inversionsOutput)
{
    int i = 0, j = 0, k = 0;
    int inversions = 0;

    for (i = 0; i < arrayLength - 1; i++)
    {
        for (j = 0; j < arrayLength - 1 - i; j++)
        {
            if (arrayInput[j] > arrayInput[j + 1])
            {
                inversions++;
                k = arrayInput[j];
                arrayInput[j] = arrayInput[j + 1];
                arrayInput[j + 1] = k;
            }
        }
    }

    *inversionsOutput = inversions;
}

void createSortedArrayFromOneToN(int length, int arrayOutput[length])
{
    int i;

    for (i = 0; i < length; i++)
    {
        arrayOutput[i] = i + 1;
    }
}

bool isPermutation(int array1[9999], int array2[], int length)
{
    int i;

    for (i = 0; i < length; i++)
    {
        if (array1[i] == array2[i])
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


