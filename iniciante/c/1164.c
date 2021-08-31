#include <stdio.h>

int main(){

	int N, soma_dos_divisores, i,j, X;
	scanf("%d", &N);
	for (i=0; i < N; i++){
		scanf("%d", &X);
		soma_dos_divisores = 0;
		for (j=1; j <X; j++){
			if (X % j == 0){
				soma_dos_divisores += j;
			}
		}
		if (soma_dos_divisores == X){
			printf("%d eh perfeito\n",X);
		}else{
			printf("%d nao eh perfeito\n",X);
		}
	}
}