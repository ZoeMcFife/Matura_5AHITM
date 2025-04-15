USE filmdb;

delimiter $$
DROP PROCEDURE IF EXISTS HelloWorld1$$
CREATE PROCEDURE HelloWorld1()
BEGIN
    SELECT 'HelloWorld' FROM dual;
end $$

call HelloWorld1()