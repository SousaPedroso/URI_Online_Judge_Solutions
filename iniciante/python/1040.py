N1, N2, N3, N4, = input().split()

N1 = float(N1)
N2 = float(N2)
N3 = float(N3)
N4 = float(N4)

media = (2*N1+3*N2+4*N3+N4)/10

print(f"Media: {media:.1f}")

if media >= 7:
    print("Aluno aprovado.")

elif media < 5:
    print("Aluno reprovado.")

else:
    print("Aluno em exame.")
    N5 = float(input())
    print(f"Nota do exame: {N5:.1f}")
    media += N5
    media /= 2

    if media >= 5:
        print("Aluno aprovado.")

    else:
        print("Aluno reprovado.")

    print(f"Media final: {media:.1f}")