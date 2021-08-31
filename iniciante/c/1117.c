#include <stdio.h>
 
int main() {

	float nota, media, soma_das_notas;
	int notas_validas;

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
    return 0;
}