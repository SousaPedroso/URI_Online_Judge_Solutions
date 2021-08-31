#include <stdio.h>
 
int main() {

	int valor, posicao_par, posicao_impar, contando_a_entrada, valor_par[5], valor_impar[5], i;

	contando_a_entrada = 1;
	posicao_impar = 0;
	posicao_par = 0;
	while (contando_a_entrada <= 15){
		scanf("%d", &valor);
		if (valor % 2 == 0){
			if (posicao_par != 4){
				valor_par[posicao_par] = valor;
				posicao_par += 1;
			}else{
				valor_par[posicao_par] = valor;
				posicao_par = 0;
				for (i=0; i<5; i++){
					printf("par[%d] = %d\n", i, valor_par[i]);
				}
			}
		}else{
			if (posicao_impar != 4){
				valor_impar[posicao_impar] = valor;
				posicao_impar += 1;
			}else{
				valor_impar[posicao_impar] = valor;
				posicao_impar = 0;
				for (i=0; i <5; i++){
					printf("impar[%d] = %d\n", i, valor_impar[i]);
				}
			}
		}
		if (contando_a_entrada == 15){
			for (i=0; i < posicao_impar; i++){
				printf("impar[%d] = %d\n", i, valor_impar[i]);
			}
			for (i=0; i < posicao_par; i++){
				printf("par[%d] = %d\n", i, valor_par[i]);
			}
		}
		contando_a_entrada += 1;
	}

    return 0;
}