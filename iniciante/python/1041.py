x, y = input().split()
x, y = float(x), float(y)

if x == 0 and y == 0:
    print("Origem")

elif x == 0:
    print("Eixo Y")

elif y == 0:
    print("Eixo X")

else:
    if x > 0 and y > 0:
        print("Q1")

    elif y < 0 and x > 0:
        print("Q4")

    elif x < 0 and y > 0:
        print("Q2")

    else:
        print("Q3")