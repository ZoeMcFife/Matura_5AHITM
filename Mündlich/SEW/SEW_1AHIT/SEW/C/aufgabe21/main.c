#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Author:       Leonard Bunea
//Title:        Aufgabe21
//Description:  Outputs Football stats to a table and .csv file
//Last Change:  2021/06/18

struct team
{
    char name[50];
    int wins, draws, loses;
    char goaldifference[8];
    int points;
    long goalDif;
};

void outputGroupToCSVFile(struct team group[], int groups);     //creates a csv file from the team struct
void inititializeGroup(struct team group[]);                    //fills a struct with data
void outputGroupInTable(struct team group[], int groups);       //outputs a table of data from the team struct
void calPoints(struct team *team);                              //calculates points
void sortGroupByPoints(struct team group[]);                    //sorts the groups by points or goal difference
void calGoalDif(struct team *team);

int main(int argc, char *argv[])
{
    struct team group[4];
    int i;

    inititializeGroup(group);
    for (int i = 0; i < 4; i++)
    {
        calPoints(&group[i]);
        calGoalDif(&group[i]);
    }
    sortGroupByPoints(group);
    outputGroupInTable(group, 4);
    outputGroupToCSVFile(group, 4);

    return EXIT_SUCCESS;
}


void inititializeGroup(struct team group[])
{
    strcpy(group[0].name, "Austria");
    strcpy(group[1].name, "Germany");
    strcpy(group[2].name, "Italy");
    strcpy(group[3].name, "France");

    group[0].wins = 5;
    group[1].wins = 5;
    group[2].wins = 9;
    group[3].wins = 5;

    group[0].draws = 1;
    group[1].draws = 1;
    group[2].draws = 1;
    group[3].draws = 1;

    group[0].loses = 1;
    group[1].loses = 1;
    group[2].loses = 1;
    group[3].loses = 1;

    strcpy(group[0].goaldifference, "5:1");
    strcpy(group[1].goaldifference, "7:4");
    strcpy(group[2].goaldifference, "2:1");
    strcpy(group[3].goaldifference, "3:3");
}

void outputGroupInTable(struct team group[], int groups)
{
        int i = 0;

    printf("Name\t\tWins\tDraws\tLoses\tGoal Difference\t Points\n-----------------------------------------------------------------------\n");

    for (i = 0; i < groups; i++)
    {
        printf("%-10s \t  %d  \t %d \t %d \t    %s \t %d\n", group[i].name, group[i].wins, group[i].draws, group[i].loses, group[i].goaldifference, group[i].points);
        printf("-----------------------------------------------------------------------\n");
    }


}

void outputGroupToCSVFile(struct team group[], int groups)
{
    int i;
    FILE *fpt;

    fpt = fopen("groups.csv", "w+");

    fprintf(fpt, "name, wins, draws, loses, goal difference, points\n");

    for (i = 0; i < groups; i++)
    {
        fprintf(fpt, "%s, %d, %d, %d, %s, %d\n", group[i].name, group[i].wins, group[i].draws, group[i].loses, group[i].goaldifference, group[i].points);
    }
    fclose(fpt);

}

void calPoints(struct team *team)
{
    team->points = team->wins * 3 + team->draws;
}

void sortGroupByPoints(struct team group[])
{
    int i = 0, j = 0;
    struct team k;
    int len = 5;


    for (i = 0; i < len - 1; i++)
    {
        for (j = 0; j < len - 1 - 1; j++)
        {
            if (group[j].points < group[j + 1].points)
            {
                k = group[j];
                group[j] = group[j + 1];
                group[j + 1] = k;
            }
            else if(group[j].points == group[j + 1].points)
            {
                if (group[j].goalDif < group[j + 1].goalDif)
                {
                    k = group[j];
                    group[j] = group[j + 1];
                    group[j + 1] = k;
                }
            }
        }
    }
}

void calGoalDif(struct team *team)
{
    long goaldifference;
    long temp[2] = {0};
    char *eptr = NULL;
    int i = 0;

    char *p = team->goaldifference;

    while (*p)
    {
        if ( isdigit(*p) && isdigit(*(p+1)) )
        {
            temp[i] = strtol(p, &p, 10);
            i++;
        }
        else
        {
            p++;
        }
    }

    goaldifference = temp[0] - temp[1];
    team->goalDif = goaldifference;
}
