package CollectionMapDemo;

import java.util.Objects;

public class Animal
{
    public Species species;
    public String name;

    Animal(Species species, String name)
    {
        this.name = name;
        this.species = species;
    }

    public void makeNoise()
    {
        species.makeNoise(this.name);
    }

    @Override
    public String toString()
    {
        return "Animal{" +
                "species=" + species +
                ", name='" + name + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o)
    {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Animal animal = (Animal) o;
        return Objects.equals(species, animal.species) && Objects.equals(name, animal.name);
    }

    @Override
    public int hashCode()
    {
        return Objects.hash(species, name);
    }
}
