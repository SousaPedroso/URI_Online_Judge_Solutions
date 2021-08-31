#include <stdio.h>

int main(){

	int N, menor_valor, i, posicao;
	scanf("%d", &N);
	int  X[N];
	for (i=0; i < N; i++){
	    scanf("%d", &X[i]);
	}
	menor_valor = X[0];
	for (i=1; i <N; i++){
		if (menor_valor > X[i]){
			menor_valor = X[i];
			posicao = i;
		}
	}
	printf("Menor valor: %d\n",menor_valor);
	printf("Posicao: %d\n",posicao);

    return 0;
}