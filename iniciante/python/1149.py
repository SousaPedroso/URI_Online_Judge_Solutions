entrada = input().split()
A, N = int(entrada[0]), int(entrada[-1])

while N <= 0:
    N = int(input())

soma = 0
for i in range(0, N):
    soma += (A+i)

print(soma)