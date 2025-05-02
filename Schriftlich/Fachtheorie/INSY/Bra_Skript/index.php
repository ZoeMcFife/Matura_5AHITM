<?php
try {
    // 1. Connect to the database
    $dsn = 'mysql:dbname=mini_school;host=127.0.0.1';
    $user = 'root';
    $password = '';
    $dbh = new PDO($dsn, $user, $password);
    $dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    echo "<h3>Simple query using query()</h3>";
    $sql = "SELECT * FROM student";
    $users = $dbh->query($sql);

    foreach ($users as $row) {
        echo $row["firstname"] . " - " . $row["lastname"] . "<br />";
    }

    echo "<h3>Prepared Statement with unnamed parameters</h3>";
    $statement = $dbh->prepare("SELECT * FROM student WHERE firstname = ? AND lastname = ?");
    $statement->execute(['Max', 'Mustermann']);
    while ($row = $statement->fetch(PDO::FETCH_ASSOC)) {
        echo $row['firstname'] . " " . $row['lastname'] . "<br />";
    }

    echo "<h3>Prepared Statement with named parameters</h3>";
    $statement = $dbh->prepare("SELECT * FROM student WHERE firstname = :vorname AND lastname = :nachname");
    $statement->execute([':vorname' => 'Max', ':nachname' => 'Mustermann']);
    while ($row = $statement->fetch(PDO::FETCH_ASSOC)) {
        echo $row['firstname'] . " " . $row['lastname'] . "<br />";
    }

    echo "<h3>Amount of rows in the result set</h3>";
    $statement = $dbh->prepare("SELECT * FROM student WHERE firstname = ?");
    $statement->execute(['Max']);
    $anzahl_user = $statement->rowCount();
    echo "We found $anzahl_user student(s).";

    echo "<h3>Insert new tuple</h3>";
    $statement = $dbh->prepare("INSERT INTO student (firstname, lastname) VALUES (?, ?)");
    $statement->execute(['Anna', 'Schmidt']);

    $neue_id = $dbh->lastInsertId();
    echo "New student inserted with ID: $neue_id";

} catch (PDOException $e) {
    echo 'Connection failed: ' . $e->getMessage();
}
?>
