#   Erstellen Sie eine View CDDauer welche die Gesamtdauer einer CD ermittelt. Die Gesamtdauer einer
#   CD ist die Summe der Dauer aller Tracks die auf der CD vorkommen

USE myspotify;

CREATE OR REPLACE VIEW CDView AS
SELECT CD.nr, CD.name, SUM(lied.dauer) AS Gesamtdauer
FROM CD
NATURAL JOIN track
NATURAL JOIN lied
GROUP BY CD.nr;


SELECT * from cd;
SELECT * from CDView;