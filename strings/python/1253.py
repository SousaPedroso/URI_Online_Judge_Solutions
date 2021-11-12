N = int(input())
posicoes = list(range(ord("A"), ord("Z")+1, 1))
incremento = 65

for i in range(N):


    mensagemCodificada = input()
    deslocamento = int(input())
    mensagemDecodificada = ""
    for char in mensagemCodificada:
        mensagemDecodificada = f"{mensagemDecodificada}{chr(posicoes[ord(char)-incremento-deslocamento])}"

    print(mensagemDecodificada)
