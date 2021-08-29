# -*- coding: utf-8 -*

N = int(input())

anos = N // 365
meses = (N % 365) // 30
dias = (N % 365) % 30
print("%d ano(s)\n%d mes(es)\n%d dia(s)" %(anos, meses, dias))