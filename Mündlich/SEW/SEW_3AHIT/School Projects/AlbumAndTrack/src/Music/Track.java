package Music;

public class Track
{
    private String title;
    private String mp3fname;
    private double length;

    Track(String title, String mp3fname, double length)
    {
        setLength(length);
        setMp3fname(mp3fname);
        setTitle(title);
    }

    public void setTitle(String title)
    {
        this.title = title;
    }

    public String getTitle()
    {
        return title;
    }

    public void setMp3fname(String mp3fname)
    {
        this.mp3fname = mp3fname;
    }

    public String getMp3fname()
    {
        return mp3fname;
    }

    public void setLength(double length)
    {
        this.length = length;
    }

    public double getLength()
    {
        return length;
    }

    public String getLengthInMinutes()
    {
        double minutes;
        double seconds;

        minutes = Math.floor(this.length / 60);
        seconds = this.length - minutes * 60;

        return (minutes > 9 ? "" : "0") + (int) minutes + ":" + (seconds > 9 ? "" : "0") + (int) seconds;
    }
}
