SELECT employee_id, name, reports_count, average_age 
FROM (
    SELECT reports_to AS rt, COUNT(reports_to) AS reports_count, round(AVG(age)) AS average_age 
    FROM employees 
    WHERE reports_to IS NOT NULL 
    GROUP BY reports_to
) AS subquery
JOIN employees ON employees.employee_id = subquery.rt order by employee_id;
