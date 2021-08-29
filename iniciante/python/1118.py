# -*- coding: utf-8 -*-

notas_validas = 0
soma_notas = 0
X = 1
while X != 2:
    nota = float(input())
    if nota >= 0 and nota <= 10:
        soma_notas += nota
        notas_validas += 1
    else:
        print("nota invalida")
    if notas_validas == 2:
        media = soma_notas / 2
        print("media = %.2f" %media)
        notas_validas = 0
        soma_notas = 0
        print("novo calculo (1-sim 2-nao)")
        X = int(input())
        while X < 1 or X > 2:
            print("novo calculo (1-sim 2-nao)")
            X = int(input())
