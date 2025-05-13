package CollectionMapDemo;

import java.util.HashMap;

public class MapDemo
{
    public void startDemo()
    {
        HashMap<Animal, Species> hashMap = populateHashMap();

        System.out.println("All animals");
        loopThroughHashMap(hashMap);

        System.out.println();
        getSpecies(hashMap, new Dog());
        System.out.println();
        getSpecies(hashMap, new Fox());

        System.out.println();
        System.out.println("Has Dog? " + isSpeciesPresent(hashMap, new Dog()));

        hashMap.remove(new Animal(new Axolotl(), "Timothy"));
        System.out.println("Has Axolotl? " + isSpeciesPresent(hashMap, new Axolotl()));
        System.out.println("Has Natani? " + isAnimalPresent(hashMap, new Animal(new Dog(),"Natani")));
    }

    private boolean isAnimalPresent(HashMap<Animal, Species> hashMap, Animal animal)
    {
        return hashMap.containsKey(animal);
    }

    private boolean isSpeciesPresent(HashMap<Animal, Species> hashMap, Species species)
    {
        return hashMap.containsValue(species);
    }

    private void getSpecies(HashMap<Animal, Species> hashMap, Species species)
    {
        System.out.println("Filtering out " + species);

        for (Animal a : hashMap.keySet())
        {
            if (!a.species.equals(species))
            {
                continue;
            }

            a.makeNoise();
        }
    }

    private void loopThroughHashMap(HashMap<Animal, Species> hashMap)
    {
        for (Animal a : hashMap.keySet())
        {
            a.makeNoise();
        }
    }

    private HashMap<Animal, Species> populateHashMap()
    {
        HashMap<Animal, Species> hashMap = new HashMap<>();

        Animal subi = new Animal(new Dog(), "Subi");
        Animal amon = new Animal(new Dog(),"Amon");
        Animal zoe = new Animal(new Fox(), "Zoe");
        Animal kirsi = new Animal(new Fox(), "Kirsi");
        Animal natani = new Animal(new Dog(),"Natani");
        Animal alex = new Animal(new Fox(), "Alex");
        Animal flora = new Animal(new Tiger(), "Flora");
        Animal tony = new Animal(new Tiger(), "Tony");
        Animal apogee = new Animal(new Dog(), "Apogee");
        Animal holly = new Animal(new Deer(), "Holly");
        Animal timothy = new Animal(new Axolotl(), "Timothy");

        hashMap.put(subi, new Dog());
        hashMap.put(amon, new Dog());
        hashMap.put(zoe, new Fox());
        hashMap.put(kirsi, new Fox());
        hashMap.put(natani, new Dog());
        hashMap.put(alex, new Fox());
        hashMap.put(flora, new Tiger());
        hashMap.put(tony, new Tiger());
        hashMap.put(apogee, new Dog());
        hashMap.put(holly, new Deer());
        hashMap.put(timothy, new Axolotl());

        return hashMap;
    }
}
