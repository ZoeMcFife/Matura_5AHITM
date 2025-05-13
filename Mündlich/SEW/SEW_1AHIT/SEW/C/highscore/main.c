#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct highscore
{
    char user[101];
    long score;
};

int readScore(struct highscore highscore[]);

int main()
{
    struct highscore highscore[1000];

    readScore(highscore);

    return EXIT_SUCCESS;
}

int readScore(struct highscore highscore[])
{
    FILE *fp = NULL;
    char line[1025] = "";
    int i = 0, j = 0;
    char *eptr = NULL;

    fp = fopen("highscore.csv", "rt");

    if(fp == NULL)
    {
        printf("READ ERROR\n");
        return EXIT_FAILURE;
    }

    while(fgets(line, sizeof(line), fp) != NULL)
    {
        while(line[j] != ";")
        {
            highscore[i].user[j] = line[j];
            printf("%c\n", line[j]);
            j++;
        }
        highscore[i].user[j] = '\0';
        printf("%s\n", highscore[i].user);

        highscore[i].score = strtol(&line[j + 1], &eptr, 10);
        if (*eptr == '\n')
        {
            return EXIT_FAILURE;
        }
        printf("%ld\n", highscore[i].score);
        j = 0;
        i++;
    }

    if (fp != NULL)
        fclose(fp);

    return i;
}
