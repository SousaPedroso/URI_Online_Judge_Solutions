N = int(input())

# Descobre o primeiro em que acontece a condicao e
# faz os numeros aumentarem de N em N
n = 0
while n < 10000:
    if n % N == 2:
        break
    n += 1

for i in range(n, 10000, N):
    print(i)