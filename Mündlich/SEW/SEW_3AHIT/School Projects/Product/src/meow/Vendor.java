package meow;

public class Vendor
{
    private String firstname;
    private String lastname;

    Vendor(String firstname, String lastname)
    {
        setFirstname(firstname);
        setLastname(lastname);
    }

    @Override
    public String toString()
    {
        return getFirstname() + " " + getLastname();
    }

    public String getLastname()
    {
        return lastname;
    }

    public String getFirstname()
    {
        return firstname;
    }

    public void setLastname(String lastname)
    {
        this.lastname = lastname;
    }

    public void setFirstname(String firstname)
    {
        this.firstname = firstname;
    }
}
