package Regex;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class MyNamedGroup {
    public static void main(String[] args) {
        /* prepare the regular expression */
        String regex =
                "\\b(?<areaCode>\\d{3})(?<prefix>\\d{3})(?<lineNumber>\\d{4})\\b";

        /* reference first two groups by names and the third one as its number */
        String replacementText = "(${areaCode}) ${prefix}-$3";
        String source = "6641234567, 2239829, and 6762345678";

        /* compile the regular expression */
        Pattern p = Pattern.compile(regex);

        /* get Matcher object */
        Matcher m = p.matcher(source);

        /* replace the phone numbers by formatted phone numbers */
        String formattedSource = m.replaceAll(replacementText);

        System.out.println("Text: " + source);
        System.out.println("Formatted Text: " + formattedSource);
    }

}