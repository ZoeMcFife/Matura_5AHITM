USE flugverbindungen;

-- ANZEIGE der Flugstrecke

/*WITH RECURSIVE h AS
    (
        SELECT abflug, ankunft, CONCAT(abflug,' - ', ankunft) AS Strecke
        FROM flug
        WHERE abflug = 'Wien'
        UNION ALL
        SELECT h.abflug, flug.ankunft, CONCAT(Strecke, ' - ', flug.ankunft)
    )
*/
