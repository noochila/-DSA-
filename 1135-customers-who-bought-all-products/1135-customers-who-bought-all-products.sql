SELECT 
    customer.customer_id 
FROM 
    customer 
GROUP BY 
    customer.customer_id 
HAVING 
    COUNT(distinct product_key) = (SELECT  COUNT(*) FROM product);
