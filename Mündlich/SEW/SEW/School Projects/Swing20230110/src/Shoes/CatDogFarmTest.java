package Shoes;

public class CatDogFarmTest
{
    public static void main(String[] args)
    {
        CatFarm catFarm = new CatFarm();
        DogFarm dogFarm = new DogFarm();

        Cat cat = new Cat("Meowdy");
        catFarm.habitant = cat;

    }
}
