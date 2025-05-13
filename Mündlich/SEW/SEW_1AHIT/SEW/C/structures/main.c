#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct team
{
    char name[50];
    int wins, draw, loses;
    char goaldifference[8];
    int points;
};

void initializeGroup(struct team group[]);
void calPoints(struct team *team);
void drawTable(struct team group);

int main(int argc, char *argv[])
{
    struct team groupC[4];
    struct team europameister;
    int i;

    initializeGroup(groupC);

    strcpy(europameister.name, "Frankreich");
    europameister.wins = 7;
    europameister.loses = 0;
    europameister.draw = 0;
    strcpy(europameister.goaldifference, "14:4");

    for (i = 0; i < 4; i++)
    {
        calPoints(&groupC[i]);
    }

    return EXIT_SUCCESS;
}

void calPoints(struct team *team)
{
    team->points = team->wins * 3 + team->draw;
}

void initializeGroup(struct team group[])
{
    strcpy(group[0].name, "Österreich");
    strcpy(group[0].name, "Nordmazedonien");
    strcpy(group[0].name, "Niederlande");
    strcpy(group[0].name, "Ukraine");

    group[0].wins = 0;
    group[1].wins = 4;
    group[2].wins = 2;
    group[3].wins = 12;

    group[0].draw = 0;
    group[1].draw = 1;
    group[2].draw = 21;
    group[3].draw = 0;

    group[0].loses = 2;
    group[1].loses = 4;
    group[2].loses = 2;
    group[3].loses = 0;

    strcpy(group[0].goaldifference, "0:24");
    strcpy(group[1].goaldifference, "2:2");
    strcpy(group[2].goaldifference, "2:1");
    strcpy(group[3].goaldifference, "32:0");
}

void drawTable(struct team group)
{

}
