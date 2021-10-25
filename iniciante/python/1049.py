tipos = {"vertebrado":
        {"ave": {"carnivoro": "aguia", "onivoro": "pomba"},
        "mamifero": {"onivoro": "homem", "herbivoro": "vaca"}},
        "invertebrado":
        {"inseto": {"hematofago": "pulga", "herbivoro": "lagarta"},
        "anelideo": {"hematofago": "sanguessuga", "onivoro": "minhoca"}}}

tipo1 = input()
tipo2 = input()
tipo3 = input()

print(tipos.get(tipo1).get(tipo2).get(tipo3))