# -*- coding:utf-8 -*-
def maior(num1, num2):
    if num1 >= num2:
        maior = num1
        menor = num2
    else:
        maior = num2
        menor = num1
    return maior, menor
    
def calcula_mdc(dec1, dec2):
    if dec1 != dec2:
        mdc = 1
        maior_num, menor_num = maior(dec1, dec2)
        dec1 = maior_num
        dec2 = menor_num
        while (dec2 != 0):
            dec1, dec2 = menor_num, maior_num % dec2
            menor_num = dec2
            maior_num = dec1
        return maior_num
    else:
        return dec1
    
N = int(input())
for i in range(N):
    string1 = int(input(), 2)
    string2 = int(input(), 2)
    tudo_amor = calcula_mdc(string1, string2)
    if tudo_amor > 1:
        print("Pair #%d: All you need is love!"%(i+1))
    elif tudo_amor == 1:
        print("Pair #%d: Love is not all you need!"%(i+1))