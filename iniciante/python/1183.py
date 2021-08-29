# -*- coding: utf-8 -

O = input() #lê se é média ou soma
M = [0] * 12
for i in range(0, len(M),1):
    M[i] = [0] * 12

for i in range(len(M)):
    for j in range(len(M)):
        M[i][j] = float(input())
        
onde_comecara = 1
contador_operacaoes = 0
soma = 0
if O == 'S':
    for i in range(0,12,1):
        for j in range(onde_comecara, 12,1):
            soma += M[i][j]
        onde_comecara += 1
    print("%.1f" %soma)

if O == 'M':
    media = 0
    for i in range(0,12,1):
        for j in range(onde_comecara, 12,1):
            soma += M[i][j]
            contador_operacaoes += 1
        onde_comecara += 1
    media = soma / contador_operacaoes
    print("%.1f" %media)
    