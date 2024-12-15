SELECT 
    d.name AS Department, 
    temp.name AS Employee, 
    temp.salary AS Salary
FROM 
    department d
JOIN 
    (
        SELECT 
            e1.name, 
            e1.salary, 
            e1.departmentId
        FROM 
            employee e1
        WHERE 
            3 >= (
                SELECT 
                    COUNT(DISTINCT e2.salary) 
                FROM 
                    employee e2
                WHERE 
                    e1.salary <= e2.salary 
                    AND e1.departmentId = e2.departmentId
            )
    ) AS temp 
ON 
    d.id = temp.departmentId;
