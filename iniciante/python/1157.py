N = int(input())

divisores = []
for i in range(1, int((N**(1/2)))+1):
    if i == N:
        divisores.append(i)

    elif (N % i == 0):
        divisores.append(i)
        divisores.append(int(N/i))

for divisor in sorted(divisores):
    print(divisor)