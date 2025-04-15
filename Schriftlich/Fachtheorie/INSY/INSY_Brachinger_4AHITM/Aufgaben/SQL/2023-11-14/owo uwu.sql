USE filmdb;

SELECT Genre, count(*) AS anzahl FROM hatgenre GROUP BY Genre
HAVING anzahl >= ALL (SELECT COUNT(*) FROM  hatgenre GROUP BY Genre);

/* Welche Schauspieler haben in den meisten filmen gespielt */

SELECT p.name, spielt.SVNr, spielt.Name, count(*) AS anzahl FROM spielt JOIN person p on spielt.SVNr = p.SVNr GROUP BY SVNr
HAVING anzahl >= ALL (SELECT count(*) FROM spielt GROUP BY SVNr);

/* Welche Schauspieler haben in den meisten rollen gespielt */

SELECT p.name, spielt.SVNr, count(distinct spielt.Name) AS anzahl FROM spielt JOIN person p on spielt.SVNr = p.SVNr GROUP BY SVNr
HAVING anzahl >= ALL (SELECT count(distinct spielt.Name) FROM spielt GROUP BY SVNr);

SELECT name, Titel, Job FROM person NATURAL JOIN crew NATURAL JOIN macht WHERE SterbeDatum IS NULL ORDER BY Job DESC;

SELECT * FROM person NATURAL JOIN schauspieler WHERE schauspieler.SVNr NOT IN (SELECT SVNr FROM spielt);

/* 10. Geben Sie alle ”reinen” Kom¨odien aus (Filme, die kein 2. Genre zugewiesen haben). */

SELECT Titel, Jahr FROM hatgenre WHERE Genre = "Kom?die"
AND (Titel,Jahr)
NOT IN (SELECT Titel, Jahr FROM hatgenre WHERE Genre != "Kom?die");

/* 11. Geben Sie alle Schauspieler aus, die schon in einem Actionfilm, aber noch in keinem Spionagefilm
mitgespielt haben. */

/*SELECT SVNr, Titel, Jahr, Genre spielt NATURAL JOIN hatgenre;
*/

/*  1. Geben Sie alle Filme aus, die im Jahr 2003 herausgekommen sind. */





/*
2. Geben Sie alle lebenden Personen aus, sortieren Sie diese nach dem Geburtsdatum.
3. Geben Sie Name und Geburtsdatum aller Schauspieler aus, die vor dem 11. Mai 1985 geboren
wurden aus, sortieren Sie diese nach dem Namen.
4. Geben Sie die Schauspieler zusammen mit den Filmen in denen sie mitgespielt haben aus.
5. Geben Sie alle Schauspieler aus, die w¨ahrend Dreharbeiten (von Filmen, bei denen sie mitgespielt
haben) verstorben sind.
6. Geben Sie alle Figuren aus, die in mindestens 3 Filmen vorkommen und immer vom selben
Schauspieler gespielt wurden.
7. Geben Sie alle Figuren aus, die in mindestens 3 Filmen vorkommen und immer von einem
anderen Schauspieler gespielt wurden. Geben Sie des weiteren die Anzhl der entsprechenden
Filme, sowie die Anzahl der Schauspieler aus.
8. Geben Sie alle Personen aus, die in einem Film sowohl Regie gef¨uhrt, das Drehbuch geschrieben,
als auch eine Rolle gespielt haben.
9. eben Sie alle Filmpaare aus, bei denen die ”Fortsetzung” VOR dem Film selbst gedreht wurde
(oder das Prequel nach dem Film).

12. Geben Sie f¨ur jeden Schauspieler, der schon eine Figur gespielt hat, die folgende Info aus: SVNr,
Name, Geburtsdatum, Anzahl der Filme in denen er mitgespielt hat, Anzahl der verschiedenen
Figuren, sowie die l¨angste Drehdauer.
13. Gesucht ist der Film mit der k¨urzesten Drehdauer, wobei der Film und die Drehdauer ausgegeben
werden soll.
14. Geben Sie f¨ur jeden Film Titel, Jahr, Anzahl der Figuren, Anzahl der beteiligten Schauspieler,
sowie die Drehdauer aus.
15. Geben Sie f¨ur alle verstorbenen Regiseure SVNr, Name und die Anzahl der Filme, bei denen
sie Regie gef¨uhrt haben, aus.
16. Geben Sie alle Filme aus, von denen es keine Fortsetzung gibt.
17. Geben Sie alle Filme zusammen mit der Anzahl der Fremdsprachen, in die sie ¨ubersetzt wurden
aus.
18. Geben Sie den Schauspieler aus, der im Jahr 2003 (Erscheinungsjahr) in den meisten Filmen
mitgespielt hat.
19. Geben Sie f¨ur jedes Jahr die Anzahl der in diesem Jahr erschienen Filme aus. Sortieren Sie
das Ergebnis absteigend nach der Anzahl der Filme und aufsteigend nach der Jahreszahl.
20. Geben Sie von allen Jahren, in denen Filme erschienen sind, diejenigen aus, in denen die es
die wenigsten waren.
21. Geben Sie f¨ur alle Personen SVNr und Name, sowie die Anzahl der Filme an denen sie beteiligt
sind aus. Sortieren Sie nach der Anzahl der Filme.
22. Geben Sie alle Schauspieler aus, die keine anderen T¨atigkeiten (also auch nicht als Sprecher)
ausge¨ubt haben.
23. Geben Sie alle Filme aus, in denen keine Schauspieler mitgespielt haben.
24. Geben Sie die Sprache aus, bei der es im Durchschnitt am l¨angsten dauert, bis Filme in diese
¨ubersetzt werden.
25. Geben Sie alle Schauspieler aus, zusammen mit der Anzahl der Figuren, die sie gesprochen
haben, die Anzahl der Filme, an denen Sie als Sprecher beteiligt waren, sowie welchem Prozentsatz
der Filme mit Sprechern dies entspricht.
 */

DROP VIEW v_schauspieler_spielt_anzahl;

CREATE VIEW v_schauspieler_spielt_anzahl AS
    (SELECT p.name, spielt.SVNr, count(spielt.Name) AS anzahl FROM spielt JOIN person p on spielt.SVNr = p.SVNr GROUP BY SVNr);

