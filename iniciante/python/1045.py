# -*- coding: utf-8 -*-

A, B, C = input().split(" ")
A = float(A)
B = float(B)
C = float(C)

if B > A:
    A, B = B, A
    
if C > A:
    A, C = C, A

if A >= B + C:
    print("NAO FORMA TRIANGULO")

if A**2 == B**2 + C**2:
    print("TRIANGULO RETANGULO")
    
if (A**2 > B**2 + C**2) and (A < B+C):
    print("TRIANGULO OBTUSANGULO")

if  A**2 < B**2 + C**2:
    print("TRIANGULO ACUTANGULO")

if A == B and A == C:
    print("TRIANGULO EQUILATERO")

if (A == B and A != C) or (A == C and A != B) or (B == C and A != B) and(A < B+C):
    print("TRIANGULO ISOSCELES")