USE weinkeller;

-- 1) Geben Sie für die Sorte 'Riesling' die Namen aller Winzer sowie die Flaschenanzahl aus.
--    Sortieren Sie dabei nach der Flaschenanzahl absteigend.
--    Ergebnis:
--      name                                    | anzahl
--      ----------------------------------------+-------
--      Freie Weingarten Wachau                 | 80
--      Weingut Prager                          | 30
--      Weingut F.X. Pichler                    | 24

SELECT name, anzahl
FROM winzer NATURAL JOIN wein
WHERE bezzeichnung LIKE '%Riesling%'
ORDER BY anzahl DESC;

-- 2) Ermitteln Sie für jeden Winzer den durchschnittlichen Flaschenpreis
--    und die Gesamtanzahl der Flaschen im Keller.
--    Berücksichtigen Sie dabei nur Winzer, von denen bekannt ist, aus welchem Ort sie kommen.
--    Sortieren Sie die Liste nach dem Preis absteigend.
--    Ergebnis:
--      name                                    | durchschnittspreis | gesamtanzahl
--      ----------------------------------------+--------------------+-------------
--      Weingut F.X. Pichler                    | 23.50              | 60
--      Weingut Prager                          | 21.00              | 30
--      Weingut Emmerich Knoll                  | 19.00              | 15
--      Lackner Tinnacher                       | 12.50              | 127
--      Freie Weingarten Wachau                 |  9.90              | 80
--      Weingut Biegler                         |  9.00              | 16

SELECT name, avg(preis) AS AVG, anzahl
FROM winzer NATURAL JOIN wein
WHERE ort IS NOT NULL
GROUP BY wnr, name
ORDER BY AVG DESC;

-- 3) Geben Sie eine Liste aller Weinbezeichnungen sowie den Namen des erzeugenden Winzers aus,
--    von denen im Jahr 2003 keine Flasche getrunken worden ist
--    (Verwendung in Protokoll = 'Eigenbedarf').
--    Berücksichtigen Sie nur Winzer, von denen mindestens eine Flasche im Keller vorhanden ist.
--    Ergebnis:
--      nr | bezzeichnung           | name
--      ---+------------------------+----------------------------
--       2 | Loibenberg             | Weingut F.X. Pichler
--       4 | Riesling Smaragd       | Weingut Prager
--       5 | Grauburgunder          | Lackner Tinnacher
--       7 | Riesling Federspiel    | Freie Weingarten Wachau
--       8 | Chardonnay             | Weingut Biegler

SELECT
  w.nr,
  w.bezzeichnung,
  z.name
FROM
  wein AS w
  JOIN winzer AS z ON w.wnr = z.wnr
WHERE
  NOT EXISTS (
    SELECT 1
    FROM protokoll AS p
    WHERE p.nr = w.nr
      AND p.verwendung = 'Eigenbedarf'
      AND YEAR(p.pDatum) = 2003
  )
  AND EXISTS (
    SELECT 1
    FROM wein AS w2
    WHERE w2.wnr = z.wnr
      AND w2.anzahl > 0
  )
ORDER BY
  w.nr;

-- 4) Suchen Sie die Winzer, von denen der Kellereigentümer die meisten Flaschen getrunken
--    (Verwendung in Protokoll = 'Eigenbedarf') hat.
--    Geben Sie jeweils den Namen des Winzers sowie die Gesamtkosten
--    des von diesem Winzer konsumierten Weines aus.
--    Ergebnis:
--      name                    | anzahl | kosten
--      ------------------------+--------+--------
--      Weingut F.X. Pichler    | 4      | 112.00

    SELECT
        z.name,
        p.anzahl,
        sum(w.preis) AS kosten
    FROM
        winzer as z JOIN weinkeller.wein w on z.wnr = w.wnr
        JOIN weinkeller.protokoll p on w.nr = p.nr
    WHERE
        verwendung = 'Eigenbedarf'
        AND
        p.anzahl >= all
           (
                SELECT (p.anzahl)
                FROM
                    winzer as z JOIN weinkeller.wein w on z.wnr = w.wnr
                    JOIN weinkeller.protokoll p on w.nr = p.nr
                WHERE
                    verwendung = 'Eigenbedarf'
                GROUP BY
                    Z.wnr, anzahl
            )
    GROUP BY
        Z.wnr, anzahl;

insert into winzer values (9,'Zargothrax', 'Fife', '666', 'Evil Fortress', null);
insert into keller value (9, 3, 3, 3);
insert into wein values(9, 'Evil Wine', 'Wine', 1992, 10, 230, 9, 9);
insert into protokoll values (8, 9, '2003-11-03', 'Eigenbedarf', 4);
insert into keller value (10, 3, 12, 3);
insert into wein values(10, 'Evil Wine 2: Electric Boogaloo', 'Wine', 1992, 6, 12, 9, 10);
insert into protokoll values (9, 10, '2003-11-03', 'Eigenbedarf', 3);

-- 5) Geben Sie für jeden Winzer aus, wie viele günstige (Preis ≤ 10 Euro, Preisklasse niedrig),
--    wie viele im Mittelfeld (10 Euro - 20 Euro, Preisklasse mittel) und
--    wie viele teure (Preis > 20 Euro, Preisklasse gehoben) Weinflaschen im Keller liegen.
--    Ergebnis:
--      name                                   | anzahl | preisklasse
--      ---------------------------------------+--------+------------
--      Freie Weingarten Wachau                | 80     | niedrig
--      Lackner Tinnacher                      | 55     | niedrig
--      Lackner Tinnacher                      | 72     | mittel
--      Weingut Biegler                        | 16     | niedrig
--      Weingut Emmerich Knoll                 | 15     | mittel
--      Weingut F.X. Pichler                   | 24     | gehoben
--      Weingut F.X. Pichler                   | 36     | mittel
--      Weingut Prager                         | 30     | gehoben

-- 6) Erstellen Sie eine Liste, die angibt, wie viele Flaschen jedes in der Datenbank
--    gespeicherten Winzers sich im Keller befinden.
--    Sortieren Sie dabei nach der Flaschenanzahl absteigend.
--    Ergebnis:
--      name                                   | anzahl
--      ---------------------------------------+-------
--      Lackner Tinnacher                      | 127
--      Freie Weingarten Wachau                | 80
--      Weingut F.X. Pichler                   | 60
--      Weingut Prager                         | 30
--      Weingut Biegler                        | 16
--      Weingut Emmerich Knoll                 | 15
--      Weingut Spatlese                       | NULL
--      Stiftskellerei                         | NULL
