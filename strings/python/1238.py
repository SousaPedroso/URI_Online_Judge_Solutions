# -*- coding: utf-8 -*-

N = int(input())
for i in range(N):
    strings = input().split(" ")
    string1 = strings[0]
    string2 = strings[1]
    ind_str_1 = 0
    ind_str_2 = 0
    string_resultante = []
    #percorrer o tamanho total das duas strings
    for j in range(len(string1)+ len(string2)):
        #só até aqui percorrer a string 1
        if j % 2 == 0 and ind_str_1 < len(string1):
            string_resultante.append(string1[ind_str_1])
            ind_str_1 += 1
        elif j % 2 == 1 and ind_str_2 < len(string2):
            string_resultante.append(string2[ind_str_2])
            ind_str_2 += 1
        elif ind_str_1 == len(string1):
            string_resultante.append(string2[ind_str_2])
            ind_str_2 += 1
        elif ind_str_2 == len(string2):
            string_resultante.append(string1[ind_str_1])
            ind_str_1 += 1
            
    for j in string_resultante:
        print(j, end="")
    print()