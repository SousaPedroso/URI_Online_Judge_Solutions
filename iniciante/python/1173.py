# -*- coding: utf-8 -*-

V = int(input())
while V > 50:
    V = int(input())
    
N = [0] * 10

for i in range(0, 10, 1):
    N[i] = V
    V *= 2
    print("N[%d] = %d" %(i, N[i]))