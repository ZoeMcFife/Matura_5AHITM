package Party;

public class EarnsTooMuchException extends Exception
{
    EarnsTooMuchException(Person person)
    {
        super(person.getFirstname() + " earns too much");
    }
}
