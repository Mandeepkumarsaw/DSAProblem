SELECT user_id, ROUND(AVG(feature), 2) AS confirmation_rate
FROM (
    SELECT s.user_id,
           CASE
               WHEN c.action = 'timeout' THEN 0
               WHEN c.action = 'confirmed' THEN 1
               WHEN c.action IS NULL THEN 0
           END AS feature
    FROM Signups s
    LEFT JOIN Confirmations c
        ON c.user_id = s.user_id
    
) AS dt
GROUP BY user_id;

-- SELECT user_id,
--        ROUND(AVG(feature), 2) AS confirmation_rate
-- FROM (
--     SELECT s.user_id,
--            CASE
--                WHEN c.action = 'confirmed' THEN 1
--                ELSE 0
--            END AS feature
--     FROM Signups s
--     LEFT JOIN Confirmations c
--         ON s.user_id = c.user_id
-- ) AS dt
-- GROUP BY user_id;