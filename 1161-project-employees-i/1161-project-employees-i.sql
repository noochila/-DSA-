SELECT 
    p.project_id, 
    IFNULL(ROUND(SUM(e.experience_years)/COUNT(*), 2), 0) AS average_years
FROM 
    project p 
LEFT JOIN 
    employee e 
ON 
    p.employee_id = e.employee_id
GROUP BY 
    p.project_id;
