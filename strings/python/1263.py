# -*- coding: utf-8 -*-

while True:
    try:
        frase = input()
        frase = frase.upper()
    except EOFError:
        break
    palavras = frase.split(" ")
    num_alit = 1
    control = 0 #auxiliar no num de aliterações variavel de controle
    for i in range(0, len(palavras)-1, 1):
        if palavras[i][0] == palavras[i+1][0]:
            control += 1
        else:
            if control != 0:
                num_alit += 1
                control = 0
    if control == 0:
        num_alit -= 1
    print(num_alit)