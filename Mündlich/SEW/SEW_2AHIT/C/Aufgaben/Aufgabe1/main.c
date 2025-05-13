#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

int checkIfSudokuFieldIsCorrect(int sudokuFieldForCheck[4][4]);
void displaySudokuField(int sudokuField[4][4]);
int getPlayerInput(int *x, int *y, int *number, int sudokoField[4][4]);
void getLongs(char string[], long output[]);
void convertIntMatrixToCharArray(int matrix[4][4], char array[16]);
void applyPlayerInput(int sudokuField[4][4], int x, int y, int number);
bool isInputValid(int sudokuField[4][4], int x, int y, int number);
void win();
void getRandomSudokuField(int sudokuField[4][4]);
void prepareSudokuFieldForCheck(int sudokuField[4][4]);

int main()
{
    int sudokuField[4][4] = {

                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0}
                            };


    int x = 0, y = 0, number = 0;
    bool isGameWon = false;

    getRandomSudokuField(sudokuField);

    printf("Welcome to 4x4 sudoku!\n");
    printf("Tip: Input 0 to clear a field.\n");

    while (isGameWon == false)
    {
        displaySudokuField(sudokuField);
        x = 0;
        y = 0;
        number = 0;

        getPlayerInput(&x,&y, &number, sudokuField);

        applyPlayerInput(sudokuField, x, y, number);

        if (checkIfSudokuFieldIsCorrect(sudokuField))
        {
            isGameWon = true;
        }

        system("cls");
    }

    displaySudokuField(sudokuField);
    win();

    return EXIT_SUCCESS;
}

//gets a random Sudokufield and copies it into 'sudokuField'
void getRandomSudokuField(int sudokuField[4][4])
{
    srand(time(NULL));

    int selectedField = rand() % 3;

    int selectedSudokuField0[4][4] = {
                                {0, 40, 0, 0},
                                {0, 0, 0, 40},
                                {0, 0, 20, 30},
                                {20, 30, 0, 0}
            };

    int selectedSudokuField1[4][4] = {
                                {20, 0, 0, 0},
                                {0, 40, 30, 0},
                                {0, 20, 10, 0},
                                {0, 0, 0, 40}
            };


    int selectedSudokuField2[4][4] = {
                                {0, 30, 20, 40},
                                {20, 40, 0, 30},
                                {0, 10, 0, 0},
                                {0, 0, 30, 0}
            };

    int selectedSudokuField3[4][4] = {
                                {0, 40, 30, 0},
                                {0, 0, 10, 0},
                                {0, 10, 0, 0},
                                {0, 30, 40, 0}
            };

    switch (selectedField)
    {
        case 0:
            memcpy(sudokuField, selectedSudokuField0, 4*4*sizeof(int));
            break;
        case 1:
            memcpy(sudokuField, selectedSudokuField1, 4*4*sizeof(int));
            break;

        case 2:
            memcpy(sudokuField, selectedSudokuField2, 4*4*sizeof(int));
            break;

        case 3:
            memcpy(sudokuField, selectedSudokuField3, 4*4*sizeof(int));
            break;
    }
}

//displays a sweet message when you complete the game
void win()
{
    printf("\n");

    printf("You completed the sudoku. Congrats!\n");

    printf("\n");
}

//gets player input of the x / y coordinate and the number the user wants to write. Validates if the input is correct too.
int getPlayerInput(int *x, int *y, int *number, int sudokoField[4][4])
{
    char input[10] = "";
    long inputAsLong[3] = {0};
    char *eptr = NULL;

    do
    {
        printf("\n");
        printf("Your Move: (number x y)\n");

        fflush(stdin);
        fgets(input, sizeof(input), stdin);

        getLongs(input, inputAsLong);
    }
    while (isInputValid(sudokoField, (int)inputAsLong[2], (int)inputAsLong[1], (int)inputAsLong[0]) == false);

    *number = (int)inputAsLong[0];
    *y = (int)inputAsLong[1];
    *x = (int)inputAsLong[2];

    return 1;
}

//Applies the player input to the sudokuField matrix. Also displays a message of the input and waits for the user to press enter.
void applyPlayerInput(int sudokuField[4][4], int x, int y, int number)
{
    char input[10];

    printf("Your input was %d in the field 'X: %d Y: %d'.\n", number, y, x);
    sudokuField[x - 1][y - 1] = number;

    printf("Press enter to continue.\n");

    do
    {
        fgets(input,sizeof(input),stdin);
    }
    while (input[0] != '\n');
}

//checks if given input is valid
bool isInputValid(int sudokuField[4][4], int x, int y, int number)
{
    if ((x < 1 || x > 4) || (y < 1 || y > 4) || (number < 0 || number > 4))
    {
        puts("Your input was invalid. Please try again.");
        return false;
    }

    if (sudokuField[x - 1][y - 1] >= 10)
    {
        printf("Can't edit this field.\n", sudokuField[x][y], number, x, y);
        return false;
    }

    return true;
}

//gets all longs from a string and puts them into an array
void getLongs(char string[], long output[])
{
    char *eptr = string;
    int i = 0;

    while (*eptr)
    {
        if(isdigit(*eptr) || ((*eptr == '-') && isdigit(*(eptr+1))))
        {
           output[i] = strtol(eptr, &eptr, 10);
           i++;
        }
        else
        {
            eptr++;
        }
    }
}

//since non-editable fields have a value higher than editable fields (e.g. 40 vs 4), this function divides those fields by 10 for the check function to work
void prepareSudokuFieldForCheck(int sudokuField[4][4])
{
    int x, y;

    for (x = 0; x < 4; x++)
    {
        for (y = 0; y < 4; y++)
        {
            if (sudokuField[x][y] >= 10)
            {
                sudokuField[x][y] = sudokuField[x][y] / 10;
            }
        }
    }
}

//checks if the sudokuField is solved.
int checkIfSudokuFieldIsCorrect(int sudokuFieldForCheck[4][4])
{
    int sudokuField[4][4] = {};

    memcpy(sudokuField, sudokuFieldForCheck, 4*4*sizeof(int));
    prepareSudokuFieldForCheck(sudokuField);

    int x, y, correct = 0, sum = 0;

    bool rowsCorrect = false;
    bool columnsCorrect = false;
    bool squaresCorrect = false;

    //returns 0 if there's an incorrect number
    for (x = 0; x < 4; x++)
    {
        for (y = 0; y < 4; y++)
        {
            if (sudokuField[x][y] != 1 && sudokuField[x][y] != 2 && sudokuField[x][y] != 3 && sudokuField[x][y] != 4)
            {
                return 0;
            }
        }
    }

    //checks rows
    for (x = 0; x < 4; x++)
    {
        for (y = 0; y < 4; y++)
        {
            sum += sudokuField[x][y];
        }

        if (sum == 10)
        {
            correct++;
        }
        sum = 0;
    }

    if (correct == 4)
    {
        rowsCorrect = true;
    }
    correct = 0;

    //checks columns
    for (y = 0; y < 4; y++)
    {
        for (x = 0; x < 4; x++)
        {
            sum += sudokuField[x][y];
        }

        if (sum == 10)
        {
            correct++;
        }
        sum = 0;
    }

    if (correct == 4)
    {
        columnsCorrect = true;
    }
    correct = 0;

    //checks squares     //0,0 2,0 0,2 2,2
    for (y = 0; y < 4; y += 2)
    {
        for (x = 0; x < 4; x += 2)
        {
            sum = sudokuField[x][y] + sudokuField[x + 1][y] + sudokuField [x + 1][y + 1] + sudokuField[x][y + 1];

            if (sum == 10)
            {
                correct++;
            }
            sum = 0;
        }
    }

    if (correct == 4)
    {
        squaresCorrect = true;
    }
    correct = 0;

    //output result
    if (rowsCorrect == true && columnsCorrect == true && squaresCorrect == true)
        return 1;
    else
        return 0;
}

//prints out the sudokuField array
void displaySudokuField(int sudokuField[4][4])
{
    char sudokoArray[16] = {0};

    convertIntMatrixToCharArray(sudokuField, sudokoArray);

    printf("╔═══╤═══╤═══╤═══╗\n");
    printf("║ %c │ %c │ %c │ %c ║\n", sudokoArray[0], sudokoArray[1], sudokoArray[2], sudokoArray[3]);
    printf("╠═══╪═══╪═══╪═══╣\n");
    printf("║ %c │ %c │ %c │ %c ║\n", sudokoArray[4], sudokoArray[5], sudokoArray[6], sudokoArray[7]);
    printf("╠═══╪═══╪═══╪═══╣\n");
    printf("║ %c │ %c │ %c │ %c ║\n", sudokoArray[8], sudokoArray[9], sudokoArray[10], sudokoArray[11]);
    printf("╠═══╪═══╪═══╪═══╣\n");
    printf("║ %c │ %c │ %c │ %c ║\n", sudokoArray[12], sudokoArray[13], sudokoArray[14], sudokoArray[15]);
    printf("╚═══╧═══╧═══╧═══╝\n");
}

//converts and int matrix into a char Array for the displaySudokuField() function
void convertIntMatrixToCharArray(int matrix[4][4], char array[16])
{
    int x, y;
    int i = 0;

    for (x = 0; x < 4; x++)
    {
        for (y = 0; y < 4; y++)
        {
            if (matrix[x][y] == 0)
            {
                array[i] = ' ';
            }
            else if (matrix[x][y] >= 10)
            {
                array[i] = matrix[x][y] / 10 + '0';
            }
            else
            {
                array[i] = matrix[x][y] + '0';
            }
            i++;
        }
    }
}

