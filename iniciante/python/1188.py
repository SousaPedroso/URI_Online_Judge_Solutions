# -*- coding: utf-8 -

M = [[0 for i in range(12)] for j in range(12)]

O = input()
for i in range(12):
    for j in range(12):
        M[i][j] = float(input())
        
contador_linhas = 12
onde_comeca_linha = 7
onde_comeca_coluna = 5
soma = 0
onde_termina_coluna = 7
total_iteracoes = 0
if O == 'S':
    for i in range(onde_comeca_linha,contador_linhas,1):
        for j in range(onde_comeca_coluna, onde_termina_coluna,1):
            soma += M[i][j]
        onde_comeca_coluna -= 1
        onde_termina_coluna += 1
    print("%.1f" %soma)
if O == 'M':
    media = 0
    for i in range(onde_comeca_linha,contador_linhas,1):
        for j in range(onde_comeca_coluna, onde_termina_coluna,1):
            soma += M[i][j]
            total_iteracoes += 1
        onde_comeca_coluna -= 1
        onde_termina_coluna += 1
    media = soma / total_iteracoes
    print("%.1f" %media)