entrada = input
inteiro = int
imprime = print
minimo = min

e1, e2 = 0, 0
x1, x2 = 0, 0
N = 0
linha1 = []
linha2 = []
transicao_linha_1 = []
transicao_linha_2 = []
linha1_etapas = []
linha2_etapas = []
memo = [[]]

def dp(etapas: int) -> int:

    for i in range(etapas):

        if i > 0:
            # Minimo entre vir da ultima etapa da mesma estação ou pegar o caminho pela outra estação
            # e ir para ela
            minimo_linha1 = minimo(linha1_etapas[-1]+linha1[i],
                                    linha2_etapas[-1]+transicao_linha_1[i-1]+linha1[i])

            minimo_linha2 = minimo(linha2_etapas[-1]+linha2[i],
                                    linha1_etapas[-1]+transicao_linha_2[i-1]+linha2[i])

            linha1_etapas.append(minimo_linha1)
            linha2_etapas.append(minimo_linha2)

        # Não tem escolha por enquanto
        else:
            linha1_etapas.append(e1+linha1[i])
            linha2_etapas.append(e2+linha2[i])

    # Estado final para cada
    linha1_etapas.append(linha1_etapas[-1]+x1)
    linha2_etapas.append(linha2_etapas[-1]+x2)

    return minimo(linha1_etapas[-1], linha2_etapas[-1])

while True:
    try:
        N = inteiro(entrada())
        linha1_etapas = []
        linha2_etapas = []

        e1, e2 = entrada().split()
        e1, e2 = inteiro(e1), inteiro(e2)

        linha2 = []
        transicao_linha_2 = []
        transicao_linha_1 = []

        a1 = entrada().split()
        linha1= [inteiro(a) for a in a1]
        a1 =  entrada().split()
        linha2= [inteiro(a) for a in a1]

        if N > 1:
            a1 = entrada().split()
            transicao_linha_2= [inteiro(a) for a in a1]

            a1 = entrada().split()
            transicao_linha_1= [inteiro(a) for a in a1]

            x1, x2 = entrada().split()
            x1, x2 = inteiro(x1), inteiro(x2)

            imprime(dp(N))
        else:
            x1, x2 = entrada().split()
            x1, x2 = inteiro(x1), inteiro(x2)
            print(minimo(e1+linha1[0]+x1, e2+linha2[0]+x2))


    except EOFError:
        break
