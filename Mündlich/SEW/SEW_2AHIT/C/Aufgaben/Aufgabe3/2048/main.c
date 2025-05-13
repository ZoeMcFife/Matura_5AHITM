#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define SIZE 4

//values for each arrow key
enum arrowKey
{
    arrowKeyUp = 72,
    arrowKeyDown = 80,
    arrowKeyRight = 77,
    arrowKeyLeft = 75
};

//game variables
struct Game
{
    int tiles[SIZE][SIZE];
    unsigned int points;
};

/*** --- primary functions --- */

void beginGame();
void update(struct Game game);
void initializeGame(struct Game *game);
void gameEnd(struct Game game);

/** --- file handling --- */
void createHighscoreFile();
void readHighScore(unsigned int *highscore);
void writeHighScore(struct Game game);

/*** --- helper functions --- */

//game states
bool isGameFull(struct Game game);
bool is2048(struct Game game);
bool areAnyMovesPossible(struct Game game);

//output
void displayIntro();
void displayControls();
void displayTiles(struct Game game);
void displayPoints(struct Game game);
void displayHighScore();

//tile movement
void tileMovement(struct Game *game);

bool slideTiles(struct Game *game);
void createNewTileAfterMove(struct Game *game);

bool moveUp(struct Game *game);
bool moveDown(struct Game *game);
bool moveLeft(struct Game *game);
bool moveRight(struct Game *game);

//other
void convertIntMatrixToStringArray(int matrix[4][4], char array[16][8]);
void rotateMatrix90Deg(int matrix[][4]);

int main()
{
    struct Game game;

    createHighscoreFile();

    beginGame();
    initializeGame(&game);

    while (areAnyMovesPossible(game))
    {
        tileMovement(&game);
        system("cls");
        update(game);
    }

    gameEnd(game);

    return (EXIT_SUCCESS);

}

void createHighscoreFile()
{
    FILE *fp;

    if (access("highscore.txt", F_OK) == 0)
    {
        return;
    }
    else if (access("highscore.txt", F_OK) == -1)
    {
        fp = fopen("highscore.txt", "w");
        fprintf(fp, "0");
        fclose(fp);
    }
}

void readHighScore(unsigned int *highscore)
{
    FILE *fp;

    fp = fopen("highscore.txt", "r");
    if (fp == NULL)
    {
        *highscore = 0;
        return;
    }

    fscanf(fp, "%d", &*highscore);

    fclose(fp);
}

void writeHighScore(struct Game game)
{
    FILE *fp;
    unsigned int currentHighscore;

    fp = fopen("highscore.txt", "r+");
    if (fp == NULL)
    {
        return;
    }

    readHighScore(&currentHighscore);

    if (currentHighscore < game.points)
    {
        fprintf(fp, "%d", game.points);
    }

    fclose(fp);
}

//begins the games
void beginGame()
{
    system("chcp 65001"); //allows unicode characters to be shown
    system("cls");
    printf("Press enter to start\n");

}

//updates game values
void update(struct Game game)
{
    writeHighScore(game);
    displayIntro();
    displayTiles(game);
    displayControls();
    displayPoints(game);
    displayHighScore();
}

//displays the intro message
void displayIntro()
{
    printf("\t\tWelcome to\n");
    printf("%s\n%s\n%s\n%s\n%s\n\n%s\n\n",
    "\t--------------------------",
    "\t  ___   ___    __   ___ ",
    "\t (__ \\ / _ \\  /. | ( _ )",
    "\t  / _/( (_) )(_  _)/ _ \\ ",
    "\t (____)\\___/   (_) \\___/",
    "\t--------------------------"
    );
}

//displays the end screen
void gameEnd(struct Game game)
{
    system("cls");
    displayTiles(game);


    if (is2048(game))
    {
        printf("\nIt's Game Over, but you achieved a 2048 tile! Your score was %d.\n", game.points);
    }
    else
    {
        printf("\nGame Over\nYour score was %d.", game.points);
    }
}


void displayControls()
{
    printf("\n\t     ← → ↑ ↓ ");
}

void displayPoints(struct Game game)
{
    printf("\t Points: %d\n", game.points);
}

void displayHighScore()
{
    unsigned int highscore;

    readHighScore(&highscore);

    printf("\t\tHighscore: %d\n", highscore);
}

//sets all tiles to 0 and then places 2 random tiles
void initializeGame(struct Game *game)
{
    int i, j;
    srand(time(NULL));

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            game->tiles[i][j] = 0;
        }
    }

    for (i = 0; i < 2; i++)
    {
        int x;
        int y;

        do
        {
            x = rand() % 3;
            y = rand() % 3;
        }
        while (game->tiles[y][x] != 0 && !isGameFull(*game));

        int k = rand();

        //I noticed that 2 as a starter tile is a lot more common than 4, so I made 4 have a 25% chance of being a starter tile. Not the greatest solution, but it works.
        switch (k % 4)
        {
            case 0:
                game->tiles[y][x] = 2;
                break;
            case 1:
                game->tiles[y][x] = 2;
                break;
            case 2:
                game->tiles[y][x] = 2;
                break;
            case 3:
                game->tiles[y][x] = 4;
                break;
        }
    }

    game->points = 0;
}

//prints out game.tiles
void displayTiles(struct Game game)
{
    char tileArray[16][8] = {"    "};

    convertIntMatrixToStringArray(game.tiles, tileArray);

    printf("\t╔═══════╤═══════╤═══════╤═══════╗\n");
    printf("\t║%s│%s│%s│%s║\n", tileArray[0], tileArray[1], tileArray[2], tileArray[3]);
    printf("\t╠═══════╪═══════╪═══════╪═══════╣\n");
    printf("\t║%s│%s│%s│%s║\n", tileArray[4], tileArray[5], tileArray[6], tileArray[7]);
    printf("\t╠═══════╪═══════╪═══════╪═══════╣\n");
    printf("\t║%s│%s│%s│%s║\n", tileArray[8], tileArray[9], tileArray[10], tileArray[11]);
    printf("\t╠═══════╪═══════╪═══════╪═══════╣\n");
    printf("\t║%s│%s│%s│%s║\n", tileArray[12], tileArray[13], tileArray[14], tileArray[15]);
    printf("\t╚═══════╧═══════╧═══════╧═══════╝\n");
}

//converts and int matrix into a string Array
void convertIntMatrixToStringArray(int matrix[4][4], char array[16][8])
{
    int x, y;
    int i = 0;

    for (x = 0; x < SIZE; x++)
    {
        for (y = 0; y < SIZE; y++)
        {
            if (matrix[x][y] == 0)
            {
                strcpy(array[i], "       ");
            }
            else
            {
                sprintf(array[i], "%7d", matrix[x][y]);
            }
            i++;
        }
    }
}

//returns true if all tiles are occupied
bool isGameFull(struct Game game)
{
    int i, j;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (game.tiles[i][j] == 0)
            {
                return false;
            }
        }
    }

    return true;
}

//returns true if any move is possible
bool areAnyMovesPossible(struct Game game)
{
    if (isGameFull(game))
        return false;
    else if (moveUp(&game) == false && moveDown(&game) == false && moveLeft(&game) == false && moveRight(&game) == false)
        return false;

    return true;
}

//returns true if there is a tile is 2048 or higher
bool is2048(struct Game game)
{
    int i, j;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (game.tiles[i][j] >= 2048)
            {
                return true;
            }
        }
    }

    return false;
}

void createNewTileAfterMove(struct Game *game)
{
    if (isGameFull(*game))
    {
        return;
    }

    srand(time(NULL));

    int x;
    int y;

    do
    {
        x = rand() % 4;
        y = rand() % 4;
    }
    while (game->tiles[y][x] != 0);

    int k = rand();

    switch (k % 4)
    {
        case 0:
            game->tiles[y][x] = 2;
            break;
        case 1:
            game->tiles[y][x] = 2;
            break;
        case 2:
            game->tiles[y][x] = 2;
            break;
        case 3:
            game->tiles[y][x] = 4;
            break;
    }
}

//rotates a matrix by 90 degree
void rotateMatrix90Deg(int matrix[][4])
{
    int i, j;

    for (i = 0; i < 4 / 2; i++)
    {
        for (j = i; j < 4 - i - 1; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[4 - 1 - j][i];
            matrix[4 - 1 - j][i] = matrix[4 - 1 - i][4 - 1 - j];
            matrix[4 - 1 - i][4 - 1 - j] = matrix[j][4 - 1 - i];
            matrix[j][4 - 1 - i] = temp;
        }
    }
}

//slide tiles up and handles collisions... basically the entire gameplay
bool slideTiles(struct Game *game)
{
    int y, x, i, temp, j, k=0;
    int moves = 0;

    int mergers[4][4] = {{-1}, {-1}, {-1}, {-1}};

    for (j = 0; j < 4; j++)
    {
        for (y = 1; y < SIZE; y++)
        {
            for (x = 0; x < SIZE; x++)
            {
                if (game->tiles[y][x] != 0)
                {

                    for (i = y - 1; i >= 0; i--)
                    {
                        if (game->tiles[i][x] == 0)
                        {
                            game->tiles[i][x] = game->tiles[y][x];
                            game->tiles[y][x] = 0;
                            moves++;
                        }
                        else if ((game->tiles[i][x] == game->tiles[y][x]) && (i != y) && (i + 1 == y) && (mergers[y][x] != 1) && (mergers[i][x] != 1))
                        {
                            game->tiles[i][x] = game->tiles[y][x] * 2;
                            game->tiles[y][x] = 0;
                            mergers[i][x] = 1;
                            moves++;

                            game->points += game->tiles[i][x];
                        }
                    }
                }
            }
        }
    }

    return moves;
}

bool moveUp(struct Game *game)
{
    return slideTiles(&*game);
}

bool moveDown(struct Game *game)
{
    rotateMatrix90Deg(game->tiles);
    rotateMatrix90Deg(game->tiles);
    bool moveMade = slideTiles(&*game);
    rotateMatrix90Deg(game->tiles);
    rotateMatrix90Deg(game->tiles);

    return moveMade;
}

bool moveLeft(struct Game *game)
{
    rotateMatrix90Deg(game->tiles);
    bool moveMade = slideTiles(&*game);
    rotateMatrix90Deg(game->tiles);
    rotateMatrix90Deg(game->tiles);
    rotateMatrix90Deg(game->tiles);

    return moveMade;
}

bool moveRight(struct Game *game)
{
    rotateMatrix90Deg(game->tiles);
    rotateMatrix90Deg(game->tiles);
    rotateMatrix90Deg(game->tiles);
    bool moveMade = slideTiles(&*game);
    rotateMatrix90Deg(game->tiles);

    return moveMade;
}

//moves tiles based on arrow key input
void tileMovement(struct Game *game)
{
    int ch = _getch ();

    if (ch == 0 || ch == 224)
    {
        switch (_getche())
        {
            case arrowKeyUp:
                moveUp(&*game);
                break;

            case arrowKeyDown:
                moveDown(&*game);
                break;

            case arrowKeyLeft:
                moveLeft(&*game);
                break;

            case arrowKeyRight:
                moveRight(&*game);
                break;
        }

        createNewTileAfterMove(&*game);
    }
}
