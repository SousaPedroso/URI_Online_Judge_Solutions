i=1
j = 7
j_max = 7

while True:
    print(f"I={i} J={j}")
    j -= 1
    
    if i == 9 and j == 12:
        break

    if j == j_max-3:
        i += 2
        j = j_max+2
        j_max += 2
