from functools import reduce

aplicar = reduce
tam = len
inteiro = int
arredonda = lambda x: inteiro(x + 0.5)
N, C, T = list(map(lambda x: inteiro(x), input().split()))

P = input().split()
P = list(map(inteiro, P))
totalPipocas = 0
totalPipocas = inteiro(aplicar(lambda tot, pipoca: tot + pipoca, P))

if C > N:
    C = N

Pm = totalPipocas // C

# Analise em relação ao limite
competidorAtual = 1
Tc = 0
maximoPipocas = 0
sacosUsados = 0
for i in range(tam(P)):
    Tc += P[i]
    sacosUsados += 1
    if Tc > Pm:
        sacosUsados -= 1

        if competidorAtual < C:
            Tc -= P[i]
            competidorAtual += 1
            sacosUsados += 1
            if maximoPipocas < Tc:
                maximoPipocas = Tc

            Tc = P[i]
        
        else:
            Tc -= P[i]
            break        

while sacosUsados < N:
    Tc += P[sacosUsados]
    sacosUsados += 1

maximoPipocas = max(maximoPipocas, Tc)
# Inicio e fim da busca binaria
inicio = Pm
fim = maximoPipocas

competidorAtual = C
i = 0
pipocas = 0

while True:
    if arredonda((inicio + fim) / 2) == Pm:
        break
    
    competidorAtual = 1
    Tc = 0
    pipocas = 0
    Pm = arredonda((inicio + fim) / 2)
    sacosUsados = 0
    for i in range(N):
        Tc += P[i]
        pipocas += P[i]
        sacosUsados += 1
        if Tc > Pm:
            competidorAtual += 1
            pipocas -= P[i]
            Tc = P[i]
            
            # Se Tc > Pm, nao tera mais como comer pipocas, sair do lacao
            if competidorAtual <= C and Tc <= Pm:
                pipocas += P[i]

            else:
                sacosUsados -= 1
                # Acabaram os competidores ou nao da mais pra comer
                break
    
    # Acabaram os sacos
    if pipocas == totalPipocas:
        fim = Pm
    
    # Acabaram os competidores
    elif sacosUsados < N:
        inicio = Pm
        
    else:
        inicio = Pm
        fim = Pm
    
Tm = Pm // T
if Pm % T > 0:
    Tm += 1

print(Tm)