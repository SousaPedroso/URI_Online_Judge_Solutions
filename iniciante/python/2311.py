# -*- coding: utf-8 -*-

class Atleta_Saltos():
    nome = None
    peso = None
    N = [None for x in range(7)]
    Pontuacao = 0

N = int(input())
Atletas_Saltos = [Atleta_Saltos() for x in range(N)]
for i in range(N):
    Atletas_Saltos[i].nome = input()
    Atletas_Saltos[i].peso = float(input())
    Atletas_Saltos[i].N[0], Atletas_Saltos[i].N[1], Atletas_Saltos[i].N[2], Atletas_Saltos[i].N[3], Atletas_Saltos[i].N[4], Atletas_Saltos[i].N[5], Atletas_Saltos[i].N[6] = input().split(" ")
    Atletas_Saltos[i].N[0] = float(Atletas_Saltos[i].N[0])
    Atletas_Saltos[i].N[1] = float(Atletas_Saltos[i].N[1])
    Atletas_Saltos[i].N[2] = float(Atletas_Saltos[i].N[2])
    Atletas_Saltos[i].N[3] = float(Atletas_Saltos[i].N[3])
    Atletas_Saltos[i].N[4] = float(Atletas_Saltos[i].N[4])
    Atletas_Saltos[i].N[5] = float(Atletas_Saltos[i].N[5])
    Atletas_Saltos[i].N[6] = float(Atletas_Saltos[i].N[6])
    maior_nota = Atletas_Saltos[i].N[0]
    pos_maior_nota = 0
    for j in range(7):
        if maior_nota < Atletas_Saltos[i].N[j]:
            pos_maior_nota = j
            maior_nota = Atletas_Saltos[i].N[j]
            
    pos_menor_nota = 0
    menor_nota = Atletas_Saltos[i].N[0]
    for j in range(7):
        if menor_nota > Atletas_Saltos[i].N[j]:
            pos_menor_nota = j
            menor_nota = Atletas_Saltos[i].N[j]
            
    for j in range(7):
        if (j != pos_menor_nota) and (j != pos_maior_nota):
            Atletas_Saltos[i].Pontuacao += Atletas_Saltos[i].N[j]
    Atletas_Saltos[i].Pontuacao *= Atletas_Saltos[i].peso

for j in range(N):
    print("%s %.2f" %(Atletas_Saltos[j].nome, Atletas_Saltos[j].Pontuacao))