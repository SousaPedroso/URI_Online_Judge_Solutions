N = int(input())

for i in range(N):
    n1, n2 = input().split()
    n1, n2 = int(n1), int(n2)

    if n2 == 0:
        print("divisao impossivel")

    else:
        print(f"{n1/n2:.1f}")