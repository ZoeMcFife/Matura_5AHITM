package Services;

import java.util.ArrayList;

public class Set implements Services
{
    public ArrayList<Integer> setElements = new ArrayList<>();

    @Override
    public int isElem(int elem)
    {
        if (this.setElements.contains(elem))
            return this.setElements.indexOf(elem);

        return -1;
    }

    @Override
    public void addElem(int elem)
    {
        if (this.isElem(elem) != -1)
            return;

        this.setElements.add(elem);
    }

    @Override
    public int numberOf()
    {
        return this.setElements.size();
    }

    public Set union(Set set)
    {
        Set unionSet = new Set();

        for (int elem : this.setElements)
            unionSet.addElem(elem);

        for (int elem : set.setElements)
            unionSet.addElem(elem);
        
        return unionSet;
    }

    public Set intersection(Set set)
    {
        Set intersectionSet = new Set();

        for (int elem : this.setElements)
        {
            if (set.isElem(elem) != -1)
                intersectionSet.addElem(elem);
        }

        return intersectionSet;
    }

    @Override
    public String toString()
    {
        return "Set{" +
                "setElements=" + setElements +
                '}';
    }
}
