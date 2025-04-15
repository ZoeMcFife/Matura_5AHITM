package CollectionMapDemo;

import java.util.Objects;

public class Fox implements Species
{
    public String species = "Fox";
    String noise = "Yip Yap";

    @Override
    public void makeNoise(String name)
    {
        System.out.println("The " + name + " (" + this.species + ") " + "says " + this.noise);
    }

    @Override
    public String toString()
    {
        return "Fox{" +
                "species='" + species + '\'' +
                ", noise='" + noise + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o)
    {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Fox fox = (Fox) o;
        return Objects.equals(species, fox.species) && Objects.equals(noise, fox.noise);
    }

    @Override
    public int hashCode()
    {
        return Objects.hash(species, noise);
    }
}
