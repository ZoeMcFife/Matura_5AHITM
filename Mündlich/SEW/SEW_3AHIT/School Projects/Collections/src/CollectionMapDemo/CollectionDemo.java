package CollectionMapDemo;

import java.util.Iterator;
import java.util.TreeSet;

public class CollectionDemo
{
    public void startDemo()
    {
        TreeSet<Animal> tree = populateTree();

        treeSetIterator(tree);
        treeTailSet(tree);
        treeHeadSet(tree);
        treeSubSet(tree);
        treeSetContains(tree);
    }

    private void treeTailSet(TreeSet<Animal> tree)
    {
        Animal axel = new Animal(new Axolotl(), "Axel");

        System.out.println("\nTail Set of " + axel);
        for (Animal a : tree.tailSet(axel))
        {
            a.makeNoise();
        }
    }

    private void treeHeadSet(TreeSet<Animal> tree)
    {
        Animal axel = new Animal(new Axolotl(), "Axel");

        System.out.println("\nHead Set of " + axel);
        for (Animal a : tree.headSet(axel))
        {
            a.makeNoise();
        }
    }

    private void treeSubSet(TreeSet<Animal> tree)
    {
        Animal holly = new Animal(new Deer(), "Holly");
        Animal timothy = new Animal(new Axolotl(), "Timothy");

        System.out.println("\nSub Set of " + holly + " and " + timothy);
        for (Animal a : tree.subSet(holly, timothy))
        {
            a.makeNoise();
        }
    }

    private void treeSetContains(TreeSet<Animal> tree)
    {
        Animal natani = new Animal(new Dog(),"Natani");
        Animal luke = new Animal(new Deer(), "Luke");

        System.out.println();
        System.out.println("Does Set contain " + natani.name + "?: " + tree.contains(natani));
        System.out.println("Does Set contain " + luke.name + "?: " + tree.contains(luke));
    }

    private void treeSetIterator(TreeSet<Animal> tree)
    {
        System.out.println("List of all Animals");
        Iterator<Animal> iterator = tree.iterator();

        while (iterator.hasNext())
        {
            iterator.next().makeNoise();
        }
    }

    private TreeSet<Animal> populateTree()
    {
        TreeSet<Animal> tree = new TreeSet<>(new AnimalNameComparator());

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

        tree.add(subi);
        tree.add(amon);
        tree.add(zoe);
        tree.add(kirsi);
        tree.add(natani);
        tree.add(alex);
        tree.add(flora);
        tree.add(tony);
        tree.add(apogee);
        tree.add(holly);
        tree.add(timothy);

        return tree;
    }


}
