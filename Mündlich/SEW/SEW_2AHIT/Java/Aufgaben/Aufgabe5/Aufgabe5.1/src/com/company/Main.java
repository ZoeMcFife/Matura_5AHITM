package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        printPKWArray(getPKWArray());
    }

    static PKW[] getPKWArray()
    {
        Scanner scanner = new Scanner(System.in);
        int arraySize;

        System.out.println("How many PKWs?");
        arraySize = scanner.nextInt();

        if (arraySize <= 0)
            arraySize = 1;

        PKW[] pkwArray = new PKW[arraySize];

        for (int i = 0; i < arraySize; i++)
        {
            int horsepower;
            String brand;

            System.out.println("Create new PKW:");

            System.out.println();

            System.out.print("Brand?: ");
            brand = readString();

            System.out.println();

            System.out.print("Horsepower?: ");
            horsepower = scanner.nextInt();

            System.out.println();
            pkwArray[i] = new PKW(brand, horsepower);
        }

        return pkwArray;
    }

    static void printPKWArray(PKW[] array)
    {
        for (PKW i : array)
        {
            System.out.println(i);
        }
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
