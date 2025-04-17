package Shoes;

//Bevor es Generics gab (vor java 5)
//Beispiel: karton dass beliebige gegenstände aufnehemen kann
public class OldBox
{
    private Object content;

    public OldBox(Object content)
    {
        this.content = content;
    }

    public void setContent(Object content)
    {
        this.content = content;
    }

    public Object getContent()
    {
        return content;
    }
}
