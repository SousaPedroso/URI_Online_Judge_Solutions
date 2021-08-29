# *-* coding: utf-8 *-*

#criação da matriz a partir do tamanho da matriz
while True:
    try:
        n = int(input())
    except EOFError:
        break
    matriz = [[0 for i in range(n)] for j in range(n)]
    #preenchimento da diagonal principal com 2
    for i in range(len(matriz)):
        j = i
        matriz[i][j] = 2
    #preenchimento da diagonal secundaria com 3
    for i in range(len(matriz)):
        j = len(matriz)-1 - i
        matriz[i][j] = 3
    for i in range(n//3,n-n//3,1):
        for j in range(n//3, n-n//3,1):
            matriz[i][j] = 1
    matriz[n//2][n//2] = 4
    for i in range(len(matriz)):
        for j in range(len(matriz)):
            print(matriz[i][j], end='')
        print()
    print()