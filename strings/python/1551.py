# -*- coding: utf-8 -*-

N = int(input())
for i in range(N):
    teste = input().split(" ")
    #lista para armazenar as letras do alfabeto
    alfabeto = []
    for caso in range(len(teste)):
        for letra in range(len(teste[caso])):
            if (not teste[caso][letra] in alfabeto) and teste[caso][letra] != ",":
                alfabeto.append(teste[caso][letra])
    
    if len(alfabeto) == 26:
        print("frase completa")
    elif len(alfabeto) >= 13:
        print("frase quase completa")
    else:
        print("frase mal elaborada")