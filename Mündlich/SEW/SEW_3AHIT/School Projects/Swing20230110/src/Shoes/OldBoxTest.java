package Shoes;

public class OldBoxTest
{
    public static void main(String[] args)
    {
        Shoes shoe = new Shoes(1204, "Blarn");
        OldBox box = new OldBox(shoe);

        System.out.println(((Shoes)(box.getContent())).getColor());

        Object content = box.getContent();

        if (content instanceof Shoes) // to prevent runtime exceptions
        {
            Shoes shoesFromBox = (Shoes) content; // .getContent() always returns Type Object so you have to cast it first
            System.out.println(shoesFromBox.getColor());
        }

    }
}
