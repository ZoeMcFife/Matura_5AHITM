package myvehicles;

import java.util.ArrayList;

public class Buffer<T>
{
    private ArrayList<T> data = new ArrayList<>();

    public void put(T element)
    {
        this.data.add(0, element);
    }

    public T get()
    {
        T e = this.data.get(0);
        this.data.remove(0);

        return e;
    }

    public int bufferSize()
    {
        return this.data.size();
    }

}
