package Shoes;

public class Box<T>
{
    private T content;

    public Box(T content)
    {
        this.content = content;
    }

    public T getContent()
    {
        return content;
    }

    public void setContent(T content)
    {
        this.content = content;
    }

    /*
    T in den Spitzen Klammern bezeichnet einen formalen Typ und ist ein Platzgalter
    für believige Klassen / interfaces

    Der Klasse Box ist an dieser Stelle egal, welche andere Klasse später den Ingalt

    Platzhalter T innerhalb der Klasse als REferenztyp verwenedted werden



     */
}
