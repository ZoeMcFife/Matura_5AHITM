USE myspotify;

DELIMITER $$
DROP FUNCTION IF EXISTS f_PlaylistDauer$$
CREATE FUNCTION f_PlaylistDauer(playlistID INTEGER) RETURNS INTEGER

BEGIN
    DECLARE playlist_dauer INTEGER DEFAULT 0;

    SELECT SUM(dauer) INTO playlist_dauer FROM hinzugefuegt NATURAL JOIN lied WHERE pid = playlistID;

    RETURN playlist_dauer;
END $$
DELIMITER $$;

SELECT * FROM playlist;

SELECT f_PlaylistDauer(10000);