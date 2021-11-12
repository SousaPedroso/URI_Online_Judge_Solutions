X = int(input())
Z = int(input())

while Z <= X:
    Z = int(input())

soma = X
i = 1
while soma <= Z:
    soma += (X+i)
    i += 1

print(i)