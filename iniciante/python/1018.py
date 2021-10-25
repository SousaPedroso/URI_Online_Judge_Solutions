valor = int(input())

notas_de_100 = valor // 100
sobra_notas_de_100 = valor % 100
notas_de_50 = sobra_notas_de_100 // 50
sobra_notas_de_50 = sobra_notas_de_100 % 50
notas_de_20 = sobra_notas_de_50 // 20
sobra_notas_de_20 = sobra_notas_de_50 % 20
notas_de_10 = sobra_notas_de_20 // 10
sobra_notas_de_10 = sobra_notas_de_20 % 10
notas_de_5 = sobra_notas_de_10 // 5
sobra_notas_de_5 = sobra_notas_de_10 % 5
notas_de_2 = sobra_notas_de_5 // 2
sobra_notas_de_2 = sobra_notas_de_5 % 2
notas_de_1 = sobra_notas_de_2 // 1

print(valor)
print(f"{notas_de_100} nota(s) de R$ 100,00")
print(f"{notas_de_50} nota(s) de R$ 50,00")
print(f"{notas_de_20} nota(s) de R$ 20,00")
print(f"{notas_de_10} nota(s) de R$ 10,00")
print(f"{notas_de_5} nota(s) de R$ 5,00")
print(f"{notas_de_2} nota(s) de R$ 2,00")
print(f"{notas_de_1} nota(s) de R$ 1,00")