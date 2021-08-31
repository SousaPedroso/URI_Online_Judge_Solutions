#include <stdio.h>

int main(){

	int i, posicao_maior_numero, maior_numero, numero_do_vetor;

	maior_numero = 0;
	posicao_maior_numero = 0;
	for (i=0; i <100; i++){
		scanf("%d", &numero_do_vetor);
		if (numero_do_vetor > maior_numero){
			maior_numero = numero_do_vetor;
			posicao_maior_numero = i+1;
		}
	}
	printf("%d\n%d\n",maior_numero, posicao_maior_numero);
}