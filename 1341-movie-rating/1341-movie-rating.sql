SELECT name AS results
FROM Users
WHERE user_id = (
    SELECT mr.user_id
    FROM MovieRating mr
    JOIN Users u ON mr.user_id = u.user_id
    GROUP BY mr.user_id, u.name
    ORDER BY COUNT(*) DESC, u.name
    LIMIT 1
)

UNION ALL

SELECT title AS results
FROM Movies m
WHERE m.movie_id = (
    SELECT mr.movie_id
    FROM MovieRating mr
    JOIN Movies m2 ON mr.movie_id = m2.movie_id
    WHERE mr.created_at BETWEEN '2020-02-01' AND '2020-02-29'
    GROUP BY mr.movie_id, m2.title
    ORDER BY AVG(mr.rating) DESC, m2.title
    LIMIT 1
);
