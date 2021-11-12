N = int(input())

for i in range(N):
    X, Y = input().split()
    X, Y = int(X), int(Y)

    X = X+1 if X%2 == 0 else X
    soma = X
    j = Y 
    while j > 1:
        X += 2
        soma += X
        j -= 1
    
    print(soma)