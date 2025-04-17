package meow.nya.socialmedia;

public class Comment
{
    private final double commentID;

    private String content;
    private User sentBy;

    private static double lastCommentID = 0;

    Comment(String content, User sentBy)
    {
        this.commentID = lastCommentID;
        lastCommentID++;

        setSentBy(sentBy);
        setContent(content);

        Database.addComment(this);
    }

    private void setContent(String content)
    {
        this.content = content;
    }

    public String getContent()
    {
        return content;
    }

    public User getSentBy()
    {
        return sentBy;
    }

    private void setSentBy(User sentBy)
    {
        this.sentBy = sentBy;
    }

    public double getCommentID()
    {
        return commentID;
    }

    @Override
    public String toString()
    {
        return "Comment{" +
                "commentID=" + commentID +
                ", content='" + content + '\'' +
                ", sentBy=" + sentBy +
                '}';
    }
}
