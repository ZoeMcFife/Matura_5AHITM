package BlackJack;

public enum Cards
{
    TWO(2, "Two"),
    THREE(3, "Three"),
    FOUR(4, "Four"),
    FIVE(5, "Five"),
    SIX(6, "Six"),
    SEVEN(7, "Seven"),
    EIGHT(8, "Eight"),
    NINE(9, "Nine"),
    TEN(10, "Ten"),
    JOKER(10, "Joker"),
    QUEEN(10, "Queen"),
    KING(10, "King"),
    ACE(11, "Ace");

    public final int value;
    public final String name;

    Cards(int value, String name)
    {
        this.value = value;
        this.name = name;
    }
}
