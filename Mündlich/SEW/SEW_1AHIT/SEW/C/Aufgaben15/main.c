
#include <stdio.h>
#include <stdlib.h>
#define ROWS 8
#define COLS 6
#include <stdbool.h>
#include "conioex.h"
#include <windows.h>


//Title:        Connect 4
//Author:       Leonard Bunea
//Description:  connect 4, but on a computer (friends needed for best experience)
//Last Change:  2021/04/17

void inititializefField(char field[][COLS]);
void outputField(char field[][COLS]);
void inputField(char field[][COLS], int col, char type);
bool checkInput(char field[][COLS], int col);
void clear();
bool checkWin(char field[][COLS], char currentPlayer);

void ComputerInputField(char field[][COLS], char type);

//global variables because #define didn't work anymore for some reason because of conioex.h
char X = 'X';
char O = 'O';

int main()
{
    char playArea[ROWS][COLS] = {0};
    char currentPlayer = X;
    char winningPlayer;
    char replay = 'y';
    char playerSelection;

    bool gameIsRunning = true;
    bool multiplayer = true;

    int discs;
    int playerInput;

    do
    {
        inititializefField(playArea);
        winningPlayer = 'F';
        discs = ROWS * COLS;

        printf("Do you want to play with a friend? y/n \n");
        playerSelection = getch();
        clear();
        printf("\n");

        if (playerSelection == 'y')
        {
            multiplayer = true;
        }
        else
        {
            multiplayer = false;
        }

        //gameplay
        if(multiplayer)
        {
            while(gameIsRunning)
            {
                //Title
                textcolor(LIGHTCYAN);
                printf("Welcome to CONNECT 4! \n");
                textcolor(WHITE);

                printf("\nCurrent player: %c \n", currentPlayer);
                outputField(playArea);

                //checks if a player has won (why did I write one before and how did I not notice) and stops the game
                if(winningPlayer != 'F')
                {
                    printf("%c WINS \n", winningPlayer);

                    break;
                }
                else if(discs == 0)
                {
                    printf("Everybody loses :( \n");
                    break;
                }

                printf("\nChoose a column: ");
                scanf("%d", &playerInput);

                if(checkInput(playArea, playerInput))
                {
                    inputField(playArea, playerInput, currentPlayer);
                    if(checkWin(playArea, currentPlayer))
                    {
                        winningPlayer = currentPlayer;
                    }
                    discs--;
                    clear();
                    if (currentPlayer == X)
                    {
                        currentPlayer = O;
                    }
                    else
                    {
                        currentPlayer = X;
                    }
                }
                else
                {
                    clear();
                }

            }
        }
        //Computer Opponent | very basic
        else if(!multiplayer)
        {
           while(gameIsRunning)
           {
               //Title
            textcolor(LIGHTCYAN);
            printf("Welcome to CONNECT 4! \n");
            textcolor(WHITE);

            printf("\nCurrent player: %c \n", currentPlayer);
            outputField(playArea);

            //checks if a player has won (why did I write one before and how did I not notice) and stops the game
            if(winningPlayer != 'F')
            {
                printf("%c WINS \n", winningPlayer);

                break;
            }
            else if(discs == 0)
            {
                printf("Everybody loses :( \n");
                break;
            }

            if(currentPlayer == X)
            {
                printf("\nChoose a column: ");
                scanf("%d", &playerInput);
                if(checkInput(playArea, playerInput))
                {
                    inputField(playArea, playerInput, currentPlayer);
                }
                else
                {
                    clear();
                }
            }
            else
            {
                ComputerInputField(playArea, currentPlayer);
                Sleep(1000);
            }

                if(checkWin(playArea, currentPlayer))
                {
                    winningPlayer = currentPlayer;
                }
                discs--;
                clear();
                if (currentPlayer == X)
                {
                    currentPlayer = O;
                }
                else
                {
                    currentPlayer = X;
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

void inititializefField(char field[][COLS])
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            field[i][j] = '.';
        }
    }
}

void outputField(char field[][COLS])
{
    int i, j;

    printf("\n");

    for(i = 0; i < COLS; i++)
    {
        printf("%d ", i+1);
    }

    printf("\n");

    //makes the lines under the column numbering (doesn't scale well beyond COLS = 10)
    for(i = 0; i < COLS*2; i++)
    {
        printf("-");
    }

    printf("\n");

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            //changes colors for a nicer look
            if(field[i][j] == O)
            {
                textcolor(GREEN);
            }
            else if(field[i][j] == X)
            {
                textcolor(RED);
            }
            else
            {
                textcolor(DARKGRAY);
            }

            printf("%c ", field[i][j]);
            textcolor(WHITE);
        }
        printf("\n");
    }
}

void inputField(char field[][COLS], int col, char type)
{
    int i, j;

    col--;

    for(i = 0; i < ROWS; i++)
    {
        if(field[i][col] != '.')
        {
            field[i-1][col] = type;
            break;
        }
        else if (i == (ROWS-1) && field[i][col] == '.')
        {
            field[i][col] = type;
            break;
        }
    }
}

bool checkInput(char field[][COLS], int col)
{
    int i;
    int fullFields = 0;

    if(col > COLS)
    {
        return false;
    }
    if(col < 0)
    {
        return false;
    }

    for(i = 0; i < ROWS; i++)
    {
        if(field[i][col-1] != '.')
        {
            fullFields++;
        }
    }

    if(fullFields == ROWS)
    {
        return false;
    }

    return true;
}

void clear()
{
    system("cls"); //too lazy to write system("cls") so I just made clear() function
}

bool checkWin(char field[][COLS], char currentPlayer)
{
    int i, j;

    //check horizontal
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS-3; j++)
        {
            if(field[i][j] == currentPlayer && field[i][j+1] == currentPlayer && field[i][j+2] == currentPlayer && field[i][j+3] == currentPlayer)
            {
                return true;
            }
        }
    }

    //vertical
    for(i = 0; i < ROWS-3; i++)
    {
        for(j = 0; j < COLS; j++)
            {
                if(field[i][j] == currentPlayer && field[i+1][j] == currentPlayer && field[i+2][j] == currentPlayer && field[i+3][j] == currentPlayer)
                {
                    return true;
                }
            }
    }

    //check diagonal "\"
    for(i = 0; i < ROWS-3; i++)
    {
        for(j = 0; j < COLS-3; j++)
            {
                if(field[i][j] == currentPlayer && field[i-1][j+1] == currentPlayer && field[i-2][j+2] == currentPlayer && field[i-3][j+3] == currentPlayer)
                {
                    return true;
                }
            }
    }

    //check diagonal "/"
    for(i = 0; i < ROWS+3; i++)
    {
        for(j = 0; j < COLS-3; j++)
        {
            if(field[i][j] == currentPlayer && field[i+1][j+1] == currentPlayer && field[i+2][j+2] == currentPlayer && field[i+3][j+3] == currentPlayer)
            {
                return true;
            }
        }
    }

    return false;
}
void ComputerInputField(char field[][COLS], char type)
{
    int i, j;
    int col;
    int max = COLS;
    int min = 1;

    col--;

    srand(time(NULL));

    do
    {
        col =  rand() % (max - min + 1) + min;
    }
    while(checkInput(field, col) != true);

    for(i = 0; i < ROWS; i++)
    {
        if(field[i][col] != '.')
        {
            field[i-1][col] = type;
            break;
        }
        else if (i == (ROWS-1) && field[i][col] == '.')
        {
            field[i][col] = type;
            break;
        }
    }
}
