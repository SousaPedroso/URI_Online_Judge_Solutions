A = [0]*100

for i in range(100):
    A[i] = float(input())

    if A[i] <= 10:
        print(f"A[{i}] = {A[i]:.1f}")