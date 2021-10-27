salario = float(input())

if salario <= 2000:
    print("Isento")

else:
    # Salario pra cada taxa menos o que sobra para próxima
    salario_com_imposto = salario - 2000
    if salario_com_imposto > 1000:
        salario_com_imposto -= 1000
        imposto_renda = 1000 * 0.08
        if salario_com_imposto  > 1500:
            imposto_renda += (1500 * 0.18)
            salario_com_imposto -= 1500
            # O que sobrar vai para a maior taxa
            imposto_renda += (salario_com_imposto * 0.28)

        else:
            imposto_renda += (salario_com_imposto * 0.18)
    
    else:
        imposto_renda = salario_com_imposto * 0.08

    print(f"R$ {imposto_renda:.2f}")