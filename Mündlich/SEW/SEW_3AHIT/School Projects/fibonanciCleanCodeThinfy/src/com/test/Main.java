package com.test;

public class Main
{
    public static void main(String[] args)
    {
        int amount = 20;
        int[] fibonacciNumbers = generateFibonacciNumbers(amount);

        printArray(fibonacciNumbers);
    }

    private static void printArray(int[] array)
    {
        for (int i : array)
        {
            System.out.println(i);
        }
    }

    private static int[] generateFibonacciNumbers(int amount)
    {
        int[] fibonacciNumbers = new int[amount];

        int initializedValues = 2;
        initializeArray(fibonacciNumbers, initializedValues);

        for (int currentIndex = 2; currentIndex < amount; currentIndex++)
        {
            fibonacciNumbers[currentIndex] = fibonacciNumbers[currentIndex - 1] + fibonacciNumbers[currentIndex - 2];
        }

        return fibonacciNumbers;

    }

    private static void initializeArray(int[] array, int amount)
    {
       for (int index = 0; index < Math.min(amount, array.length); index++)
       {
           array[index] = 1;
       }
    }
}
