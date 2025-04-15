USE frienddb;

SELECT p.pid, name, f.pid, f.friend FROM friends f JOIN person p ON f.pid = p.pid;

/* Geben Sie die Nummern der Freunde von Max an (direkte und indirekte) */

WITH RECURSIVE h AS
    (
        SELECT pid, friend from friends WHERE pid = 1
        UNION ALL
        SELECT h.pid, friends.friend FROM h, friends
        WHERE h.friend = friends.pid
    )
SELECT DISTINCT * FROM h;

