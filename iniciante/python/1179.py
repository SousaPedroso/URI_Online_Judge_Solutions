# -*- coding: utf-8 -*-

par = [None]*5
impar = [None] * 5
cont_pares = 0
cont_impares = 0
for i in range(15):
    n = int(input())
    if n % 2 == 0:
        par[cont_pares] = n
        cont_pares += 1
        
    if cont_pares == 5:
        for j in range(len(par)):
            print("par[%d] = %d" %(j, par[j]))
        par = [None] * 5
        cont_pares = 0
    
    if n % 2 == 1:
        impar[cont_impares] = n
        cont_impares += 1
    
    if cont_impares == 5:
        for j in range(len(impar)):
            print("impar[%d] = %d" %(j, impar[j]))
        impar = [None] * 5
        cont_impares = 0

i = 0
while impar[i] != None:
    print("impar[%d] = %d" %(i, impar[i]))
    i += 1

i = 0
while par[i] != None:
    print("par[%d] = %d" %(i, par[i]))
    i += 1