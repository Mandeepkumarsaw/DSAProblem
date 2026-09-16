SELECT product_name,year,price
FROM Sales s
RIGHT JOIN Product p
   ON p.product_id = s.product_id
HAVING price IS NOT NULL   
