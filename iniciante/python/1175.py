N = [0]*20
for i in range(20):
    N[20-(i+1)] = int(input())
    
for i in range(20):
    print(f"N[{i}] = {N[i]}")