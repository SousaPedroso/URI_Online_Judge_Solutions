# -*- coding: utf-8 -*-

nome_vend = input()
salario_fixo = float(input())
montante_total = float(input())
TOTAL = salario_fixo + (0.15 * montante_total)
print("TOTAL = R$ %.2f" %TOTAL)