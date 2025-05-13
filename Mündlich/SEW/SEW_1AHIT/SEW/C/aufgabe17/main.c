#include <stdio.h>
#include <stdlib.h>
#include "conioex.h"
#include <stdbool.h>
#define ROWS 4
#define COLS 4

//Title:        15 Puzzle
//Author:       Leonard Bunea
//Description:  15 Puzzle game
//Last Change:  2021/05/11

//function prototypes
void outputField(int field[][COLS]);
int initializeField(int field[][COLS]);
int move(int field[][COLS]);
bool checkFinished(int field[][COLS]);
bool checkFinished2(int field[][COLS]);
bool find(int field[][COLS], int *row, int *col, int toFind);
bool isInArray(int integer, int array[]);

int main()
{
    int field[ROWS][COLS] = {0};
    char replay = 'y';

    do
    {
        initializeField(field);

        //main gameplay loop
        while(checkFinished(field) == false && checkFinished2(field) == false)
        {
            outputField(field);
            move(field);
        }

        printf("\n\tYou WIN!\n"); //congratulates the player if they win

        printf("\n");
        printf("Do you want to play again? y/n \n");
        replay = getch();
        system("cls");
    }
    while(replay == 'y' || replay == 'Y');

    return EXIT_SUCCESS;
}

int initializeField(int field[][COLS])
{
    srand(time(NULL));

    int i;
    int randomPositionROWS;
    int randomPositionCOLS;
    int value = 15, valueTemp;

    //fills the matrix numbers between 15 and 0 randomly
    for(i = 0; i < ROWS * COLS - 1; i++)
    {
        valueTemp = value;

        while(valueTemp == value)
        {
            randomPositionROWS = rand() % (ROWS);
            randomPositionCOLS = rand() % (COLS);

            if(field[randomPositionCOLS][randomPositionROWS] == 0)
            {
                field[randomPositionCOLS][randomPositionROWS] = value;
                value--;
            }
        }
    }
}

//outputs the matrix in a 4 x 4 square
void outputField(int field[][COLS])
{
    int i, j;

    system("cls");
    textcolor(CYAN);
    printf("\t15 PUZZLE \n");
    textcolor(WHITE);
    printf("---------------------------\n\n");

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            if(field[i][j] == 0)
            {
                textcolor(BLACK);
            }
            else
            {
                textcolor(WHITE);
            }

            printf("%d\t", field[i][j]);
        }
        printf("\n\n");
    }
}

int move(int field[][COLS])
{
    int zeroRow, zeroCol, possibleMoveUP, possibleMoveDOWN, possibleMoveRIGHT, possibleMoveLEFT;
    int possibleMoves[4];
    int playerInput, playerCol, playerRow, temp;
    int i;

    find(field, &zeroRow, &zeroCol, 0);//finds zero position

    //determines every possible move
    if(zeroRow > 0 && zeroCol > 0 && zeroCol < 3 && zeroRow < 3)
    {
        possibleMoveDOWN = field[zeroRow + 1][zeroCol];
        possibleMoveUP = field[zeroRow - 1][zeroCol];
        possibleMoveRIGHT = field[zeroRow][zeroCol + 1];
        possibleMoveLEFT = field[zeroRow][zeroCol - 1];
    }
    else if(zeroRow == 0 && zeroCol == 0)
    {
        possibleMoveDOWN = field[zeroRow + 1][zeroCol];
        possibleMoveRIGHT = field[zeroRow][zeroCol + 1];
        possibleMoveUP = 0;
        possibleMoveLEFT = 0;
    }
    else if(zeroRow == 0 && zeroCol == 3)
    {
        possibleMoveDOWN = field[zeroRow + 1][zeroCol];
        possibleMoveLEFT = field[zeroRow][zeroCol - 1];
        possibleMoveUP = 0;
        possibleMoveRIGHT = 0;
    }
    else if(zeroRow == 3 && zeroCol == 0)
    {
        possibleMoveUP = field[zeroRow - 1][zeroCol];
        possibleMoveRIGHT = field[zeroRow][zeroCol + 1];
        possibleMoveDOWN = 0;
        possibleMoveLEFT = 0;
    }
    else if(zeroRow == 3 && zeroCol == 3)
    {
        possibleMoveUP = field[zeroRow - 1][zeroCol];
        possibleMoveLEFT = field[zeroRow][zeroCol  - 1];
        possibleMoveDOWN = 0;
        possibleMoveRIGHT = 0;
    }
    else if(zeroRow == 0)
    {
        possibleMoveDOWN = field[zeroRow + 1][zeroCol];
        possibleMoveUP = 0;
        possibleMoveRIGHT = field[zeroRow][zeroCol + 1];
        possibleMoveLEFT = field[zeroRow][zeroCol - 1];
    }
    else if(zeroRow == 3)
    {
        possibleMoveDOWN = 0;
        possibleMoveUP = field[zeroRow - 1][zeroCol];
        possibleMoveRIGHT = field[zeroRow][zeroCol + 1];
        possibleMoveLEFT = field[zeroRow][zeroCol - 1];
    }
    else if(zeroCol == 0)
    {
        possibleMoveDOWN = field[zeroRow + 1][zeroCol];
        possibleMoveUP = field[zeroRow - 1][zeroCol];
        possibleMoveRIGHT = field[zeroRow][zeroCol + 1];
        possibleMoveLEFT = 0;
    }
    else if(zeroCol == 3)
    {
        possibleMoveDOWN = field[zeroRow + 1][zeroCol];
        possibleMoveUP = field[zeroRow - 1][zeroCol];
        possibleMoveRIGHT = 0;
        possibleMoveLEFT = field[zeroRow][zeroCol - 1];
    }

    possibleMoves[0] = possibleMoveDOWN;
    possibleMoves[1] = possibleMoveUP;
    possibleMoves[2] = possibleMoveLEFT;
    possibleMoves[3] = possibleMoveRIGHT;

    textcolor(WHITE);

    printf("\n");
    printf("What block do you want to move?\n\nPossible moves are: \n\n");

    for(i = 0; i < 4; i++)
    {
        if(possibleMoves[i] != 0)
        {
            printf("\tMove %d: %d \n", i, possibleMoves[i]);
        }
    }

    //user inputs which block to move
    do
    {
        fflush(stdin);
        printf("\nYour move:\t");
    }
    while(scanf("%d", &playerInput) != 1);


    //printf("%d \n", isInArray(playerInput, possibleMoves));

    //moves blocks
    if(find(field, &playerRow, &playerCol, playerInput) && isInArray(playerInput, possibleMoves))
    {
        temp = field[playerRow][playerCol];
        field[playerRow][playerCol] = field[zeroRow][zeroCol];
        field[zeroRow][zeroCol] = temp;
    }
}

//compares the playing field with 'checkArray' and determines if the player has successfully finished the game
bool checkFinished(int field[][COLS])
{
    int checkArray[ROWS][COLS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};

    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            if(field[i][j] != checkArray[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

bool checkFinished2(int field[][COLS])
{
    int checkArray[ROWS][COLS] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 15}};

    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            if(field[i][j] != checkArray[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

//returns the coordinates of a certain number in a matrix, returns false if number doesn't isn't found
bool find(int field[][COLS], int *row, int *col, int toFind)
{
    int i,j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            if(field[i][j] == toFind)
            {
                *row = i;
                *col = j;
                return true;
            }
        }
    }

    return false;
}

//checks if an integer is in an array
bool isInArray(int integer, int array[])
{
    int i;
    int len = 4;

    for(i = 0; i < len; i++)
    {
        if(array[i] == integer)
        {
            return true;
        }
    }

    return false;
}
