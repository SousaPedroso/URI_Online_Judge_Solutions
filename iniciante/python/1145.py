X, Y = input().split()
X, Y = int(X), int(Y)

for i in range(1, Y+1):
    if i % X != 0: 
        print(i, end=" ")
    else:
        print(i)