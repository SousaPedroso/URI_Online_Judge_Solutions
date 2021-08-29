# -*- coding: utf-8 -*-

class Atletas():
    nome = ""
    S = None
    B = None
    A = None
    S1 = None
    B1 = None
    A1 = None

N = int(input())
Atleta = [Atletas() for x in range(N)]
Pontos_saque = 0
Pontos_bloqueio = 0
Pontos_ataque = 0
Tentativas_saque = 0
Tentativas_bloqueio = 0
Tentativas_ataque = 0

for i in range(len(Atleta)):
    Atleta[i].nome = input()
    Atleta[i].S, Atleta[i].B, Atleta[i].A = input().split(" ")
    Atleta[i].S1, Atleta[i].B1, Atleta[i].A1 = input().split(" ")
    Atleta[i].S = int(Atleta[i].S)
    Atleta[i].B = int(Atleta[i].B)
    Atleta[i].A = int(Atleta[i].A)
    Atleta[i].S1 = int(Atleta[i].S1)
    Atleta[i].B1 = int(Atleta[i].B1)
    Atleta[i].A1 = int(Atleta[i].A1)
    Pontos_saque += Atleta[i].S1
    Pontos_bloqueio += Atleta[i].B1
    Pontos_ataque += Atleta[i].A1
    Tentativas_saque += Atleta[i].S
    Tentativas_bloqueio += Atleta[i].B
    Tentativas_ataque += Atleta[i].A

print("Pontos de Saque: %.2f %%." %((Pontos_saque/Tentativas_saque)*100))
print("Pontos de Bloqueio: %.2f %%." %((Pontos_bloqueio/Tentativas_bloqueio)*100))
print("Pontos de Ataque: %.2f %%." %((Pontos_ataque/Tentativas_ataque)*100))