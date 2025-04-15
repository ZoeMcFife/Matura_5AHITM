drop database company;

create database company default char set=utf8;

USE company;

CREATE TABLE abteilung
(
    anr INTEGER PRIMARY KEY,
    aname VARCHAR(30),
    leiter INTEGER NOT NULL
);

CREATE TABLE mitarbeiter
(
    mnr INTEGER PRIMARY KEY,
    vname VARCHAR(30),
    nname VARCHAR(30),
    anr INTEGER,
    CONSTRAINT fk_mitarbeiter_abteilung FOREIGN KEY (anr) REFERENCES abteilung (anr)
);

ALTER TABLE abteilung ADD CONSTRAINT fk_abteiling_mitarbeiter
FOREIGN KEY (leiter) REFERENCES mitarbeiter(mnr);

SHOW CREATE TABLE abteilung;
SHOW CREATE TABLE mitarbeiter;

SET FOREIGN_KEY_CHECKS = 0;
INSERT INTO abteilung(anr, aname, leiter) VALUES (1, "Owo", 1);
INSERT INTO mitarbeiter(mnr, vname, nname, anr) VALUES (1, "Rawr", "x3", 1);
SET FOREIGN_KEY_CHECKS = 1;
