package Kobold;

public class KoboldTest
{
    public static void main(String[] args)
    {
        koboldTest(new Kobold("Max", 1));
        koboldTest(new Kobold("Moritz", 2000));
        koboldTest(new Kobold("Maru", 5));
        koboldTest(new SlowKobold("Pumuckl", 1));
        koboldTest(new SlowKobold("BlauerKabauter", 5));
    }

    private static void koboldTest(Kobold kobold)
    {
        System.out.println("Kobold Test: " + kobold.toString());

        for (int i = 10; i < 100; i+=10)
        {
            System.out.println("MessUp " + i + ": " + kobold.messUp(i));
        }

        System.out.println("Test Complete\n");
    }
}
