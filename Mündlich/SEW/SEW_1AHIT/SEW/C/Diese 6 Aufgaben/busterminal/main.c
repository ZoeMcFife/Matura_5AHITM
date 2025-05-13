#include <stdio.h>
#include <stdlib.h>

//Title:        Busterminal
//Author:       Leonard Bunea
//Description:  Calculates time till the next bus
//Last Change:  2020/12/02

int nextBus(int time);

int main()
{
    int currentTime;
    int nextBusTime;
    int timeTillNextBus;

    printf("What time is it?: ");       //gets current time from user
    scanf("%d", &currentTime);

    if (currentTime > 2400 || currentTime % 100 > 59)       //checks if time is valid
    {
        printf("Invalid time");
        return EXIT_FAILURE;
    }
    else
    {
        nextBusTime = nextBus(currentTime);                         //time till next Bus
        if (nextBusTime != currentTime)                             //checks if bus is already here
        {
            timeTillNextBus = 60 + nextBusTime%100 - currentTime%100;   //calculates time till next bus in minutes

            if (timeTillNextBus > 30 && timeTillNextBus < 60)   //reduces time by 30 or 60 to get correct time
            {
                timeTillNextBus -= 30;
            }
            else if (timeTillNextBus > 60)
            {
                timeTillNextBus -= 60;
            }
            printf("The next bus will come in %d minutes. (%d:%02d)", timeTillNextBus, (nextBusTime - nextBusTime%100)/100, nextBusTime%100);  //print out time when the next bus will come
        }
        else
        {
            printf("The bus is already here.");
        }

        return EXIT_SUCCESS;
    }
}

int nextBus(int time)
{
    int nextBusTime;
    int hour;
    int minute;

    minute = time % 100;                //splits time into hours and minutes
    hour = (time - time % 100) / 100;

    if (minute == 0)                    //checks if bus is already here (time is xx:00 or xx:30)
    {
        nextBusTime = time;

        return nextBusTime;
    }
    else if (minute == 30)
    {
        nextBusTime = time;

        return nextBusTime;
    }
    else
    {
        if (minute < 30)
        {
            minute = 30 - minute;   //calculates how much time is needed till xx:30 and adds it to time.
            time += minute;
        }
        else if ( minute > 30)
        {
            time = time - minute + 100; //subtracts minutes from time to get to xx:00 and adds 1 hour
        }

        nextBusTime = time;

        return nextBusTime;
    }
}
