# -*- coding: utf-8 *-*

N = 1
def matriz_par_impar(tamanho):
    iteracoes = tamanho // 2 #quantidade de iteracoes a realizar
    posi_inic = 0
    posi_final = tamanho -1
    valor_p_iteracao = 1
    matriz = [[0 for i in range(0,tamanho,1)] for i in range(0,tamanho,1)]
    while iteracoes > 0:
        for j in range(posi_inic, posi_final+1,1):
            matriz[posi_inic][j] = valor_p_iteracao
        for i in range(posi_inic+1, posi_final+1,1):
            matriz[i][posi_final] = valor_p_iteracao
        for j in range(posi_final-1, posi_inic-1, -1):
            matriz[posi_final][j] = valor_p_iteracao
        for i in range(posi_final-1, posi_inic, -1):
            matriz[i][posi_inic] = valor_p_iteracao
        iteracoes -= 1
        valor_p_iteracao += 1
        posi_final -= 1
        posi_inic += 1
    if tamanho % 2 == 1:
        meio = (tamanho-1) // 2
        matriz[meio][meio] = meio+1
    for i in range(len(matriz)):
        for j in range(len(matriz)):
            if j != len(matriz)-1:
                print("%3d " %matriz[i][j], end="")
            else:
                print("%3d" %matriz[i][j], end="")
        print()
    print()
    
while N != 0:
    N =int(input())
    if N != 0:
        matriz_par_impar(N)