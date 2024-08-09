-- SELECT w1.id 
-- FROM weather AS w1 
-- WHERE w1.temperature > (
--     SELECT w2.temperature 
--     FROM weather AS w2 
--     WHERE DATEDIFF(w1.recordDate, w2.recordDate) = 1
-- );

select w1.id from weather as w1 inner join weather as w2 where datediff(w1.recordDate,w2.recordDate)=1 and w1.temperature>w2.temperature;