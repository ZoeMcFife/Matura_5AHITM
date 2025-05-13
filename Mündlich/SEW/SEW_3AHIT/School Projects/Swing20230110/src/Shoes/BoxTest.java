package Shoes;

public class BoxTest
{
    public static void main(String[] args)
    {
        Shoes myshoes = new Shoes(24, "sad");
        Box<Shoes> box = new Box<>(myshoes);

        Box<Cat> box1 = new Box<Cat>(new Cat("catto"));

        System.out.println(box.getContent().getColor());
        System.out.println(box1.getContent().name);

    }
}
