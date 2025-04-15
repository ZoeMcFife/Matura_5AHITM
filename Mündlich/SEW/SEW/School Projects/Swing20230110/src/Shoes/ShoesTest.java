package Shoes;

import java.util.ArrayList;
import java.util.List;

public class ShoesTest
{
    public static void main(String[] args)
    {
        ShoesComparator s1 = new ShoesComparator(1, "banana");
        ShoesComparator s2 = new ShoesComparator(2, "ama on reddit");
        ShoesComparator s3 = new ShoesComparator(1, "among us");
        ShoesComparator s4 = new ShoesComparator(4, "fog");
        ShoesComparator s5 = new ShoesComparator(3, "dog");

        List<ShoesComparator> shoesComparatorList = new ArrayList<>();
        shoesComparatorList.add(s1);
        shoesComparatorList.add(s2);
        shoesComparatorList.add(s3);
        shoesComparatorList.add(s4);
        shoesComparatorList.add(s5);


        System.out.println(shoesComparatorList);

        shoesComparatorList.sort(new ShoesComparator(1, "2"));

        System.out.println(shoesComparatorList);
    }
}
