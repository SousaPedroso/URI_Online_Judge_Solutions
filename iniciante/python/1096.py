i=1
j = 7

while True:
    print(f"I={i} J={j}")
    j -= 1
    
    if i == 9 and j == 4:
        break

    if j == 4:
        i += 2
        j = 7

