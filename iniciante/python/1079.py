N = int(input())

for i in range(N):
    media = 0
    num_1, num_2, num_3 = input().split()
    num_1, num_2, num_3 = float(num_1), float(num_2), float(num_3)

    media = ((2*num_1 + 3*num_2 + 5*num_3)/10)
    print(f"{media:.1f}")