#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

//Name:         Leonard Bunea
//Title:        Das NIM-Spiel
//Description:  Simple game of removing matches
//Last Change:  2021/03/22

void showHeap(int heaps[]);
void removeFromHeap(int currentPlayer, int heaps[4], int *heapsOutput[4]);
void computerRemovesFromHeap(int heaps[4], int *heapsOutput[4]);
int heapSum(int heaps[4]);

int main()
{
//-------------------------------------------------
//          variable declarations

    int heaps[4] = {1, 3, 5, 7};
    int currentPlayer = 1;
    bool multiplayer = true;
    bool continuePlaying = true;
    int i;
    int sum;
    char playerSelection;
    char replay = 'y';

//-------------------------------------------------

    do
    {
        //resets the heaps and variables
        heaps[0] = 1;
        heaps[1] = 2;
        heaps[2] = 3;
        heaps[3] = 7;
        currentPlayer = 1;

        printf("Do you want to play with a friend? y/n \n");
        playerSelection = getch();
        system("cls");
        printf("\n");

        if (playerSelection == 'y')
        {
            multiplayer = true;
        }
        else
        {
            multiplayer = false;
        }

        //game
        if (multiplayer)    //for playing with two people
        {
            while (continuePlaying)
            {
                system("cls");
                showHeap(heaps);
                removeFromHeap(currentPlayer, heaps, &heaps);
                sum = heapSum(heaps);

                if (sum == 0)   //win condition
                {
                    system("cls");
                    showHeap(heaps);
                    printf("\n Player %d won! \n", currentPlayer);
                    break;
                }

                if (currentPlayer == 1)
                {
                    currentPlayer = 2;
                }
                else
                {
                    currentPlayer = 1;
                }
            }
        }
        else if (!multiplayer)  //playing against the computer
        {
            while (continuePlaying)
            {

                showHeap(heaps);

                if (currentPlayer == 1)
                {
                    removeFromHeap(currentPlayer, heaps, &heaps);
                }
                if (currentPlayer == 2)
                {
                    computerRemovesFromHeap(heaps, &heaps);
                }

                sum = heapSum(heaps);

                if (sum == 0)   //win condition
                {
                    system("cls");
                    showHeap(heaps);
                    printf("\n Player %d won! \n", currentPlayer);
                    break;
                }

                if (currentPlayer == 1)
                {
                    currentPlayer = 2;
                }
                else
                {
                    currentPlayer = 1;
                }
            }
        }
        printf("\n");
        printf("Do you want to play again? y/n \n");
        replay = getch();
        system("cls");
    }
    while (replay == 'y' || replay == 'Y');

    return EXIT_SUCCESS;
}

//function that prints out the heaps to show them on screen
void showHeap(int heaps[])
{
    int i;
    int j;

    for (i = 0; i < 4; i++)
    {
        printf("%d: ", heaps[i]);

        for(j = 0; j < heaps[i]; j++)
        {
            printf("|");
        }
        printf("\n");
    }
}

//subtracts from heaps
removeFromHeap(int currentPlayer, int heaps[4], int *heapsOutput[4])
{
    int removeFromHeapX;
    int removeXFromHeap;
    bool isValid = true;
    int i;
    int check1, check2;

    printf("\n");
    printf("Player %ds turn:", currentPlayer);

    do
    {
        isValid = true;

        printf("\n");
        printf("From which heap do you want to take from? ");
        scanf("%d", &removeFromHeapX);
        removeFromHeapX -= 1; //arrays start at 0

        printf("How many do you want to take? ");
        scanf("%d", &removeXFromHeap);

        if (removeFromHeapX > 4 || removeFromHeapX < 0)
        {
            isValid = false;
            printf("Selection Invalid. Please try again.\n");
        }
        else if (heaps[removeFromHeapX] < removeXFromHeap || removeXFromHeap > 3)
        {
            isValid = false;
            printf("Selection Invalid. Please try again.\n");
        }
    }
    while (!isValid);

    heaps[removeFromHeapX] = heaps[removeFromHeapX] - removeXFromHeap;

    heapsOutput = heaps; //works | *heapsOutput = heaps doesn't work
}

//like removeFromHeap() but the values are randomly generated
void computerRemovesFromHeap(int heaps[4], int *heapsOutput[4])
{
    int removeFromHeapX;
    int removeXFromHeap;
    bool validHeapFound;
    int fullHeaps = 0;
    int i;

    for (i = 0; i < 4; i++)
    {
        if (heaps[i] != 0)
        {
            fullHeaps++;
        }
    }

    srand(time(NULL));

    do
    {
        removeFromHeapX = (rand() % 4);

        if (heaps[removeFromHeapX] == 0)
        {
            validHeapFound = false;
        }
        else
        {
            validHeapFound = true;
        }
    }
    while (!validHeapFound);

    removeXFromHeap = (rand() % 3) + 1;

    printf("\n");

    if (fullHeaps == 1 && heaps[removeFromHeapX] <= 3) //computer has a higher chance of winning
    {
        removeXFromHeap = heaps[removeFromHeapX];
    }
    if (heaps[removeFromHeapX] < removeXFromHeap)
    {
        removeXFromHeap = heaps[removeFromHeapX];
        heaps[removeFromHeapX] = 0;
    }
    else
    {
        heaps[removeFromHeapX] = heaps[removeFromHeapX] - removeXFromHeap;
    }

    Sleep(1000);    //user has time to see what the computer takes
    system("cls");

    printf("\n");
    printf("Computers turn: \n");
    printf("Computer takes %d from heap %d. \n", removeXFromHeap, removeFromHeapX + 1);

    heapsOutput = heaps;
}

//calculates the sum of every element of heaps
int heapSum(int heaps[4])
{
    int sum = 0;
    int i;

    for (i = 0; i < 4; i++)
    {
        sum += heaps[i];
    }

    return sum;
}
