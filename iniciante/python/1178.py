N = [0 for i in range(100)]

X = float(input())
N[0] = X
print(f"N[0] = {N[0]:.4f}")
for i in range(1,100):
    N[i] = N[i-1]/2
    print(f"N[{i}] = {N[i]:.4f}")