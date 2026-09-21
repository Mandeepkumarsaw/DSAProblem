SELECT MAX(num) AS num
FROM (
    SELECT DISTINCT num FROM Mynumbers
    GROUP BY num HAVING COUNT(num) = 1
) t;
