select products.id, products.name from products
inner join categories
on products.id_categories = categories.id
where position('super' in categories.name) > 0;