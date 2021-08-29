# -*- coding: utf-8 -*-

lin = input()
v = lin.split(" ")
a = int(v[0])
b = int(v[1])
c = int(v[2])
MaiorAB = (a+b+abs(a-b))/2
MaiorAB = (MaiorAB+c+abs(MaiorAB-c))/2
print("%d eh o maior" %MaiorAB)