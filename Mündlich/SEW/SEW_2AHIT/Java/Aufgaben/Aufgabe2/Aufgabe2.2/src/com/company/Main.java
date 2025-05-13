package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args)
    {
        System.out.print("String1: ");
        String string1 = readString();
        System.out.println();
        System.out.print("String2: ");
        String string2 = readString();

        System.out.println("Match: " + findLongestMatch(string1, string2));
    }

    static String findLongestMatch(String string1, String string2)
    {
        String match = "No match found";
        int largestMatchLengthFound = 1;

        if (string1.equals(string2)) return string1;
        if (string1.isEmpty() || string2.isEmpty()) return "Invalid Input";

        //Swaps to the shortest string to improve performance
        if (string1.length() > string2.length())
        {
            String temp = string1;
            string1 = string2;
            string2 = temp;
        }

        // Loops through every substring
        for (int j = string1.length(); j > 0; j--)
        {
            for (int i = 0; i < string1.length(); i++)
            {
                if (i >= j)
                    continue;

                String contained = string1.substring(i, j);

                if (string2.contains(contained) && contained.length() > largestMatchLengthFound)
                {
                    largestMatchLengthFound = contained.length();
                    match = contained;
                }
            }
        }

        return match;
    }

    public static String readString()
    {
        BufferedReader br;
        String inputString = "";

        br = new BufferedReader(new InputStreamReader(System.in));

        try
        {
            inputString = br.readLine();
        }
        catch(IOException e)
        {
            System.out.println("Read Error!");
        }

        return inputString;
    }

}
