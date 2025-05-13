#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "conioex.h"

//Title:        Password Generator
//Author:       Leonard Bunea
//Description:  generates passwords
//Last Change:  2021/04/17


bool passwordChecker(char password[]);
void generateRandomPasswordsAndCheck(int amount, int passwordLength, char passwordArray[amount][passwordLength]);
void rngPassword(char password[], int len);

int main()
{
    char password[10];
    int i;
    int passwordAmount = 1000, passwordLen = 20;
    passwordLen++;
    char passwordArray[1000][21];
    generateRandomPasswordsAndCheck(passwordAmount, passwordLen, passwordArray);

    printf("%d randomly generated passwords of length %d: \n", passwordAmount, passwordLen-1);
    printf("-------------------------------------------------------------------------------\n");
    for(i = 0; i < passwordAmount; i++)
    {
        printf("Password %d:\t   %s\n", i, passwordArray[i]);
    }

    return EXIT_SUCCESS;
}

bool passwordChecker(char password[])
{
    int i;
    int len = 0, letter = 0, numbers = 0, upper = 0, lower = 0, special = 0;

    len = strlen(password);

    for(i = 0; i < len; i++)
    {
        if(isalpha(password[i]))
        {
            letter++;
        }
        if(isdigit(password[i]))
        {
            numbers++;
        }
        if(isupper(password[i]))
        {
            upper++;
        }
        if(islower(password[i]))
        {
            lower++;
        }
        if(ispunct(password[i]) && i != 0 && i != len-1)
        {
            special++;
        }
    }

    //printf("DEBUG: %d %d %d %d %d %d \n", len, letter, numbers, upper, lower, special);

    if(len >= 8 && letter >= 2 && numbers >= 1 && upper >= 1 && lower >= 1 && special >= 1)
    {
      //  printf("TRUE \n");
        return true;
    }
    else
    {
        return false;
    }
}

void generateRandomPasswordsAndCheck(int amount, int passwordLength, char passwordArray[amount][passwordLength])
{
    srand(time(NULL));
    char password[passwordLength];

    int i, j, len = passwordLength+1;

    for(i = 0; i < amount; i++)
    {
        rngPassword(password, passwordLength);

        if(passwordChecker(password) == 1)
        {
            strcpy(passwordArray[i], password);
        }
        else
        {
            i--;
        }
    }
}

void rngPassword(char generatedPassword[], int len)
{
    char randomChar;
    int max = 126, min = 33;
    int i;

    //generate Password
    for(i = 0; i < len-1; i++)
    {
        randomChar = rand() % (max - min + 1) + min;
        generatedPassword[i] = randomChar;
    }
    generatedPassword[len] = '\0';
}
