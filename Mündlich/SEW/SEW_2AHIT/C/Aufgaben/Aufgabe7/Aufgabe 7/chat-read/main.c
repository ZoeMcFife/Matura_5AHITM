#include <stdio.h>
#include <stdlib.h>
#include "../ConFun.h"
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

#define CHATFILEPATH "..//chathistory.bin"
#define NUMBEROFMESSAGES getFileSizeinBytes() / sizeof(message)

///READ

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

void readMessages();
void printMessageHistory();
void writeMessageToChat(message message);

void displayMessageContents(message message);
int getFileSizeinBytes();
message returnLatestMessage();
void sendMessage(message message);

void createFile();

int main()
{
    textcolor(WHITE);

    message intro;

    srand(time(NULL));

    /// If the file is empty this sends a message. Things break down if the file is empty ...
    if (getFileSizeinBytes() == 0)
    {
        intro.sender.color = rand() % 14 - 1;
        strcpy(intro.messageText, "Welcome to the chatroom! Please stay civil.");
        strcpy(intro.sender.name, "COMPUTER");
        intro.timestamp =(unsigned long)time(NULL);
        sendMessage(intro);
    }

    printMessageHistory();

    readMessages();
    return 0;
}

void readMessages()
{
    message lastMessage;
    message latestMessage;

    /// This checks if the last message sent was sent as the same time as the newest message. idk if this is the best way to do it but it works.

    while (1)
    {
        createFile();

        latestMessage = returnLatestMessage();

        if (getFileSizeinBytes() <= sizeof(message))
        {
            lastMessage.timestamp = latestMessage.timestamp;
        }
        else if ((latestMessage.timestamp > lastMessage.timestamp) || latestMessage.timestamp == 0)
        {
            writeMessageToChat(latestMessage);
            lastMessage = latestMessage;
        }
        else if (latestMessage.timestamp == lastMessage.timestamp)
        {
            Sleep(100);
            continue;
        }


        Sleep(100);
    }
}

void writeMessageToChat(message message)
{
    if (strcmp(message.messageText, "[EXIT]") == 0)
    {
        textcolor(message.sender.color);
        printf("===== R.I.P %s went offline =====\n", message.sender.name);
        textcolor(WHITE);
        return;
    }

    if (strcmp(message.messageText, "[USER_REGISTER]") == 0 )
    {
        textcolor(message.sender.color);
        printf("===== @EVERYONE %s JUST ENTERED THE CHAT ROOM =====\n", message.sender.name);
        textcolor(WHITE);
        return;
    }

    printf("%-10s - ", message.sender.name);
    textcolor(message.sender.color);
    printf("%s\n", message.messageText);
    textcolor(WHITE);
}

/// Prints the entire message history when you start the programm
void printMessageHistory()
{
    message messageHistory[NUMBEROFMESSAGES];

    FILE *fp;

    fp = fopen(CHATFILEPATH, "rb");

    if (fp == NULL)
    {
        printf("Couldn't connect to chat. (printMessageHistory)\n");
        return;
    }

    fread(messageHistory, sizeof(message), NUMBEROFMESSAGES, fp);

    int i;

    for (i = 0; i < NUMBEROFMESSAGES; i++)
    {
        writeMessageToChat(messageHistory[i]);
    }

    fclose(fp);
}

message returnLatestMessage()
{
    FILE *fp;

    fp = fopen(CHATFILEPATH, "rb");

    if (fp == NULL)
    {
        printf("Couldn't connect to chat. (returnLatestMessage)\n");
    }

    message latestMessage;

    fseek(fp, -sizeof(message), SEEK_END);

    fread(&latestMessage, sizeof(message), 1, fp);

    fclose(fp);

    return latestMessage;
}

void displayMessageContents(message message)
{
    printf("Message by User %s:\n", message.sender.name);
    printf("Content: %s\n", message.messageText);
    printf("Timestamp: %d\n", message.timestamp);
    printf("user: %s\n", message.sender.name);
    printf("user color: %d\n", message.sender.color);
}

int getFileSizeinBytes()
{
    FILE *fp;

    fp = fopen(CHATFILEPATH, "rb");

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
