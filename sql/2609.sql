select categories.name, sum(amount) from categories
inner join products
on products.id_categories = categories.id
group by categories.name;