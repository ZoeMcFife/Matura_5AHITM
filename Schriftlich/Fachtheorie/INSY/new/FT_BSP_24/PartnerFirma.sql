DROP DATABASE IF EXISTS partner_firma_db;

CREATE DATABASE partner_firma_db CHAR SET utf8;

USE partner_firma_db;

SET FOREIGN_KEY_CHECKS = 0;

CREATE TABLE mitarbeiter
(
    pnr INTEGER PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(50),
    arbeitet_in INTEGER,

    CONSTRAINT fk_mitarbeiter_abteilung
    FOREIGN KEY (arbeitet_in) REFERENCES abteilung(aid)
    ON UPDATE CASCADE
    ON DELETE SET NULL
);

CREATE TABLE abteilung
(
    aid INTEGER PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(50),
    leitet INTEGER,

    CONSTRAINT fk_abteilung_abteilungsleiter
    FOREIGN KEY (leitet) REFERENCES abteilungsleiter(pnr)
    ON UPDATE CASCADE
    ON DELETE RESTRICT
);

CREATE TABLE abteilungsleiter
(
    pnr INTEGER PRIMARY KEY,

    CONSTRAINT fk_mitarbeiter_abteilungsleiter
    FOREIGN KEY (pnr) REFERENCES mitarbeiter(pnr)
    ON UPDATE CASCADE
    ON DELETE CASCADE
);

SET FOREIGN_KEY_CHECKS = 1;

-- Theoretisch könnte man statt set foreign key check auch einfach mit alter table statements die constraints hinzufügen
-- ZYKLISCHE REFERENZ!!!!!
-- ACHTUNG -> kann zu fehler führen


-- Step 2: Add foreign keys AFTER all tables exist
-- ALTER TABLE mitarbeiter
-- ADD CONSTRAINT fk_mitarbeiter_abteilung
-- FOREIGN KEY (arbeitet_in) REFERENCES abteilung(aid)
-- ON UPDATE CASCADE
-- ON DELETE SET NULL;

-- ALTER TABLE abteilung
-- ADD CONSTRAINT fk_abteilung_leiter
-- FOREIGN KEY (leitet) REFERENCES abteilungsleiter(pnr)
-- ON UPDATE CASCADE
-- ON DELETE RESTRICT;

-- ALTER TABLE abteilungsleiter
-- ADD CONSTRAINT fk_leiter_mitarbeiter
-- FOREIGN KEY (pnr) REFERENCES mitarbeiter(pnr)
-- ON UPDATE CASCADE
-- ON DELETE CASCADE;