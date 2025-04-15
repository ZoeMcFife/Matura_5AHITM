package meow.nya.socialmedia;

import java.util.ArrayList;
import java.util.HashMap;

public class Database
{
    private static HashMap<Double, User> users = new HashMap<>();
    private static HashMap<Double, Comment> comments = new HashMap<>();
    private static HashMap<Double, Post> posts = new HashMap<>();

    public static void addUser(User user)
    {
        users.put(user.getUserID(), user);
    }

    public static void addComment(Comment comment)
    {
        comments.put(comment.getCommentID(), comment);
    }

    public static void addPost(Post post)
    {
        posts.put(post.getPostID(), post);
    }

    public static Comment getComment(double id)
    {
        return comments.get(id);
    }

    public static Post getPost(double id)
    {
        return posts.get(id);
    }

    public static User getUser(double id)
    {
        return users.get(id);
    }

    public static HashMap<Double, Comment> getComments()
    {
        return comments;
    }

    public static HashMap<Double, User> getUsers()
    {
        return users;
    }

    public static HashMap<Double, Post> getPosts()
    {
        return posts;
    }
}
