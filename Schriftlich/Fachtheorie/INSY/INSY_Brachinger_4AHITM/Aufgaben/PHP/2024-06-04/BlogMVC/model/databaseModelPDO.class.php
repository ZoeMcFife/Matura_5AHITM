<?php

require_once("conf/conf.inc.php");

class DatabaseModelPDO
{
    private $host = config::DBHOST;
    private $username = config::DBUSER;
    private $password = config::DBPASS;
    private $dbName = config::DBNAME;
    private $connectionID;

    public function connect()
    {
        if ($this->connectionID != null)
        {
            return $this->connectionID;
        }

        try
        {
            $dsn = "mysql:host=".$this->host.";dbname=".$this->dbName;
            $this->connectionID = new PDO($dsn, $this->username, $this->password);
            $this->connectionID->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        }
        catch (PDOException $e)
        {
            die("Exception: ".$e->getMessage());
        }

        return $this->connectionID;
    }
}