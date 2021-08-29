# -*- coding: utf-8 -*-

N = 1
while N != 0:
    N = int(input())
    if N == 0:
        break
    M = [[None for x in range(N)] for x in range(N)]
    for i in range(len(M)):
        aux = i+1
        for j in range(len(M)):
            if j < i:
                M[i][j] = aux
                aux -= 1
            elif j == i:
                aux = 1
                M[i][j] = aux
            else:
                aux += 1
                M[i][j] = aux
                
    for i in range(len(M)):
        for j in range(len(M)):
            if j == 0:
                print("%3d" %M[i][j],end="")
            else:
                print("%4d" %M[i][j],end="")
        print()
    print()