T = int(input())

for i in range(T):
    PA, PB, G1, G2 = input().split()
    PA, PB, G1, G2 = int(PA), int(PB), float(G1)/100, float(G2)/100

    anos = 0
    while anos <= 100 and PA <= PB:
        PA += int(G1*PA)
        PB += int(G2*PB)
        anos += 1

    if anos > 100:
        print("Mais de 1 seculo.")
    else:
        print(f"{anos} anos.")