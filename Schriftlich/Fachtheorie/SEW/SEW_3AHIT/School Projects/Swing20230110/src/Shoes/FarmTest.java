package Shoes;

public class FarmTest
{
    public static void main(String[] args)
    {
        Dog dog = new Dog("Subi");
        Cat cat = new Cat("El Gato");

        Farm<Dog> dogFarm = new Farm<>(dog);
        Farm<Cat> catFarm = new Farm<>(cat);

        System.out.println(dogFarm);
        System.out.println(catFarm);


    }
}

