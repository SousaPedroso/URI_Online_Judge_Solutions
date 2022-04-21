# -*- coding: utf-8 -*-

N = int(input())

for i in range(N):
    bricks = [0]*9
    for j in range(0, 9, 2):
        values = [int(v) for v in input().split(" ")]
        bricks[j] = [0]*(j+1)

        for k in range(0, j+1, 2):
            bricks[j][k] = values[int(k/2)]

        if j != 8:
            bricks[j+1] = [0]*(j+2)
    
    for j in range(8, 0, -1):
        if j % 2 == 0:
            for k in range(1,j+1,2):
                if j == 8:
                    bricks[j][k] = int((bricks[j-2][k-1] - bricks[j][k-1] - bricks[j][k+1]) / 2)
                else:
                    bricks[j][k] = bricks[j+1][k] + bricks[j+1][k+1]

        else:
            for k in range(0,j+1,1):
                bricks[j][k] = bricks[j+1][k] + bricks[j+1][k+1]
    
    for j in range(9):
        for k in range(j+1):
            if k == j:
                print(bricks[j][k])
            else:
                print(bricks[j][k], end=" ")

    bricks = []
