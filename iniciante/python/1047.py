h_inicial, m_inicial, h_final, m_final = input().split()
h_inicial, m_inicial, h_final, m_final = int(h_inicial), int(m_inicial), int(h_final), int(m_final)

# Converter para minutos os horarios
comeco_jogo = h_inicial * 60 + m_inicial
fim_jogo = h_final * 60 + m_final

if fim_jogo <= comeco_jogo:
    # Pega o quanto foi do primeiro dia e soma com o segundo dia
    tempo_jogo = (24 * 60-comeco_jogo) + fim_jogo
else:
    tempo_jogo = fim_jogo - comeco_jogo

# Pega as horas do jogo e os minutos
horas_jogo = tempo_jogo // 60
miutos_jogo = tempo_jogo % 60

print(f"O JOGO DUROU {horas_jogo} HORA(S) E {miutos_jogo} MINUTO(S)")