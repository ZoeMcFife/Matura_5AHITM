package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Locale;

public class Main
{
    public static void main(String[] args)
    {
        String string = readString();

        stringMethodsTest(string);
    }

    private static void stringMethodsTest(String string)
    {
        System.out.println("Lenght:" + string.length());
        System.out.println("3rd Char: " + string.charAt(2));
        System.out.println("Substring 2 - 5: " + (string.length() >= 6 ? (string.substring(2, 6)) : "no substring"));
        System.out.println("Is lower: " + string.equals(string.toLowerCase()));
        System.out.println("Is upper: " + string.equals(string.toUpperCase()));
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
