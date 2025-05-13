package com.company;

import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        int count;
        int lowerBound;
        int upperBound;

        Scanner scanner = new Scanner(System.in);

        System.out.println("Count:");
        count = scanner.nextInt();

        System.out.println("Lower Bound:");
        lowerBound = scanner.nextInt();

        System.out.println("Upper Bound:");
        upperBound = scanner.nextInt();

        System.out.println();

        createRandomNumbers(count, lowerBound, upperBound);
    }

    static void createRandomNumbers(int count, int lowerBound, int upperBound)
    {
        if (count <= 0 || lowerBound > upperBound) return;

        int half = (lowerBound + upperBound) / 2;
        int aboveHalf = 0;
        int percentageAbove;
        int percentageBelow;

        for (int i = 0; i < count; i++)
        {
            int random = (int) (Math.random() * upperBound + lowerBound);
            if (random > half)
            {
                aboveHalf++;
            }

            System.out.println("Random number: " + random);
        }

        percentageAbove = (int) (((double) aboveHalf / count) * 100);
        percentageBelow = (int) ((double)(count - aboveHalf) / count * 100);

        System.out.println();

        System.out.println("Percentage above half: " + percentageAbove + "%");
        System.out.println("Percentage below half: " + percentageBelow + "%");
    }
}
