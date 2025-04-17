package Music;

public class Album
{
    private String title;
    private String interpret;
    private Track[] tracks;

    private double length;

    Album(String title, String interpret, Track[] tracks)
    {
        setTitle(title);
        setInterpret(interpret);
        setTracks(tracks);
    }

    public void printInfo()
    {
        System.out.println("Album: " + this.title);
        System.out.println("From: " + this.interpret);
        System.out.println("Duration: " + getLengthInMinutes() + " Minutes");

        int i = 0;
        for (Track t : this.tracks)
        {
            System.out.println("Track " + (i + 1) + ": " + t.getTitle() + " [" + t.getLengthInMinutes() + "]");

            i++;
        }
    }

    public double getLength()
    {
        this.length = 0;

        for (Track t : this.tracks)
        {
            this.length += t.getLength();
        }

        return this.length;
    }

    public double getLengthInMinutes()
    {
        return Math.round((getLength() / 60) * 100) / 100;
    }

    public void setTitle(String title)
    {
        this.title = title;
    }

    public String getTitle()
    {
        return title;
    }

    public void setInterpret(String interpret)
    {
        this.interpret = interpret;
    }

    public String getInterpret()
    {
        return interpret;
    }

    public void setTracks(Track[] tracks)
    {
        this.tracks = tracks;
    }

    public Track[] getTracks()
    {
        return tracks;
    }
}
