package moreLambda;

import java.util.Arrays;
import java.util.List;
import java.util.Locale;

public class listOfStrings
{
    public static void main(String[] args)
    {
        String[] msg = {"Java", "MAKES", "us", "depressed!"};
        List<String> lst = Arrays.asList(msg);

        lst.forEach(s -> System.out.println(s.toLowerCase(Locale.ROOT)));
    }
}
