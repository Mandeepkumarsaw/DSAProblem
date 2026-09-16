SELECT unique_id,name
FROM Employees e
LEFT JOIN EmployeeUNI ei
   ON ei.id = e.id
