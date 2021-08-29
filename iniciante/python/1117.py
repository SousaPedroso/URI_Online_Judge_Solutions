# -*- coding: utf-8 -*-

notas_validas = 0
soma_notas = 0
while notas_validas < 2:
    nota = float(input())
    if nota >= 0 and nota <= 10:
        soma_notas += nota
        notas_validas += 1
    else:
        print("nota invalida")

media = soma_notas / 2
print("media = %.2f" %media)