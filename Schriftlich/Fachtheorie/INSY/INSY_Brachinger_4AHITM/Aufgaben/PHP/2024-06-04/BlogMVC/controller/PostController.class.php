<?php

require_once ("model/postRepository.class.php");
require_once ("model/databaseModelPDO.class.php");

class PostController
{
    protected $dbID;
    protected $postRepository;
    protected $categoryRepository;
    protected $allPosts;
    protected $post;

    public function __construct()
    {
        $db = new DatabaseModelPDO();
        $this->dbID = $db->connect();
        $this->postRepository = new PostRepository($this->dbID);
    }

    public function allPosts()
    {
        $this->allPosts = $this->postRepository->getAllPosts();
        print_r($this->allPosts);
        require_once('view/allPosts.php');
    }
}