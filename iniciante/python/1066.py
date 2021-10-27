pares = 0
impares = 0
positivos = 0
negativos = 0
n1 = int(input())
if n1 % 2 == 0:
    pares += 1
else:
    impares += 1

if n1 > 0:
    positivos += 1
elif n1 < 0:
    negativos += 1

n2 = int(input())
if n2 % 2 == 0:
    pares += 1
else:
    impares += 1

if n2 > 0:
    positivos += 1
elif n2 < 0:
    negativos += 1

n3 = int(input())
if n3 % 2 == 0:
    pares += 1
else:
    impares += 1

if n3 > 0:
    positivos += 1
elif n3 < 0:
    negativos += 1

n4 = int(input())
if n4 % 2 == 0:
    pares += 1
else:
    impares += 1

if n4 > 0:
    positivos += 1
elif n4 < 0:
    negativos += 1

n5 = int(input())
if n5 % 2 == 0:
    pares += 1
else:
    impares += 1

if n5 > 0:
    positivos += 1
elif n5 < 0:
    negativos += 1


print(f"{pares} valor(es) par(es)")
print(f"{impares} valor(es) impar(es)")
print(f"{positivos} valor(es) positivo(s)")
print(f"{negativos} valor(es) negativo(s)")
