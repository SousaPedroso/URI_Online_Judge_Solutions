select products.name, providers.name, price from
products inner join providers
on products.id_providers = providers.id
inner join categories
on products.id_categories = categories.id
where price > 1000 and categories.name = 'Super Luxury';