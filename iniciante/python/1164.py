# -*- coding: utf-8 -*-

N = int(input())
while N < 1 or N > 20:
    N = int(input())
    
for i in range(0, N, 1):
    X = int(input())
    while X < 1 or X > 100000000:
        X = int(input())
    soma_dos_divisores = 0
    for j in range(1, X, 1):
        if X % j == 0:
            soma_dos_divisores += j;
    if soma_dos_divisores == X:
	    print("%d eh perfeito" %X)
    else:
	    print("%d nao eh perfeito" %X)