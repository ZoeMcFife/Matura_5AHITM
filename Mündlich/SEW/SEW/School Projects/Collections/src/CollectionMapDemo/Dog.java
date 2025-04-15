package CollectionMapDemo;

import java.util.Objects;

public class Dog implements Species
{
    public String species = "Dog";
    String noise = "Woof";

    @Override
    public void makeNoise(String name)
    {
        System.out.println("The " + name + " (" + this.species + ") " + "says " + this.noise);
    }

    @Override
    public String toString()
    {
        return "Dog{" +
                "species='" + species + '\'' +
                ", noise='" + noise + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o)
    {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Dog dog = (Dog) o;
        return Objects.equals(species, dog.species) && Objects.equals(noise, dog.noise);
    }

    @Override
    public int hashCode()
    {
        return Objects.hash(species, noise);
    }
}
