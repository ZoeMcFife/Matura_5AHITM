USE myspotify;

CREATE OR REPLACE TRIGGER SongPlaylistTrigger
BEFORE INSERT ON hinzugefuegt
FOR EACH ROW
BEGIN
    CALL add_song_to_all_playlists(new.sid, new.pid);
END;

CREATE OR REPLACE PROCEDURE add_song_to_all_playlists(sid INTEGER, pid INTEGER)
BEGIN
    DECLARE song_title VARCHAR(30);
    DECLARE playlist_title VARCHAR(30);

    SELECT titel INTO song_title FROM lied WHERE lied.sid = sid;
    SELECT name INTO playlist_title FROM playlist WHERE playlist.pid = pid;

    INSERT INTO hinzugefuegt(sid, titel, email, pid, name, datum) VALUES (sid, song_title, 'email', pid, playlist_title, NOW());
END;

SELECT * FROM playlist;