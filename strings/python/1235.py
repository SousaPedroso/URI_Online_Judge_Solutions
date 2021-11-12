# -*- coding: utf-8 -*-

N = int(input())
for i in range(N):
    palavra_inversa = input()
    tamanho = len(palavra_inversa)
    meio = tamanho//2
    primeira_metade = palavra_inversa[meio-1::-1]
    segunda_metade = palavra_inversa[-1:meio-1:-1]
    palavra_correta = primeira_metade + segunda_metade
    print(palavra_correta)