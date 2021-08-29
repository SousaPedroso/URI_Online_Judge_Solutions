# -*- coding: utf-8 -*-

N = float(input())

nota_100 = N // 100
N_auxiliar = N % 100
M_auxiliar = (N - int(N)) * 100
nota_50 = N_auxiliar // 50
nota_20 = (N_auxiliar % 50) // 20
nota_10 = ((N_auxiliar % 50) % 20) // 10
nota_5 = (((N_auxiliar % 50) % 20) % 10) // 5
nota_2 = ((((N_auxiliar % 50) % 20) % 10) % 5) // 2
print("NOTAS:");
print("%d nota(s) de R$ 100.00" %nota_100);
print("%d nota(s) de R$ 50.00" %nota_50);
print("%d nota(s) de R$ 20.00" %nota_20);
print("%d nota(s) de R$ 10.00" %nota_10);
print("%d nota(s) de R$ 5.00" %nota_5);
print("%d nota(s) de R$ 2.00" %nota_2);
print("MOEDAS:")
moeda_1 = ((((N_auxiliar % 50) % 20) % 10) % 5) % 2
moeda_50cents = M_auxiliar // 50
moeda_25cents = (M_auxiliar % 50) // 25
moeda_10cents = ((M_auxiliar % 50) % 25) // 10
moeda_5cents = (((M_auxiliar % 50) % 25) % 10) // 5
moeda_1cent = (((M_auxiliar % 50) % 25) % 10) % 5
print("%d moeda(s) de R$ 1.00" %moeda_1)
print("%d moeda(s) de R$ 0.50" %moeda_50cents)
print("%d moeda(s) de R$ 0.25" %moeda_25cents)
print("%d moeda(s) de R$ 0.10" %moeda_10cents)
print("%d moeda(s) de R$ 0.05" %moeda_5cents)
print("%d moeda(s) de R$ 0.01" %moeda_1cent)
