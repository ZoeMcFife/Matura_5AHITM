package Party;

import java.util.Objects;

public class Company implements Location
{
    private String location;

    Company(String location)
    {
        setLocation(location);
    }

    @Override
    public void setLocation(String location)
    {
        this.location = location;
    }

    @Override
    public String getLocation()
    {
        return location;
    }

    @Override
    public boolean equals(Object o)
    {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Company company = (Company) o;
        return Objects.equals(location, company.location);
    }

    @Override
    public int hashCode()
    {
        return Objects.hash(location);
    }
}
