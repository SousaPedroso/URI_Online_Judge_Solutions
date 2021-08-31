#include <stdio.h>

int main(){

	int N,i, quantidade_de_valores_dentro, quantidade_de_valores_fora;

	scanf("%d", &N);
	quantidade_de_valores_dentro = 0;
	quantidade_de_valores_fora = 0;
	int X[N];
	for (i = 0; i <N; i++){
		scanf("%d", &X[N]);
		if (X[N] >= 10 && X[N] <= 20){
			quantidade_de_valores_dentro += 1;
		}else{
			quantidade_de_valores_fora += 1;
		}
	}
	printf("%d in\n%d out\n", quantidade_de_valores_dentro, quantidade_de_valores_fora);
	
	return 0;
}