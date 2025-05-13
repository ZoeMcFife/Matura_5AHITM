package com.company;

import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Hangman
{
    private ArrayList<Character> wrongCharacters = new ArrayList<Character>();
    private ArrayList<String> words = new ArrayList<String>();
    private String selectedWord;
    private ArrayList<Character> correctCharacters = new ArrayList<Character>();
    private ArrayList<Integer> correctIndexesOfGuessedWord = new ArrayList<Integer>();

    public void addToWordList(String word)
    {
        words.add(word);
    }

    public void addToWordList(String[] word)
    {
        for (String str : word)
        {
            words.add(str);
        }
    }

    public void clearWordList()
    {
        words.clear();
    }

    private String getRandomWord()
    {
        try
        {
            return words.get((int)(Math.random() * words.size()));
        }
        catch (Exception e)
        {
            return "Error";
        }
    }

    private boolean isGuessCorrect(char guess)
    {
        return this.selectedWord.contains(Character.toString(guess));
    }

    private boolean hasWordBeenGuessed()
    {
        for (int i = 0; i < selectedWord.length(); i++)
        {
            if (selectedWord.toCharArray()[i] != correctCharacters.get(i))
            {
                return false;
            }
        }

        return true;
    }

    private void updateIndexesOfGuess(char guess)
    {
        char[] word = selectedWord.toCharArray();

        for (int i = 0; i < word.length; i++)
        {
            if (word[i] == guess)
            {
                correctIndexesOfGuessedWord.add(i);
            }
        }
    }

    private void updateGuessedWord()
    {
        char[] word = selectedWord.toCharArray();

        for (int i = 0; i < word.length; i++)
        {
            if (correctIndexesOfGuessedWord.contains(i))
            {
                correctCharacters.set(i, word[i]);
            }
        }
    }

    public void initializeGame()
    {
        selectedWord = getRandomWord();

        for (int i = 0; i < selectedWord.length(); i++)
        {
            correctCharacters.add('_');
        }

        Frame frame = new Frame()
        {
            private static final long serialVersionUID = 1L;

            public void paint(Graphics graphics)
            {
                setTitle("Hangman");
                graphics.setFont(new Font("Helvetica", Font.PLAIN, 15));
                graphics.setColor(Color.orange);

                if (hasWordBeenGuessed())
                {
                    String title = "You won";

                    graphics.drawString(title, 50, 200);

                    return;
                }

                if (wrongCharacters.size() == 7)
                {
                    String title = "You lost :(";

                    graphics.drawString(title, 50, 200);

                    return;
                }

                String wrongTitle = "Wrong:   ";
                for (char z : wrongCharacters)
                {
                    wrongTitle = wrongTitle + z + " ";
                }
                graphics.drawString(wrongTitle, 30, 230);

                String correctTitle = "Correct: ";
                for (char z : correctCharacters)
                {
                    correctTitle = correctTitle + z + " ";
                }
                graphics.drawString(correctTitle, 30, 250);

                int counter = wrongCharacters.size();
                if (counter > 7)
                    counter = 7;

                switch (counter)
                {
                    case 7:
                        graphics.drawLine(120, 140, 110, 170);
                    case 6:
                        graphics.drawLine(120, 140, 130, 170);
                    case 5:
                        graphics.drawLine(120, 110, 120, 140);
                        graphics.drawLine(100, 120, 140, 120);
                    case 4:
                        graphics.drawOval(110, 90, 20, 20);
                        graphics.drawOval(114, 95, 5, 3);
                        graphics.drawOval(122, 95, 5, 3);
                        graphics.drawOval(118, 102, 5, 5);
                    case 3:
                        graphics.drawLine(120, 80, 180, 80);
                        graphics.drawLine(120, 90, 120, 80);
                    case 2:
                        graphics.drawLine(180, 80, 180, 170);
                    case 1:
                        graphics.drawArc(160, 170, 40, 40, 0, 180);
                    case 0:
                        graphics.setColor(Color.black);
                        graphics.drawRect(28, 58, 244, 134);
                        graphics.drawRect(30, 60, 240, 130);
                }

            };
        };
        frame.setBounds(0, 0, 300, 270);
        frame.addWindowListener(new WindowAdapter()
        {
            public void windowClosing(WindowEvent e)
            {
                System.exit(0);
            }
        });
        frame.setVisible(true);

        System.out.println("TIPP: " + this.selectedWord);
        int guessesLeft = 7;

        while (guessesLeft > 0)
        {
            System.out.println("Guesses left: " + guessesLeft);
            System.out.print("Your Guess: ");

            char input = readChar();

            if (!isGuessCorrect(input))
            {
                wrongCharacters.add(input);
                guessesLeft--;
            }
            else
            {
                updateIndexesOfGuess(input);
                updateGuessedWord();
            }

            frame.repaint();
        }
    }

    private static char readChar()
    {
        BufferedReader br;
        String inputString;
        char retval = '?';

        br = new BufferedReader(new InputStreamReader(System.in));

        try
        {
            inputString = br.readLine();
            retval = inputString.charAt(0);
        }
        catch (Exception e)
        {
            System.out.println("Not a char!");
        }

        return retval;
    }
}


