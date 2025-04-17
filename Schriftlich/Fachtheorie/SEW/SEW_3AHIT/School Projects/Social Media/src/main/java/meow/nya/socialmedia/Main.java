package meow.nya.socialmedia;

public class Main
{
    public static void main(String[] args)
    {
        User user = new User("Test", "Test");
        User friend = new User("Frienndo", "McFrend");
        User a = new User("A", "a");
        User e = new User("e", "E");

        Post post = new Post(PostType.textPost, user);
        user.post(post);

        Comment comment = new Comment("This post is stupid", user);
        user.comment(post, comment);

        user.addFriend(friend.getUserID());
        e.addFriend(user.getUserID());
        a.addFriend(e.getUserID());
        friend.addFriend(e.getUserID());

        System.out.println(Database.getUsers());

        System.out.println(user.getFriends());
        System.out.println(friend.getFriends());
        System.out.println(a.getFriends());
        System.out.println(e.getFriends());

    }
}
