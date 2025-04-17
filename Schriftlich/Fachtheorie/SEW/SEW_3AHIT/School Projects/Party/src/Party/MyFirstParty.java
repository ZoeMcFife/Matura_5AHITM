package Party;

import java.util.ArrayList;
import java.util.logging.Logger;

public class MyFirstParty implements Party
{
    public String location;
    public ArrayList<Person> persons = new ArrayList<>();
    Logger log;

    @Override
    public void setLocation(Location location)
    {
        this.location = location.getLocation();
    }

    @Override
    public void participating(Person person) throws EarnsTooMuchException, ParticipationException
    {
        if (person.earnings > 40000)
            throw new EarnsTooMuchException(person);
        if (!person.worksAt.getLocation().equals(this.location))
            throw new ParticipationException();

        this.persons.add(person);
    }
}
