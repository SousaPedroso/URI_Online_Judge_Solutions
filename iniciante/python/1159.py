
while True:
    X = int(input())

    if X == 0:
        break
    
    X += 1 if X % 2 == 1 else 0

    # Progressao aritmetica de razao 2
    Sn = int(((X + X+8)*5)/2)
    print(Sn)