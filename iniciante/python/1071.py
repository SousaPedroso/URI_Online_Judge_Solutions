x = int(input())
y = int(input())

if x < y:
    x, y = y, x

soma_impares = 0
# Nao e inclusivo, pular para o proximo
if y % 2 != 0:
    y += 2
else:
    # Pega o impar
    y += 1

for i in range(y, x, 2):
    soma_impares += i

print(soma_impares)