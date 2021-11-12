# -*- coding: utf-8 -*-

N = int(input())
for i in range(N):
    teste = input().split()
    mensagem_oculta = ""
    for indice in range(len(teste)):
        mensagem_oculta += teste[indice][0]
    print(mensagem_oculta)