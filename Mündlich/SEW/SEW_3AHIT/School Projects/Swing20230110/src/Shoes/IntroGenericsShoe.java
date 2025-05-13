package Shoes;

import java.util.ArrayList;
import java.util.List;

public class IntroGenericsShoe
{
    public static void main(String[] args)
    {
        List<Shoes> shoes = new ArrayList<Shoes>();
        List<Shoes> moreShoes = new ArrayList<>();

        shoes.add(new Shoes(30, "bawonga"));
        System.out.println(shoes.get(0).getColor());
    }
}
