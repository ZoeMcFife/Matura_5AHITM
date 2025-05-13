#include <stdio.h>
#include <stdlib.h>
#include "../ConFun.h"
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

#define CHATFILEPATH "..//chathistory.bin"

///WRITE

typedef struct
{
    char name[100];
    int color;
} user;

typedef struct
{
    char messageText[1000];
    int timestamp;
    user sender;
} message;

void registerNewUser(user *user);
void messaging(user user);

void sendMessage(message message);

void clampInt(int *value, int min, int max);

void createFile();

int main()
{
    textcolor(WHITE);

    user user;

    textcolor(WHITE);

    registerNewUser(&user);
    clrscr();

    messaging(user);

    return EXIT_SUCCESS;
}

/// Creates a users profile
void registerNewUser(user *user)
{
    textcolor(WHITE); /// This should set the text color to white but it doesn't work when opening main.exe for some reason

    printf("What's your name?\n");
    textcolor(WHITE);
    fgets(user->name, 100, stdin);
    user->name[strcspn(user->name, "\n")] = 0;

    printf("Hi %s! That's a nice name!\n\n", user->name);

    char colorStrTemp[4];

    printf("Now choose your color!\n");
    printf("1 - RED\n2 - LIGHTRED\n3 - GREEN\n4 - LIGHTGREEN\n5 - BLUE\n6 - LIGHTBLUE\n7 - YELLOW\n8 - DARKORANGE\n9 - CYAN\n10 - LIGHTCYAN\n11 - MAGENTA\n12 - LIGHTMAGENTA\n13 - WHITE\n14 - GRAY\n15 - BLACK (Why would you want this tho?)\n");

    fgets(colorStrTemp, sizeof(colorStrTemp), stdin);

    user->color = atoi(colorStrTemp);

    printf("--- Welcome to the chat! ---\n\n ");

    /// Tells the chat reader that you joined the chat
    message REGISTER;
    REGISTER.sender = *user;
    strcpy(REGISTER.messageText, "[USER_REGISTER]");
    REGISTER.timestamp = (unsigned long)time(NULL);

    sendMessage(REGISTER);
}

void messaging(user user)
{
    char exitString[7] = "[EXIT]";
    message message;

    message.sender = user;

    /// allows the user to send messages.
    do
    {
        createFile();

        textcolor(WHITE);

        printf("Write here:\t");

        textcolor(user.color);

        gets(message.messageText);
        message.messageText[strcspn(message.messageText, "\n")] = 0;
        message.timestamp = (unsigned long)time(NULL);
        sendMessage(message);
        if (strcmp(message.messageText, exitString) != 0)
            printf("Message sent! %d\n", message.timestamp);

        /// The way I programmed this, the chat only displays messages in 1 second intervals (checks if the previous message was sent at the same time) there's definitely a better way to do this
        Sleep(1000);
    }
    while (strcmp(message.messageText, exitString) != 0);

    textcolor(WHITE);
    printf("Chat exited\n");
}

/// Sends a message
void sendMessage(message message)
{
    FILE *fp;

    fp = fopen(CHATFILEPATH, "ab");

    if (fp == NULL)
    {
        printf("Error. Couldn't connect to chat. 3: \n");
        return;
    }

    if (fwrite(&message, sizeof(message), 1, fp) == 1)
    {
        textcolor(WHITE);
    }

    fclose(fp);
}

/// this should clamp an int value between two numbers. I even used 'fancy' ternary operators, but it seems to crash the program. /// UPDATE: clampInt was set as a void function and I was returning the result....
void clampInt(int *value, int min, int max)
{
    (*value > max) ? *value = max : ((*value < min) ? *value = min : *value);
}

void createFile()
{
    if (access(CHATFILEPATH, F_OK) == 0)
    {
        return;
    }
    else if (access(CHATFILEPATH, F_OK) == -1)
    {
        FILE *fp;

        fp = fopen(CHATFILEPATH, "wb");

        fclose(fp);
    }
}
