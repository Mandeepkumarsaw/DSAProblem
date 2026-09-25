SELECT
  d.visited_on,
  (
    SELECT SUM(d2.amount)
    FROM (
      SELECT visited_on, SUM(amount) AS amount
      FROM Customer
      GROUP BY visited_on
    ) d2
    WHERE d2.visited_on BETWEEN DATE_SUB(d.visited_on, INTERVAL 6 DAY) AND d.visited_on
  ) AS amount,
  
  ROUND(
    (
      SELECT SUM(d3.amount)
      FROM (
        SELECT visited_on, SUM(amount) AS amount
        FROM Customer
        GROUP BY visited_on
      ) d3
      WHERE d3.visited_on BETWEEN DATE_SUB(d.visited_on, INTERVAL 6 DAY) AND d.visited_on
    ) / 7, 2
  ) AS average_amount
FROM (
  SELECT visited_on, SUM(amount) AS amount
  FROM Customer
  GROUP BY visited_on
) d
WHERE d.visited_on >= (SELECT MIN(visited_on) FROM Customer) + INTERVAL 6 DAY
ORDER BY d.visited_on;
