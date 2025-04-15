package Regex;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class TransformNumbers
{
    TransformNumbers()
    {
        System.out.println(transformIntoText("99 persons are invited by 10 friends."));
    }

    private String transformIntoText(String input)
    {
        StringBuilder output = new StringBuilder();

        String findNumberRegex = "[0-9]+";

        Pattern p = Pattern.compile(findNumberRegex);

        Matcher m = p.matcher(input);

        int lastIndex = 0;

        while (m.find())
        {
            output.append(input, lastIndex, m.start()).append(EnglishNumberToWords.convert(Long.parseLong(m.group())));
            lastIndex = m.end();
        }

        if (lastIndex < input.length())
        {
            output.append(input, lastIndex, input.length());
        }

        return output.toString();
    }
}
