package Kobold;

public class CoboldTest
{
    public static void main(String[] args)
    {
        Cobold kobo = new Cobold("Kobo", new Blur(5));
        HonestCobold hon = new HonestCobold("Hon", new Blur(5));
        hon.beHonestFor(5);
        Cobold rot = new Cobold("Rot", new Delay(2));
        Cobold mo = new Cobold("Mo", new Delay(5), new Friend(kobo));
        Cobold blarn = new Cobold("Blarn", new Odds(new Blur(10)));

        coboldTest(kobo);
        coboldTest(hon);
        coboldTest(blarn);
        coboldTest(mo);
        coboldTest(rot);
        coboldTest(hon);

        Cobold max = new Cobold("Max", new Blur(1));
        Cobold pumuckl = new Cobold("Pumuckl", new Delay(1));
        coboldTest(new Cobold("Freak",
                new Odds(new Delay(1)),
                new Friend(max),
                new Friend(pumuckl)));

        coboldTest(new Cobold("Evil Cobold", new Theft(20, false)));

    }

    public static void coboldTest(Cobold cobold)
    {
        System.out.println("Cobold Test: " + cobold.name);
        System.out.println("-------------");

        System.out.println(cobold.messUp(1));

        System.out.println(cobold.messUp(5));

        System.out.println(cobold.messUp(15));

        System.out.println(cobold.messUp(30));
    }
}
