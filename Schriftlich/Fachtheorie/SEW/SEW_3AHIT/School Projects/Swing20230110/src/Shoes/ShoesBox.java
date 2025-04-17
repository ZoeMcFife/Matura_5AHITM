package Shoes;

/*
* There are two possibilies for implementing the generic interface;
* No.1:
*   While defining the class that implements the interface (listing: Shoesbox)
* */

public class ShoesBox implements Container<Shoes>
{
    Shoes content;

    public void setContent(Shoes content)
    {
        this.content = content;
    }

    @Override
    public Shoes getContent()
    {
        return content;
    }

    /*
    *   1 the placeholder E that was used in the interface will be replaced by the concrete type SHoes
    *
    *   2 Shoesbox implements only the interface
     */
}
