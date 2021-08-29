# -*- coding: utf-8 -*

posi_mai=0
num_mai = 0
vet = [0] * 100
for i in range(len(vet)):
    vet[i] = int(input())
    if num_mai < vet[i]:
        num_mai = vet[i]
        posi_mai = i+1

print("%d" %num_mai)
print("%d" %posi_mai)