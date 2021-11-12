# -*- coding:utf-8 -*-

while True:
    try:
        num = input()
        cutoff = input()
        inteira = ""
        ponto = False
        if "." in num:
            ponto = True
        
        if ponto:
            num = num.split(".")
        
        if ponto and len(num[1]) != 0 and len(num[0]) != 0:
            if (float(cutoff) <= float("0."+num[1])):
                print(int(num[0])+1)
            else:
                print(int(num[0]))
                
        elif not(ponto):
            print(int(num))
        
        elif ponto and len(num[1]) == 0 and len(num[0]) != 0:
            print(int(num[0]))
            
        elif ponto and len(num[1]) != 0 and len(num[0]) == 0:
            if (float(cutoff) <= float("0."+num[1])):
                print(1)
            else:
                print(0)
        
    except EOFError:
        break