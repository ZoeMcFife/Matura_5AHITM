package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main
{
    public static void main(String[] args)
    {
        printArray(getIntArray());
    }

    static int[] getIntArray()
    {
        int arrayLength = 0;

        System.out.println("Array Length?");
        arrayLength = readInt();

        int[] array = new int[arrayLength];

        for (int i = 0; i < arrayLength; i++)
        {
            System.out.println("Enter Integer:");
            array[i] = readInt();
        }

        return array;
    }

    static void printArray(int[] array)
    {
        for (int current : array)
        {
            System.out.println(current);
        }

        for (int i = 0; i < array.length; i++)
        {
            System.out.println(array[i]);
        }
    }

    public static int readInt()
    {
        BufferedReader br;
        String inputString;
        int value = 0;

        br = new BufferedReader(new InputStreamReader(System.in));

        try
        {
            inputString = br.readLine();
            value = Integer.parseInt(inputString);
        }
        catch(IOException e)
        {
            System.out.println("Read Error!");
        }
        catch(NumberFormatException ex)
        {
            System.out.println("Value is not an Integer!");
        }
        return value;
    }
}
