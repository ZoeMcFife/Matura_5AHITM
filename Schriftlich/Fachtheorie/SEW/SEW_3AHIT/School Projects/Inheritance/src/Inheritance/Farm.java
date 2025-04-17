package Inheritance;

public class Farm
{
    public Animal[] animals;

    public Farm(Animal[] animals)
    {
        this.animals = animals;
    }

    public void feed(String food)
    {
        for (Animal a : this.animals)
        {
            if (a.likes(food))
                a.speak();
            else
                a.getAngry();
        }
    }

    public static void main(String[] args)
    {
        Dog d1 = new Dog();
        Dog d2 = new Dog();
        Cat c1 = new Cat();
        Bird b1 = new Bird();

        Farm myFarm = new Farm(new Animal[]{d1, d2, c1, b1});

        myFarm.feed("milk");
    }
}
