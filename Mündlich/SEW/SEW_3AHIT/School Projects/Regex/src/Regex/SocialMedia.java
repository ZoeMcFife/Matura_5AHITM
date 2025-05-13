package Regex;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class SocialMedia
{
    SocialMedia()
    {
        System.out.println(countUsages("Make me see the world #firstnamelastname Hello @firstnamelastname, where is the best job for me in this world? When will I take the train to Paris?"));
    }

    private int countUsages(String input)
    {
        String nameRegex = "(((#(firstnamelastname))|(@(firstnamelastname))))";
        Pattern p = Pattern.compile(nameRegex);
        Matcher m = p.matcher(input);

        int usages = 0;

        while (m.find())
        {
            usages++;
        }

        return usages;
    }
}
