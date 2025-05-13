package com.company;

import java.util.Arrays;

public class EuroBanknote
{
    private String nzbNumber;
    private int series;

    // Constructor

    EuroBanknote(String nzbNumber, int series)
    {
        setNzbNumber(nzbNumber);
        setSeries(series);
    }

    // Getter / Setters

    public String getNzbNumber()
    {
        return nzbNumber;
    }

    public void setNzbNumber(String nzbNumber)
    {
        if (nzbNumber.length() != 12)
        {
            System.err.println("setNzbNumber: invalid nzbNumber");
            return;
        }

        this.nzbNumber = nzbNumber;
    }

    public int getSeries()
    {
        return series;
    }

    public void setSeries(int series)
    {
        if (series <= 1)
        {
            this.series = 1;
        }
        else if (series >= 2)
        {
            this.series = 2;
        }
    }

    public char getCheckNumber()
    {
        return (nzbNumber.toCharArray()[11]);
    }

    // Functions

    public boolean isValid()
    {
        char[] serial = convertNzbNumberToDigits().toCharArray();
        serial = Arrays.copyOf(serial, serial.length - 1); // removes last number

        int sum = 0;
        int checkNumResult;

        for (char i : serial)
        {
            sum += Character.getNumericValue(i);
        }

        checkNumResult = (this.series == 1 ? 8 : 7) - (sum % 9);

        if (checkNumResult == 0)
        {
            checkNumResult = 9;
        }

        return checkNumResult == Character.getNumericValue(getCheckNumber());
    }

    private String convertNzbNumberToDigits()
    {
        if (this.series == 1)
        {
            return findPositionOfLetterInAlphabet(nzbNumber.toCharArray()[0]) + nzbNumber.substring(1);
        }

        return findPositionOfLetterInAlphabet(nzbNumber.toCharArray()[0]) + findPositionOfLetterInAlphabet(nzbNumber.toCharArray()[1]) + nzbNumber.substring(1);
    }

    private static int findPositionOfLetterInAlphabet(char letter)
    {
        return Character.toLowerCase(letter) - 96;
    }

    // to String

    @Override
    public String toString()
    {
        return "EuroBanknote{" +
                "nzbNumber='" + nzbNumber + '\'' +
                '}';
    }
}
