USE kaufen;

/*
a)
Geben Sie jene Kunden (mit KndNr, Vorname und Nachname) aus,
welche zumindest einen Artikel bestellt haben, der den Text "DVD" beinhaltet.
Hat ein Kunde mehrmals derartige Artikel bestellt, soll er nur 1x ausgegeben werden.
*/

SELECT
    DISTINCT (KndNr), Vorname, Nachname
FROM
    kunden NATURAL JOIN bestellungen
    NATURAL JOIN positionen
WHERE
    positionen.Artikel LIKE '%DVD%';
/*
b)
Geben Sie zu jeder Kundennummer (KndNr) die Anzahl der Bestellungen aus.
Dabei sollen nur jene Kundennummern angezeigt werden,
welche mindestens 2 Bestellungen haben.
*/

SELECT
    KndNr,
    COUNT(BestellungsNr) AS Anzahl
FROM
    kunden NATURAL JOIN bestellungen
GROUP BY
    KndNr
HAVING
    Anzahl >= 2;

/*
c)
Geben Sie jene Kunden (mit KndNr, Vorname und Nachname) aus,
von denen keine Kreditkarte in der Datenbank gespeichert ist.
*/

SELECT
    KndNr,
    Vorname,
    Nachname
FROM
    kunden as k
WHERE
    KndNr NOT IN
    (SELECT KndNr FROM kunden NATURAL JOIN kreditkarten);

/*
d)
Erstellen Sie eine View „Anzahl2024“, welche die Anzahl der Bestellungen
aus dem heurigen Jahr (2024) beinhaltet.
Die einzige Spalte dieser View soll „Anzahl“ lauten.
*/

CREATE VIEW Anzahl2024 AS
SELECT
    COUNT(BestellungsNr) AS Anzahl
FROM
    bestellungen
WHERE
    year(bestellungen.Datum) = '2024';


/*
e)
Alle Kreditkarten, deren Ablaufdatum vor dem 1. Jänner 2024 liegt,
sollen gelöscht werden.
Erstellen Sie das nötige DML-Statement.
*/

DELETE FROM kreditkarten
WHERE Ablaufdatum  < '2024-01-01';