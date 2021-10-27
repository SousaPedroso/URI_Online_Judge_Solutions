N = int(input())

for i in range(N):
    num_1, num_2 = input().split()
    num_1, num_2 = int(num_1), int(num_2)
    soma = 0

    if num_1 > num_2:
        num_1, num_2 = num_2, num_1
        
    # Pega o proximo impar
    if num_1 % 2 == 0:
        num_1 +=1
    else:
        num_1 += 2

    for j in range(num_1, num_2, 2):
        soma += j

    print(soma)