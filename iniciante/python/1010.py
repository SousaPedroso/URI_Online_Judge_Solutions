codigo1, qtd1, preco1 = input().split()
codigo2, qtd2, preco2 = input().split()

print(f"VALOR A PAGAR: R$ {float(preco1)*int(qtd1)+float(preco2)*int(qtd2):.2f}")