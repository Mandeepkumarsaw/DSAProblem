SELECT e.employee_id,
       e.name,
       COUNT(e.employee_id) AS reports_count,
       ROUND(AVG(r.age)) AS average_age
FROM Employees e
JOIN Employees r
   ON e.employee_id = r.reports_to
GROUP BY r.reports_to
ORDER BY employee_id;       
