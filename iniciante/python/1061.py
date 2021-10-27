dia_inicio = input().split()[1]
dia_inicio = int(dia_inicio)
hora_inicio, minuto_inicio, segundo_inicio = input().split(" : ")
hora_inicio, minuto_inicio, segundo_inicio = int(hora_inicio), int(minuto_inicio), int(segundo_inicio)

dia_termino = input().split()[1]
dia_termino = int(dia_termino)
hora_termino, minuto_termino, segundo_termino = input().split(" : ")
hora_termino, minuto_termino, segundo_termino = int(hora_termino), int(minuto_termino), int(segundo_termino)

# Tempo em segundos para o inicio e termino
inicio_segundos = hora_inicio * 3600 + minuto_inicio * 60 + segundo_inicio
termino_segundos = hora_termino * 3600 + minuto_termino * 60 + segundo_termino

# Considerar a diferença de dias e somar com o tempo de termino e subtrair o inicio
# Pois nao foram dias completos
tempo_evento = (dia_termino - dia_inicio) * 3600 * 24

tempo_evento += termino_segundos
tempo_evento -= inicio_segundos

# Conversao de volta para dias, horas, minutos e segundos
dias_evento = tempo_evento // (3600 * 24)
tempo_restante = tempo_evento % (3600 * 24)
horas_evento = tempo_restante // 3600
tempo_restante %= 3600
minutos_evento = tempo_restante // 60
tempo_restante %= 60
segundos_evento = tempo_restante // 1

print(f"{dias_evento} dia(s)")
print(f"{horas_evento} hora(s)")
print(f"{minutos_evento} minuto(s)")
print(f"{segundos_evento} segundo(s)")