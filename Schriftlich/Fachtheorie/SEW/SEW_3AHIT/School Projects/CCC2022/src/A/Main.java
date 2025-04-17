package A;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public class Main
{
    public static void main(String[] args)
    {
        printToFile(Integer.toString(countB(getStrFromFile("level1_1.in"))), "level1_1.out");
        printToFile(Integer.toString(countB(getStrFromFile("level1_2.in"))), "level1_2.out");
        printToFile(Integer.toString(countB(getStrFromFile("level1_3.in"))), "level1_3.out");
        printToFile(Integer.toString(countB(getStrFromFile("level1_4.in"))), "level1_4.out");
        printToFile(Integer.toString(countB(getStrFromFile("level1_5.in"))), "level1_5.out");
    }

    public static String[] getDictionaryFromFile(String filename)
    {
        FileReader fileReader = new FileReader(filename);

    }


    public static void printToFile(String str, String filename)
    {
        Path file = Path.of(filename);

        try
        {
            Files.writeString(file, str);
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }

    public static String getStrFromFile(String filename)
    {
        char[] charArray = new char[100000];

        try
        {
            FileReader fileReader = new FileReader(filename);

            fileReader.read(charArray);

            return new String(charArray);
        }
        catch (FileNotFoundException e)
        {
            e.printStackTrace();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }

        return "";
    }

    public static int countB(String string)
    {
        char[] charArray = string.toCharArray();
        int count = 0;

        for (char c : charArray)
        {
            if (c == 'B')
            {
                count++;
            }
        }

        return count;
    }
}
