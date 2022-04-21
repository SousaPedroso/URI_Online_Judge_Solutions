# -*- coding: utf-8 -*-

while True:
    try:
        hashmat, enemy = input().split(" ")
        hashmat = int(hashmat)
        enemy = int(enemy)
        print(abs(hashmat-enemy))
    except EOFError:
        break