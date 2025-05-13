package Time;

public class Time
{
    int hours;
    int minutes;
    int seconds;

    Time(int hours, int minutes, int seconds)
    {
        this.hours = hours;
        this.minutes = minutes;
        this.seconds = seconds;
    }

    public static Time convert(int initialSeconds)
    {
        int hours = Math.floorDiv(initialSeconds, 3600);
        int minutes = Math.floorDiv(initialSeconds - 3600 * hours, 60);
        int seconds = initialSeconds - 3600 * hours - 60 * minutes;

        return new Time(hours, minutes, seconds);
    }

    @Override
    public String toString()
    {
        return
                (this.hours < 10 ? "0" : "") + this.hours + ":" +
                        (this.minutes < 10 ? "0" : "") + this.minutes + ":" +
                        (this.seconds < 10 ? "0" : "") + this.seconds
                ;
    }
}
