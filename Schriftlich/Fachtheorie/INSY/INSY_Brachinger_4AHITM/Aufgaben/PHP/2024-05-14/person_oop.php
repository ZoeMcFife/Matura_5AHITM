<?php

require_once("kimiko/config.inc");

$connection = null;

$host = config::DBHOST;
$name = config::DBNAME;

try
{
    $connection = new PDO("mysql:host=$host;dbname=$name", config::DBUSER, config::DBPASS);
    $connection->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    echo "Connection Successful!";
    echo "<br>";
}
catch (PDOException $e)
{
    echo $e->getMessage();
    echo "<br>";
    die("Connection failed");
}

$result = $connection->query("select * from person");

echo "<br><h1>Person</h1>";
while ($row = $result->fetch(PDO::FETCH_ASSOC))
{
    print_r($row);
    echo "<br>";
}



