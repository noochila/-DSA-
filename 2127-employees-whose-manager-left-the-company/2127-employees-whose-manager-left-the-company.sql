-- # Write your MySQL query statement below
-- select employee_id from (select * from Employees where manager_id is not null and salary<30000 and manager_id not in (select employee_id from employees )) as temp order by employee_id


select employee_id from employees where salary<30000 and manager_id not in (select employee_id from employees) order by employee_id