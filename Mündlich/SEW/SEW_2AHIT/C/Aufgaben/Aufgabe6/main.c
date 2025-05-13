#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdbool.h>

#define QUESTIONSBINARYFILE "fragen.bin"
#define NUMBEROFQUESTIONS getFileSizeinBytes() / sizeof(question)

typedef struct
{
    char question[1000];

    char option1[150];
    char option2[150];
    char option3[150];
    char option4[150];

    int correctOption;
}question;

/// Other
int getFileSizeinBytes();
bool isIncludedInIntArray(int src, int check[], int checkLen, int *index);
int convertCharOptionToInt(char option, bool fromMainMenu);
char userYesNoPrompt();
void removeQuestionFromArray(question array[], int index);

/// Displaying a question
void displayQuestion(int questionIndex, bool showHint);
question getQuestion(int questionIndex);
int getRandomQuestionIndex();

/// User Input
int getUsersOption();
bool isUserOptionCorrect(int questionIndex, int option);
void handleUserInput(bool isOptionCorrect);

/// Main Menu
void mainMenu();

void displayMainMenu();
int getUserMainMenuOption();
void handleUserMainMenuOption(int mainMenuOption);

/// Menu Options
void viewQuestionsMenuOption();
void removeQuestionMenuOption();
void editQuestionMenuOption();
void addQuestionMenuOption();
void playMenuOption();
void exitMainMenuOption();

void addQuestion(question q);
void editQuestion(int questionIndex, question newQuestion);
void removeQuestion(int questionIndex);

/// Main Game Mode
void gameLoop();

int main()
{
    mainMenu();

    return EXIT_SUCCESS;
}

/// Main Menu
void mainMenu()
{
    bool applicationRunning = true;

    while (applicationRunning)
    {
        displayMainMenu();
        handleUserMainMenuOption(getUserMainMenuOption());
    }
}

void displayMainMenu()
{
    printf("---- Answer Questions THE GAME ----\n\n");

    printf("- Select Option Below -\n\n");

    printf("\t--- PLAY \t\t(p)\n\n");
    printf("\t---- VIEW QUESTIONS \t(v)\n");
    printf("\t---- ADD QUESTION \t(a)\n");
    printf("\t---- EDIT QUESTION \t(e)\n");
    printf("\t---- REMOVE QUESTION \t(r)\n\n");
    printf("\t--- EXIT \t\t(x)\n\n");
}

int getUserMainMenuOption()
{
    char userInputString[100000];
    bool isInputValid = false;
    char userInput;

    do
    {
        printf("\n\n-------- ");

        fflush(stdin);

        fgets(userInputString, sizeof(userInputString), stdin);

        userInput = userInputString[0];

        if (tolower(userInput) == 'p' || tolower(userInput) == 'v' || tolower(userInput) == 'a' || tolower(userInput) == 'e' || tolower(userInput) == 'x' || tolower(userInput) == 'r')
        {
            isInputValid = true;
        }
        else
        {
            printf("Please enter a correct option!\n");
            isInputValid = false;
        }
    }
    while (!isInputValid);

    return convertCharOptionToInt(tolower(userInput), true);
}

void handleUserMainMenuOption(int mainMenuOption)
{
    switch (mainMenuOption)
    {
        case 1:
            playMenuOption();
            break;
        case 2:
            printf("soggy\n");
            viewQuestionsMenuOption();
            break;
        case 3:
            addQuestionMenuOption();
            break;
        case 4:
            editQuestionMenuOption();
            break;
        case 5:
            removeQuestionMenuOption();
            break;
        case 6:
            exitMainMenuOption();
            break;
    }
}

/// Menu Options
void viewQuestionsMenuOption()
{
    system("cls");

    int i;

    for (i = 0; i < NUMBEROFQUESTIONS; i++)
    {
        displayQuestion(i, true);
    }

    printf("Press any key to continue . . . \n");
    getch();

    system("cls");
}

void removeQuestionMenuOption()
{
    system("cls");

    if (NUMBEROFQUESTIONS == 0)
    {
        printf("There are no questions to remove.\n");
        getch();
        system("cls");
        return;
    }

    bool hasUserEnteredAValidIndex = false;
    int index;
    char userInput[20];
    char *eptr = NULL;

    do
    {
        printf("Which question do you want to edit? (use question index)\n");
        fgets(userInput, sizeof(userInput), stdin);

        index = (int)strtol(userInput, &eptr, 10);

        if (index > NUMBEROFQUESTIONS)
        {
            printf("Index out of range!\n");
            hasUserEnteredAValidIndex = false;
        }
        else if (index < 0)
        {
            printf("Index out of range!\n");
            hasUserEnteredAValidIndex = false;
        }
        else if (index >= 0 && index < NUMBEROFQUESTIONS)
        {
            hasUserEnteredAValidIndex = true;
        }
        else
        {
            hasUserEnteredAValidIndex = false;
        }
    }
    while (!hasUserEnteredAValidIndex);

    printf("Remove this question?\n");
    displayQuestion(index, true);

    if (userYesNoPrompt() == 'y')
    {
        removeQuestion(index);
        printf("Question was removed!\n");
    }
    else
    {
        printf("Okay, nothing was done.\n");
    }

    getch();
    system("cls");

}

void removeQuestion(int questionIndex)
{
    question questions[NUMBEROFQUESTIONS];

    int temp = NUMBEROFQUESTIONS - 1;

    FILE *fp;

    fp = fopen(QUESTIONSBINARYFILE, "rb");

    fread(questions, sizeof(questions), 1, fp);

    fclose(fp);

    removeQuestionFromArray(questions, questionIndex);

    fp = fopen(QUESTIONSBINARYFILE, "wb");

    fwrite(questions, sizeof(question), temp, fp);

    fclose(fp);
}

void editQuestionMenuOption()
{
    system("cls");

    if (NUMBEROFQUESTIONS == 0)
    {
        printf("There are no questions to edit.\n");
        getch();
        system("cls");
        return;
    }

    bool hasUserEnteredAValidIndex = false;
    int index;
    char userInput[20];
    char *eptr = NULL;

    do
    {
        printf("Which question do you want to edit? (use question index)\n");
        fgets(userInput, sizeof(userInput), stdin);

        index = (int)strtol(userInput, &eptr, 10);

        if (index > NUMBEROFQUESTIONS)
        {
            printf("Index out of range!\n");
            hasUserEnteredAValidIndex = false;
        }
        else if (index < 0)
        {
            printf("Index out of range!\n");
            hasUserEnteredAValidIndex = false;
        }
        else if (index >= 0 && index < NUMBEROFQUESTIONS)
        {
            hasUserEnteredAValidIndex = true;
        }
        else
        {
            hasUserEnteredAValidIndex = false;
        }
    }
    while (!hasUserEnteredAValidIndex);

    printf("Edit this question?\n");
    displayQuestion(index, true);

    if (userYesNoPrompt() == 'y')
    {
        question question = getQuestion(index);

        printf("Edit Question Title?\n");

        if (userYesNoPrompt() == 'y')
        {
            do
            {
                printf("What's the question?\n");
                fgets(question.question, sizeof(question.question), stdin);
                question.question[strcspn(question.question, "\n")] = 0;
            }
            while (question.question[1] == 0);
        }

        printf("Edit Option 1?\n");

        if (userYesNoPrompt() == 'y')
        {
            do
            {
                printf("Option 1\n");
                fgets(question.option1, sizeof(question.question), stdin);
                question.option1[strcspn(question.option1, "\n")] = 0;
            }
            while (question.option1[1] == 0);
        }

        printf("Edit Option 2?\n");

        if (userYesNoPrompt() == 'y')
        {
            do
            {
                printf("Option 2\n");
                fgets(question.option2, sizeof(question.question), stdin);
                question.option2[strcspn(question.option2, "\n")] = 0;
            }
            while (question.option2[1] == 0);
        }


        printf("Edit Option 3?\n");

        if (userYesNoPrompt() == 'y')
        {
            do
            {
                printf("Option 3\n");
                fgets(question.option3, sizeof(question.question), stdin);
                question.option3[strcspn(question.option3, "\n")] = 0;
            }
            while (question.option3[1] == 0);
        }

        printf("Edit Option 4?\n");

        if (userYesNoPrompt() == 'y')
        {
            do
            {
                printf("Option 4\n");
                fgets(question.option4, sizeof(question.question), stdin);
                question.option4[strcspn(question.option4, "\n")] = 0;
            }
            while (question.option4[1] == 0);
        }

        printf("Edit correct option?\n");

        if (userYesNoPrompt() == 'y')
        {
            question.correctOption = getUsersOption();
        }

        editQuestion(index, question);
    }
    else
    {
        printf("Okay, nothing was done.\n");
    }


    getch();
    system("cls");
}

void editQuestion(int questionIndex, question newQuestion)
{
    question question = getQuestion(questionIndex);

    FILE *fp;

    fp = fopen(QUESTIONSBINARYFILE, "r+b");

    if (fp == NULL)
    {
        printf("Couldn't open file!\n");
        return;
    }

    fseek(fp, sizeof(question) * questionIndex, SEEK_SET);

    fwrite(&newQuestion, sizeof(question), 1, fp);

    printf("Question Edited!\n");

    fclose(fp);
}

void addQuestionMenuOption()
{
    system("cls");

    question question;

    do
    {
        printf("What's the question?\n");
        fgets(question.question, sizeof(question.question), stdin);
        question.question[strcspn(question.question, "\n")] = 0;
    }
    while (question.question[1] == 0);

    printf("\nNow add the options.\n\n");

    do
    {
        printf("Option 1\n");
        fgets(question.option1, sizeof(question.question), stdin);
        question.option1[strcspn(question.option1, "\n")] = 0;
    }
    while (question.option1[1] == 0);

    do
    {
        printf("Option 2\n");
        fgets(question.option2, sizeof(question.question), stdin);
        question.option2[strcspn(question.option2, "\n")] = 0;
    }
    while (question.option2[1] == 0);


    do
    {
        printf("Option 3\n");
        fgets(question.option3, sizeof(question.question), stdin);
        question.option3[strcspn(question.option3, "\n")] = 0;
    }
    while (question.option3[1] == 0);


    do
    {
        printf("Option 4\n");
        fgets(question.option4, sizeof(question.question), stdin);
        question.option4[strcspn(question.option4, "\n")] = 0;
    }
    while (question.option4[1] == 0);

    printf("\nFinally, what is the correct answer?\n\n");

    question.correctOption = getUsersOption();

    printf("\n\n Add this question?\n");

    printf("\n---- %s ----\n\n", question.question);

    printf("A: %s\n", question.option1);
    printf("B: %s\n", question.option2);
    printf("C: %s\n", question.option3);
    printf("D: %s\n", question.option4);
    printf("---> Correct Option -> %d <-\n", question.correctOption);

    printf("\n--------------------------------------------------------------------------------------------------------------\n\n");

    if (userYesNoPrompt() == 'y')
    {
        addQuestion(question);
        printf("Question added!\n");
    }
    else
    {
        printf("Okay, nothing was done.\n");
    }
    getch();
    system("cls");
}

void addQuestion(question q)
{
    FILE *fp;

    fp = fopen(QUESTIONSBINARYFILE, "ab");

    if (fp == NULL)
    {
        printf("Couldn't open file!\n");
        return;
    }

    fwrite(&q, sizeof(question), 1, fp);

    fclose(fp);
}
void playMenuOption()
{
    gameLoop();
}

void exitMainMenuOption()
{
    exit(EXIT_SUCCESS);
}


/// Main Game Mode
void gameLoop()
{
    system("cls");

    if (NUMBEROFQUESTIONS == 0)
    {
        printf("Oh well, this is kinda awkward. There are no questions. Uhh uhm you win? \n");
        getch();
        system("cls");
        printf("---- You answered 0 questions out of 0 correctly. You answered 100%% of all questions! ----");
        getch();
        system("cls");
        return;
    }

    bool continueGame = true;

    int index;
    int userInput;
    bool isCorrect;

    int i = 0;
    int temp;

    int correctAnswers = 0;

    int usedQuestionindices[NUMBEROFQUESTIONS];

    for (i = 0; i < NUMBEROFQUESTIONS; i++)
    {
        usedQuestionindices[i] = -1;
    }

    i = 0;

    while (continueGame)
    {
        do
        {
            index = getRandomQuestionIndex();
        }
        while (isIncludedInIntArray(index, usedQuestionindices, NUMBEROFQUESTIONS, &temp));

        usedQuestionindices[i] = index;
        i++;

        displayQuestion(index, false);
        userInput = getUsersOption();

        isCorrect = isUserOptionCorrect(index, userInput);
        handleUserInput(isCorrect);

        if (isCorrect)
        {
            correctAnswers++;
        }
        else
        {
            continueGame = false;
        }

        if (i == NUMBEROFQUESTIONS)
        {
            continueGame = false;
        }
    }

    system("cls");

    int percentage = (int)(((float)correctAnswers / (NUMBEROFQUESTIONS)) * 100);

    printf("---- You answered %d questions out of %d correctly. You answered %d%% of all questions!  ----", correctAnswers, getFileSizeinBytes() / sizeof(question), percentage);

    getch();
    system("cls");
}

/// User Input
int getUsersOption()
{
    char userInputString[10];
    bool isInputValid = false;
    char userInput;

    do
    {
        printf("---- Enter your answer ----\n\n-------- ");

        fflush(stdin);

        fgets(userInputString, sizeof(userInputString), stdin);

        userInput = userInputString[0];

        if (toupper(userInput) == 'A' || toupper(userInput) == 'B' || toupper(userInput) == 'C' || toupper(userInput) == 'D')
        {
            isInputValid = true;
        }
        else
        {
            printf("Please enter only A, B, C or D!\n");
            isInputValid = false;
        }
    }
    while (!isInputValid);

    return convertCharOptionToInt(toupper(userInput), false);
}

int convertCharOptionToInt(char option, bool fromMainMenu)
{
    if (!fromMainMenu)
    {
        switch (option)
        {
            case 'A':
                return 1;
            case 'B':
                return 2;
            case 'C':
                return 3;
            case 'D':
                return 4;
            default:
                return -1;
        }
    }
    else
    {
        switch (option)
        {
            case 'p':
                return 1;
            case 'v':
                return 2;
            case 'a':
                return 3;
            case 'e':
                return 4;
            case 'r':
                return 5;
            case 'x':
                return 6;
            default:
                return -1;
        }
    }

}

bool isUserOptionCorrect(int questionIndex, int option)
{
    question question = getQuestion(questionIndex);

    if (question.correctOption == option)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void handleUserInput(bool isOptionCorrect)
{
    if (isOptionCorrect)
    {
        printf("\n---- CORRECT ----\n\n\n\n");
    }
    else
    {
        printf("\n---- NOT CORRECT ----\n\n\n\n");
    }
}

/// Displaying a question
void displayQuestion(int questionIndex, bool showHint)
{
    question question = getQuestion(questionIndex);

    printf("\n---- %s ----\n\n", question.question);

    printf("A: %s\n", question.option1);
    printf("B: %s\n", question.option2);
    printf("C: %s\n", question.option3);
    printf("D: %s\n", question.option4);

    if (showHint)
        printf("---> Correct Option -> %d <-\n", question.correctOption);

    printf("\n--------------------------------------------------------------------------------------------------------------\n\n");
}

question getQuestion(int questionIndex)
{
    if (questionIndex == -1)
    {
        printf("Critical read error. No question file found!\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp;

    fp = fopen(QUESTIONSBINARYFILE, "rb");

    if (fp == NULL)
    {
        printf("ERROR OPENING FILE.\n");
        return;
    }

    question questionOut;

    fseek(fp, questionIndex * sizeof(question), SEEK_SET);
    fread(&questionOut, sizeof(question), 1, fp);

    fclose(fp);

    return questionOut;
}

int getRandomQuestionIndex()
{
    int questionIndex;
    srand(time(NULL));

    int fileSizeInBytes = getFileSizeinBytes();

    if (fileSizeInBytes == -1)
        return -1;

    questionIndex = rand() % (NUMBEROFQUESTIONS);

    return questionIndex;
}

/// Other
int getFileSizeinBytes()
{
    FILE *fp;

    fp = fopen(QUESTIONSBINARYFILE, "rb");

    if (fp == NULL)
    {
        printf("ERROR OPENING FILE.\n");
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    int fileSizeInBytes = ftell(fp);
    fclose(fp);

    return fileSizeInBytes;
}

bool isIncludedInIntArray(int src, int check[], int checkLen, int *index)
{
    int i;

    for (i = 0; i < checkLen; i++)
    {
        if (src == check[i])
        {
            *index = i;
            return true;
        }
    }

    *index = -1;
    return false;
}

char userYesNoPrompt()
{
    char yesno;

    do
    {
        printf("\n---- y / n ----\n\n");
        yesno = tolower(getch());
    }
    while (yesno != 'y' && yesno != 'n');

    return yesno;
}

void removeQuestionFromArray(question array[], int index)
{
    int i;

    for (i = index; i < NUMBEROFQUESTIONS - 1; i++)
    {
        array[i] = array[i + 1];
    }
}
