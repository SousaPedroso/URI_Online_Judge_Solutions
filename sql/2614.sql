select customers.name, rentals.rentals_date from
customers inner join rentals
on customers.id = rentals.id_customers
where extract(month from rentals.rentals_date) = 9 and
extract(year from rentals.rentals_date) = 2016;