# -*- coding: utf-8 -*-

entrada = input().split()
J, R = int(entrada[0]), int(entrada[1])

movimentos = input().split()
victory_points_acumulados = [0]*J
maximo_de_victory_points = int(movimentos[0])
jogador_ganhando = 0

if J > 1:
    for i in range(len(movimentos)):
        victory_points_acumulados[i%J] += int(movimentos[i])
        if victory_points_acumulados[i%J] >= maximo_de_victory_points:
            jogador_ganhando = i % J
            maximo_de_victory_points = victory_points_acumulados[i%J]
        
print(jogador_ganhando+1)