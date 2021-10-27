alcool = 0
gasolina = 0
diesel = 0
codigo = 0
while codigo != 4:
    
    codigo = int(input())
    while codigo > 4:
        codigo = int(input())
        
    if codigo == 1:
        alcool += 1

    elif codigo == 2:
        gasolina += 1

    elif codigo == 3:
        diesel += 1

    

print("MUITO OBRIGADO")
print(f"Alcool: {alcool}")
print(f"Gasolina: {gasolina}")
print(f"Diesel: {diesel}")