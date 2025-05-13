package Kobold;

public class CoboldTest
{
    public static void main(String[] args)
    {
        Cobold pum = new Cobold("Pum", new Delay(3), new Blur(2000));

        System.out.println(pum.messUp(30));
    }

}
