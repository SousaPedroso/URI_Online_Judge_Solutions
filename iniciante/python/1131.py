grenais = 0
vit_inter = 0
vit_gremio = 0
empates = 0
resposta = 1
while resposta != 2:
    gols_inter, gols_gremio = input().split()
    gols_inter, gols_gremio = int(gols_inter), int(gols_gremio)
    grenais += 1

    if gols_inter > gols_gremio:
        vit_inter += 1
    elif gols_gremio > gols_inter:
        vit_gremio += 1
    else:
        empates += 1

    print("Novo grenal (1-sim 2-nao)")
    resposta = int(input())

print(f"{grenais} grenais")
print(f"Inter:{vit_inter}")
print(f"Gremio:{vit_gremio}")
print(f"Empates:{empates}")
if vit_inter > vit_gremio:
    print("Inter venceu mais")
elif vit_gremio > vit_inter:
    print("Gremio venceu mais")
else:
    print("Nao houve vencedor")