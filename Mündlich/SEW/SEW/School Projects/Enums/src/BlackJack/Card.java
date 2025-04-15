package BlackJack;

public class Card
{
    private String name;
    private int value;

    Card(int value, String name)
    {
        this.value = value;
        this.name = name;
    }

    public String getName()
    {
        return name;
    }

    public int getValue()
    {
        return value;
    }
}
