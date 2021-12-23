# -*- coding: utf-8 -*-

np = list(map(int, input().split()))
N, P = np[0], np[1:]

def ordena_vetor(vetor):
    
    trocas = 0
    i = 0
    while i < N:
        if vetor[i] != (i+1):
            trocas += (2 * (vetor[i]-1 -i))-1
            aux_troca = vetor[vetor[i]-1]
            vetor[vetor[i]-1] = vetor[i]
            vetor[i] = aux_troca
        else:
            i += 1
    
    return trocas
    
while N != 0:
    
    trocas = ordena_vetor(P)
    if trocas % 2 == 1:
        print("Marcelo")
    else:
        print("Carlos")

    try:
        np = list(map(int, input().split()))
        N, P = np[0], np[1:]
    except:
        N = 0
