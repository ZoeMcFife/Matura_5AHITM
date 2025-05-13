package Regex;

import java.util.Locale;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ChangeTextFragments
{
    ChangeTextFragments()
    {
        System.out.println(transformText(" HI Friend ! Leo MUST LEAVE !"));
    }

    public String transformText(String string)
    {
        String regex = "\\b(?<uppercase>[A-Z]{3,})\\b";

        Pattern p = Pattern.compile(regex);

        Matcher m = p.matcher(string);

        String formattedSource = m.replaceAll(a -> a.group().toLowerCase());

        return formattedSource;
    }
}
