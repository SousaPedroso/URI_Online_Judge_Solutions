# -*- coding: utf-8 -*-
n = int(input())

for tentativas in range(n):
  todo_alfabeto = list ('abcdefghijklmnopqrstuvwxyz')
  vezes = []
  letras = []
  frase = input().lower()
  texto = ""
  for i in range (len(frase)):
    if frase[i] not in letras:
      if frase[i] in todo_alfabeto:
        if frase[i] != " ":
          vezes.append(frase.count(frase[i]))
          letras.append(frase[i])
  #print (vezes)
  #print(letras)    
  maior = 1
  for i in range (len(vezes)):
    if vezes[i] >= maior:
      maior = vezes[i]
  i =0
  while i < len(vezes):
    if vezes[i] == maior:
      texto = texto + letras[i]
    i = i+ 1
  texto = sorted(texto)
  final = ''
  for i in range (len(texto)):
    final = final + str(texto[i])
  print(final)