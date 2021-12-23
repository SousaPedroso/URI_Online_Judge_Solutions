tam = len

while True:
    try:
        expressao = input()
    except EOFError:
        exit()

    parentesesEsquerdo = []
    parentesesDireito = []
    
    resposta = "correct"

    for pos in range(tam(expressao)):

        if expressao[pos] == ")":
            parentesesDireito.append(pos)

            if tam(parentesesDireito) > tam(parentesesEsquerdo):
                resposta = "incorrect"
                break

        elif expressao[pos] == "(":
            parentesesEsquerdo.append(pos)

    if tam(parentesesEsquerdo) != tam(parentesesDireito):
        resposta = "incorrect"

    print(resposta)
