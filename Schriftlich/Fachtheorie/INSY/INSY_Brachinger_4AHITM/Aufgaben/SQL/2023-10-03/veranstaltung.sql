drop database veranstaltung;

create database veranstaltung default char set=utf8;

USE veranstaltung;

CREATE TABLE vereinsmitglieder
(
    mitgliedsnummer INT PRIMARY KEY,
    vorname VARCHAR(30),
    nachname VARCHAR(30),
    adresse VARCHAR(100),
    geburtsdatum DATE,
    eintrittsdatum DATE
);

CREATE TABLE veranstaltungen
(
    bezeichnung VARCHAR(100) PRIMARY KEY,
    datum DATE,
    beginn TIME,
    ende TIME,
    ort VARCHAR(100),
    leiter INT,

    CONSTRAINT fk_vereinsmitglieder_veranstaltungen FOREIGN KEY (leiter) references vereinsmitglieder (mitgliedsnummer)
);

CREATE TABLE serien
(
    bezeichnung VARCHAR(100) PRIMARY KEY
);

CREATE TABLE veranstaltung_gehört_zu_serie
(
    bezeichnung_veranstaltung VARCHAR(100),
    bezeichnung_serie VARCHAR(100),

    CONSTRAINT fk_veranstaltungen_veranstaltung_gehört_zu_serie FOREIGN KEY (bezeichnung_veranstaltung) REFERENCES veranstaltungen (bezeichnung),
    CONSTRAINT fk_serien_veranstaltung_gehört_zu_serie FOREIGN KEY (bezeichnung_veranstaltung) REFERENCES serien (bezeichnung)
);

CREATE TABLE musikstücke
(
    mnr INT PRIMARY KEY,
    titel VARCHAR(50),
    komponist VARCHAR(50),
    texter VARCHAR(50),
    arrangeur VARCHAR(50)
);

CREATE TABLE veranstaltung_führt_auf_musikstück
(
    bezeichnung VARCHAR(100),
    mnr INT,

    CONSTRAINT fk_veranstaltungen_veranstaltung_führt_auf_musikstück FOREIGN KEY (bezeichnung) REFERENCES veranstaltungen (bezeichnung),
    CONSTRAINT fk_musikstücke_veranstaltung_führt_auf_musikstück FOREIGN KEY (mnr) REFERENCES musikstücke (mnr)
);

CREATE TABLE notenhefte
(
    isbn VARCHAR(30) PRIMARY KEY,
    verlag VARCHAR(30)
);

CREATE TABLE musikstück_in_notenheft
(
    mnr INT,
    isbn VARCHAR(30),

    CONSTRAINT fk_musikstücke_musikstück_in_notenheft FOREIGN KEY (mnr) REFERENCES musikstücke (mnr),
    CONSTRAINT fk_notenhefte_musikstück_in_notenheft FOREIGN KEY (isbn) REFERENCES notenhefte (isbn)
);

CREATE TABLE exemplare
(
    inventarnummer INT PRIMARY KEY,
    isbn VARCHAR(30),

    CONSTRAINT fk_exemplare_notenhefte FOREIGN KEY (isbn) REFERENCES notenhefte (isbn)
);

CREATE TABLE vereinsmitglieder_nehmen_teil_veranstaltung
(
    mitgliedsnummer INT,
    bezeichnung VARCHAR(100),

    CONSTRAINT fk_vereinsmitglieder_vereinsmitglieder_nehmen_teil_veranstaltung FOREIGN KEY (mitgliedsnummer) REFERENCES vereinsmitglieder (mitgliedsnummer),
    CONSTRAINT fk_veranstaltungen_vereinsmitglieder_nehmen_teil_veranstaltung FOREIGN KEY (bezeichnung) REFERENCES veranstaltungen (bezeichnung)
);

CREATE TABLE auszeichnungen
(
    bezeichnung VARCHAR(100) PRIMARY KEY,
    beschreibung VARCHAR(200)
);

CREATE TABLE vereinsmitglieder_erhalten_auszeichnungen
(
    mitgliedsnummer INT,
    bezeichnung VARCHAR(100),

    CONSTRAINT fk_vereinsmitglieder_vereinsmitglieder_erhalten_auszeichnungen FOREIGN KEY (mitgliedsnummer) REFERENCES vereinsmitglieder (mitgliedsnummer),
    CONSTRAINT fk_auszeichnungen_vereinsmitglieder_erhalten_auszeichnungen FOREIGN KEY (bezeichnung) REFERENCES auszeichnungen (bezeichnung)
);

CREATE TABLE veranstaltung_exemplar_vereinsmitglied
(
    mitgliedsnummer INT,
    inventarnummer INT,
    bezeichnung VARCHAR(100),

    CONSTRAINT fk_vereinsmitglieder_veranstaltung_exemplar_vereinsmitglied FOREIGN KEY (mitgliedsnummer) REFERENCES vereinsmitglieder (mitgliedsnummer),
    CONSTRAINT fk_veranstaltungen_veranstaltung_exemplar_vereinsmitglied FOREIGN KEY (bezeichnung) REFERENCES veranstaltungen (bezeichnung),
    CONSTRAINT fk_exemplare_veranstaltung_exemplar_vereinsmitglied FOREIGN KEY (inventarnummer) REFERENCES exemplare (inventarnummer)
);

CREATE TABLE funktionen
(
    bezeichnung VARCHAR(100) PRIMARY KEY
);

CREATE TABLE funktionsperioden
(
    mitgliedsnummer INT,
    beginn DATETIME,
    ende DATETIME,
    bezeichnung VARCHAR(100),
    PRIMARY KEY (mitgliedsnummer, beginn),

    CONSTRAINT fk_vereinsmitglieder_funktionsperioden FOREIGN KEY (mitgliedsnummer) REFERENCES vereinsmitglieder (mitgliedsnummer),
    CONSTRAINT fk_funktionen_funktionsperioden FOREIGN KEY (bezeichnung) REFERENCES funktionen (bezeichnung)
);

CREATE TABLE fotos
(
    mitgliedsnummer INT PRIMARY KEY,
    foto BLOB,

    CONSTRAINT fk_vereinsmitglieder_fotos FOREIGN KEY (mitgliedsnummer) REFERENCES vereinsmitglieder (mitgliedsnummer)
);

CREATE TABLE austritte
(
    mitgliedsnummer INT PRIMARY KEY,
    austrittsdatum datetime,

    CONSTRAINT fk_vereinsmitglieder_austritte FOREIGN KEY (mitgliedsnummer) REFERENCES vereinsmitglieder (mitgliedsnummer)
);

CREATE TABLE chorleiter
(
    mitgliedsnummer INT PRIMARY KEY,
    ausbildung VARCHAR(30),
    erfahrung VARCHAR(30),

    CONSTRAINT fk_vereinsmitglieder_chorleiter FOREIGN KEY (mitgliedsnummer) REFERENCES vereinsmitglieder (mitgliedsnummer)
);

CREATE TABLE sänger
(
    mitgliedsnummer INT PRIMARY KEY,
    stimmlage VARCHAR(30),

    CONSTRAINT fk_vereinsmitglieder_sänger FOREIGN KEY (mitgliedsnummer) REFERENCES vereinsmitglieder (mitgliedsnummer)
);

CREATE TABLE musiker
(
    mitgliedsnummer INT PRIMARY KEY,

    CONSTRAINT fk_vereinsmitglieder_musiker FOREIGN KEY (mitgliedsnummer) REFERENCES vereinsmitglieder (mitgliedsnummer)
);

CREATE TABLE instrumente
(
    bezeichnung VARCHAR(100) PRIMARY KEY
);

CREATE TABLE musiker_spielt_instrument
(
    mitgliedsnummer INT,
    bezeichung VARCHAR(100),

    CONSTRAINT fk_musiker_musiker_spielt_instrument FOREIGN KEY (mitgliedsnummer) REFERENCES musiker (mitgliedsnummer),
    CONSTRAINT fk_instrument_musiker_spielt_instrument FOREIGN KEY (bezeichung) REFERENCES instrumente (bezeichnung)
);