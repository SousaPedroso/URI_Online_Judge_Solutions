select city from customers
group by city
order by count(customers.name) desc;