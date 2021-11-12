# -*- coding: utf-8 -*-

palavra = input()

palavra_vogais = ""

for i in palavra:
    if i == "a" or i == "e" or i == "i" or i =="o" or i == "u":
        palavra_vogais = f"{palavra_vogais}{i}"

palindromo = True
cont = 0
for i in palavra_vogais[::-1]:
    if i != palavra_vogais[cont]:
        palindromo = False
        break
    cont += 1

if palindromo:
    print('S')
else:
    print('N')