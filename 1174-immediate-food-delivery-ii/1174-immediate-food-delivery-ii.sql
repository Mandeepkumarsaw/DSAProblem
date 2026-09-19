 SELECT ROUND(
      SUM(CASE WHEN d.order_date=d.customer_pref_delivery_date THEN 1 ELSE 0 END) * 100 / COUNT(*),2
 ) AS immediate_percentage
 FROM Delivery d
 WHERE order_date = (
       SELECT MIN(a.order_date)
       FROM Delivery a
       WHERE a.customer_id = d.customer_id    
  )
 
