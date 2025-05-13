package CollectionMapDemo;

import java.util.Objects;

public class Deer implements Species
{
    public String species = "Deer";
    String noise = "bleh";

    @Override
    public void makeNoise(String name)
    {
        System.out.println("The " + name + " (" + this.species + ") " + "says " + this.noise);

    }

    @Override
    public String toString()
    {
        return "Deer{" +
                "species='" + species + '\'' +
                ", noise='" + noise + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o)
    {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Deer deer = (Deer) o;
        return Objects.equals(species, deer.species) && Objects.equals(noise, deer.noise);
    }

    @Override
    public int hashCode()
    {
        return Objects.hash(species, noise);
    }
}
