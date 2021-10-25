from math import sqrt
A, B, C = input().split()
A, B, C = float(A), float(B), float(C)

delta = B**2-4*A*C

if delta < 0 or A == 0:
    print("Impossivel calcular")

else:
    raiz_delta = sqrt(delta)
    R1 = ((-1*B)+raiz_delta) / (2*A)
    R2 = ((-1*B)-raiz_delta) / (2*A)
    print(f"R1 = {R1:.5f}")
    print(f"R2 = {R2:.5f}")
