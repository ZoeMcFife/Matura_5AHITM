package Party;

public class PartyTest
{
    public static void startParty(MyFirstParty party, Person... persons)
    {
        for (Person person : persons)
        {
            try
            {
                party.participating(person);
            }
            catch (EarnsTooMuchException e)
            {
                System.out.println(e.getMessage());
            }
            catch (ParticipationException e)
            {
                System.out.println(e.getMessage());
            }
        }

        System.out.println("Party goers");
        for (Person p : party.persons)
        {
            System.out.println(p);
        }
    }

    public static void main(String[] args)
    {
        MyFirstParty party = new MyFirstParty();
        Company company1 = new Company("company1");
        Company company2 = new Company("company2");

        party.setLocation(company1);

        Person bob = new Person("Bob", "B.", company1, 5000);
        Person robert = new Person("Robert", "B.", company1, 60000);
        Person leagd = new Person("Leagd", "B.", company2, 5000);
        Person name = new Person("Name", "B.", company2, 20900);

        startParty(party, bob, robert, leagd, name);

        MyFirstParty party2 = new MyFirstParty();
        party2.setLocation(company2);
        startParty(party2, bob, robert, leagd, name);
    }

}
