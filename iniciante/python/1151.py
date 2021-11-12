N = int(input())
fibonacci  = [0]*N
for i in range(N):
    if i > 1:
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2]

    elif i == 1:
        fibonacci[1] = 1

    if i == N-1:
        print(fibonacci[i])

    else:
        print(fibonacci[i], end=" ")