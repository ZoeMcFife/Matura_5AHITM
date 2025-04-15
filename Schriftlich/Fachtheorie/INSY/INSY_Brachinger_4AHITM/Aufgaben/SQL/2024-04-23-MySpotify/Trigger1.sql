USE myspotify;

CREATE OR REPLACE TRIGGER DateTrigger
BEFORE INSERT ON hinzugefuegt
FOR EACH ROW
BEGIN
    DECLARE playlistDate DATE;

    SELECT datum INTO playlistDate FROM playlist WHERE playlist.pid = NEW.pid;

    IF NEW.datum < playlistDate THEN
        SET NEW.datum = playlistDate;
    END IF;
END;