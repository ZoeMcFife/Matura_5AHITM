package Time;

public class TimeTest
{
    public static void main(String[] args)
    {
        System.out.println(Time.convert(2345));
        System.out.println(Time.convert(0));
        System.out.println(Time.convert(59));
        System.out.println(Time.convert(60));
        System.out.println(Time.convert(100));
        System.out.println(Time.convert(3600));
        System.out.println(Time.convert(4000));
    }
}
