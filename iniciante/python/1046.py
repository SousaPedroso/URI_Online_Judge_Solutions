h_inicial, h_final = input().split()
h_inicial, h_final = int(h_inicial), int(h_final)

# O tempo do primeiro dia mais o do outro dia
if h_final <= h_inicial:
    tempo_jogo = (24-h_inicial) + h_final
else:
    tempo_jogo = h_final - h_inicial

print(f"O JOGO DUROU {tempo_jogo} HORA(S)")