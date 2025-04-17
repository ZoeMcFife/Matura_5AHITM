package Regex;


import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class MyPatternMatcher {
    public static void findPattern(String regex, String source) {
        /* compile regex into a Pattern object */
        Pattern p = Pattern.compile(regex);

        /* get the Matcher object */
        Matcher m = p.matcher(source);

        /* print regex and source text */
        System.out.println("\nRegex: " + regex);
        System.out.println("Text: " + source);

        /* perform find */
        boolean found = false;
        while (m.find()) {
            System.out.println("Matched Text: " + m.group() +
                    ", Start: " + m.start() + ", " + " End: " + m.end());

            /* found at least one match */
            found = true;
        }

        if(!found) {
            /* no match was found */
            System.out.println("No match found.");
        }
    }

    public static void main(String[] args) {
        String regex = "[abc]@.";

        String source = "cric@somewhere.com is a valid e-mail address";
        MyPatternMatcher.findPattern(regex, source);

        source = "kelly@somewhere.com is invalid";
        MyPatternMatcher.findPattern(regex, source);

        source = "a@band@yea@u";
        MyPatternMatcher.findPattern(regex, source);

        source = "There is an @ sign here";
        MyPatternMatcher.findPattern(regex, source);
    }

}