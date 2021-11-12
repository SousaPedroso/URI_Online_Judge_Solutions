L = int(input())
T = input()

M = [[0 for i in range(12)] for j in range(12)]
soma = 0
for i in range(12):
    for j in range(12):
        M[i][j] = float(input())
        if i == L:
            soma += M[i][j]

if T == 'M':
    soma /= 12

print(f"{soma:.1f}")