salario = float(input())

if salario <= 400:
    novo_salario = 1.15 * salario
    print(f"Novo salario: {novo_salario:.2f}")
    print(f"Reajuste ganho: {novo_salario-salario:.2f}")
    print("Em percentual: 15 %")

elif salario <= 800:
    novo_salario = 1.12 * salario
    print(f"Novo salario: {novo_salario:.2f}")
    print(f"Reajuste ganho: {novo_salario-salario:.2f}")
    print("Em percentual: 12 %")

elif salario <= 1200:
    novo_salario = 1.1 * salario
    print(f"Novo salario: {novo_salario:.2f}")
    print(f"Reajuste ganho: {novo_salario-salario:.2f}")
    print("Em percentual: 10 %")

elif salario <= 2000:
    novo_salario = 1.07 * salario
    print(f"Novo salario: {novo_salario:.2f}")
    print(f"Reajuste ganho: {novo_salario-salario:.2f}")
    print("Em percentual: 7 %")

else:
    novo_salario = 1.04 * salario
    print(f"Novo salario: {novo_salario:.2f}")
    print(f"Reajuste ganho: {novo_salario-salario:.2f}")
    print("Em percentual: 4 %")