# Write your MySQL query statement below
select visited_on,(
    select sum(amount)    from customer where visited_on between date_sub(c1.visited_on,interval 6 day) and c1.visited_on
   
)as amount,(
     select round(sum(amount)/7,2)    from customer where visited_on between date_sub(c1.visited_on,interval 6 day) and c1.visited_on
)as average_amount
from customer c1
where
visited_on>=(
    select date_add(min(visited_on),interval 6 day) from customer
)
group by visited_on order by visited_on