<?php

require_once("kimiko/config.inc");

// mysqli --> procedural or OOP

$dbh = mysqli_connect(config::DBHOST, config::DBUSER, config::DBPASS, config::DBNAME);

if ($dbh !== false)
{
    echo "Connection established";
    echo "<br>";
}
else
{
    die("Connection error");
}

$result = mysqli_query($dbh, "select * from person");

while ($row = mysqli_fetch_assoc($result))
{
    print_r($row);
    echo "<br>";
}

mysqli_close($dbh);