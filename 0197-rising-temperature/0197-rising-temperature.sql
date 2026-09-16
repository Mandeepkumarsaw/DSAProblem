SELECT w.id
FROM Weather w
JOIN Weather w1
   ON DATEDIFf(w.recordDate,w1.recordDate) = 1
WHERE w.temperature > w1.temperature
