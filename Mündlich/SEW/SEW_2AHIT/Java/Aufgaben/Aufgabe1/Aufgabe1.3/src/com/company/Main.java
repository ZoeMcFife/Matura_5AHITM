package com.company;

public class Main
{
    public static void main(String[] args)
    {
        for (int i = 20; i < 100; i++)
        {
            System.out.println("w="+ i + " " + getGermanWordForNumber(i));
        }
    }

    static String getGermanWordForNumber(int number)
    {
        if (number < 20 || number > 99) return "";

        int digit01 = number % 10;
        int digit10 = (number / 10) % 10;

        String word;

        String[] digitNamesFor01 = {"", "ein", "zwei", "drei", "vier", "fünf", "sechs", "sieben", "acht", "neun"};
        String[] digitNamesFor10 = {"", "", "zwan", "drei", "vier", "fünf", "sechs", "sieb", "acht", "neun"};

        // A name of a number is split into four low level parts:       Example: 56 --> sechs, und, fünf, zig
        // Exception: 20, 30, 40, ...                                   Example: 50 --> fünf, zig

        String part1;
        String part2;
        String part3;
        String part4;

        if (digit10 == 3)
            part4 = "ßig";
        else
            part4 = "zig";

        if (digit01 == 0)
        {
            part1 = digitNamesFor10[digit10];

            part3 = "";
            part2 = "";
        }
        else
        {
            part1 = digitNamesFor01[digit01];
            part2 = "und";
            part3 = digitNamesFor10[digit10];
        }

        word = part1 + part2 + part3 + part4;

        return word;
    }
}
