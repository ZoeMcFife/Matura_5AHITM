DROP DATABASE IF EXISTS flugverbindungen;

CREATE DATABASE flugverbindungen DEFAULT CHARACTER SET = utf8;

USE flugverbindungen;

CREATE TABLE flug
(
    abflug VARCHAR(30),
    ankunft VARCHAR(30),

    PRIMARY KEY (abflug, ankunft)
);

INSERT INTO flug VALUES ('Wien', 'Frankfurt');
INSERT INTO flug VALUES ('Frankfurt', 'London');
INSERT INTO flug VALUES ('Wien', 'Budapest');
INSERT INTO flug VALUES ('Wien', 'Venedig');
INSERT INTO flug VALUES ('Venedig', 'Rom');
INSERT INTO flug VALUES ('Wien', 'Zuerich');
INSERT INTO flug VALUES ('Zuerich', 'Paris');
INSERT INTO flug VALUES ('Paris', 'Madrid');
INSERT INTO flug VALUES ('Madrid', 'Malta');


/* Direkt Flüge von Wien */

SELECT * FROM flug WHERE abflug = 'Wien';

/* Zielflughäfen mit einmal umsteigen */

SELECT f1.abflug, f2.ankunft, 1 AS umsteigen
FROM flug f1, flug f2
WHERE f1.ankunft = f2.abflug
AND f1.abflug = 'Wien'
UNION
SELECT *, 0 AS umsteigen
FROM flug WHERE abflug = 'Wien';

/* Zielflughäfen mit zweimal umsteigen */

SELECT f1.abflug, f2.ankunft, 1 AS umsteigen
FROM flug f1, flug f2
WHERE f1.ankunft = f2.abflug
AND f1.abflug = 'Wien'

UNION

SELECT *, 0 AS umsteigen
FROM flug WHERE abflug = 'Wien'

UNION

SELECT f1.abflug, f3.ankunft, 2 AS umsteigen
FROM flug f1, flug f2, flug f3
WHERE f1.ankunft = f2.abflug
AND f2.ankunft = f3.abflug
AND f1.abflug = 'Wien';

-- CTE - Common Table Expression
WITH RECURSIVE h AS
(
    SELECT abflug, ankunft, 0 AS UMSTEIGEN FROM flug WHERE abflug = 'Wien'
    UNION ALL
    SELECT h.abflug, flug.ankunft, UMSTEIGEN+1
    FROM h, flug
    WHERE h.ankunft = flug.abflug
)
SELECT * FROM h;

