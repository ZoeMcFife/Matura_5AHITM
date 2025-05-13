package com.company;

import java.util.ArrayList;
import java.util.List;

public class Main
{
    public static void main(String[] args)
    {
        Hangman hangman = new Hangman();

        String str[] = {"word", "test", "another word", "cool word", "complicated word", "dog", "long word"};

        hangman.addToWordList(str);

        hangman.initializeGame();
    }
}
