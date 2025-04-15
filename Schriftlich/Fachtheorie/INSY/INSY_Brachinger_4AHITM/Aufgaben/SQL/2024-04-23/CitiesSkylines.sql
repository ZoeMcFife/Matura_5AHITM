USE insyprocfuncuebung;

DELIMITER $$
DROP TRIGGER IF EXISTS CheckPopulation$$
CREATE TRIGGER CheckPopulation
BEFORE INSERT ON city
FOR EACH ROW
BEGIN
   IF NEW.Population < 0 THEN
       SET NEW.Population = 0;
   END IF;
END $$

#INSERT INTO city VALUES('Delta Capital', 'Wolfram', 'Wolfram Delta', -4800000000, 20, 30);

UPDATE city SET Population=4800000000 WHERE Name = 'Delta Capital';

SELECT * FROM city WHERE Name = 'Delta Capital';