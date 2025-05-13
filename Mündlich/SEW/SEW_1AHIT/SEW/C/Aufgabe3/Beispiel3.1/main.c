#include <stdio.h>
#include <stdlib.h>

//title:        Day or Easter Sunday Calculator
//Author:       Leonard Bunea
//Description:  Calculates the weekday or easter sunday
//Last Change:  2020/12/15

int weekday(int year, int month, int day);
int eastersunday(int year);
char easterSundayMonth[];

int main()
{
    int year, month, day;
    char menuOption;

    printf("Do you want to calculate the weekday of a day or the easter sunday of a year? (w / e):    ");
    menuOption = getchar();
    printf("\n");

    //outputs the day or easter sunday, based on user selection
    if (menuOption == 'w')
    {
        printf("Enter year: ");
        scanf("%d", &year);
        printf("Enter month: ");
        scanf("%d", &month);
        printf("Enter day: ");
        scanf("%d", &day);

        printf("\n");

        printf("That day is a %s.", weekday(year, month, day));
    }
    else if (menuOption == 'e')
    {
        printf("Enter year: ");
        scanf("%d", &year);

        printf("\n");

        eastersunday(year);
    }
    else
    {
        printf("invalid selection \n");
    }

    return EXIT_SUCCESS;
}

int weekday(int year, int month, int day) //calculates weekday
{
    int h;
    int k;
    int a;
    int b;
    int c;
    int n;

    //calculations
    if (month > 2)
    {
        month -= 3;
    }

    h = year / 100;
    k = year % 100;
    a = (146097 * h) / 4;
    b = (1461 * k) / 4;
    c = (153 * month + 2) / 5;

    n = a + b + c + day + 1721119;

    n = n % 7;

    //returns weekday
    switch (n)
    {
    case 0:
        return "monday";
    case 1:
        return "tuesday";
    case 2:
        return "wednesday";
    case 3:
        return "thursday";
    case 4:
        return "friday";
    case 5:
        return "saturday";
    case 6:
        return "sunday";
    }
}

int eastersunday(int year)              //calculates easter sunday date
{
    int h, u, v, w, m, n, a, b, c, d, e;
    int marchDate, aprilDate;

    //calculations
    h = year / 100;
    u = h / 4;
    v = (h - 17) / 25;
    w = (h - v) / 3;
    m = (15 + h - u - w) % 30;
    n = (4 + h - u) % 7;
    a = year % 19;
    b = year % 4;
    c = year % 7;
    d = (19 * a + m) % 30;
    e = (2 * b + 4 * c + 6 * d + n) % 7;

    //calculates the date in march and april
    marchDate = 22 + d + e;
    aprilDate = d + e - 9;

    if (aprilDate == 26)
    {
        aprilDate = 19;
    }
    else if (aprilDate == 25 && d == 28 && e == 6 && a > 10)
    {
        aprilDate = 18;
    }

    if (marchDate > 31 || marchDate < 1)                    //checks which date is valid and returns them
    {
        printf("Easter Sunday is on: %d April", aprilDate);
        return aprilDate;
    }
    else if (aprilDate > 30 || aprilDate < 1)
    {
        printf("Easter Sunday is on: %d March", marchDate);
        return marchDate;
    }
}

