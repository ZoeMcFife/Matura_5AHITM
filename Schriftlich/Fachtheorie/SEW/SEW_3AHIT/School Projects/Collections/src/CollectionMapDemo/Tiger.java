package CollectionMapDemo;

import java.util.Objects;

public class Tiger implements Species
{
    public String species = "Tiger";
    String noise = "RAWR";

    @Override
    public void makeNoise(String name)
    {
        System.out.println("The " + name + " (" + this.species + ") " + "says " + this.noise);

    }

    @Override
    public String toString()
    {
        return "Tiger{" +
                "species='" + species + '\'' +
                ", noise='" + noise + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o)
    {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Tiger tiger = (Tiger) o;
        return Objects.equals(species, tiger.species) && Objects.equals(noise, tiger.noise);
    }

    @Override
    public int hashCode()
    {
        return Objects.hash(species, noise);
    }
}
