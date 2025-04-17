package Shoes;

import java.util.ArrayList;
import java.util.List;

public class AnimalTest
{
    public static void main(String[] args)
    {
        Cat cat = new Cat("meowdy");
        Cat cat2 = new Cat("Steve");
        Cat cat3 = new Cat("Micheal Stevens");
        Dog dog = new Dog("Amon Gus");

        List<Animal> animalList = new ArrayList<>();

        animalList.add(cat);
        animalList.add(cat2);
        animalList.add(cat3);
        animalList.add(dog);

        Animal.printNames(animalList);
    }
}
