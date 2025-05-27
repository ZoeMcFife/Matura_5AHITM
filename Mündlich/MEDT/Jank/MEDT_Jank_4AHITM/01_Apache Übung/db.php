<?php
// den in PHP vorhandenen mySQL-Client verwenden:
// Verbindung zum mysql-Server herstellen; notwendige Angaben:
// Name des DB-Servers: localhost
// Username zum Anmelden: root
// Passwort des Users: kein Passwort
// Name der Datenbank am DB-Server, die verwendet werden soll: first
$mysqli = new mysqli("localhost", "root", "", "first");
// Eine Datenabfrage wird formuliert:
// Gib mir den Namen und die E-Mail-Adresse von allen Datensätzen,
// die in der Tabelle friends vorhanden sind:
$sql = "SELECT `name`,`mail` FROM `friends`";
// Die Abfrage nun durchführen:
$results = $mysqli->query($sql);
// die HTML-Tabelle für die Ausgabe der Daten aufbauen:
// Ausgabe des Tabellenkopfes:
echo "<table border=1 cellpadding=12>";
echo "<tr>";
echo "<td>Name</td>";
echo "<td>E-Mail</td>";
echo "</tr>";
// Schleife über alle Datensätze der Abfrage:
// solange (while) ein Datensatz vorhanden ist im
// Abfrage-Ergebnis ($results):
while($rowitem = mysqli_fetch_array($results))
// jeder Datensatz ist durch $rowitem (Zeilenwert) erreichbar:
{
echo "<tr>";
// Die verwendeten Namen in den eckigen Klammern müssen
// den Namen in der Datenbank entsprechen:
echo "<td>" . $rowitem['name'] . "</td>";
echo "<td>" . $rowitem['mail'] . "</td>";
echo "</tr>";
}
echo "</table>";
?>