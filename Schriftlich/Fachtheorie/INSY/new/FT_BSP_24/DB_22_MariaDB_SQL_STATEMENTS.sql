DROP DATABASE IF EXISTS kaufen;

CREATE DATABASE kaufen CHAR SET UTF8;

USE kaufen;

CREATE TABLE Kunden
(
    KndNr INTEGER PRIMARY KEY AUTO_INCREMENT,
    Nachname VARCHAR(32),
    Vorname VARCHAR(32),
    Strasse VARCHAR(100),
    PLZ VARCHAR(32),
    Ort VARCHAR(100)
);

CREATE TABLE Kreditkarten
(
    KartenNr INTEGER PRIMARY KEY AUTO_INCREMENT,
    Firma VARCHAR(32),
    KndNr INTEGER,
    Ablaufdatum DATE,

    CONSTRAINT fk_Kunden_Kreditkarten
    FOREIGN KEY (KndNr)
    REFERENCES Kunden(KndNr)
    ON UPDATE CASCADE
    ON DELETE CASCADE
);

CREATE TABLE Bestellungen
(
    BestellungsNr INTEGER PRIMARY KEY AUTO_INCREMENT,
    KndNr INTEGER,
    Datum DATE,

    CONSTRAINT fk_Kunden_Bestellungen
    FOREIGN KEY (KndNr)
    REFERENCES Kunden(KndNr)
    ON UPDATE CASCADE
    ON DELETE RESTRICT
);

CREATE TABLE Positionen
(
    PositionNr INTEGER AUTO_INCREMENT,
    BestellungsNr INTEGER,
    Artikel VARCHAR(32),
    Anzahl INTEGER,
    Preis DECIMAL(10,2),

    PRIMARY KEY (PositionNr, BestellungsNr),
    CONSTRAINT fk_bestellung_position
    FOREIGN KEY (BestellungsNr)
    REFERENCES Bestellungen(BestellungsNr)
    ON UPDATE CASCADE
    ON DELETE RESTRICT
);


/* Test Daten */

-- 1) Bestehende Cyberpunk-2077–Kunden
INSERT INTO Kunden (Nachname, Vorname, Strasse, PLZ, Ort) VALUES
  ('Street',     'V',     'Watson, Kabuki St. 13',           '20183', 'Night City'),
  ('Silverhand', 'Johnny','Heywood, Vista Del Rey 210',      '20204', 'Night City'),
  ('Alvarez',    'Judy',   'Pacifica, Coastview Ave. 42',     '20345', 'Night City'),
  ('Rodriguez',  'Panam',  'Santo Domingo, Silvermoon Blvd. 7','20456','Night City');

-- 2) Neuer Kunde OHNE Kreditkarte (zum Testen von c))
INSERT INTO Kunden (Nachname, Vorname, Strasse, PLZ, Ort) VALUES
  ('Maelstrom', 'Rogue', 'Watson, Kabuki St. 42', '20183', 'Night City');

-- 3) Cyberpunk-2077–Kreditkarten (inkl. abgelaufener Karten für e))
INSERT INTO Kreditkarten (Firma, KndNr, Ablaufdatum) VALUES
  ('Arasaka Corp',       1, '2077-12-31'),
  ('Trauma Team Intl',   1, '2078-11-11'),
  ('Militech',           2, '2078-06-30'),
  ('Kang Tao',           3, '2077-09-15'),
  ('Trauma Team Intl',   4, '2079-01-01'),
  ('Kiroshi Corp',       2, '2021-05-20'),  -- abgelaufen vor 2024
  ('Militech R&D',       3, '2023-12-31');  -- abgelaufen vor 2024

-- 4) Cyberpunk-2077–Bestellungen (2077)
INSERT INTO Bestellungen (KndNr, Datum) VALUES
  (1, '2077-09-17'),
  (1, '2077-10-05'),
  (2, '2077-09-18'),
  (3, '2077-09-20'),
  (4, '2077-09-22');

-- 5) Neue Bestellungen für KndNr=5 (Rogue) – eine in 2024, eine anderswo
INSERT INTO Bestellungen (KndNr, Datum) VALUES
  (5, '2024-06-01'),  -- zählt in der View Anzahl2024
  (5, '2023-12-15');

-- 6) Positionen – die alten Cyberpunk-Waren …
INSERT INTO Positionen (BestellungsNr, Artikel, Anzahl, Preis) VALUES
  (1, 'Braindance Module',      1, 2999.99),
  (1, 'Neuro-Interface Cable',  2,  199.50),
  (2, 'Monowire Whip',          1, 4999.00),
  (3, 'Relic Neural Implant',   1, 9999.99),
  (3, 'Sandevistan OS',         1, 7999.99),
  (4, 'Poly-lam Skin Patch',    3,  249.25),
  (5, 'Aldecaldos Camp Kit',    1, 1250.00),
  (5, 'Combat Med-kit',         2,  350.00),

-- … plus die neuen Positionen für Rogue (KndNr=5):
  (6, 'Cyber DVD-R Pack',     5,   4.99),   -- enthält “DVD” → testet a)
  (7, 'Smart Gun Holster',     1, 199.99);   -- eine zweite Bestellung für b)


-- —— 1) Zusätzliche Kunden ——
INSERT INTO Kunden (Nachname, Vorname, Strasse, PLZ, Ort) VALUES
  ('Eurodyne',  'Kerry',    'Westbrook, Cantina Row 9',     '20512', 'Night City'),
  ('Sato',      'Hiroshi',  'Japantown, Sakura St. 88',      '20513', 'Night City'),
  ('Takemura',  'Goro',     'Westbrook, Night Market 3',     '20514', 'Night City'),
  ('Lockwood',  'Adam',     'Heywood, Comfort Gardens 16',   '20515', 'Night City'),
  ('Carver',    'Del',      'Pacifica, Tide Plaza 2',        '20516', 'Night City');

-- —— 2) Zusätzliche Kreditkarten ——
INSERT INTO Kreditkarten (Firma, KndNr, Ablaufdatum) VALUES
  ('Arasaka Security',   6, '2026-04-30'),  -- Kerry
  ('Kiroshi Optics',     7, '2022-08-15'),  -- Hiroshi (abgelaufen)
  ('Trauma Team Intl',   8, '2024-01-01'),  -- Goro (Grenzfall)
  ('Biotechnica',        9, '2025-03-31'),  -- Adam
  ('Militech R&D',      10, '2023-11-30');  -- Del (abgelaufen)

-- —— 3) Zusätzliche Bestellungen ——
INSERT INTO Bestellungen (KndNr, Datum) VALUES
  (6, '2024-07-15'),  -- Kerry
  (7, '2023-11-11'),  -- Hiroshi
  (6, '2024-01-01'),  -- Kerry (Grenzdatum)
  (8, '2024-12-31'),  -- Goro
  (2, '2024-05-20'),  -- Johnny
  (9, '2024-03-05');  -- Adam

-- —— 4) Zusätzliche Positionen ——
INSERT INTO Positionen (BestellungsNr, Artikel, Anzahl, Preis) VALUES
  -- Für Kerry (Bestellung 8)
  (8,  'Night City DVD Collector''s Edition', 1,  49.99),
  (8,  'Cyberdeck MK5',                       1,2799.00),

  -- Für Hiroshi (Bestellung 9)
  (9,  'Synthetic Steak Pack',                3,   25.00),
  (9,  'Retro DVD Media Drive',               1,  129.99),
  (9,  'XBD',                                 5,   1200.29),

  -- Für Kerry (Bestellung 10)
  (10, 'BluExtravaganza DVD Pack',            2,    9.99),

  -- Für Goro (Bestellung 11)
  (11, 'Collector''s DVD Trilogy Box',        1,  149.99),
  (11, 'High-End HUD Visor',                  1,  499.99),

  -- Für Johnny (Bestellung 12)
  (12, 'Digital Frost Grenade',               2,  599.00),
  (12, 'DVD-Formatted Crypto Module',         2,  399.99),

  -- Für Adam (Bestellung 13)
  (13, 'Night City Atlas (Book)',             1,   59.95),
  (13, 'Cyber DVD-ROM Toolkit',               1,   19.99);
