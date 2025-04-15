USE insyprocfuncuebung;

DELIMITER $$
DROP PROCEDURE IF EXISTS CountCities2 $$
CREATE PROCEDURE CountCities2()
BEGIN
    DECLARE cnt1 INTEGER DEFAULT 0;
    DECLARE cnt2 INTEGER DEFAULT 0;

    DECLARE done INTEGER DEFAULT 0;

    DECLARE i_name TYPE OF city.name;
    DECLARE i_longitude TYPE OF city.longitude;

    DECLARE cur1 CURSOR FOR SELECT name, longitude FROM city;

    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done=1;

    OPEN cur1;
    city_loop: LOOP
        FETCH cur1 INTO i_name, i_longitude;

        IF done=1 THEN
            LEAVE city_loop;
        END IF;

        IF i_longitude IS NOT NULL THEN
            SET cnt1=cnt1+1;
        END IF;
    END LOOP city_loop;
    CLOSE cur1;

    SELECT COUNT(longitude) INTO cnt2 FROM city;
    SELECT cnt1 AS withCursor, cnt2 AS withoutCursor;

END $$
DELIMITER ;

CALL CountCities2();