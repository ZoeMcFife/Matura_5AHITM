package meow.nya.socialmedia;

import java.util.ArrayList;

public class User
{
    private final double userID;
    private String firstname;
    private String lastname;

    private ArrayList<User> friends = new ArrayList<>();

    private static double lastUserID = 0;

    User(String firstname, String lastname)
    {
        this.userID = lastUserID;
        lastUserID++;

        setFirstname(firstname);
        setLastname(lastname);
        Database.addUser(this);
    }

    public void post(Post post)
    {
        System.out.println(post);
    }

    public void comment(Post post, Comment comment)
    {
        post.comment(comment);
        System.out.println(comment);
    }

    public void addFriend(double userID)
    {
        friends.add(Database.getUser(userID));
        Database.getUser(userID).friendAdded(this.getUserID());
    }

    public void friendAdded(double userID)
    {
        friends.add(Database.getUser(userID));
    }

    public String getFirstname()
    {
        return firstname;
    }

    public void setFirstname(String firstname)
    {
        this.firstname = firstname;
    }

    public String getLastname()
    {
        return lastname;
    }

    public void setLastname(String lastname)
    {
        this.lastname = lastname;
    }

    public double getUserID()
    {
        return userID;
    }

    public ArrayList<User> getFriends()
    {
        return friends;
    }

    @Override
    public String toString()
    {
        return getFirstname() + " " + getLastname() + " " + getUserID();
    }
}
