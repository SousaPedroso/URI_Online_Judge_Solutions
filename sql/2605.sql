select products.name, providers.name from products
inner join providers
on id_providers = providers.id
where id_categories = 6;