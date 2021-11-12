num = 0
soma = 0
while True:
    N = int(input())

    if N < 0:
        break

    num += 1
    soma += N

print(f"{soma/num:.2f}")