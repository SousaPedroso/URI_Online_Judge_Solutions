# -*- coding: utf-8 -*-

Total = 0
Total_sapos = 0
Total_coelhos = 0
Total_ratos = 0
N = int(input())
for i in range(0,N,1):
    Quantia, Tipo = input().split(" ")
    Quantia = int(Quantia)
    Total += Quantia
    if Tipo == 'C':
        Total_coelhos += Quantia
    elif Tipo == 'R':
        Total_ratos += Quantia
    else:
        Total_sapos += Quantia

print("Total: %d cobaias" %Total)
print("Total de coelhos: %d" %Total_coelhos)
print("Total de ratos: %d" %Total_ratos)
print("Total de sapos: %d" %Total_sapos)
Percentual_c = (Total_coelhos / Total) * 100
print("Percentual de coelhos: %.2f %%" %Percentual_c)
Percentual_r = (Total_ratos / Total) * 100
print("Percentual de ratos: %.2f %%" %Percentual_r)
Percentual_s = (Total_sapos / Total) * 100
print("Percentual de sapos: %.2f %%" %Percentual_s)