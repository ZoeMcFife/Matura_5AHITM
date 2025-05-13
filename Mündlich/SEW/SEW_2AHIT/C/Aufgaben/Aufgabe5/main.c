#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define scoreboardWebsite "highscore.html"

typedef struct
{
    char name[100];
    unsigned int time;
    unsigned int failures;
    int points;
}
player;

void makeHTML(player players[], int playerCount);

void createHTMLFile();
void createstartHTMLLayout();
void createHTMLTable(player players[], int playerCount);
void createEndHTMLLayout();

void createCSSFile();
void isImagePresent();

int getfile(char filename[]);
int getLineCount(char filename[]);
int getLongs(char string[], long output[]);

long calculatePoints(long numberValues);
void sortPlayers(player players[], int playerCount);

void readPlayers(char filename[], player players[], int playerCount);

int main()
{
    player players[1000];
    char filename[100];
    int playerCount;

    if (getFile(filename) == 1)
    {
        playerCount = getLineCount(filename);

        readPlayers(filename, players, playerCount);
        sortPlayers(players, playerCount);

        makeHTML(players, playerCount);
        createCSSFile();
        isImagePresent();

        ShellExecute(NULL, "open", scoreboardWebsite, NULL, NULL, SW_SHOWNORMAL);
    }


    return EXIT_SUCCESS;
}

void makeHTML(player players[], int playerCount)
{
    createHTMLFile();
    createstartHTMLLayout();
    createHTMLTable(players, playerCount);
    createEndHTMLLayout();
}

void isImagePresent()
{
    FILE *fp;

    if (access("spider.jpg", F_OK) == 0)
    {
        printf("'spider.jpg' is present.\n");
        return;
    }
    else if (access("spider.jpg", F_OK) == -1)
    {
        printf("'spider.jpg' is missing!\n");
    }
}

void createCSSFile()
{
    FILE *fp;

    if (access("style.css", F_OK) == 0)
    {
        printf(".CSS 'style.css' is present.\n");
        return;
    }
    else if (access("style.css", F_OK) == -1)
    {
        fp = fopen("style.css", "w");

        fprintf(fp, "body \n{ \n    background-color: aliceblue; \n    font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif; \n    color: rgb(49, 43, 14); \n    background-image: url('spider.jpg'); \n} \n \n#scoreboard \n{ \n    position: absolute; \n    left: 50%%; \n    top: 50%%; \n    transform: translate(-50%%, -50%%); \n    padding: 20px; \n    background-color: rgba(240, 255, 255, 0.486); \n} \n \ntable \n{ \n    margin: auto; \n    cursor: default; \n} \n \ntable, tr, td \n{ \n    border: none; \n \n} \n \n#title \n{ \n    font-size: 250%%; \n    font-weight: bolder; \n}  \n \n#title td:not(:first-child) \n{ \n    padding: 20px; \n} \n \n.top3 \n{ \n    margin: auto; \n    text-align: center; \n} \n \n \n.top3 td  \n{ \n    font-size: 200%%; \n    font-weight: bold; \n    transition: 1s; \n} \n \n.top3 td:hover \n{ \n    background-color: rgba(222, 184, 135, 0.404); \n} \n \n.top3:hover \n{ \n    transition: 1s; \n    font-size: 160%%; \n    color: black; \n} \n \n.top3:not(:first-child) \n{ \n    padding: 20px; \n} \n");
        fclose(fp);

        printf("Created .CSS File 'style.css'\n");
    }
}

void createHTMLFile()
{
    FILE *fp;

    fp = fopen(scoreboardWebsite, "w");

    fp=freopen(NULL,"w",fp);

    fclose(fp);

    printf("Created File 'highscore.html'\n");
}

void createstartHTMLLayout()
{
    FILE *fp;

    fp = fopen(scoreboardWebsite, "w");

    if (fp == NULL)
    {
        printf("Couldn't open file. \n");
        return;
    }

    fprintf(fp, "<!doctype html>\n<html>\n<head><title>Spidergame</title><link rel='stylesheet' href='style.css'>\n</head>\n<body>\n");

    fclose(fp);

    printf("Created Start HTML Layout.\n");
}

void createEndHTMLLayout()
{
    FILE *fp;

    fp = fopen(scoreboardWebsite, "a");

    if (fp == NULL)
    {
        printf("Couldn't open file. \n");
        return;
    }

    fprintf(fp, "</table></div>\n</body>\n</html>\n");

    fclose(fp);

    printf("Created End HTML Layout.\n");
}

void createHTMLTable(player players[], int playerCount)
{
    FILE *fp;

    fp = fopen(scoreboardWebsite, "a");

    if (fp == NULL)
    {
        printf("Couldn't open file. \n");
        return;
    }

    fprintf(fp, "<div id='scoreboard'><table border='1'>\n<tr id='title'><td>Place</td><td>Name</td><td>Time</td><td>Points</td></tr>\n");

    int i;

    for (i = 0; i < playerCount; i++)
    {
        if (i > 2)
        {
            break;
        }
        else
        {
            fprintf(fp, "<tr class='top3'><td>%d</td><td>%s</td><td>%ds</td><td>%d</td></tr>\n", i + 1, players[i].name, players[i].time, players[i].points);
        }
    }

    fclose(fp);

    printf("Created Player Score Table\n");
}

void readPlayers(char filename[], player players[], int playerCount)
{
    FILE *fp;

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Couldn't read file %s \n", filename);
        return;
    }

    int i;

    char currentLine[1000];
    long numberValues[2];
    char *name;

    for (i = 0; i < playerCount; i++)
    {
        fgets(currentLine, 100, fp);
        getLongs(currentLine, numberValues);

        name = strtok(currentLine, ";");

        strcpy(players[i].name, name);
        players[i].time = numberValues[0];
        players[i].failures = numberValues[1];
        players[i].points = (int)((1.0 / (numberValues[0] + numberValues[1] / 10)) * 100);
    }

    fclose(fp);

    printf("Successfully read all %d players from file\n", playerCount);
}

void sortPlayers(player players[], int playerCount)
{
    int sorted, i;

    player tmp;

    do
    {
        sorted = 1;
        for (i = 1; i < playerCount; i++)
        {
            if (players[i-1].points < players[i].points)
            {
                tmp = players[i-1];
                players[i-1] = players[i];
                players[i] = tmp;
                sorted = 0;
            }
        }
    }
    while (!sorted);

    printf("Successfully sorted all %d players from file\n", playerCount);
}

int getFile(char filename[])
{
    printf("Which file do you want to use?\n");

    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = 0;

    printf("File: '%s'\n", filename);

    FILE *fp;

    fp = fopen(filename, "rt");

    if (fp == NULL)
    {
        printf("File '%s' is invalid.\n", filename);
        return 0;
    }
    else
    {
        printf("File '%s' is valid.\n", filename);
        return 1;
    }
}

int getLineCount(char filename[])
{
    int count = 0;
    char line[10000];

    FILE *fp;

    fp = fopen(filename, "rt");

    if (fp == NULL)
    {
        printf("Error opening file:'%s'\n", filename);
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        count++;
    }

    fclose(fp);

    return count;
}

int getLongs(char string[], long output[])
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

    return i;
}
