WITH T AS (
    SELECT requester_id AS id, accepter_id AS friend
    FROM RequestAccepted
    UNION
    SELECT accepter_id AS id, requester_id AS friend
    FROM RequestAccepted
)
SELECT id, COUNT(friend) AS num
FROM T
GROUP BY id
ORDER BY num DESC
LIMIT 1;
