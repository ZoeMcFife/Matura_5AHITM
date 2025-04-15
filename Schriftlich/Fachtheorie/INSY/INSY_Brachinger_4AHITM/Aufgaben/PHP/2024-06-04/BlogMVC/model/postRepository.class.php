<?php

require_once ("model/post.class.php");

class PostRepository
{
    private $connectionID;

    public function __construct(PDO $dbID)
    {
        $this->connectionID = $dbID;
    }

    public function getAllPosts(): array
    {
        $sql = "select * from category c, posts p where c.id = p.category_id";

        $statement = $this->connectionID->query($sql);

        $allPostsFromSource = $statement->fetchAll(PDO::FETCH_OBJ);

        $posts[] = [];

        foreach ($allPostsFromSource as $postFromSource)
        {
            $posts[] = new Post( (int) $postFromSource->id, $postFromSource->category_id, $postFromSource->name, $postFromSource->title, $postFromSource->body, $postFromSource->author, $postFromSource->created_at);
        }

        return $posts;
    }

    public function getPostById(int $postID) { }
    public function getByCategoryID(int $catID) { }
    public function insertPost(string $title, string $body, int $catID, string $author)
    {
        $query = "insert into posts(category_id, title, body, author) values (:catID, :title, :body, :author)";

        try
        {
            $statement = $this->connectionID->prepare($query);
            $statement->bindParam(":catID", $catID, PDO::PARAM_INT);
            $statement->bindParam(":title", $title, PDO::PARAM_STR);
            $statement->bindParam(":body", $body, PDO::PARAM_STR);
            $statement->bindParam(":author", $author, PDO::PARAM_STR);

            $statement->execute();
        }
        catch (PDOException $e)
        {

        }
    }
    public function deletePost(int $postID) { }
    public function updatePost(int $id, Post $post) { }

}