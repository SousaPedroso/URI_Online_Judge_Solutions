X, Y = map(lambda x: int(x), input().split())

v1 = 1
v2 = X / Y

# Diferença de espaço em uma volta
dif = v1 - v2

num_voltas = 1 / dif

if num_voltas % int(num_voltas) > 0:
    num_voltas = int(num_voltas)+1
else:
    num_voltas = int(num_voltas)

print(num_voltas)