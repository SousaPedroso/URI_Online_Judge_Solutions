while True:
    X = int(input())

    if X == 0:
        break

    for i in range(1, X+1):
        if i < X:
            print(i, end=" ")
        else:
            print(i)