package Shoes;

/**
 * There are two possibilies for implementing the generic interface;
 *
 * No. 2:
 *      The class is as generic as the interface itself
 * */

public class AnyBox<E> implements Container<E>
{
    E content;

    @Override
    public void setContent(E content)
    {
        this.content = content;
    }

    @Override
    public E getContent()
    {
        return content;
    }
}
