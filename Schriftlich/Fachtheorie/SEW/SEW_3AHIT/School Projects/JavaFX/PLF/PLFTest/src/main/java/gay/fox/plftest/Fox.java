package gay.fox.plftest;

public class Fox
{
    private String name;
    private int redditKarma;
    private String furColor;

    Fox()
    {
        setName("Alone");
        setFurColor("#000000");
        setRedditKarma(0);
    }

    Fox(String name, int redditKarma, String furColor)
    {
        setName(name);
        setRedditKarma(redditKarma);
        setFurColor(furColor);
    }

    public void yiff()
    {
        System.out.println("'YIP YAP YIP' - " + getName());
    }

    @Override
    public String toString()
    {
        return "Fox Stats\n" + "----------\n" + "Name: " + getName() + "\nReddit Karma: " + getRedditKarma() + "\nFur Color: " + getFurColor();
    }

    public String getName()
    {
        return name;
    }

    public void setName(String name)
    {
        this.name = name;
    }

    public int getRedditKarma()
    {
        return redditKarma;
    }

    public void setRedditKarma(int redditKarma)
    {
        this.redditKarma = redditKarma;
    }

    public String getFurColor()
    {
        return furColor;
    }

    public void setFurColor(String furColor)
    {
        this.furColor = furColor;
    }
}
