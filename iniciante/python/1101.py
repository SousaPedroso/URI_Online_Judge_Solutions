# -*- coding: utf-8 -*-

M = 1
N = 1
while True:
    M, N = input().split(" ")
    M = int(M)
    N = int(N)
    if M <= 0 or N <= 0:
        break
    Sum = 0
    elementos =""
    if M < N:
        for i in range(M, N+1,1):
            Sum += i
            if i !=  M:
                elementos = elementos + " " + str(i)
            else:
                elementos = elementos + str(i)
        print(elementos, end=" Sum=%d" %Sum)
        print()
    else:
        for i in range(N, M+1,1):
            Sum += i
            if i != N:
                elementos = elementos + " " + str(i)
            else:
                elementos = elementos + str(i)
        print(elementos, end=" Sum=%d" %Sum)
        print()