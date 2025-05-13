package Shoes;

import java.util.List;

public class Animal
{
    public String name;

    /* Nach oben beschränkter Wildcard-Typ: <? extends Superclass>
     * Jede Klasse, die von Superclass ableitet ist oder superclass selbst
     */

    public static void printNames(List<?/*1*/ extends /*2*/ Animal> /*3*/ animalList)
    {
        for (Animal animal : animalList)
        {
            System.out.println("Animal: " + animal.name);
        }

        /*
         * 1 erst kommt der Wildcard-Operator ? Joker
         * 2 Gefolgt von extends
         * 3 und schließlich der oberen Grenze
         */
    }

    /*
     * Nach unten beschränkte Wildcard-Typ: <? super Subclass>
     * Jede Klasse, die eine Superclass von Subclass ist oder Subclass selbst
     */

    public static void moreanimals(List<? super Animal> animalList)
    {
        animalList.add(new Cat("a"));
        animalList.add(new Cat("mon"));
    }

}
