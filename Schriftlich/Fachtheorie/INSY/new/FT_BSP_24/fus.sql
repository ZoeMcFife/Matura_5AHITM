USE fifa_tournament;

-- a) Gebe alle Mannschaften (MID, Name) aus, die mindestens eine rote oder gelbe Karte erhalten haben

SELECT
    DISTINCT mannschaft.mid, mannschaft.name
FROM
    mannschaft JOIN fifa_tournament.ereignis e on mannschaft.MID = e.MID
WHERE
    Bezeichnung LIKE '%Gelbe%'
    OR Bezeichnung LIKE '%Rote%';


-- b) Gebe alle Mannschaften (MID, Name) aus, die KEINE rote oder gelbe Karte erhalten haben

SELECT
    DISTINCT mannschaft.mid, mannschaft.name
FROM
    mannschaft
WHERE
    mannschaft.MID NOT IN
    (SELECT MID
     FROM ereignis
     WHERE
    Bezeichnung LIKE '%Gelbe%'
    OR Bezeichnung LIKE '%Rote%');

-- c) Liste aller Mannschaften mit mindestens 3 Toren (MID, Name, Toranzahl)

SELECT
    mannschaft.mid,
    mannschaft.name,
    COUNT(ENR) AS TORE
FROM
    mannschaft JOIN fifa_tournament.ereignis e on mannschaft.MID = e.MID
WHERE
    Bezeichnung LIKE '%Tor%';

-- d) Fehlererklärung zur NATURAL JOIN-Abfrage:
-- NATURAL JOIN verbindet Tabellen automatisch über Spalten mit gleichem Namen.
-- In diesem Fall haben Spieler und Mannschaft zwar beide eine Spalte "Name",
-- aber diese enthält unterschiedliche Daten (Spielername vs. Mannschaftsname).
-- Deshalb versucht NATURAL JOIN über "Name" zu joinen, was zu keiner Übereinstimmung führt.

select Mannschaft.Name as Mannschaftsname, Spieler.Name as Spielername
from Spieler natural join Mannschaft;

-- Korrekte Version: JOIN über die gemeinsame MID-Spalte

SELECT
    Mannschaft.Name as Mannschaftsname, Spieler.Name as Spielername
FROM
    spieler JOIN mannschaft on spieler.MID = mannschaft.MID;