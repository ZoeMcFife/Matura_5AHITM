package Lambdas;

import java.util.Comparator;

public class ExcerciseComparator implements Comparator<Exercise>
{
    @Override
    public int compare(Exercise o1, Exercise o2)
    {
        if (o1.theResult == o2.theResult)
            return o1.name.compareTo(o2.name);

        return Integer.compare(o1.theResult, o2.theResult);
    }
}
