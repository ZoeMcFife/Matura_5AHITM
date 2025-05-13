package Shoes;

import java.util.Comparator;

public class ShoesComparator extends Shoes implements Comparator<ShoesComparator>
{

    public ShoesComparator(int size, String color)
    {
        super(size, color);
    }


    @Override
    public int compare(ShoesComparator o1, ShoesComparator o2)
    {
        int result = 0;

        int sizeComparing = Integer.valueOf(o1.getSize()).compareTo(o2.getSize());
        int colorComparing = o1.getColor().compareTo(o2.getColor());

        if (sizeComparing != 0)
            result = sizeComparing;

        if (colorComparing != 0)
            result = colorComparing;

        return result;
    }
}
