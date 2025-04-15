package Art;

public class MobileTest
{
    public static void main(String[] args)
    {
        Star star1 = new Star(4);
        Star star2 = new Star(2);
        Star star3 = new Star(9);

        Wire wire12 = new Wire(star1, star2, 9);
        Wire wire123 = new Wire(wire12, star3, 10);
        wire123.balance();

        System.out.println(wire123);
    }
}
