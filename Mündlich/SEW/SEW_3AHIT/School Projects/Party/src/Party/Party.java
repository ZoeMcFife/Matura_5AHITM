package Party;

public interface Party
{
    void participating(Person person) throws EarnsTooMuchException, ParticipationException;
    void setLocation(Location location);
}
