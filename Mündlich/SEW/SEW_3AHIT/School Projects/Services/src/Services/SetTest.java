package Services;

public class SetTest
{
    public static void main(String[] args)
    {
        Set a = new Set();
        Set b = new Set();

        a.addElem(1);
        a.addElem(2);
        a.addElem(3);
        a.addElem(4);
        a.addElem(6);
        a.addElem(8);

        b.addElem(2);
        b.addElem(4);
        b.addElem(6);
        b.addElem(8);
        b.addElem(10);

        Set c = a.union(b);
        Set d = a.intersection(b);

        System.out.println(a);
        System.out.println();
        System.out.println(b);
        System.out.println();
        System.out.println(c);
        System.out.println();
        System.out.println(d);
    }
}
