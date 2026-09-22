SELECT DISTINCT a.num as ConsecutiveNums
FROM Logs a
JOIN Logs b ON a.id=b.id-1 AND a.num = b.num
JOIN Logs c ON b.id = c.id-1 AND b.num=c.num