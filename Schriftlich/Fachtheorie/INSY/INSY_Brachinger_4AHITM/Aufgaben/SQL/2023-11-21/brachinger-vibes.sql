USE filmdb;

/* Doppelrollen */

SELECT SPIELT.SVNr, p.Name, count(*) AS roles
FROM schauspieler s
NATURAL JOIN person p
JOIN spielt ON s.SVNr = spielt.SVNr
GROUP BY SVNr, Titel, Jahr
HAVING count(*) > 1;

/* kürzeste Drehdauer */

SELECT Titel, Jahr, min(dauer) as Dauer from
(SELECT Titel, Jahr, DrehEnde - film.DrehBeginn AS dauer from film) as Td;

SELECT Titel, Jahr, (DrehEnde - DrehBeginn) as Drehdauer from film where (DrehEnde - DrehBeginn) <= ALL (select (DrehEnde - DrehBeginn) from film);

/* Beteiligten eines films */

SELECT film.Titel, s.SVNR, (DrehEnde - film.DrehBeginn) AS drehdauer
FROM film
JOIN spielt s ON film.Titel = s.Titel and film.Jahr = s.Jahr
UNION
SELECT film.Titel, macht.SVNR, (DrehEnde - film.DrehBeginn) AS drehdauer
FROM film
JOIN macht ON film.Titel = macht.Titel and film.Jahr = macht.Jahr
;

SELECT Titel,
       Jahr,
       count(distinct SVNr) AS "Schauspieler",
       count(distinct Name) AS "Figuren",
       (DrehEnde - film.DrehBeginn) AS "Drehdauer"
FROM film
LEFT OUTER JOIN spielt USING (Titel, Jahr)
GROUP BY Titel, Jahr, DrehEnde, DrehBeginn;

/* Geben Sie f¨ur alle verstorbenen Regiseure SVNr, Name und die Anzahl der Filme, bei denen
sie Regie gef¨uhrt haben, aus. */

SELECT person.SVNr, person.Name, count(distinct Titel) AS Anzahl
FROM person
NATURAL JOIN crew
NATURAL JOIN macht
WHERE SterbeDatum IS NOT NULL
AND Job = "Regie"
GROUP BY SVNR, person.Name;

/* 16. Geben Sie alle Filme aus, von denen es keine Fortsetzung gibt */

SELECT * FROM film WHERE (Titel, Jahr)
NOT IN (SELECT Titel, Jahr FROM fortsetzung);

SELECT f.*
FROM film f
WHERE NOT EXISTS
    (SELECT * FROM fortsetzung fo
       WHERE fo.VonTitel = f.Titel AND fo.VonJahr = f.Jahr);

/*18. Geben Sie den Schauspieler aus, der im Jahr 2003 (Erscheinungsjahr) in den meisten Filmen
mitgespielt hat.*/

SELECT SVNr, count(DISTINCT Titel, Jahr) AS Filme
FROM film
NATURAL JOIN spielt
WHERE Jahr = 2003
GROUP BY SVNr
HAVING Filme >= ALL
(SELECT count(DISTINCT Titel, Jahr) AS Filme
 FROM film NATURAL JOIN spielt
 WHERE Jahr = 2003
 GROUP BY SVNr);

SELECT s.SVNr, person.name, count(distinct Titel)
FROM person NATURAL JOIN schauspieler join spielt s on schauspieler.SVNr = s.SVNr
WHERE Jahr = 2003
GROUP BY SVNr, person.name
HAVING count(distinct Titel) >= ALL
(
       SELECT count(distinct Titel)
       FROM spielt
       WHERE Jahr = 2003
       GROUP BY SVNr
              );