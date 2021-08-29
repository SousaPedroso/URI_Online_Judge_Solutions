# -*- coding: utf-8 -*

media = 0
cont_num_posi = 0
vet = [0] * 6
for i in range(len(vet)):
    vet[i] = float(input())
    if (vet[i]) > 0:
        cont_num_posi += 1
        media += vet[i]
media /= cont_num_posi
print("%d valores positivos\n%.1f" %(cont_num_posi, media))