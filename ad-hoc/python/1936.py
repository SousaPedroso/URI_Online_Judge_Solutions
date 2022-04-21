# -*- coding: utf-8 -*-

def fatorial(n):
    fat = 1
    i = 2
    while fat < n:
        fat *= i
        i += 1
       
    if fat == n:
        return fat
    else:
        return fat / (i-1)
    
N = int(input())
numeros_usados = 0
while N > 0:
    fat = fatorial(N)
    N -= fat
    numeros_usados += 1
    
print(numeros_usados)