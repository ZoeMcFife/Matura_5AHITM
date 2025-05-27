<?php
// Verbindung zum Datenbankserver herstellen:
$mysqli = new mysqli("localhost", "user", "password", "database");
// Abfrage auf die virtuelle Tabelle DUAL ausführen:
$result = $mysqli->query("SELECT 'Great job!!!' AS _msg FROM DUAL");
// Ergebnis der Abfrage auslesen:
$row = $result→fetch_assoc();
// Ergebnis ausgeben:
echo $row['_msg'];
?>