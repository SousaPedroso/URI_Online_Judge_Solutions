P = int(input())

n = P/2
i = 2
total_iteracoes = 1
if (i == n+1):
    total_iteracoes += 1
    i = 1
    
while i != 1:

    i *= 2
    total_iteracoes += 1
    if (i == n+1):
        total_iteracoes += 1
        break
    
    while (i > n):
        u = i - n
        i = 2*u-1
        total_iteracoes += 1
        if (i == n+1):
            total_iteracoes += 1
            break


    if (i == n+1):
        break

print(total_iteracoes)