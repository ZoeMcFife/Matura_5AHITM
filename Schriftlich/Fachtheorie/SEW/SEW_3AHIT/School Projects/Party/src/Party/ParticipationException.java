package Party;

public class ParticipationException extends Exception
{
    ParticipationException()
    {
        super("Person location is not the same as party location.");
    }
}
