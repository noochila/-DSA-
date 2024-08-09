
select m.machine_id,round(avg((t.timestamp-m.timestamp)),3) as processing_time from activity as m 
join activity as t 
on m.activity_type='start' and t.activity_type='end' and m.process_id=t.process_id and m.machine_id=t.machine_id
group by  m.machine_id ;