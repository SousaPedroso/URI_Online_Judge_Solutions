# -*- coding: utf-8 -*

N = int(input())
num_intervalo=0
num_fora_intervalo = 0
vet = [0] * N
for i in range(len(vet)):
    vet[i] = int(input())
    if vet[i] >= 10 and vet[i] <= 20:
        num_intervalo += 1
    else:
        num_fora_intervalo += 1
print("%d in\n%d out" %(num_intervalo, num_fora_intervalo))