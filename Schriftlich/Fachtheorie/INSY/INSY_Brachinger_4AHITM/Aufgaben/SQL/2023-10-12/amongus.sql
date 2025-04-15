-- Amongus.sql

-- Aktuelle Datenbank verwenden
USE weinkellerei;

-- Tabellen in der aktuellen Datenbank anzeigen
SHOW TABLES;

-- Anmerkung: Die Zeile 'mysql -u root' ist ein Befehl für die Shell und sollte nicht in der SQL-Mitschrift stehen

-- Verfügbare Datenbanken anzeigen
SHOW DATABASES;

-- Struktur der Tabelle 'WINZER' beschreiben
DESCRIBE WINZER;

-- SQL-Anweisung zur Erstellung der Tabelle 'WINZER' anzeigen
SHOW CREATE TABLE WINZER;

-- Alle Datensätze der Tabelle 'winzer' auswählen
SELECT * FROM winzer;

-- Nur den Vornamen aus der Tabelle 'winzer' auswählen
SELECT vname FROM winzer;

-- Alias für den Vornamen verwenden
SELECT vname AS winzername FROM winzer;

-- Datensätze auswählen, bei denen 'wnr' größer als 5 ist
SELECT * FROM winzer WHERE wnr > 5;

-- Verfügbare Operatoren: <, >, <=, >=, !=, <>
-- Verfügbare logische Operatoren: AND, OR, NOT

-- Datensätze auswählen, bei denen 'vnr' zwischen 2 und 8 und 'plz' gleich 5600 ist
SELECT * FROM winzer WHERE vnr >= 2 AND vnr <= 8 AND plz = 5600;

-- Datensätze auswählen, bei denen die Telefonnummer NULL ist
SELECT * FROM winzer WHERE telefon IS NULL;

-- Datensätze auswählen, bei denen die Telefonnummer nicht NULL ist
SELECT * FROM winzer WHERE telefon IS NOT NULL;

-- Datensätze nach dem Namen in aufsteigender Reihenfolge sortieren
SELECT * FROM winzer ORDER BY name;

-- Datensätze nach dem Namen in absteigender Reihenfolge sortieren
SELECT * FROM winzer ORDER BY name DESC;

-- Datensätze nach 'plz' in absteigender und 'vname' in aufsteigender Reihenfolge sortieren
SELECT * FROM winzer ORDER BY plz DESC, vname ASC;

-- Datensätze auswählen, bei denen der Name mit 'Weingut' beginnt
SELECT * FROM winzer WHERE name LIKE 'Weingut%';

-- Datensätze auswählen, bei denen 'plz' 3610 oder 3601 ist
SELECT * FROM winzer WHERE plz IN (3610, 3601);

-- Datensätze auswählen, die in der Tabelle 'wein' vorhanden sind
SELECT * FROM winzer WHERE wnr IN (SELECT wnr FROM wein);

-- Datensätze auswählen, die nicht in der Tabelle 'wein' vorhanden sind
SELECT * FROM winzer WHERE wnr NOT IN (SELECT wnr FROM wein);