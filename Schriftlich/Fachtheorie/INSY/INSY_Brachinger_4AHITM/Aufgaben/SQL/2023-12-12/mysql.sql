USE mysql;

SHOW TABLES;

/* USER an HOST + Username
   Wildcard % for more hosts
 */

/* GLOBAL PRIV */
-- has json for priviliges
-- access stored as number
-- gets calculated in user view with a Y or N


/* TABLE PRIV */
-- table specific permissions


-- creating a user:

-- CREATE USER buchi@localhost IDENTIFIED BY 'htl';

GRANT SELECT, INSERT, UPDATE, DELETE ON filmdb.person TO buchi@localhost WITH GRANT OPTION ;

-- with Grant option: can give own rights to other users

-- Superuser
-- GRANT ALL PRIVILEGES ON *.* TO buchi@localhost WITH GRANT OPTION;

SHOW GRANTS FOR buchi@localhost;

REVOKE ALL PRIVILEGES ON *.* FROM buchi@localhost;

-- Spalten spezifische
-- GRANT SELECT (name, SVNR) ON filmdb.person TO ...


-- VIEW

use filmdb;

DROP VIEW v_schauspieler;

CREATE VIEW v_schauspieler AS (select * FROM PERSON NATURAL JOIN schauspieler);

SELECT * from v_schauspieler;

create role ro_SCHUELER;

grant ro_SCHUELER TO buchi@localhost;

GRANT SELECT ON FILMDB.film TO ro_SCHUELER;


/* need to set yourself the role*/
SET ROLE ro_Schueler;