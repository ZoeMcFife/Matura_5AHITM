package Regex;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class DefiningRegex
{
    DefiningRegex()
    {
        String digits10Regex = "(1234567890)";
        String digits5to10LettersRegex = "[A-Za-z0-9]{5,10}";
        String endWithRegex = "(.*[\\\\.\\\\!\\\\?])$";
        String nonEmptyStringWithNoDigitsRegex = "^(\\D*)$";
        String titleRegex = "([\\w]*[\\.])";

        MyPatternMatcher.findPattern(digits10Regex, "1234567890");
        MyPatternMatcher.findPattern(digits5to10LettersRegex, "15153a");
        MyPatternMatcher.findPattern(endWithRegex, "meow?");
        MyPatternMatcher.findPattern(nonEmptyStringWithNoDigitsRegex, "thisisastring1");
        MyPatternMatcher.findPattern(titleRegex, "Mr. Bean");

    }




}
