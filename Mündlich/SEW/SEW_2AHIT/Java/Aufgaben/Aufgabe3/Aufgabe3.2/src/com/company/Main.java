package com.company;

import java.util.Arrays;
import java.util.Calendar;
import java.util.GregorianCalendar;

public class Main
{
    public static void main(String[] args)
    {
        if (args.length != 3 ) Usage();

        int day = Integer.parseInt(args[0]);
        int month = Integer.parseInt(args[1]);
        int year = Integer.parseInt(args[2]);

        if (day > 31 || day < 1 || month > 12 || month < 1 || year < 1) Usage();

        printCalender(getCalenderArray(year, month, day));
    }

    public static void Usage()
    {
        System.out.println("Usage: Main DAY MONTH YEAR");
        System.exit(1);
    }

    static String[] getCalenderArray(int year, int month, int day)
    {
        String[] monthAbbreviations = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

        GregorianCalendar calendarDate = new GregorianCalendar(year, month - 1, day);
        GregorianCalendar firstDayOfMonth = new GregorianCalendar(year, month - 1, 1);
        int lastDayOfMonth = calendarDate.getActualMaximum(Calendar.DATE);

        String[] calenderArray = new String[6*7 + 3];
        Arrays.fill(calenderArray, "    ");

        calenderArray[6*7 + 2] = Integer.toString(year);
        calenderArray[6*7 + 1] = monthAbbreviations[month - 1];
        calenderArray[6*7] = day + ".";

        int shift = getCalenderShift(firstDayOfMonth);

        int currentDay = 1;
        for (int i = shift; i <= lastDayOfMonth + shift - 1; i++)
        {
            if (currentDay < 10)
            {
                calenderArray[i] = "  " + currentDay + " ";
            }
            else
            {
                calenderArray[i] = " " + currentDay + " ";
            }

            if (currentDay < 10 && currentDay == day)
            {
                calenderArray[i] = " <" + currentDay + ">";
            }
            else if (currentDay == day)
            {
                calenderArray[i] = "<" + currentDay + ">";
            }

            currentDay++;
        }

        return calenderArray;
    }

    static int getCalenderShift(GregorianCalendar firstDay)
    {
        int weekday = firstDay.get(Calendar.DAY_OF_WEEK);

        // Sunday is the first day of the week according to Java. Not fun.
        if (weekday == 1)
            weekday = 6;
        else
            weekday -= 2;

        return weekday;
    }

    static void printCalender(String[] calenderArray)
    {
        System.out.println("         " + calenderArray[6*7] + " " + calenderArray[6*7+1] + " " + calenderArray[6*7 + 2]);
        System.out.println("----------------------------");
        int currentDay = 0;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                System.out.print(calenderArray[currentDay]);
                currentDay++;
            }
            System.out.println();
        }
    }
}
