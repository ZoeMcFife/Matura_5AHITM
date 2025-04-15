<?php


require_once("kimiko/config.inc");

// mysqli --> procedural or OOP

$dbh = mysqli_connect(config::DBHOST, config::DBUSER, config::DBPASS, config::DBNAME);

if ($dbh !== false) {
    echo "Connection established";
    echo "<br>";
} else {
    die("Connection error");
}

if (isset($_POST['username']) && isset($_POST['password']))
{
    $username = $_POST['username'];
    $password = $_POST['password'];

    $query = "select * from users where username = '$username' and password = '$password'";

    $result = $dbh->query($query);

    if ($result->num_rows > 0)
    {
        echo "YOU ARE GOOD <br>";

        while ($row = mysqli_fetch_assoc($result))
        {
            echo "ID: ".$row['id']." - User: ".$row['username']." Password: ".$row['password'];
        }
    }
    else
    {
        echo "YOU ARE BAD <br>";
    }

}

mysqli_close($dbh);

?>

<!DOCTYPE html>
<html lang="en-us">
    <head>
        <title>Login</title>
    </head>
    <form action="form.php" method="post">
        <LABEL>Username: <input type="text" name="username"></LABEL>
        <br>
        <LABEL>Password: <input type="password" name="password"></LABEL>
        <br>
        <input type="submit" value="Login">
    </form>
</html>



