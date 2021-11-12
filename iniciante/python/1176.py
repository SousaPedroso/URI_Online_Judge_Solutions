fib = [0, 1]
T = int(input())

for i in range(T):
    X = int(input())

    # Evitar calculos novamente
    if X >= len(fib):
        for j in range(len(fib), X+1):
            fib.append(0)
            fib[j] = fib[j-1] + fib[j-2]

    print(f"Fib({X}) = {fib[X]}")