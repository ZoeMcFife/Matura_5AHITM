drop database if exists filmdb;
create database filmdb default character set=utf8 default collate utf8_general_ci;

use filmdb;
DROP TABLE IF EXISTS hatGenre;
DROP TABLE IF EXISTS Fortsetzung;
DROP TABLE IF EXISTS FremdTitel;
DROP TABLE IF EXISTS Genre;
DROP TABLE IF EXISTS spielt;
DROP TABLE IF EXISTS spricht;
DROP TABLE IF EXISTS Figur;
DROP TABLE IF EXISTS macht;
DROP TABLE IF EXISTS Taetigkeit;
DROP TABLE IF EXISTS Schauspieler;
DROP TABLE IF EXISTS Crew;
DROP TABLE IF EXISTS Person;
DROP TABLE IF EXISTS Film;


CREATE TABLE Person (
    SVNr         INTEGER PRIMARY KEY,
    Name         VARCHAR (40) NOT NULL,
    GeburtsDatum DATE NOT NULL,
    SterbeDatum  DATE)ENGINE='InnoDB';
CREATE TABLE Schauspieler (
    SVNr         INTEGER PRIMARY KEY,
    FOREIGN KEY (SVNr) REFERENCES Person(SVNr))ENGINE='InnoDB';
CREATE TABLE Crew (
    SVNr         INTEGER PRIMARY KEY,
    FOREIGN KEY (SVNr) REFERENCES Person(SVNr))ENGINE='InnoDB';
CREATE TABLE Figur (
    Name         VARCHAR (30) PRIMARY KEY)ENGINE='InnoDB';
CREATE TABLE Taetigkeit (
    Job          VARCHAR (20) PRIMARY KEY)ENGINE='InnoDB';
CREATE TABLE Film (
    Titel        VARCHAR (50),
    Jahr         INTEGER,
    DrehBeginn   DATE,
    DrehEnde     DATE,
    Dauer        INTEGER,
    Land         VARCHAR (15),
    PRIMARY KEY (Titel, Jahr))ENGINE='InnoDB';
CREATE TABLE Fortsetzung (
    Titel        VARCHAR (50),
    Jahr         INTEGER,
    VonTitel VARCHAR (50),
    VonJahr  INTEGER,
    PRIMARY KEY (Titel, Jahr),
    FOREIGN KEY (Titel, Jahr) REFERENCES Film(Titel,Jahr),
    FOREIGN KEY (VonTitel, VonJahr) REFERENCES Film (Titel, Jahr))ENGINE='InnoDB';
CREATE TABLE FremdTitel (
    Titel        VARCHAR (50),
    Jahr         INTEGER,
    Sprache      VARCHAR (15),
    OrigTitel    VARCHAR (50),
    OrigJahr     INTEGER,
    PRIMARY KEY (OrigTitel, OrigJahr, Sprache),
    FOREIGN KEY (OrigTitel, OrigJahr) REFERENCES Film (Titel, Jahr))ENGINE='InnoDB';
CREATE TABLE Genre (
    Genre        VARCHAR (10) PRIMARY KEY)ENGINE='InnoDB';
CREATE TABLE hatGenre (
    Titel        VARCHAR (50),
    Jahr         INTEGER,
    Genre        VARCHAR (10),
    PRIMARY KEY (Titel, Jahr, Genre),
    FOREIGN KEY (Titel, Jahr) REFERENCES Film(Titel,Jahr),
    FOREIGN KEY (Genre) REFERENCES Genre(Genre))ENGINE='InnoDB';
CREATE TABLE spielt (
    SVNr         INTEGER,
    Titel        VARCHAR (50),
    Jahr         INTEGER,
    Name         VARCHAR (30),
    PRIMARY KEY (SVNr, Titel, Jahr, Name),
    FOREIGN KEY (SVNr) REFERENCES Schauspieler(SVNr),
    FOREIGN KEY (Titel, Jahr) REFERENCES Film(Titel,Jahr),
    FOREIGN KEY (Name) REFERENCES Figur(Name))ENGINE='InnoDB';
CREATE TABLE spricht (
    SVNr         INTEGER,
    Titel        VARCHAR (50),
    Jahr         INTEGER,
    Name         VARCHAR (30),
    PRIMARY KEY (SVNr, Titel, Jahr, Name),
    FOREIGN KEY (SVNr) REFERENCES Schauspieler(SVNR),
    FOREIGN KEY (Titel, Jahr) REFERENCES Film(Titel,Jahr),
    FOREIGN KEY (Name) REFERENCES Figur(Name))ENGINE='InnoDB';
CREATE TABLE macht (
    SVNr         INTEGER,
    Titel        VARCHAR (50),
    Jahr         INTEGER,
    Job          VARCHAR (30),
    PRIMARY KEY (SVNr, Titel, Jahr, Job),
    FOREIGN KEY (SVNr) REFERENCES Crew(SVNr),
    FOREIGN KEY (Titel, Jahr) REFERENCES Film(Titel,Jahr),
    FOREIGN KEY (Job) REFERENCES Taetigkeit(Job))ENGINE='InnoDB';
    
INSERT INTO Person VALUES
(1000, 'Desmond Llewelyn', '1914-09-12', '1999-12-19');
INSERT INTO Person VALUES
(1011, 'Samantha Bond', '1962-11-27', NULL);
INSERT INTO Person VALUES
(1012, 'Caroline Bliss', '1961-01-01', NULL);
INSERT INTO Person VALUES
(1013, 'Lois Maxwell', '1927-02-14', NULL);
INSERT INTO Person VALUES
(1021, 'Sean Connery', '1930-08-25', NULL);
INSERT INTO Person VALUES
(1022, 'Roger Moore', '1927-10-14', NULL);
INSERT INTO Person VALUES
(1033, 'U.N. Known', '1900-01-01', '1999-12-31');
INSERT INTO Person VALUES
(1066, 'D. Ed Wood', '1920-02-02', '2004-04-03');
INSERT INTO Person VALUES
(3333, 'Woody Allen', '1935-12-01', NULL);
INSERT INTO Person VALUES
(4444, 'Robert Huber', '1969-07-20', NULL);
INSERT INTO Person VALUES
(5001, 'Jeanine-Caroline Watzlawic', '1990-11-11', NULL);
INSERT INTO Person VALUES
(5002, 'Renee-Dominik Watzlawic', '1990-11-11', NULL);




INSERT INTO Schauspieler VALUES
(1000);
INSERT INTO Schauspieler VALUES
(1011);
INSERT INTO Schauspieler VALUES
(1012);
INSERT INTO Schauspieler VALUES
(1013);
INSERT INTO Schauspieler VALUES
(1021);
INSERT INTO Schauspieler VALUES
(1022);
INSERT INTO Schauspieler VALUES
(1033);
INSERT INTO Schauspieler VALUES
(3333);
INSERT INTO Schauspieler VALUES
(4444);
INSERT INTO Schauspieler VALUES
(5001);

INSERT INTO Crew VALUES
(1033);
INSERT INTO Crew VALUES
(1066);
INSERT INTO Crew VALUES
(3333);
INSERT INTO Crew VALUES
(4444);
INSERT INTO Crew VALUES
(5002);

INSERT INTO Taetigkeit VALUES
('Regie');
INSERT INTO Taetigkeit VALUES
('Kamera');
INSERT INTO Taetigkeit VALUES
('Drehbuch');


INSERT INTO Genre VALUES
('Horror');
INSERT INTO Genre VALUES
('Spionage');
INSERT INTO Genre VALUES
('Action');
INSERT INTO Genre VALUES
('Komödie');
INSERT INTO Genre VALUES
('Animation');


INSERT INTO Film VALUES 
('James Bond Saves the World', 2000, '1999-12-03', '2000-03-17', 97, 'USA');
INSERT INTO hatGenre VALUES
('James Bond Saves the World', 2000,'Spionage');
INSERT INTO hatGenre VALUES
('James Bond Saves the World', 2000,'Action');
INSERT INTO Film VALUES 
('James Bond and the Man on the Moon', 2003, '2002-03-05', '2002-06-07', 93, 'USA');
INSERT INTO hatGenre VALUES
('James Bond and the Man on the Moon', 2003,'Spionage');
INSERT INTO hatGenre VALUES
('James Bond and the Man on the Moon', 2003,'Action');
INSERT INTO hatGenre VALUES
('James Bond and the Man on the Moon', 2003,'Komödie');
INSERT INTO Film VALUES 
('James Bond Saves the World, Again', 2004, '2003-11-07', '2004-05-05', 95, 'USA');
INSERT INTO hatGenre VALUES
('James Bond Saves the World, Again', 2004,'Action');
INSERT INTO hatGenre VALUES
('James Bond Saves the World, Again', 2004,'Komödie');
INSERT INTO Film VALUES 
('Nothing but Neursois', 2003, '2002-01-01', '2002-12-31', 99, 'NY, NY');
INSERT INTO hatGenre VALUES
('Nothing but Neursois', 2003,'Komödie');
INSERT INTO Film VALUES 
('Die Abenteuer von Bertl', 2001, '2001-07-03', '2001-07-23', 57, 'Österreich');
INSERT INTO hatGenre VALUES
('Die Abenteuer von Bertl', 2001,'Komödie');
INSERT INTO Film VALUES 
('Bertl - eine Kindheit in Floridsdorf', 2002, '2002-07-07', '2002-07-27', 73, 'Österreich');
INSERT INTO hatGenre VALUES
('Bertl - eine Kindheit in Floridsdorf', 2002,'Komödie');
INSERT INTO Film VALUES 
('Bertl zwischen Meidling und Simmering', 2003, '2003-07-01', '2003-07-21', 111, 'Österreich');
INSERT INTO hatGenre VALUES
('Bertl zwischen Meidling und Simmering', 2003,'Komödie');
INSERT INTO hatGenre VALUES
('Bertl zwischen Meidling und Simmering', 2003,'Action');
INSERT INTO Film VALUES 
('My Youth', 2005, '2004-01-01', '2004-12-31', 13, 'Japan');
INSERT INTO hatGenre VALUES
('My Youth', 2005,'Komödie');
INSERT INTO hatGenre VALUES
('My Youth', 2005,'Animation');
INSERT INTO Film VALUES 
('Die Abenteuer von Bertl', 1951, '1950-07-03', '1950-11-23', 88, 'Deutschland');
INSERT INTO hatGenre VALUES
('Die Abenteuer von Bertl', 1951,'Komödie');
INSERT INTO Film VALUES 
('Ein Zombie in Favoriten', 1977, '1977-01-06', '1977-02-01', 17, 'Österreich');
INSERT INTO hatGenre VALUES
('Ein Zombie in Favoriten', 1977, 'Horror');


INSERT INTO FremdTitel VALUES
('James Bond zeigt es allen', 2002, 'Deutsch','James Bond Saves the World', 2000);
INSERT INTO FremdTitel VALUES
('James Bond auf dem Materhorn', 2004, 'Deutsch','James Bond and the Man on the Moon', 2003);
INSERT INTO FremdTitel VALUES
('James Bond - jetzt wird noch mehr geknallt', 2004, 'Deutsch','James Bond Saves the World, Again', 2004);
INSERT INTO FremdTitel VALUES
('James Bond I', 2005, 'Italiano','James Bond Saves the World', 2000);
INSERT INTO FremdTitel VALUES
('James Bond II', 2005, 'Italiano','James Bond Saves the World, Again', 2004);
INSERT INTO FremdTitel VALUES
('Jean Lien - Le Beau', 2002, 'Francais','James Bond Saves the World', 2000);
INSERT INTO FremdTitel VALUES
('Jean Lien - Le Grand', 2004, 'Francais','James Bond and the Man on the Moon', 2003);
INSERT INTO FremdTitel VALUES
('Jean Lien - Le Fort', 2004, 'Francais','James Bond Saves the World, Again', 2004);


INSERT INTO Fortsetzung VALUES
('Die Abenteuer von Bertl', 2001, 'Bertl - eine Kindheit in Floridsdorf', 2002);
INSERT INTO Fortsetzung VALUES
('Bertl zwischen Meidling und Simmering', 2003, 'Die Abenteuer von Bertl', 2001);
INSERT INTO Fortsetzung VALUES
('James Bond and the Man on the Moon', 2003, 'James Bond Saves the World', 2000);
INSERT INTO Fortsetzung VALUES
('James Bond Saves the World, Again', 2004, 'James Bond and the Man on the Moon', 2003);




INSERT INTO Figur VALUES
('James Bond');
INSERT INTO Figur VALUES
('Q');
INSERT INTO Figur VALUES
('Miss Moneypenny');
INSERT INTO Figur Values
('N.E.Urose');
INSERT INTO Figur VALUES
('Woody Allen');
INSERT INTO Figur VALUES
('The Thick Man');
INSERT INTO Figur VALUES
('The Thin Man');
INSERT INTO Figur VALUES
('The Invisible Man');
INSERT INTO Figur VALUES
('Narrator');
INSERT INTO Figur VALUES
('Bertl');
INSERT INTO Figur VALUES
('Man at the Loony Bin');


INSERT INTO spielt VALUES
(1021, 'James Bond Saves the World', 2000, 'James Bond');
INSERT INTO spielt VALUES
(1000, 'James Bond Saves the World', 2000, 'Q');
INSERT INTO spielt VALUES
(1011, 'James Bond Saves the World', 2000, 'Miss Moneypenny');
INSERT INTO spielt VALUES
(1021, 'James Bond and the Man on the Moon', 2003, 'James Bond');
INSERT INTO spielt VALUES
(1000, 'James Bond and the Man on the Moon', 2003, 'Q');
INSERT INTO spielt VALUES
(1012, 'James Bond and the Man on the Moon', 2003, 'Miss Moneypenny');
INSERT INTO spielt VALUES
(1022, 'James Bond Saves the World, Again', 2004, 'James Bond');
INSERT INTO spielt VALUES
(1033, 'James Bond and the Man on the Moon', 2003, 'The Thick Man');
INSERT INTO spielt VALUES
(1033, 'James Bond and the Man on the Moon', 2003, 'The Thin Man');
INSERT INTO spielt VALUES
(1033, 'James Bond and the Man on the Moon', 2003, 'The Invisible Man');
INSERT INTO spielt VALUES
(3333, 'James Bond and the Man on the Moon', 2003, 'Man at the Loony Bin');
INSERT INTO spielt VALUES
(1000, 'James Bond Saves the World, Again', 2004, 'Q');
INSERT INTO spielt VALUES
(1013, 'James Bond Saves the World, Again', 2004, 'Miss Moneypenny');
INSERT INTO spielt VALUES
(3333, 'Nothing but Neursois', 2003, 'N.E.Urose');
INSERT INTO spielt VALUES
(4444, 'Bertl - eine Kindheit in Floridsdorf', 2002, 'Bertl');
INSERT INTO spielt VALUES
(4444, 'Die Abenteuer von Bertl', 2001, 'Bertl');
INSERT INTO spielt VALUES
(4444, 'Bertl zwischen Meidling und Simmering', 2003, 'Bertl');
INSERT INTO spielt VALUES
(1000, 'Die Abenteuer von Bertl', 1951, 'Bertl');


INSERT INTO spricht VALUES
(1000, 'My Youth', 2005, 'Narrator');
INSERT INTO spricht VALUES
(1000, 'Ein Zombie in Favoriten', 1977, 'Narrator');
INSERT INTO spricht VALUES
(3333, 'My Youth', 2005, 'Woody Allen');


INSERT INTO macht VALUES
(4444, 'Die Abenteuer von Bertl', 2001, 'Regie');
INSERT INTO macht VALUES
(4444, 'Bertl - eine Kindheit in Floridsdorf', 2002, 'Regie');
INSERT INTO macht VALUES
(4444, 'Bertl - eine Kindheit in Floridsdorf', 2002, 'Drehbuch');
INSERT INTO macht VALUES
(4444, 'Bertl zwischen Meidling und Simmering', 2003, 'Regie');
INSERT INTO macht VALUES
(3333, 'Nothing but Neursois', 2003, 'Regie');
INSERT INTO macht VALUES
(3333, 'Nothing but Neursois', 2003, 'Drehbuch');
INSERT INTO macht VALUES
(3333, 'Nothing but Neursois', 2003, 'Kamera');
INSERT INTO macht VALUES
(1066, 'Nothing but Neursois', 2003, 'Regie');
INSERT INTO macht VALUES
(3333, 'My Youth', 2005, 'Regie');
INSERT INTO macht VALUES
(3333, 'My Youth', 2005, 'Drehbuch');


