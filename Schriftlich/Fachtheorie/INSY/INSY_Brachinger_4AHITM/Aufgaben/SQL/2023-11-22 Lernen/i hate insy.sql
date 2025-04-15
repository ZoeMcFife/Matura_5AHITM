USE filmdb;

-- Filme 2003

SELECT * FROM film WHERE jahr = 2003;

-- 2. Geben Sie alle lebenden Personen aus, sortieren Sie diese nach dem Geburtsdatum.
SELECT * FROM person WHERE SterbeDatum IS NULL ORDER BY GeburtsDatum;

-- Geben Sie Name und Geburtsdatum aller Schauspieler aus, die vor dem 11. Mai 1985 geboren wurden aus, sortieren Sie diese nach dem Namen.

SELECT Name, GeburtsDatum FROM schauspieler NATURAL JOIN person WHERE GeburtsDatum < "1985-05-11" ORDER BY Name;

-- Geben Sie die Schauspieler zusammen mit den Filmen in denen sie mitgespielt haben aus.
SELECT DISTINCT person.SVNr, person.Name, Titel, Jahr FROM spielt JOIN person ON spielt.SVNr = person.SVNr;

/* Geben Sie f¨ur jeden Schauspieler, der schon eine Figur gespielt hat, die folgende Info aus: SVNr,
Name, Geburtsdatum, Anzahl der Filme in denen er mitgespielt hat, Anzahl der verschiedenen
Figuren, sowie die l¨angste Drehdauer. */

/*SELECT DISTINCT p.SVNr,
                p.Name,
                p.GeburtsDatum,
                COUNT(f.Titel, f.Jahr)
FROM spielt s JOIN person p ON s.SVNr = p.SVNr
JOIN film f ON s.Titel = f.Titel AND s.Jahr = f.Jahr
GROUP BY p.SVNr, f.Titel, f.Jahr*/

/* too puppy brained for this*/

/* Gesucht ist der Film mit der k¨urzesten Drehdauer, wobei der Film und die Drehdauer ausgegeben
werden soll. */

SELECT Titel, Jahr, min(dauer) as Dauer from
(SELECT Titel, Jahr, DrehEnde - film.DrehBeginn AS dauer from film) as Td;

/* 14. Geben Sie f¨ur jeden Film Titel, Jahr, Anzahl der Figuren, Anzahl der beteiligten Schauspieler,
sowie die Drehdauer aus.*/

SELECT Titel, Jahr, COUNT(SVNr) AS Schauspieler, COUNT(Name) AS Figuren, (DrehEnde - DrehBeginn) AS Dauer
FROM film
LEFT OUTER JOIN spielt USING (Titel, Jahr)
GROUP BY Titel, Jahr, DrehEnde, DrehBeginn;

/* Geben Sie den Schauspieler aus, der im Jahr 2003 (Erscheinungsjahr) in den meisten Filmen
mitgespielt hat.*/

SELECT DISTINCT SVNr, person.name, COUNT(DISTINCT Titel, Jahr) AS filme
FROM spielt JOIN person USING (svnr)
WHERE Jahr = 2003
GROUP BY SVNr
HAVING filme >= ALL(
SELECT COUNT(DISTINCT Titel, Jahr)
FROM spielt
WHERE Jahr = 2003
GROUP BY SVNr);

/* Geben Sie f¨ur alle verstorbenen Regiseure SVNr, Name und die Anzahl der Filme, bei denen
sie Regie gef¨uhrt haben, aus.*/

SELECT p.SVNr, p.Name, COUNT(DISTINCT Titel, Jahr)
FROM macht JOIN person p USING (SVNr)
WHERE SterbeDatum IS NOT NULL
AND Job = 'Regie'
GROUP BY SVNr;

/* 16. Geben Sie alle Filme aus, von denen es keine Fortsetzung gibt*/

SELECT Titel, Jahr
FROM film WHERE (Titel, Jahr) NOT IN
(SELECT VonTitel, VonJahr FROM fortsetzung);

/*17. Geben Sie alle Filme zusammen mit der Anzahl der Fremdsprachen, in die sie ¨ubersetzt wurden
aus. */

SELECT f.Titel, f.Jahr, COUNT(DISTINCT Sprache)
FROM film f
LEFT OUTER JOIN fremdtitel fd ON f.Titel = fd.OrigTitel and f.Jahr = fd.OrigJahr
GROUP BY f.Titel, f.Jahr;

/*  Geben Sie f¨ur jedes Jahr die Anzahl der in diesem Jahr erschienen Filme aus. Sortieren Sie
das Ergebnis absteigend nach der Anzahl der Filme und aufsteigend nach der Jahreszahl.*/

SELECT Jahr, COUNT(DISTINCT Titel, Jahr) AS Filme
FROM film
GROUP BY Jahr
ORDER BY Filme DESC , Jahr;

/* Geben Sie alle Figuren aus, die in mindestens 3 Filmen vorkommen und immer von einem
anderen Schauspieler gespielt wurden. Geben Sie des weiteren die Anzhl der entsprechenden
Filme, sowie die Anzahl der Schauspieler aus. */

SELECT s.Name, p.Name, COUNT(*) AS Filme
FROM spielt s
JOIN person p ON p.SVNr = s.SVNr
GROUP BY s.Name
HAVING Filme >= 3 AND COUNT(DISTINCT p.SVNr) = 1;

/* 23. Geben Sie alle Filme aus, in denen keine Schauspieler mitgespielt haben.*/

SELECT Titel, Jahr
FROM film f
WHERE NOT EXISTS (SELECT * FROM spielt s WHERE f.Titel = s.Titel AND f.Jahr = s.Jahr);