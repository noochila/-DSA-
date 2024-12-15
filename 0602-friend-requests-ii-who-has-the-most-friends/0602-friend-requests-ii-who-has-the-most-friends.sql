select id,count(id) as num from (select requester_id as id from requestaccepted
union all
select accepter_id from requestaccepted ) as temp group by id order by num desc  limit 1;