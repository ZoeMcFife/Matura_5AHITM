drop database if exists weinkellerei;
create database weinkellerei default character set=utf8;
use weinkellerei;

CREATE TABLE winzer (
wnr INTEGER NOT NULL,
name VARCHAR(25),
strasse VARCHAR(20),
plz INTEGER,
ort VARCHAR(15),
telefon VARCHAR(12),
CONSTRAINT pk_winzer PRIMARY KEY (wnr)
);

CREATE TABLE keller (
knr INTEGER NOT NULL,
reihe INTEGER,
regal INTEGER,
fach INTEGER,
CONSTRAINT pk_keller PRIMARY KEY (knr)
);

CREATE TABLE wein (
nr INTEGER NOT NULL,
bezeichnung VARCHAR(20),
sorte VARCHAR(15),
jahrgang INTEGER,
preis DECIMAL(5,2),
anzahl INTEGER,
wnr INTEGER,
position INTEGER,
CONSTRAINT pk_wein PRIMARY KEY (nr),
CONSTRAINT fk_wein_winzer FOREIGN KEY (wnr) REFERENCES winzer (wnr),
CONSTRAINT fk_wein_keller FOREIGN KEY (position) REFERENCES keller (knr)
);

CREATE TABLE protokoll (
pnr INTEGER NOT NULL,
nr INTEGER,
pDatum DATE,
verwendung VARCHAR(30),
anzahl INTEGER,
CONSTRAINT pk_protokoll PRIMARY KEY (pnr),
CONSTRAINT fk_protokoll_wein FOREIGN KEY (nr) REFERENCES wein (nr)
);

INSERT INTO winzer VALUES (1, 'Lackner Tinnacher', 'Steinbach 8', 4567, 'Gamlitz', '1234567');
INSERT INTO winzer VALUES (2, 'Weingut Prager', 'Weissenkirchen 48', 3610, 'Weissenkirchen', '1234567');
INSERT INTO winzer VALUES (3, 'Weingut Emmerich Knoll', 'Unterloiben 10', 3601, 'Unterloiben', '1234456');
INSERT INTO winzer VALUES (4, 'Weingut F.X.Pichler', 'Unterloiben 27', 3601, 'Unterloiben', '11122233');
INSERT INTO winzer VALUES (5, 'Weingut Spätlese', 'Weintalstrasse 23', 1136, 'Wien', null);
INSERT INTO winzer VALUES (6, 'Freie Weingärten Wachau', 'Kremstalstrasse 23', 3600, 'Krems', '2304002');
INSERT INTO winzer VALUES (7, 'Stiftskellerei', null, null, null, null);
INSERT INTO winzer VALUES (8, 'Weingut Biegler', 'Wienerstrasse 88', 2352, 'Gumpoldskirchen', '54564565');


INSERT INTO keller (knr,reihe,regal,fach) VALUES (1, 1, 1, 1);
INSERT INTO keller (knr,reihe,regal,fach) VALUES (2, 1, 1, 2);
INSERT INTO keller (knr,reihe,regal,fach) VALUES (3, 1, 1, 3);
INSERT INTO keller (knr,reihe,regal,fach) VALUES (4, 1, 2, 1);
INSERT INTO keller (knr,reihe,regal,fach) VALUES (5, 1, 2, 2);
INSERT INTO keller (knr,reihe,regal,fach) VALUES (6, 2, 1, 1);
INSERT INTO keller (knr,reihe,regal,fach) VALUES (7, 2, 1, 2);
INSERT INTO keller (knr,reihe,regal,fach) VALUES (8, 2, 2, 1);


INSERT INTO wein VALUES (1, 'Riesling Kellerberg', 'Riesling', 1999, 28.0, 24, 4, 1);
INSERT INTO wein VALUES (2, 'Loibenberg', 'Gr. Veltliner', 2000, 19.0, 36, 4, 2);
INSERT INTO wein VALUES (3, 'Ried Kreutles', 'Gr. Veltliner', 2000, 19.0, 15, 3, 4);
INSERT INTO wein VALUES (4, 'Riesling Smaragd', 'Riesling', 2000, 21.0, 30, 2, 5);
INSERT INTO wein VALUES (5, 'Grauburgunder', 'Grauburgunder', 2003, 16.0, 72, 1, 6);
INSERT INTO wein VALUES (6, 'Morillon', 'Chardonnay', 2003, 9.0, 55, 1, 7);
INSERT INTO wein VALUES (7, 'Riesling Federspiel', 'Riesling', 2003, 9.9, 80, 6, 3);
INSERT INTO wein VALUES (8, 'Chardonnay', 'Chardonnay', 2003, 9.0, 16, 8, 8);


INSERT INTO protokoll VALUES (1, 1, '2003-01-12', 'Geschenk an Herrn Berger', 12);
INSERT INTO protokoll VALUES (2, 3, '2003-07-10', 'Eigenbedarf', 2);
INSERT INTO protokoll VALUES (3, 1, '2003-07-23', 'Eigenbedarf', 4);
INSERT INTO protokoll VALUES (4, 6, '2003-08-14', 'Geschenk (Frau Kunz)', 6);
INSERT INTO protokoll VALUES (5, 1, '2003-08-27', 'Glasbruch', 1);
INSERT INTO protokoll VALUES (6, 4, '2003-11-03', 'Korkgeruch', 1);
INSERT INTO protokoll VALUES (7, 6, '2003-11-03', 'Eigenbedarf', 3);
