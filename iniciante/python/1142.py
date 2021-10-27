N = int(input())
n = 1

while N > 0:
    N -= 1
    for i in range(3):
        print(n, end= " ")
        n += 1
        
    n += 1
    print("PUM")