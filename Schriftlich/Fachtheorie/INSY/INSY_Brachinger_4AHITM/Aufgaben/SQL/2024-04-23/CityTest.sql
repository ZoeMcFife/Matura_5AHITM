USE insyProcFuncUebung;

DELIMITER $$
DROP PROCEDURE IF EXISTS CountCities$$
CREATE PROCEDURE CountCities()
BEGIN
    DECLARE cnt INTEGER;
    SELECT COUNT(*) INTO cnt FROM city;
    SELECT CONCAT('Anzahl der Tupel in City: ', cnt) AS Ausgabe;
END$$
DELIMITER ;
CALL CountCities()
