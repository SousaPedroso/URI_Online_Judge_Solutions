#include <stdio.h>
 
int main() {

	float nota, media, soma_das_notas;
	int notas_validas, X;

	X = 1;
	while (X == 1){
		notas_validas = 0;
		soma_das_notas = 0;
		while (notas_validas < 2){
			scanf("%f", &nota);
			if (nota < 0 || nota > 10){
				printf("nota invalida\n");
			}else{
				notas_validas += 1;
				soma_das_notas += nota;
				if (notas_validas == 2){
					media = soma_das_notas / 2;
					printf("media = %.2f\n", media);
				}
			}
		}
		printf("novo calculo (1-sim 2-nao)\n");
		scanf("%d", &X);
		while (X < 1 || X>2){
			printf("novo calculo (1-sim 2-nao)\n");
			scanf("%d", &X);
		}
	}
    return 0;
}