package Party;

public class Person
{
    private String firstname;
    private String lastname;

    public String name;
    public Company worksAt;
    public int earnings;

    Person(Company company, int earnings)
    {
        this.worksAt = company;
        this.earnings = earnings;
        setFirstname("");
        setLastname("");
    }

    Person(String firstname, String lastname, Company company, int earnings)
    {
        this.worksAt = company;
        this.earnings = earnings;
        setFirstname(firstname);
        setLastname(lastname);
    }

    public void setFirstname(String firstname)
    {
        this.firstname = firstname;
    }

    public void setLastname(String lastname)
    {
        this.lastname = lastname;
    }

    public String getFirstname()
    {
        return firstname;
    }

    @Override
    public String toString()
    {
        return this.firstname + " " + this.lastname;
    }
}
