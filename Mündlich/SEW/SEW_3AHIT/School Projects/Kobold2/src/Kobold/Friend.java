package Kobold;

public class Friend implements Behaviour
{
    private Cobold friend;

    Friend(Cobold cobold)
    {
        this.friend = cobold;
    }

    @Override
    public int modify(int n)
    {
        return this.friend.messUp(n);
    }
}
