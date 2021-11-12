N = int(input())

def primo(X):
    divisores = 1
    for i in range(2, int(X**(1/2))+1):
        if X % i == 0:
            divisores += 1

        if divisores == 2:
            return False

    return True


for i in range(N):
    X = int(input())
    
    if primo(X):
        print(f"{X} eh primo")
    else:
        print(f"{X} nao eh primo")
