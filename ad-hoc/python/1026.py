
while True:

    try:
        A, B = input().split()

    except EOFError:
        exit()

    A, B = int(A), int(B)
    if A < B:
        A, B = B, A

    # Representacao A bits
    A, B = bin(A), bin(B)

    # Pega a diferença em bits dos dois e adiciona em B
    B = f"{'0'*(len(A)-len(B))}{B[2:]}"
    A = A[2:]
    soma = ""
    for i in range(len(A)-1, -1, -1):
        # Ou exclusivo, nao carrega o bit
        if A[i] == B[i]:
            soma = f"0{soma}"
        else:
            soma = f"1{soma}"

    soma = f"0b{soma}"
    print(int(soma, 0))