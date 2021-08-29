# -*- coding: utf-8 -*-

N = int(input())
entrada = input()
X = entrada.split()
menor_elem = int(X[0])
pos_menor = 0
for pos in range(1, len(X), 1):
    if menor_elem > int(X[pos]):
        menor_elem = int(X[pos])
        pos_menor = pos
print("Menor valor: %d" %menor_elem)
print("Posicao: %d" %pos_menor)