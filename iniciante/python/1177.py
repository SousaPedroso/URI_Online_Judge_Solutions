
T = int(input())
N = [0 for i in range(1000)]

for i in range(1000):
    N[i] = i % T
    print(f"N[{i}] = {N[i]}")