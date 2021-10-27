while True:
    x, y = input().split()
    x, y = int(x), int(y)

    if x == 0 or y == 0:
        exit()

    if x > 0:
        if y > 0:
            print("primeiro")
        else:
            print("quarto")
    else:
        if y > 0:
            print("segundo")
        else:
            print("terceiro")