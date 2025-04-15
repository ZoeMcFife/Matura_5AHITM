<?php

class Category{
    private $cid;
    private $category_name;
    private $created_at;

    public function __construct(int $categoryID, string $name, string $createdAt){
        $this->cid=$categoryID;
        $this->category_name=$name;
        $this->created_at=$createdAt;
    }

    /**
     * Get the value of cid
     */ 
    public function getCid()
    {
        return $this->cid;
    }

    /**
     * Set the value of cid
     *
     * @return  self
     */ 
    public function setCid($cid)
    {
        $this->cid = $cid;

        return $this;
    }

    /**
     * Get the value of category_name
     */ 
    public function getCategory_name()
    {
        return $this->category_name;
    }

    /**
     * Set the value of category_name
     *
     * @return  self
     */ 
    public function setCategory_name($category_name)
    {
        $this->category_name = $category_name;

        return $this;
    }

    /**
     * Get the value of created_at
     */ 
    public function getCreated_at()
    {
        return $this->created_at;
    }

    /**
     * Set the value of created_at
     *
     * @return  self
     */ 
    public function setCreated_at($created_at)
    {
        $this->created_at = $created_at;

        return $this;
    }
}