# -*- coding: utf-8 -*-

entrada = input().split()


anos = dict()
A, B, C = int(entrada[0]), int(entrada[1]), int(entrada[2])

if A == B or A== C or B==C:
    print("S")
elif(((A + B) == C) or ((A+C) == B) or ((B+C) == A )):
    print("S")
else:
    print("N")