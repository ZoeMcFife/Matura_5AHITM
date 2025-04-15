USE weinkellerei;

SELECT wein.bezeichnung, winzer.name FROM wein NATURAL JOIN winzer;

SELECT wein.bezeichnung, winzer.name FROM wein JOIN winzer ON wein.wnr = winzer.wnr;

SELECT wein.bezeichnung, winzer.name FROM wein JOIN winzer USING(wnr);

/* Welcher wein wo im keller zu finden ist */

SELECT bezeichnung, reihe, regal, fach FROM wein JOIN keller k on wein.position = k.knr;

/* Liste und winzer und weine (alle) */

SELECT winzer.name, ifnull(wein.bezeichnung, "Kein Wein") AS "Wein" FROM wein RIGHT OUTER JOIN winzer ON wein.wnr = winzer.wnr;

/* Geben Sie fur die Sorte ’Riesling’ die Namen aller Winzer sowie die Flaschenanzahl aus. Sortieren ¨
Sie dabei nach der Flaschenanzahl absteigend. */

SELECT winzer.name, wein.anzahl FROM winzer NATURAL JOIN wein WHERE wein.sorte = "Riesling" ORDER BY wein.anzahl DESC;

/* Geben Sie eine Liste aller Weinbezeichnungen sowie den Namen des erzeugenden Winzers aus,
von denen im Jahr 2003 keine Flasche getrunken worden ist (Verwendung in Tabelle Protokoll =
’Eigenbedarf’). Sie brauchen dabei nur Winzer berucksichtigen, von denen mindestens eine Flasche ¨
im Keller vorhanden ist. */

SELECT we.bezeichnung, w.name FROM winzer w NATURAL JOIN wein we WHERE we.nr NOT IN (SELECT nr FROM protokoll WHERE verwendung = "Eigenbedarf" AND YEAR(pDatum) = 2003);

/* . Geben Sie fur jeden Winzer aus, ¨
wie viele gunstige (Preis ¨ ≤ 10 Euro, Preisklasse niedrig),
wie viele im Mittelfeld (10 Euro - 20 Euro, Preisklasse mittel) und
wie viele teure (Preis > 20 Euro, Preisklasse gehoben) Weinflaschen im Keller liegen. */

SELECT winzer.name, wein.anzahl, "niedrig" as preisklasse FROM winzer NATURAL JOIN wein WHERE wein.preis <= 10 UNION
SELECT winzer.name, wein.anzahl, "mittel" as preisklasse FROM winzer NATURAL JOIN wein WHERE wein.preis > 10 AND preis < 20 UNION
SELECT winzer.name, wein.anzahl, "teuer" as preisklasse FROM winzer NATURAL JOIN wein WHERE wein.preis >= 20;

/* Agreggat Funktionen */
/*
    * sum
    * max
    * min
    * avg
    * count
*/

/* wie viele flashen im keller insgesamt */

SELECT SUM(anzahl) AS "anzahl" FROM wein;

/* Ermitteln Sie fur jeden Winzer den durchschnittlichen Flaschenpreis und die Gesamtanzahl der ¨
Flaschen im Keller. Berucksichtigen Sie dabei nur Winzer, von denen bekannt ist, aus welchem Ort ¨
sie kommen. Sortieren Sie die Liste nach dem Preis absteigend. */

SELECT w.name, AVG(we.preis) AS Durschschnittspreis, SUM(we.anzahl)
FROM wein we NATURAL JOIN winzer w
WHERE w.ort IS NOT NULL
GROUP BY w.name, w.wnr
ORDER BY Durschschnittspreis DESC;

/* Pro winzer wie viele Weine bieten sie an */

SELECT w.name, COUNT(we.wnr) AS Weintypen FROM wein we RIGHT OUTER JOIN winzer w ON we.wnr = w.wnr GROUP BY w.name, we.wnr;

/* Suchen Sie die Winzer, von denen der Kellereigentumer die meisten Flaschen getrunken (Verwen- ¨
dung in Tabelle Protokoll = ’Eigenbedarf’) hat. Geben Sie jeweils den Namen des Winzers sowie
die Gesamtkosten des von diesem Winzer konsumierten Weines aus. */


select winzer.name, sum(proto.anzahl) as a, (sum(proto.anzahl) * wein.preis) as p
from winzer natural join (wein join (
    select * from protokoll where verwendung = "Eigenbedarf"
) as proto on wein.nr = proto.nr)
group by winzer.name, proto.anzahl, wein.preis
order by a desc limit 1;

select *
from winzer natural join (wein join (
    select * from protokoll where verwendung = "Eigenbedarf"
) as proto on wein.nr = proto.nr)
group by winzer.name;

select name, sum(wein.anzahl) as a
from winzer left outer join wein on winzer.wnr = wein.wnr
group by name
order by a desc;