# -*- coding: utf-8 -*-

entrada = input().split()
N, X = int(entrada[0]), int(entrada[1])

scenicViewPoints = input().split()
maxNumViewPoints = 1
curNumViewPoints = 1
for scenicViewPoint in range(len(scenicViewPoints)-1):
    if int(scenicViewPoints[scenicViewPoint+1]) - int(scenicViewPoints[scenicViewPoint]) <= X:
        curNumViewPoints += 1
    else:
        if curNumViewPoints > maxNumViewPoints:
            maxNumViewPoints = curNumViewPoints
        curNumViewPoints = 1

if curNumViewPoints >= maxNumViewPoints:
    maxNumViewPoints = curNumViewPoints

print(maxNumViewPoints)