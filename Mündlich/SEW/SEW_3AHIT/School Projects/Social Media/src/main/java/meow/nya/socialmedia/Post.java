package meow.nya.socialmedia;

import java.util.ArrayList;

public class Post
{
    private final double postID;

    private PostType postType;
    private User postedBy;
    private int likes;
    private ArrayList<Comment> comments = new ArrayList<>();

    private static double lastPostID = 0;

    Post(PostType postType, User postedBy)
    {
        this.postID = lastPostID;
        lastPostID++;
        this.likes = 0;
        setPostType(postType);
        setPostedBy(postedBy);
        Database.addPost(this);
    }

    public void like()
    {
        this.likes++;
    }

    public void comment(Comment comment)
    {
        this.comments.add(comment);
    }

    private void setPostType(PostType postType)
    {
        this.postType = postType;
    }

    public PostType getPostType()
    {
        return postType;
    }

    public int getLikes()
    {
        return likes;
    }

    private void setPostedBy(User postedBy)
    {
        this.postedBy = postedBy;
    }

    public User getPostedBy()
    {
        return postedBy;
    }

    public double getPostID()
    {
        return postID;
    }

    public ArrayList<Comment> getComments()
    {
        return comments;
    }

    @Override
    public String toString()
    {
        return "Post{" +
                "postID=" + postID +
                ", postType=" + postType +
                ", postedBy=" + postedBy +
                ", likes=" + likes +
                ", comments=" + comments +
                '}';
    }
}
