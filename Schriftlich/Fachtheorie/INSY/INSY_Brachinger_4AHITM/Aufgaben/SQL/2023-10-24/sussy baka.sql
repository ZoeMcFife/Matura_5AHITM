USE filmdb;

SELECT titel, jahr, count(genre) FROM hatgenre GROUP BY titel, jahr;

SELECT svnr, COUNT(distinct titel, jahr) FROM spielt GROUP BY name;

SELECT spielt.svnr, person.name, count(DISTINCT titel, jahr)
FROM spielt, schauspieler, person
WHERE spielt.SVNr = schauspieler.SVNr
AND schauspieler.SVNr = person.SVNr
GROUP BY spielt.SVNr, person.Name;

SELECT spielt.svnr, person.name, count(DISTINCT titel, jahr) AS anz
FROM spielt, schauspieler, person
WHERE spielt.SVNr = schauspieler.SVNr
AND schauspieler.SVNr = person.SVNr
GROUP BY spielt.SVNr, person.Name HAVING anz > 3;

SELECT spielt.svnr, person.name, count(DISTINCT titel, jahr) AS anz
FROM spielt, schauspieler, person
WHERE spielt.SVNr = schauspieler.SVNr
  AND schauspieler.SVNr = person.SVNr
GROUP BY spielt.SVNr, person.Name
HAVING anz >= ALL (
    SELECT COUNT(DISTINCT titel, jahr) FROM spielt GROUP BY spielt.SVNr
);

SELECT SVNr, count(SVNr) FROM macht WHERE Job = "Regie" GROUP BY SVNr HAVING count(*) >= ALL (SELECT count(SVNr) FROM macht WHERE job = "Regie" GROUP BY SVNr) ;
