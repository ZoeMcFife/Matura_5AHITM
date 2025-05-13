#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Title:        Guessing Game
//Author:       Leonard Bunea
//Description:  user or the computer guess numbers
//Last Change:  2021/01/01

int userGuess();
int computerGuess();


int main()
{
    char userInput;
    bool keepProgrammRunning = true;

    while (keepProgrammRunning == true)
    {
        printf("Who should guess numbers? (u for user / c for computer): \t");      //user selects if computer or user guesses
        userInput = getchar();

        if (userInput == 'u')       //initializes functions
        {
            userGuess();
        }
        else if (userInput == 'c')
        {
            computerGuess();
        }
        else
        {
            printf("Invalid Input");
        }

        char tempAnswer;
        printf("Do you want to continue? y / n \n");
        tempAnswer = getch();
        switch (tempAnswer)
        {
        case 'y':
            keepProgrammRunning = true;
            break;
        case 'n':
            keepProgrammRunning = false;
            break;
        default:
            printf("Invalid Input.");
            break;
        }
    }


    return EXIT_SUCCESS;
}

//user is guessing a random number
int userGuess()
{
    int userInput = NULL;
    int randomNumber;
    long startTime, endTime;

    //initializes RNG
    srand(time(NULL));
    randomNumber = rand() % (1000 - 1 + 1) + 1;
    startTime = clock();

    //loops while user has not guessed the number and gives "helpful" tips
    while (userInput != randomNumber)
    {
        printf("\nGuess the number!\n");
        scanf("%d", &userInput);

        if (userInput == randomNumber)
        {
            printf("Congrats! You guessed the number! \n");
        }
        else if (userInput > randomNumber)
        {
            printf("The number is smaller than your guess!\n");
        }
        else if (userInput < randomNumber)
        {
            printf("The number is larger than your guess!\n");
        }
    }

    endTime = clock();

    //outputs results
    printf("You guessed the number '%d' in %ld seconds!\n", randomNumber, ((endTime - startTime) / 1000));
}

//computer is guessing a number from the user
int computerGuess()
{
    int userInput = NULL;
    long startTime, endTime;
    int computerGuess = 500, computerGuessMin = 0, computerGuessMax = 1000;
    char userChecksComputer;

    //user inputs a number
    do
    {
        printf("Enter a number between 1 and 1000!: \t \n");
        scanf("%d", &userInput);
    }
    while (userInput > 1000 || userInput < 1);

    //instructs user how to play
    printf("Ok User! \nTo tell the computer its number is smaller, type 's'. \nTo tell it it's larger, type 'l'. \nTo tell it that it has guessed the number, type 'g'.\n");

    printf("Ok Computer! It's your turn now!\n\n");
    fflush(stdin);

    //main
    startTime = clock();
    while (userChecksComputer != 'g')
    {
        printf("Computer: The number is %d!\n", computerGuess);
        scanf("%c", &userChecksComputer);
        fflush(stdin);

        if (userChecksComputer == 's')
        {
            computerGuessMax = computerGuess;
            computerGuess = (computerGuessMax - computerGuessMin) / 2 + computerGuessMin;
        }
        else if (userChecksComputer == 'l')
        {
            computerGuessMin = computerGuess;
            computerGuess = (computerGuessMax + computerGuessMin) / 2;
        }
        else if (userChecksComputer == 'g')
        {

            if (computerGuess != userInput)
            {
                printf("The computer didn't guess the number. User, please do not lie to the computer.\n");
            }
            else
            {
                endTime = clock();
                printf("Good Job Computer! You did it! And it only took you %ld seconds!\n", ((endTime - startTime) / 1000));
            }
        }
        else //user inputs incorrectly
        {
            printf("User! Behave! You can only input 's', 'l' or 'g'!\n");
        }
    }
}
