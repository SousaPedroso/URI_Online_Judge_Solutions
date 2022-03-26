select customers.id, customers.name from
locations right join customers
on locations.id_customers = customers.id
group by customers.id
having count(locations.id_customers) = 0
order by customers.id;