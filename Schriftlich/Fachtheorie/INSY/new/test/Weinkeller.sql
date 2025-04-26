-- 1) Create the database and switch to it
CREATE DATABASE IF NOT EXISTS weinkeller
  CHARACTER SET utf8mb4
  COLLATE utf8mb4_general_ci;
USE weinkeller;

-- 2) Winzer (winemakers) table
CREATE TABLE winzer (
  wnr       INT             NOT NULL PRIMARY KEY,
  name      VARCHAR(100)    NOT NULL,
  strasse   VARCHAR(100),
  plz       VARCHAR(10),
  ort       VARCHAR(50),
  telefon   VARCHAR(20)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- 3) Keller (cellar-location) table
CREATE TABLE keller (
  knr       INT             NOT NULL PRIMARY KEY,
  reihe     TINYINT  UNSIGNED NOT NULL,
  regal     TINYINT  UNSIGNED NOT NULL,
  fach      TINYINT  UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- 4) Wein (bottles) table
CREATE TABLE wein (
  nr           INT           NOT NULL PRIMARY KEY,
  bezzeichnung VARCHAR(100)  NOT NULL,
  sorte        VARCHAR(50)   NOT NULL,
  jahrgang     YEAR          NOT NULL,
  preis        DECIMAL(6,2)  NOT NULL,
  anzahl       INT           NOT NULL,
  wnr          INT           NOT NULL,
  position     INT           NOT NULL,
  FOREIGN KEY (wnr)       REFERENCES winzer(wnr)
    ON UPDATE CASCADE
    ON DELETE RESTRICT,
  FOREIGN KEY (position)  REFERENCES keller(knr)
    ON UPDATE CASCADE
    ON DELETE RESTRICT
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- 5) Protokoll (removals/log) table
CREATE TABLE protokoll (
  pnr         INT           NOT NULL PRIMARY KEY,
  nr          INT           NOT NULL,
  pDatum      DATE          NOT NULL,
  verwendung  VARCHAR(100)  NOT NULL,
  anzahl      INT           NOT NULL,
  FOREIGN KEY (nr) REFERENCES wein(nr)
    ON UPDATE CASCADE
    ON DELETE RESTRICT
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- ------------------------------------------------------------------------------
-- 6) Insert data into winzer
INSERT INTO winzer (wnr, name, strasse, plz, ort, telefon) VALUES
(1, 'Lackner Tinnacher',           'Steinbach 8',          '4567', 'Gamlitz',         '1234567'),
(2, 'Weingut Prager',              'Weissenkirchen 48',    '3610', 'Weissenkirchen',  '1234567'),
(3, 'Weingut Emmerich Knoll',      'Unterloiben 10',       '3601', 'Unterloiben',      '1234456'),
(4, 'Weingut F.X. Pichler',        'Unterloiben 27',       '3601', 'Unterloiben',      '11122233'),
(5, 'Weingut Spatlese',            'Weintalstrasse 23',    '1136', 'Wien',             NULL),
(6, 'Freie Weingarten Wachau',     'Kremstalstrasse 23',   '3600', 'Krems',            '2304002'),
(7, 'Stiftskellerei',              NULL,                   NULL,    NULL,               NULL),
(8, 'Weingut Biegler',             'Wienerstrasse 88',     '2352', 'Gumpoldskirchen',  '54564565');

-- 7) Insert data into keller
INSERT INTO keller (knr, reihe, regal, fach) VALUES
(1, 1, 1, 1),
(2, 1, 1, 2),
(3, 1, 1, 3),
(4, 1, 2, 1),
(5, 1, 2, 2),
(6, 2, 1, 1),
(7, 2, 1, 2),
(8, 2, 2, 1);

-- 8) Insert data into wein
INSERT INTO wein (nr, bezzeichnung,            sorte,            jahrgang, preis,  anzahl, wnr, position) VALUES
(1, 'Riesling Kellerberg',       'Riesling',       1999,      28.00, 24,     4,   1),
(2, 'Loibenberg',                'Gr. Veltliner',  2000,      19.00, 36,     4,   2),
(3, 'Ried Kreutles',             'Gr. Veltliner',  2000,      19.00, 15,     3,   4),
(4, 'Riesling Smaragd',          'Riesling',       2000,      21.00, 30,     2,   5),
(5, 'Grauburgunder',             'Grauburgunder',  2003,      16.00, 72,     1,   6),
(6, 'Morillon',                  'Chardonnay',     2003,       9.00, 55,     1,   7),
(7, 'Riesling Federspiel',       'Riesling',       2003,       9.90, 80,     6,   3),
(8, 'Chardonnay',                'Chardonnay',     2003,       9.00, 16,     8,   8);

-- 9) Insert data into protokoll
INSERT INTO protokoll (pnr, nr, pDatum,        verwendung,                       anzahl) VALUES
(1, 1, '2003-01-12', 'Geschenk an Herrn Berger',      12),
(2, 3, '2003-07-10', 'Eigenbedarf',                   2),
(3, 1, '2003-07-23', 'Eigenbedarf',                   4),
(4, 6, '2003-08-14', 'Geschenk (Frau Kunz)',          6),
(5, 1, '2003-08-27', 'Glasbruch',                     1),
(6, 4, '2003-11-03', 'Korkgeruch',                    1),
(7, 6, '2003-11-03', 'Eigenbedarf',                   3);

-- All hands secure—database is ready, Captain! 🏴‍☠️
