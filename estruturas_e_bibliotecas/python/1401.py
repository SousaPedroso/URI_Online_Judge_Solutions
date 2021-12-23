entrada = input
lista = list
mergeSort = sorted
N = int(entrada())
permutacoesGeradas = {}

def permutations(caracteres):
    
    if len(caracteres) <= 1:
        yield caracteres
    else:
        for perm in permutations(caracteres[1:]):
            for i in range(len(caracteres)):
                permutacao = f"{perm[:i]}{caracteres[0:1]}{perm[i:]}"
                if permutacoesGeradas.get(permutacao) == None:
                    permutacoesGeradas[permutacao] = 1
                    yield permutacao

for i in range(N):
    alfanumericos = entrada()

    permutacoes = mergeSort(permutations(alfanumericos))
    for perm in permutacoes:
        print(perm)

    print()
    permutacoesGeradas = {}