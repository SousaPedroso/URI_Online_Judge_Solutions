i = 0
j = 1

while True:
    print(f"I={i} J={j}")
    j += 1
    
    if i == 2 and j == 4+i:
        break

    if j == 4+i:
        i += 0.2
        j = 1+i
        i = round(i, 2)
        j = round(j, 2)
        # Checa se e inteiro
        if str(i)[-1] == '0':
            i = int(i)
        
        if str(j)[-1] == '0':
            j = int(j)
