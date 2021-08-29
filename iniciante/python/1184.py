# -*- coding: utf-8 -*-

O = input()
M = [[None for x in range(12)] for x in range(12)]
for i in range(len(M)):
    for j in range(len(M)):
        M[i][j] = float(input())

def funcao_soma(M):
    Soma = 0
    cont_elem = 0
    for i in range(len(M)):
        for j in range(len(M)):
            if j < i:
                Soma += M[i][j]
                cont_elem += 1
    return Soma, cont_elem
    
if O == 'S':
    S, num_elem = funcao_soma(M)
    print("%.1f" %S)

if O == 'M':
    S, num_elem = funcao_soma(M)
    media = S / num_elem
    print("%.1f" %media)