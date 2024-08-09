SELECT w1.id 
FROM weather AS w1 
WHERE w1.temperature > (
    SELECT w2.temperature 
    FROM weather AS w2 
    WHERE DATE(w2.recordDate) = DATE_SUB(DATE(w1.recordDate), INTERVAL 1 DAY)
);
