-- Disable foreign key checks while we build
SET @OLD_FOREIGN_KEY_CHECKS = @@FOREIGN_KEY_CHECKS;
SET FOREIGN_KEY_CHECKS = 0;

-- Create and switch to the database
CREATE DATABASE IF NOT EXISTS fifa_tournament
  CHARACTER SET utf8mb4
  COLLATE utf8mb4_unicode_ci;
USE fifa_tournament;

-- Table: Mannschaft (Teams)
CREATE TABLE Mannschaft (
  MID   INT           NOT NULL,
  Name  VARCHAR(100)  NOT NULL,
  PRIMARY KEY (MID)
) ENGINE=InnoDB;

-- Table: Spieler (Players)
CREATE TABLE Spieler (
  MID   INT           NOT NULL,
  SID   INT           NOT NULL,
  Name  VARCHAR(100)  NOT NULL,
  PRIMARY KEY (MID, SID),
  FOREIGN KEY (MID) REFERENCES Mannschaft(MID)
    ON UPDATE CASCADE
    ON DELETE RESTRICT
) ENGINE=InnoDB;

-- Table: Begegnung (Matchups)
CREATE TABLE Begegnung (
  BNR   INT            NOT NULL,
  MID1  INT            NOT NULL,
  MID2  INT            NOT NULL,
  Datum DATE           NULL,
  PRIMARY KEY (BNR),
  FOREIGN KEY (MID1) REFERENCES Mannschaft(MID)
    ON UPDATE CASCADE
    ON DELETE RESTRICT,
  FOREIGN KEY (MID2) REFERENCES Mannschaft(MID)
    ON UPDATE CASCADE
    ON DELETE RESTRICT
) ENGINE=InnoDB;

-- Table: Ereignis (Events)
CREATE TABLE Ereignis (
  ENR         INT           NOT NULL,
  BNR         INT           NOT NULL,
  MID         INT           NOT NULL,
  SID         INT           NOT NULL,
  Minute      INT           NOT NULL,
  Bezeichnung VARCHAR(50)   NOT NULL,
  PRIMARY KEY (ENR),
  FOREIGN KEY (BNR) REFERENCES Begegnung(BNR)
    ON UPDATE CASCADE
    ON DELETE CASCADE,
  FOREIGN KEY (MID, SID) REFERENCES Spieler(MID, SID)
    ON UPDATE CASCADE
    ON DELETE CASCADE
) ENGINE=InnoDB;

-- Re-enable foreign key checks
SET FOREIGN_KEY_CHECKS = 1;

-- Insert data into Mannschaft
INSERT INTO Mannschaft (MID, Name) VALUES
  (1, 'Argentinien'),
  (2, 'Frankreich'),
  (3, 'Kroatien'),
  (4, 'Marokko'),
  (5, 'Portugal');

-- Insert data into Spieler
INSERT INTO Spieler (MID, SID, Name) VALUES
  (1, 1, 'Messi'),
  (1, 2, 'Alvarez'),
  (1, 3, 'Romero'),
  (2, 1, 'Mbappe'),
  (2, 2, 'Giroud'),
  (4, 1, 'Cheddira'),
  (5, 1, 'Ronaldo');

-- Insert data into Begegnung
INSERT INTO Begegnung (BNR, MID1, MID2, Datum) VALUES
  (1, 1, 3, '2022-12-13'),
  (2, 2, 4, '2022-12-14'),
  (3, 3, 4, '2022-12-17'),
  (4, 1, 2, '2022-12-18'),
  (5, 4, 5, NULL);

-- Insert data into Ereignis
INSERT INTO Ereignis (ENR, BNR, MID, SID, Minute, Bezeichnung) VALUES
  (1, 1, 1, 1, 34, 'Tor'),
  (2, 1, 1, 2, 39, 'Tor'),
  (3, 1, 1, 2, 69, 'Tor'),
  (4, 1, 1, 3, 68, 'Gelbe Karte'),
  (5, 5, 4, 1, 90, 'Rote Karte');
