package CollectionMapDemo;

import java.util.Objects;

public class Axolotl implements Species
{
    public String species = "Axolotl";
    String noise = "eeee";

    @Override
    public void makeNoise(String name)
    {
        System.out.println("The " + name + " (" + this.species + ") " + "says " + this.noise);
    }

    @Override
    public String toString()
    {
        return "Axolotl{" +
                "species='" + species + '\'' +
                ", noise='" + noise + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o)
    {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Axolotl axolotl = (Axolotl) o;
        return Objects.equals(species, axolotl.species) && Objects.equals(noise, axolotl.noise);
    }

    @Override
    public int hashCode()
    {
        return Objects.hash(species, noise);
    }
}
